#!/usr/bin/env python3
# -*- coding: utf-8 -*-
#
import os
import sys
sys.path.insert(0, os.path.abspath('.'))

from better import better_theme_path

# -- General configuration ------------------------------------------------

extensions = [
    'sphinx.ext.viewcode',
    'sphinx.ext.imgmath',
    'sphinx.ext.todo',
    'sphinx.ext.autosummary',
]
templates_path = ['_templates']
source_suffix = '.rst'
master_doc = 'index'

# General information about the project.
project = 'COSC2325'
copyright = '2017, Roie R. Black'
author = 'Roie R. Black'

version = 'SU17'
release = 'SU17'
language = None
exclude_patterns = ['_build', 'Thumbs.db', '.DS_Store']
pygments_style = 'sphinx'
todo_include_todos = False


# -- Options for HTML output ----------------------------------------------

html_theme_path = [better_theme_path]
html_theme = 'better'
# html_theme_options = {}
html_static_path = ['_static']
html_logo = '_static/images/ACClogo.png'

# -- Options for LaTeX output ---------------------------------------------

latex_elements = {
    # The paper size ('letterpaper' or 'a4paper').
    #
    'papersize': 'letterpaper',
    'pointsize': '11pt',
    # 'preamble': '',
    'figure_align': 'htbp',
}

latex_documents = [
    (master_doc, 'COSC2325.tex', 'COSC2325 Lecture Notes',
     'Roie R. Black', 'manual'),
]

