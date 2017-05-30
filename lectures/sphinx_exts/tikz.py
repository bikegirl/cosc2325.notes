# -*- coding: utf-8 -*-
"""
    sphinx.ext.tikz
    ~~~~~~~~~~~~~~~

    Include TiKz graphics in Sphinx documents

    :copyright: 2016 by Roie R. Blacl
    :license: BSD, see LICENSE for details
"""
from sphinx.errors import SphinxError
from sphinx.util.nodes import set_source_info
from docutils.parsers.rst import Directive
from docutils import nodes, utils
from docutils.parsers.rst import directives

import os
import shutil
import tempfile
import hashlib

LATEX_IMAGE_DIR = '/Users/rblack/_lib/images/'
IMAGE_URL = '/_images/'
LATEX_BUILD_DIR = '/Users/rblack/_acc/tmp/images'

class TikzExtError(SphinxError):
    category = 'Tikz extension error'

DOC_HEAD = r'''\documentclass[preview]{standalone}
\usepackage{tikz}
'''

DOC_BODY = r'''
\begin{document}
\begin{tikzpicture}
%s
\end{tikzpicture}
\end{document}
'''

class RenderTikzImage(object):

    def __init__(self, text, font_size=11):
        print "Rendering", text, os.getcwd()
        self.text = text
        self.font_size = font_size
        self.imagedir = os.path.join(os.getcwd(),
        '_build','html','_images')

    def render(self):
        '''return name of final rendered image file'''
        hash = hashlib.md5(self.text).hexdigest()
        hname = hash + '.png'
        outfn = os.path.join(self.imagedir, hname)
        if os.path.exists(outfn):
            return hname

        # create temp file for running lates
        print "Rendering latex image as pdf", hash + '.png'
        tempdir = tempfile.mkdtemp()
        curpath = os.getcwd()
        os.chdir(tempdir)

        # create latex file to process
        self.wrap_text()

        # run pdflates to build pdf file
        status = os.system('pdflatex --interaction=nonstopmode tikz')
        assert 0 == status, tempdir

        # convert to png file
        status = os.system('convert -density 300 tikz.pdf -quality 90 tikz.png')

        # copy final image to image dir
        os.chdir(curpath)
        imagepath = os.path.abspath(self.imagedir)
        if not os.path.exists(imagepath):
            os.makedirs(imagepath)
        print "Copying file to ", imagepath, outfn
        shutil.copyfile(os.path.join(tempdir, "tikz.png"), outfn)
        shutil.rmtree(tempdir)
        return hname

    def wrap_text(self):
        latex = DOC_HEAD 
        latex += (DOC_BODY) % self.text

        # write latex file
        f = file('tikz.tex','w')
        f.write(latex)
        f.close()


class tikz(nodes.General, nodes.Element):
    pass

class Tikz(Directive):

    has_content = True
    required_arguments = 0
    optional_arguments = 1
    final_argument_whitespace = True
    option_spec = {
        'label': directives.unchanged,
        'name': directives.unchanged,
        'nowrap': directives.flag,
        'width': directives.unchanged,
        'align': directives.unchanged,

    }

    def run(self):
        latex = '\n'.join(self.content)
        node = tikz()
        node['latex'] = latex
        node['label'] = None
        node['docname'] = self.state.document.settings.env.docname
        style = ''
        if 'width' in self.options:
            style += 'width=%s' % self.options['width']
        if 'align' in self.options:
            style += ' class="align-%s"' % self.options['align']
        node['style'] = style

        ret = [node]
        set_source_info(self,node)
        return ret

def html_visit_tikz(self, node):
    latex = node['latex']
    try:
        imagedir = self.builder.imgpath
        fname = RenderTikzImage(latex).render()
        print "Rendered imge:", fname
    except TikzExtError, exc:
        msg = unicode(str(exc), 'utf-8', 'replace')
        sm = nodes.system_message(msg, type='WARNING', level=2,
                backrefs=[], source=node['latex'])
        raise nodes.SkipNode
        sm.walkabout(self)
        self.builder.warn('display latex %r: ' % node['latex'] + str(exc))
        raise nodes.SkipNode
    if fname is None:
        # something failed -- use text-only as a bad substitute
        self.body.append('<span class="tikz">%s</span>' %
                         self.encode(node['latex']).strip())
    else:
         c = ('<img class="tikz" src="%s/%s" %s' % (IMAGE_URL,fname,node['style']))
         self.body.append( c + '/>')
    raise nodes.SkipNode

def latex_visit_tikz(self, node):
    self.body.append('$' + node['latex'] + '$')
    raise nodes.SkipNode

def latex_visit_displaytikz(self, node):
    self.body.append(node['latex'])
    raise nodes.SkipNode

def setup(app):
    app.add_node(tikz,
        latex=(latex_visit_tikz, None),
        html=(html_visit_tikz,None))
    app.add_directive('tikz', Tikz)

 
