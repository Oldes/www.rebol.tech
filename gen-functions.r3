REBOL [
	Title: "Make Rebol dictionary"
	Author: @Oldes
]
import 'json
import 'thru-cache
system/options/quiet: false


test: {
;; The content of this file is parsed to extract function details and usage examples.
;; The function description, along with details of its arguments and refinements, isn't
;; included in this document. Instead, it is sourced directly from the function specification.
;; The original data in this file were collected from https://www.rebol.com/r3/docs/functions.html

## ABOUT
[[ license usage help ]]

Displays REBOL title and version information on the REBOL
console.
```stdout
**************************************************************************
**                                                                      **
**  REBOL 3.0 [Alpha Test]                                              **
**                                                                      **
**    Copyright: 2009 REBOL Technologies                                **
**               All rights reserved.                                   **
**    Website:   www.REBOL.com                                          **
**                                                                      **
**    Version:   2.100.82.3.1                                           **
**    Build:     4-Sep-2009/6:35:16                                     **
**    Warning:   For testing purposes only. Use at your own risk.       **
**                                                                      **
**    Language:  English                                                **
**    Locale:    United States                                          **
**    Home:      C:\rebol\                                              **
**                                                                      **
**************************************************************************
```

------------------------------------------------------------------
## ABS
@@ abbb

------------------------------------------------------------------
## ABSOLUTE
[[ abs sign? negate -]]

Returns a positive value equal in magnitude.
```rebol
>> absolute -123
== 123
>> absolute -1:23
== 1:23
>> absolute -1x4
== 1x4
>> absolute -1x-2
== 1x2
```
------------------------------------------------------------------
## ACCESS-OS
------------------------------------------------------------------
## ACOS
[[ arccosine ]]
------------------------------------------------------------------
## ACTION?
[[ function? op? native? any-function? type? ]]

```html

<p>Actions are special functions that operate with datatypes. See <span class="datatype">action!</span> for more.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">print action? :add
true</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print action? :append
true</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print action? :+
false</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print action? "add"
false</code></pre></div>

```
------------------------------------------------------------------
}

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


as-arg: func[val][ajoin [{<span class="rebarg">} esc-html val </span>]]
as-func: func[name][ ajoin [{<a href="#} name {">} esc-html name {</a>}]]

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
			  		see-also: transcode see-also
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
			  		if p? [append detail "</p>^/" p?: off]
			  		if type != "html" [
			  			detab trim/head/tail code
			  			code: ajoin [
			  				{<div class="example-code"><pre class="} type {-block"><code class="} type {">}
			  				esc-html code {</code></pre></div>}
			  			]
			  		]
			  		append detail code
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
					][ out/:name: copy detail]
				) break
				| LF (if p? [append detail "</p>^/" p?: false])
			  	| copy temp: thru LF (
			  		unless p? [append detail "<p>^/" p?: true]
			  		append detail temp
			  	)
			  ]
		]
	]
	out
][
	alpha: system/catalog/bitsets/alpha
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
				emit [{^/ <h6>Description:</h6>^/} spec/details]
			]
		]
		emit {^/</section>}
		;break
	]
	write %public/doc/functions.inc out
	out
]

emit-funcs-html

