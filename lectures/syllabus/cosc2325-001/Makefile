COURSE  = cosc2325
SECTION = 001
TERM    = spring2017
HOST    = www.co-pylit.org

.PHONY: all
all:    syllabus html

.PHONY: syllabus
syllabus:
	cd syllabus && rst2latex.py --report=5 index.rst > syllabus.tex
	cd syllabus && pdflatex syllabus.tex
	mv syllabus/syllabus.pdf _build/$(COURSE)-$(SECTION).pdf

.PHONY: html
html:
	rst2html.py index.rst > _build/index.html
	rst2html.py syllabus/index.rst > _build/syllabus.html
	cp syllabus/$(COURSE)_textbook.jpg _build

.PHONY: sync
sync:
	rsync -aruv _build/ rblack@$(HOST):html/classes/$(TERM)/$(COURSE)-$(SECTION)
