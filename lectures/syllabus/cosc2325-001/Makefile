COURSE  = cosc2325
SECTION = 001
TERM    = spring2017
HOST    = www.co-pylit.org

.PHONY: all
all:    syllabus

.PHONY: syllabus
syllabus:
	rst2latex.py --report=5 index.rst > syllabus.tex
	pdflatex syllabus.tex
	mv syllabus.pdf ../$(COURSE)-$(SECTION).pdf
