REBOL [
	Title: "Make Rebol dictionary"
	Author: @Oldes
]

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

ansi-to-html: function/with [text][
	out: copy ""
	end: clear []
	parse text [ collect into out any [
		"^[[" copy val: [
			(cls: clear "")
			any [copy num: 1 3 digit (append cls ajoin ["ansi" num sp]) opt #";"]
			#"m"
		] keep (
			either find ["m" "0m"] val [
				ajoin take/all end
			][
				append end </span>
				ajoin [{<span class="} trim/tail cls {">}]
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

gen-code-output: function[source][
	code: transcode source
	bind code lib
	echo %.temp
	try/with code :print
	echo none
	out: read/string %.temp
	result: ajoin [
		{<div class="example-code"><pre class="rebol-block"><code class="rebol">>> }
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

load-func-details: function/with [data][
	if file? data [data: read/string data]
	out: make map! 500
	parse data [
		any [
			  opt CR LF
			| ";;" thru LF
			| "## " copy name: to LF skip (
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
			  	"```" copy type: any alpha any SP LF copy code: to "^/```" 4 skip (
			  		;? type
			  		trim/head/tail code
			  		if type != "html" [
			  			detab trim/head/tail code
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
				| #"-" some "-" any SP opt LF (
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
					][ out/:name: copy head detail]
				) break
				| "#######" some SP copy temp: to LF skip (emit ajoin [LF <h7> temp </h7>])
				| "######" some SP copy temp: to LF skip (emit ajoin [LF <h6> temp </h6>])
				| "#####" some SP copy temp: to LF skip (emit ajoin [LF <h5> temp </h5>])
				| "####" some SP copy temp: to LF skip (emit ajoin [LF <h4> temp </h4>])
				| "###" some SP copy temp: to LF skip (emit ajoin [LF <h3> temp </h3>])
				| LF (emit "")
			  	| copy temp: thru LF (
			  		unless p? [append detail "<p>^/" p?: true]
			  		append detail md-text temp
			  	)
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
	not-spec: complement charset "[]\`"
	url-text: complement charset "]^/^M"
	url-href: complement charset ")^/^M"
	md-text: func[val /local out txt href tmp][
		;; this is very simplified Markdown conversion of links and inline code
		out: copy ""
		parse val [collect into out any [
			#"`" copy tmp: some not-spec opt #"`" keep (
				ajoin either/only #"!" == last tmp [
					{<span class="datatype">} tmp </span>
				][	{<a href="#} tmp {">} tmp </a>]
			)
			| #"\" keep skip ;; escape char
			| #"[" copy txt: some url-text "](" copy href: some url-href #")" keep (
				ajoin [{<a href="} href {">} md-text txt </a>]
			)
			| keep some not-spec
		]]
		out
	]
]

get-func-info: function[key value][
;? key
	spec: spec-of :value
	;?? spec
	args: copy []
	refs: copy []
	refa: copy []
	retu: copy []
	parse spec [
		any block!
		copy desc: any string!
		(rets: none args: copy [])
		any [
			set arg: [word! | lit-word! | get-word!] 
			set def: opt block!
			set des: any string! (
				repend args [arg def reform any [des ""]]
			)
			|
			quote return: set rets: block! set des: opt string! (
				repend retu [rets any [des ""]]
			)
		]
		any [
			(refa: copy [])
			set ref: refinement!
			set des: opt string!
			(repend refs [ref reform any [des ""]])
			any [
				set arg: [word! | lit-word! | get-word!] 
				set def: opt block!
				copy des: any string!
				(
					repend refa [arg def reform any [des ""]]
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
	desc: reform desc
	if empty? args [args: none]
	if tmp: find refs /local [clear tmp] 
	if empty? refs [refs: none]
	to map! reduce/no-set [
		name:        key
		usage:       usage
		description: desc
		type:        type?/word :value
		arguments:   args
		refinements: refs
		returns:     retu
	]
]

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

out: clear ""
emit: func[data][
	if block? data [data: ajoin data]
	append append out data LF
]

emit-funcs-html: does [
	details: load-func-details %public/doc/functions.md
	? details
	data: make block! 1000
	foreach [key value] system/contexts/lib [
		if any-function? :value [
			append data nm: to-rebdoc-name :key
			append data m: get-func-info :key :value
			m/details: details/:key
		]
	]
	sort/skip/case data 2
	clear out

	foreach [name spec] data [
		parse name ["|" name:]
		emit [{
<hr>
<section id="} spec/name {">
 <a name="} spec/name {"></a>
 <h2>} uppercase form spec/name {<a class="headerlink" href="#} spec/name {" title="Link to this heading">¶</a></h2>}]

 		either ref? spec/details [
 			emit [{<p>Note: Shell shortcut for <a href="#} lowercase spec/details {">} spec/details {</a>.</p>}]
 		][
			emit [<p> spec/description </p>]
			emit [{
<h6>Usage:</h6>
<pre class="usage fs-5">} spec/usage {</span></pre>}]
					if any [spec/arguments spec/refinements] [
					emit {^/<pre class="help">}
					if spec/arguments [
						emit {<span class="tit">ARGUMENTS:</span>}
						foreach [n t d] spec/arguments [
							t: either t [ajoin [{[<span class="types">} t {</span>]}]][""]
							emit reform [{ } pad n 11 t d]
						]
					]
					if spec/refinements [
						emit {<span class="tit">REFINEMENTS:</span>}
						foreach [n d a] spec/refinements [
							emit reform [{ } pad mold n 11 d]
							foreach [n t d] a [
								t: either t [ajoin [{[<span class="types">} t {</span>]}]][""]
								emit reform [{  } pad n 10 t d]
							]
						]
					]
					emit </pre>
				]
			if spec/details [
				emit [{^/<h6>Description:</h6>^/} spec/details]
			]
		]
		emit {</section>}
		;break
	]
	write %public/doc/functions.inc out
	out
]

emit-funcs-html

