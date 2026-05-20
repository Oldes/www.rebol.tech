REBOL [
	Title: "Make Rebol function dictionary"
	Author: @Oldes
]

do %common.reb
foreach m [brotli zstd zlib-ng deflate bzip2][ attempt [import (m)] ]
system/options/quiet: false

current-html: %functions.html

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
					][ out/:name: copy head detail]
				) break
				|
			  	block-level
			  ]
		]
	]
	out
] :markdown-ctx

get-func-info: function[key value][
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

emit-funcs-html: function/with [] [
	details: load-func-details %public/docs/functions.md
	;? details
	data: make block! 1000
	foreach [key value] system/contexts/lib [
	;foreach [key value] reduce ['format :format] [
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
<pre class="usage fs-6">} spec/usage {</span></pre>}]
			if any [spec/arguments spec/refinements] [
				emit {^/<pre class="help">}
				if spec/arguments [
					emit {<span class="tit">ARGUMENTS:</span>}
					foreach [n t d] spec/arguments [
						t: either t [ajoin [{[<span class="types">} t {</span>]}]][""]
						emit reform [{ } pad n 11 t]
						emit-description d
					]
				]
				if spec/refinements [
					emit {<span class="tit">REFINEMENTS:</span>}
					foreach [n d a] spec/refinements [
						emit reform [{ } pad mold n 11 d]
						foreach [n t d] a [
							t: either t [ajoin [{[<span class="types">} t {</span>]}]][""]
							emit reform [{  } pad n 10 t]
							emit-description d
						]
					]
				]
				emit </pre>
			]
			if any [spec/details not empty? spec/extra-desc] [
				emit {^/<h5>Description:</h5>^/}
				if not empty? spec/extra-desc [
					emit [<div class="extra-desc"> colorize trim/auto ajoin/with spec/extra-desc LF </div>]
				]
				emit spec/details
			]
		]
		emit {</section>}
		;break
	]
	write %public/docs/functions.inc out
	out
][
	out: clear ""
	emit: func[data][
		if none? data [exit]
		if block? data [data: ajoin data]
		append append out data LF
	]

	emit-description: function [des][
		if any [none? des empty? des] [return ""]
		des: trim/auto ajoin/with des LF
		des: split-lines colorize des
		;; determine if the first string fits the width of the terminal
		take/last out
		either all [
			pos: find/last/tail out LF
			((length? remove-html copy pos) + (length? des/1)) < 100
		][
			emit [SP uppercase/part des/1 1]
			++ des
		][  append out LF ]
		foreach line des [
			emit ["              "  line]
		]
	]
]


emit-funcs-html
used-ansi-classes: sort unique used-ansi-classes
?? used-ansi-classes

