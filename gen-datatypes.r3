REBOL [
	Title: "Make Rebol datatype dictionary"
	Author: @Oldes
]
do %common.reb
system/options/quiet: false

current-html: %datatypes.html

load-datatypes-details: function/with [data][
	if file? data [data: read/string data]
	out: make map! 500
	replace/all data #"<" "&lt;"
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
					][ out/:name: copy trim/head head detail]
				) break
				|
			  	block-level
			  ]
		]
	]
	out
] :markdown-ctx


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
