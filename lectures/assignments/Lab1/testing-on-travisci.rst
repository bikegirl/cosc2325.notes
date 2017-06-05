Testing on TravisCI
*******************

..  include::   /references.inc

When you clone your lab project repositories (after accepting the invitation
through the link on the assignment page), any tests you set up can be run
automatically using the services of TravisCI_. This is pretty cool, but you do
not have full control over this process in this class setup.

..  note::

    This is something you can do for free on any public repositories you set up
    in your personal account on Github_.
    

Once I see that the repo has been cloned, I will activate the link to TravisCI.
At that point, any time you push new code to Github_, TravisCI_ will
automatically fire up a new Linux virtual machine, and clone your repository
into it. You will provide information on what TravisCI_ is to do using a simple
file named **.travis.yml** that you put in your project repository, at the same
level as the **.git** folder.

Here is a sample file:

..  literalinclude::    /code/Memory/.travis.yml
    :linenos:
    :caption: .travis.yml

The file is written in another of those markup languages" we have been talking
about (like |RST|). The language is called **YAML** (Yet Another Markup
Language - who says programmers do not have a sense of humor?) Indenting is
important in this file, and is usually only two spaces.

The first line in this file identifies the programming language you are using.

The **compiler** line identifies exactly what compiler you want to use for this
project. (It is possible to set up a list of compilers, to make sure your code
works on all of them!)

The really important pat of this file is that **script** part.

The two lines below that line are commands you want to run to complete your
test. TravisCI will run each of them, in the order specified. If each command
exits with no errors, your build "succeeded". If their are any errors in any step, the
build "failed".

TravisCI_ generates an image file, which you can embed in your **README.rst**
file (you do have one of those in your project repository, right!) The URL for
this badge is found by navigating to the TravisCI web site and logging in to it
(you can use your Github_ credentials for this). You should see your project
listed. Click on the project, and the current build status badge is shown to
the right of the project name. The URL you need to copy into your
**README.rst** file is shown there.  The actual |RST| line looks something like
this:

..  code-block:: rst

    .. image::  https://travis-ci.com/ACC-COSC2325-001-SU17/Lab1-Memory.svg?token=83eTDixzjHz75nxE14oq&branch=master

Messy, but it points to your personal project. 

When the build finishes, you will get an email telling you what happened when
your build was run. You can them navigate to your Github_ account, and see your
nice build "badge". Most programmers who use these automated testing services
will not get up from their work session until they see a green badge. Guido
likes that!

..  vim:ft=rst spell:
 
