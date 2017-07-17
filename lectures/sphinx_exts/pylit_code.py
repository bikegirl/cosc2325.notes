# -*- coding: utf-8 -*-
"""
    sphinx.directives.pylit_code
    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    :copyright: Copyright 2012 by Roie R. Black
    :license: BSD, see LICENSE for details.
"""

import sys
import codecs

from docutils import nodes
from docutils.writers.html4css1 import Writer, HTMLTranslator as BaseTranslator
from docutils.parsers.rst import Directive, directives

from sphinx import addnodes
from sphinx.util import parselinenos
from sphinx.util.nodes import set_source_info

class pylit_code(nodes.General, nodes.Element):
    pass

class pylit_include(nodes.General, nodes.Element):
    pass

class PylitCodeBlock(Directive):
    """
    Directive for a code block with special highlighting or line numbering
    settings.
    """

    has_content = True
    required_arguments = 1
    optional_arguments = 0
    final_argument_whitespace = False
    option_spec = {
        'linenos': directives.flag,
        'emphasize-lines': directives.unchanged_required,
    }

    def run(self):
        code = u'\n'.join(self.content)
        linespec = self.options.get('emphasize-lines')
        if linespec:
            try:
                nlines = len(self.content)
                hl_lines = [x+1 for x in parselinenos(linespec, nlines)]
            except ValueError, err:
                document = self.state.document
                return [document.reporter.warning(str(err), line=self.lineno)]
        else:
            hl_lines = None

        literal = nodes.literal_block(code, code)
        literal['language'] = self.arguments[0]
        literal['language'] = 'text'
        literal['linenos'] = 'linenos' in self.options
        if hl_lines is not None:
            literal['highlight_args'] = {'hl_lines': hl_lines}
        set_source_info(self, literal)
        return [literal]


class PylitInclude(Directive):
    """
    Like ``.. include:: :literal:``, but only warns if the include file is
    not found, and does not raise errors.  Also has several options for
    selecting what to include.
    """

    has_content = False
    required_arguments = 1
    optional_arguments = 0
    final_argument_whitespace = False
    option_spec = {
        'linenos': directives.flag,
        'tab-width': int,
        'language': directives.unchanged_required,
        'encoding': directives.encoding,
        'lines': directives.unchanged_required,
        'emphasize-lines': directives.unchanged_required,
    }

    def run(self):
        document = self.state.document
        if not document.settings.file_insertion_enabled:
            return [document.reporter.warning('File insertion disabled',
                                              line=self.lineno)]
        env = document.settings.env
        rel_filename, filename = env.relfn2path(self.arguments[0])

        encoding = self.options.get('encoding', env.config.source_encoding)
        codec_info = codecs.lookup(encoding)
        try:
            f = codecs.StreamReaderWriter(open(filename, 'rb'),
                    codec_info[2], codec_info[3], 'strict')
            lines = f.readlines()
            f.close()
        except (IOError, OSError):
            return [document.reporter.warning(
                'Include file %r not found or reading it failed' % filename,
                line=self.lineno)]
        except UnicodeError:
            return [document.reporter.warning(
                'Encoding %r used for reading included file %r seems to '
                'be wrong, try giving an :encoding: option' %
                (encoding, filename))]

        linespec = self.options.get('lines')
        if linespec is not None:
            try:
                linelist = parselinenos(linespec, len(lines))
            except ValueError, err:
                return [document.reporter.warning(str(err), line=self.lineno)]
            # just ignore nonexisting lines
            nlines = len(lines)
            lines = [lines[i] for i in linelist if i < nlines]
            if not lines:
                return [document.reporter.warning(
                    'Line spec %r: no lines pulled from include file %r' %
                    (linespec, filename), line=self.lineno)]

        linespec = self.options.get('emphasize-lines')
        if linespec:
            try:
                hl_lines = [x+1 for x in parselinenos(linespec, len(lines))]
            except ValueError, err:
                return [document.reporter.warning(str(err), line=self.lineno)]
        else:
            hl_lines = None

        text = ''.join(lines)
        if self.options.get('tab-width'):
            text = text.expandtabs(self.options['tab-width'])
        retnode = nodes.literal_block(text, text, source=filename)
        set_source_info(self, retnode)
        if self.options.get('language', ''):
            retnode['language'] = self.options['language']
        if 'linenos' in self.options:
            retnode['linenos'] = True
        if hl_lines is not None:
            retnode['highlight_args'] = {'hl_lines': hl_lines}
        env.note_dependency(rel_filename)
        return [retnode]

def html_visit_pylit_code(self, node):
    lang = self.highlightlang
    linenos = node.rawsource.count('\n') >= \
              self.highlightlinenothreshold - 1
    highlight_args = node.get('highlight_args', {})
    if node.has_key('language'):
        # code-block directives
        lang = node['language']
        lang = 'text'
        highlight_args['force'] = True
    if node.has_key('linenos'):
        linenos = node['linenos']
    def warner(msg):
        self.builder.warn(msg, (self.builder.current_docname, node.line))
    highlighted = self.highlighter.highlight_block(
        node.rawsource, lang, warn=warner, linenos=linenos,
        **highlight_args)
    starttag = self.starttag(node, 'div', suffix='',
                             CLASS='highlight-%s' % lang)
    self.body.append(starttag + highlighted + '</div>\n')
    raise nodes.SkipNode

def html_visit_pylit_include(self, node):
    lang = self.highlightlang
    linenos = node.rawsource.count('\n') >= \
              self.highlightlinenothreshold - 1
    highlight_args = node.get('highlight_args', {})
    if node.has_key('language'):
        # code-block directives
        lang = node['language']
        lang = 'text'
        highlight_args['force'] = True
    if node.has_key('linenos'):
        linenos = node['linenos']
    def warner(msg):
        self.builder.warn(msg, (self.builder.current_docname, node.line))
    highlighted = self.highlighter.highlight_block(
        node.rawsource, lang, warn=warner, linenos=linenos,
        **highlight_args)
    starttag = self.starttag(node, 'div', suffix='',
                             CLASS='highlight-%s' % lang)
    self.body.append(starttag + highlighted + '</div>\n')
    raise nodes.SkipNode

def setup(app):
    app.add_node(pylit_code,
        html = (html_visit_pylit_code, None),
    )
    app.add_node(pylit_include,
        html = (html_visit_pylit_include, None),
    )
    
    app.add_directive('pylit-code', PylitCodeBlock)
    app.add_directive('pylit-include', PylitInclude)
