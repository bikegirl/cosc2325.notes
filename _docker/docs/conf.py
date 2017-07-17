# -*- coding: utf-8 -*-
#
import os
import sys
sys.path.insert(0, os.path.abspath('.'))


# -- General configuration ------------------------------------------------

extensions = []
templates_path = ['_templates']
source_suffix = '.rst'
master_doc = 'index'

# General information about the project.
project = u'Docker Tests'
copyright = u'2017, Roie R. Black'
author = u'Roie R. Black'

version = u'0.1'
release = u'0.1'
language = None

exclude_patterns = ['_build', 'Thumbs.db', '.DS_Store']
pygments_style = 'sphinx'
todo_include_todos = False


# -- Options for HTML output ----------------------------------------------

html_theme = 'alabaster'
html_static_path = ['_static']


# -- Options for LaTeX output ---------------------------------------------

latex_elements = {
    'papersize': 'letterpaper',
    'pointsize': '12pt',
    'figure_align': 'htbp',
}

latex_documents = [
    (master_doc, 'DockerTests.tex', u'Docker Tests',
     u'Roie R. Black', 'manual'),
]
