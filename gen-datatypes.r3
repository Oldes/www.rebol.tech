REBOL [
	Title: "Make Rebol dictionary"
	Author: @Oldes
]

;@@TODO: Merge with get-functions.r3  !!!!


system/options/quiet: false


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


known-datatypes: [
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
"list!"
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
"refinement!"
"routine!"
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

current-html: "datatypes.html"

load-datatypes-details: function/with [data][
	if file? data [data: read/string data]
	out: make map! 500
	parse data [
		any [
			  opt CR LF
			| ";;" thru LF
			| "## " copy name: to LF skip (
				? name
				see-also: none
				detail: clear ""
				p?: false
				name: to word! lowercase name
			  )
			  opt [
				"[[" copy see-also: to "]]" thru LF (
					see-also: sort transcode see-also
				)
				|
				"@@ " copy temp: thru LF to "^/--" (
					detail: as ref! trim/head/tail temp
				)
			  ]
			  any [
			  	;@@ break on ---- divider
			  	"-" some "-" any SP opt LF (
					if p? [append detail "</p>^/" p?: off]
					if see-also [
						append detail {^/<div class="see-also">See also: }
						foreach name see-also [
							append append detail as-func name ", "
						]
						clear skip tail detail -2
						append detail </div>
					]
					unless any [
						detail == ""
						detail == "<p>No description provided.</p>"
					][ out/:name: copy trim/head head detail]
				) break
				|
			  	block-level
			  ]
		]
	]
	out
][
	alpha: system/catalog/bitsets/alpha
	p?: false
	detail: none
	emit: func[val] [
		if p? [append detail "</p>^/" p?: false]
		append detail val
	]
	not-spec: complement charset "[\`"
	url-text: complement charset "]^/^M"
	url-href: complement charset ")^/^M"
	md-text: func[val /local out txt href tmp wrd][
		;; this is very simplified Markdown conversion of links and inline code
		out: copy ""
		parse val [collect into out any [
			#"`" copy tmp: some not-spec opt #"`" keep (
				ajoin case [
					all [find known-datatypes tmp]  [[{<a href="#} tmp {" class=datatype>} tmp </a>]]
					any-function? select lib attempt [to word! tmp] [[{<a href="functions.html#} tmp {">} tmp </a>]]
					'else [[<code class=inline> tmp </code>]]
				]
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
		| "######" some SP copy temp: to LF skip (emit ajoin [LF <h6> temp </h6>])
		| "#####" some SP copy temp: to LF skip (emit ajoin [LF <h5> temp </h5>])
		| "####" some SP copy temp: to LF skip (emit ajoin [LF <h4> temp </h4>])
		| "###" some SP copy temp: to LF skip (emit ajoin [LF <h3> temp </h3>])
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

get-datatype-info: function[key value][
;? key
	spec: spec-of :value
	args: copy []
	refs: copy []
	refa: copy []
	retu: copy []
	parse spec [
		any block!
		set desc: string! copy desc-ext: any string!
		(rets: none args: copy [])
		any [
			set arg: [word! | lit-word! | get-word!] 
			set def: opt block!
			copy des: any string! (
				repend args [arg any [def [any-type!]] des]
			)
			|
			quote return: set rets: block! set des: opt string! (
				repend retu [rets any [des ""]]
			)
		]
		any [
			(refa: copy [])
			set ref: refinement!
			copy des: any string!
			(repend refs [ref des])
			any [
				set arg: [word! | lit-word! | get-word!] 
				set def: opt block!
				copy des: any string!
				(
					repend refa [arg any [def [any-type!]] des]
				)
			]
			(append/only refs copy refa)
		]
		to end
	]
	either op? :value [
		usage: reform [as-arg args/1 key as-arg args/4]
	] [
		usage: mold key
		foreach [arg def des] args [
			append append usage #" " as-arg arg
		]
	]
	case []
	if empty? args [args: none]
	if tmp: find refs /local [clear tmp] 
	if empty? refs [refs: none]
	to map! reduce/no-set [
		name:        key
		usage:       usage
		description: desc
		extra-desc:  desc-ext
		type:        type?/word :value
		arguments:   args
		refinements: refs
		returns:     retu
	]
]

;probe get-func-info 'format :format
;quit
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

emit-datatypes-html: function/with [] [
	data: load-datatypes-details %public/docs/datatypes.md
	clear out

	foreach [name description] data [
		emit [{
<hr>
<section id="} name {">
 <a name="} name {"></a>
 <h2>} uppercase form name {<a class="headerlink" href="#} name {" title="Link to this heading">¶</a></h2>}]
 		emit description
		emit {</section>}
	]
	write %public/docs/datatypes.inc out
	out
][
	out: clear ""
	emit: func[data][
		if none? data [exit]
		if block? data [data: ajoin data]
		append append out data LF
	]
]

emit-datatypes-html
