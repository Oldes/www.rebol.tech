REBOL [
	Title: "Make Rebol function dictionary"
	Author: @Oldes
]


do %common.reb

with ctx/config/app [
	example-files: read example-dir/*.r3
	example-tags: make map! load %example-tags.reb
	example-perex: copy example-tags
	foreach line read/lines %example-perex.txt [
		parse line [
			copy ttl: to #":" 2 skip copy perex: to end
			(example-perex/:ttl: perex)
		]
	]

	foreach file example-files [
		unless all [
			data: attempt [load/header example-dir/:file]
			hdr: data/1
			string? hdr/title
			parse hdr/title ["Rosetta code: " copy title to end]
		][	print ["Failed:" file] continue ]
		unless block? blk: examples/:title [
			blk: examples/:title: copy []
		]
		append blk file
		unless tag: example-tags/:title [
			print mold title 
		]
	]
	examples-sorted: sort/skip to block! examples 2

	page-content: %example.rsp

	while [not tail? examples-sorted][
		set [title: files:] examples-sorted
		link-prev: if examples-sorted/-2 [
			reduce [
				examples-sorted/-2
				replace copy examples-sorted/-1/1 %.r3 %.html
			]
		]
		examples-sorted: skip examples-sorted 2
		link-next: if examples-sorted/1 [
			reduce [
				examples-sorted/1
				replace copy examples-sorted/2/1 %.r3 %.html
			]
		]

		print title
		clear ctx/out/content
		example-title: title
		page-title: ajoin ["Rebol Examples: " title]
		example-code: copy []
		sort/compare files func[a b][a/length > b/length]
		html-file: replace copy first files %.r3 %.html
		foreach file files [
			append example-code esc-html detab read/string example-dir/:file
		]
		insert html-file %public/examples/

		page-content: %source/example-content.rsp
		rsp-process ctx %source/page.rsp
		write html-file ctx/out/content
	]

	print-hline
	;? example-files
	print as-yellow page-title: "Rebol3 Code Examples"
	page-content: %examples-content.rsp
	highlight?: off
	rsp-process ctx %source/page.rsp
	probe write %public/examples/index.html ctx/out/content
]

