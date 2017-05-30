# -*- coding: utf-8 -*-
"""
    sphinx.ext.pylit_oz
    ~~~~~~~~~~~~~~~~~~~

    Allow zed/oz specification blocks to be included in Sphinx-generated
    documents inline.

    :copyright: Copyright 2012 by the Roie Black
    :license: BSD, see LICENSE for details.
"""
from sphinx.errors import SphinxError
from sphinx.util.nodes import set_source_info
from sphinx.util.compat import Directive
from docutils import nodes
from docutils.parsers.rst import directives

import tempfile, os, hashlib, shutil

class LatexExtError(SphinxError):
    category = 'Latex Extension Error'

class RenderLatexImage(object):

    def __init__(self, text, font_size=11):
        print "Rendering",text, os.getcwd()
        self.text = text
        self.font_size = font_size
        self.imagedir = os.path.join(os.getcwd(),'build','html','_images')

    def render(self):
        '''return name of final image file'''
        # generate a unique name for the image
        hash = hashlib.md5(self.text).hexdigest()
        outfn = os.path.join(self.imagedir, hash + '.png')
        if os.path.exists(outfn):
            return outfn

        # create tem file for running latex
        print "Rendering latex iage", hash + '.png'
        tempdir = tempfile.mkdtemp()
        curpath = os.getcwd()
        os.chdir(tempdir)

        # create the latex file to process
        self.wrap_text()

        # run latex to build the dvi file
        status = os.system("latex --interaction=nonstopmode objectz")
        assert 0==status, tempdir
        
        # run dvipng to convert image to a png file
        status = os.system('dvipng -T tight -z9 -o objectz.png objectz.dvi')
        assert 0==status, tempdir

        # copy the image to the final directory
        os.chdir(curpath)
        imagepath = os.path.abspath(self.imagedir)
        if not os.path.exists(imagepath):
            os.makedirs(imagepath)
        print "copying file to",imagepath, outfn
        shutil.copyfile(os.path.join(tempdir, "objectz.png"),outfn)
        shutil.rmtree(tempdir)
        return outfn

    def wrap_text(self):
        latex_class = 'article'
        objectzscript = self.text
        font_size = self.font_size
        text = """\\documentclass[%(font_size)spt]{%(latex_class)s}
\\usepackage{oz}
\\pagestyle{empty}
\\begin{document}
%(objectzscript)s
\\end{document}""" % locals()

        # write script out to build file
        f = file('objectz.tex','w')
        f.write(text)
        f.close()

class Pylit_ozError(SphinxError):
    category = 'Pylit-oz error'

class pylit_oz(nodes.General, nodes.Element):
    pass

class Pylit_oz(Directive):

    has_content = True
    required_arguments = 0
    optional_arguments = 1
    final_argument_whitespace = True
    option_spec = {
        'label': directives.unchanged,
        'name': directives.unchanged,
        'nowrap': directives.flag,
    }

    def run(self):
        latex = '\n'.join(self.content)
        node = pylit_oz()
        node['latex'] = latex
        node['label'] = None
        node['docname'] = self.state.document.settings.env.docname
        ret = [node]
        set_source_info(self,node)
        return ret

def html_visit_pylit_oz(self, node):
    latex = node['latex']
    try: 
        imagedir = self.builder.imgpath
        print "VISIT", imagedir, self.builder.images
        fname  = RenderLatexImage(latex).render()
        print "rendered image:",fname
    except LatexExtError, exc:
        msg = unicode(str(exc), 'utf-8', 'replace')
        sm = nodes.system.message(msg, type-'WARNING', level=2,
            backrefs=[], source=node['latex'])
        raise nodes.SkipNode
        sm.walkabout(self)
        self.builder.warn('display latex %r: ' % node['latex'] + str(exc))
        raise nodes.SkipNode
    if fname is None:
        self.body.append('<span class="math">%s</span>' %
                self.encode(node['latex']).strip())
    else:
        c = ('<img class="math" src="%s"' % fname)
        self.body.append(c + '/>')
    raise nodes.SkipNode

def latex_visit_pylit_oz(self, node):
    self.body.append(node['latex'])
    raise nodes.SkipNode

def setup(app):
    app.add_node(pylit_oz,
            html = (html_visit_pylit_oz, None),
            latex = (latex_visit_pylit_oz, None),
    )
    app.add_directive('pylit-oz', Pylit_oz)

