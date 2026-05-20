Rebol [title: "Common utils"]

known-datatypes: [
	"action!"
	"binary!"
	"bitset!"
	"block!"
	"char!"
	"closure!"
	"command!"
	"datatype!"
	"date!"
	"decimal!"
	"email!"
	"end!"
	"error!"
	"event!"
	"file!"
	"frame!"
	"function!"
	"get-path!"
	"get-word!"
	"gob!"
	"handle!"
	"hash!"
	"image!"
	"integer!"
	"issue!"
	"library!"
	"lit-path!"
	"lit-word!"
	"logic!"
	"map!"
	"module!"
	"money!"
	"native!"
	"none!"
	"object!"
	"op!"
	"pair!"
	"paren!"
	"path!"
	"percent!"
	"port!"
	"rebcode!"
	"ref!"
	"refinement!"
	"set-path!"
	"set-word!"
	"string!"
	"struct!"
	"tag!"
	"task!"
	"time!"
	"tuple!"
	"typeset!"
	"unset!"
	"url!"
	"utype!"
	"vector!"
	"word!"
]

current-html: _

form-inline-code: func[text class /local page][
	ajoin switch/default class [
		datatype [
			if current-html != %datatypes.html [page: %datatypes.html]
			[{<a href="} page #"#" text {" class=datatype>} text </a>]
		]
		function [
			if current-html != %functions.html [page: %functions.html]
			[{<a href="} page #"#" text {">} text </a>]
		]
	][[<code class=inline> text </code>]]
]

markdown-ctx: context [
	alpha: system/catalog/bitsets/alpha
	p?: false
	detail: _
	emit: func[val] [
		if p? [append detail "</p>^/" p?: false]
		append detail val
	]
	not-spec: complement charset "[\`*_"
	url-text: complement charset "]^/^M"
	url-href: complement charset ")^/^M"
	b-chars:  complement charset "*\^/"
	u-chars:  complement charset "_\^/"
	c-chars:  complement charset "`\^/"
	md-text: func[val /local out txt href wrd s e][
		;; this is very simplified Markdown conversion of links and inline code
		out: copy ""
		parse val [collect into out any [
			 #"`" s: some [#"\" skip | any c-chars] e: #"`" keep (
				txt: copy/part s e
				replace/all txt #"\" "" 
				form-inline-code txt case [
					all [find known-datatypes txt]                  ['datatype]
					any-function? select lib attempt [to word! txt] ['function]
				]
			)
			| "**" s: some [#"\" skip | any b-chars] e: "**" keep (
				ajoin [<b> md-text copy/part s e </b>]
			)
			| #"_" s: some [#"\" skip | any u-chars] e: #"_" keep (
				ajoin [<u> md-text copy/part s e </u>]
			)
			| #"\" keep skip ;; escape char
			| #"[" copy txt: some url-text "](" copy href: some url-href #")" keep (
				ajoin [{<a href="} href {">} md-text txt </a>]
			)
			| keep some not-spec
		]]
		out
	]
	;- block level rules -
	block-level: [
		"```" copy type: any alpha any SP LF copy code: to "^/```" 4 skip (
			;? type
			trim/tail code
			if type != "html" [
				detab code
				either type == "code" [
					code: gen-code-output code
				][
					code: ajoin [
						{<div class="example-code"><pre class="} type {-block"><code class="} type {">}
						esc-html code {</code></pre></div>}
					]
				]
			]
			emit code
		)
		| "######" some SP copy temp: to LF skip (emit ajoin [LF <h6> md-text temp </h6>])
		| "#####" some SP copy temp: to LF skip (emit ajoin [LF <h5> md-text temp </h5>])
		| "####" some SP copy temp: to LF skip (emit ajoin [LF <h4> md-text temp </h4>])
		| "###" some SP copy temp: to LF skip (emit ajoin [LF <h3> md-text temp </h3>])
		;@@ note: H2 and H1 are ignored, as these are part of the upper context!
		| ahead "- " (emit <ul>) some [
			"- " copy temp: to LF skip (emit ajoin [<li> md-text temp </li>])
		] (emit </ul>)
		| ahead #"|" table-rule (emit-table)
		| ahead #">" blockquote-rule
		| LF (emit "")
		| copy temp: thru LF (
			unless p? [append detail "<p>^/" p?: true]
			append detail md-text temp
		)
	]

	;- table rules -
	cell: [] row: [] rows: []
	cell-chars: complement charset "\|^/"
	escaped-pipe: [#"\" #"|" (append cell #"|")]
	cell-content: [
		some [ 
			  copy tmp: some cell-chars (append cell tmp)
			| "\|" (append cell #"|")
			| #"\" (append cell #"\")
		] (
			append row copy trim/head/tail cell
			clear cell
		)
	]
	table-cell: [ #"|" cell-content ]
	separator-line: [ some [#"|" any [#"-" | #":" | #" "]] LF (append rows '---)]
	empty-line: [ #"|" any #" " newline ]
	table-row: [
		some table-cell opt #"|" LF
		(append/only rows copy row  row: copy [])
	]
	table-rule: [some [empty-line | separator-line | table-row]]
	emit-table: function [][
		emit "^/<table class=doctable>"
		while [not tail? rows][
			emit "^/<tr>"
			row: first+ rows
			type: either word? rows/1 [++ rows 'th]['td]
			foreach cell row [
				emit ajoin [#"<" type #">" md-text cell "</" type #">"]
			]
			emit"</tr>"
		]
		emit "^/</table>^/"
	]

	;- blockquote rules -
	s: e: _
	blockquote-rule: [
		s: some [#">" thru LF] e: (emit-blockquote copy/part s e)
	]
	emit-blockquote: function[text][
		out: copy ""
		parse text [any [remove [#">" opt SP] thru LF]]
		parse text [any SP "**" copy title: to ":**" 3 skip any SP text:]
		either title [
			emit <div class="admonition note">
			emit <p class="admonition-title"> 
			emit title
			emit </p>
			parse text [any block-level]
			emit </div>
		][
			emit <blockquote>
			emit md-text text
			emit </blockquote>
		]
	]
]

esc-html: function/with [txt][
	out: clear ""
	parse to string! txt [ collect into out any [
		  keep some normal
		| #"<" keep ("&lt;")
		| #">" keep ("&gt;")
	]]
	out
][
	normal: complement charset "<>"
]



colorize: function/with [
	text [string!]
][
	clear out
	underline?: off
	code?: off
	parse text [
		any [
			copy str: to delimiter (emit str) [
				s:
				"```" 4 skip to "^/```" e: 4 skip (
					emit-code skip copy/part s e 4
				)
				|
				#"`" (
					emit either/only code? [</code>][<code>]
					code?: not code?
				)
				|
				#"^"" thru #"^"" e: (
					emit either/only code? [
						copy/part s e
					][
						<span class="ansi32">
						copy/part s e
						</span>
					]
				)
				|
				#"_" (
					emit either/only underline? [</u>][<u>]
					underline?: not underline?
				)
				|
				#"^^" (emit copy/part s 1) skip
				|
				#"^/" (emit LF)
			]
		]
		opt [copy str: to end (emit str)]
	]
	if underline? [emit </u>]
	copy out
][
	out: ""
	emit: func[str][
		append out either block? str [ajoin str][str]
	]
	emit-code: func[text /local pos][
		;; Move the code tag before initial indentation
		either all [
			pos: find/last/tail out LF
			parse pos [any SP]
		][	insert pos <code class="desc">][
		][	append pos <code class="desc">]
		emit [ LF text LF </code>]
	]
	not-comm: complement make bitset! ";"  
	delimiter: make bitset! {^/_`^^"}
]


remove-html: function [txt][
	parse txt [any [to #"<" remove thru #">"]]
	txt
]

used-ansi-classes: copy []
ansi-to-html: function/with [text][
	out: copy ""
	end: clear []
	parse text [ collect into out any [
		"^[["
		[
			"38;5;" copy num: 1 3 digit #"m" (cls: ajoin ["ansiclr" num])
			|
			copy val: [
				(cls: clear "")
				any [copy num: 1 3 digit (append cls ajoin ["ansi" num sp]) opt #";"]
				#"m"
			]
		] keep (
			append used-ansi-classes copy trim/tail cls 
			either find ["m" "0m" "39m"] val [
				ajoin take/all end
			][
				append end </span>
				ajoin [{<span class="} cls {">}]
			]
		)
		| keep not-esc
		| skip
	]]
	out
][
	digit: system/catalog/bitsets/numeric
	not-esc: complement charset "^[" 
]

gen-code-output: function [source][
	code: transcode source
	bind code lib
	echo %.temp
	try/with [do source] :print
	echo none
	out: read/string %.temp
	result: ajoin [
		{<div class="example-code"><pre class="rebol-block"><code class="rebol">}
		esc-html source {</code></pre></div>}
	]
	unless empty? out [
		append result ajoin [
			{^/<div class="example-code"><pre class="text-block"><code>}
			ansi-to-html esc-html out {</code></pre></div>}
		]
	]
	delete %.temp
	result
]

as-arg: func[val][ajoin [{<span class="rebarg">} esc-html val </span>]]
as-func: func[name][ ajoin [{<a href="#} name {">} esc-html name </a>]]

to-rebdoc-name: function/with[name][
	name: form name
	parse name [any [
		to esc [
			  change #"?" "-q"
			| change #"!" "-x"
			| change #"+" "-plu"
			| change #"=" "-eq"
			| change #"<" "-qt"
			| change #">" "-lt"
			| change #"*" "-mul"
			| change #"|" "-pip"
			| change #"%" "-per"
			| change #"&" "-and"
			| change #"/" "-div"
		]
		| skip
	]]
	if #"-" == name/1 [insert name #"|"]
	name
][
	esc: charset "?!=/<>+*|%&"
]
