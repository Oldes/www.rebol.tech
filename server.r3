#!/usr/local/bin/rebol3 -s
Rebol [
	Title:  "Webserver for rebol.tech"
	File:   %server-rebol.tech.r3
	Date:    9-Mar-2025
	Author: "Oldes"
	Version: 1.0.0
	Needs:   3.16.0
]

import %httpd.reb

system/schemes/httpd/set-verbose 0
system/options/quiet: false

make-dir %_logs/  ;; make sure that there is the directory for logs

serve-http [
	port: 8100
	;- Main server configuration                                                                 
	root: %public/
	keep-alive: [30 100] ;= [timeout max-requests] or FALSE to turn it off
	log-access: %_logs/rebol.tech-access.log
	log-errors: %_logs/rebol.tech-errors.log
	list-dir?:  true
	app: context [
		name: "Rebol3 Documentation"
	]
]

