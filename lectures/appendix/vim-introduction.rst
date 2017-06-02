The Vim Programmer's Editor
###########################

..  include::   /references.inc

You absolutely must learn how to use a good cross-platform editor, not just the
one you currently use that only works on Windows. In my over 50 years of
programming, the one tool I have been able to use on just about any computer
system I have ever touched is a version on Vim_, which is commonly installed on
all Unix/Linux machines. Vim_ is readily available for Windows and Mac users as
well.

Picking an editor is a religious affair. One developer might love editor X, and
another, editor Y. They will go head to head debating the relative merits of
each. 

When you leave this class, you pick the editor you want to use. It is you who
will have to use this thing, and you should learn it well. My rules for picking
one is based on the simple fact that I work on a huge variety of systems, and
Vim_ has always been there for me. YMMV!

I will ask you to use Vim_ in this class, just to give your the experience in
using it. Don't panic, it is not that hard to learn. I does have one
significant quirk, though. It is called a "modal" editor, because at any given
moment in time, Vim is operating in one of two major modfes. More on that
later.

Installing Vim
**************

Before we can do much with this editor, we need to install it. I will show how
to install it on all three major platforms. After that, we will do a short
introduction int it's use.

Installing on Windows
=====================

Download the latest release of gVim (**gvim80.exe**) from the Vim_ website. Run
this file to install the editor on your system.

..  note::

    Be sure to let the installer create files that let you run Vim) on the command line.

Installing on Mac
=================

If you are a software developer,and you use a Mac, I recommend that you install
and learn about Homebrew_. 

Here is how I add MacVim_ to my Mac systems:

First, do this if Homebrew_ is not  installed:

..  code-block:: bash

    $ ruby -e "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install)"

..  warning::

    There is another, currently less popular, tool called *MacPorts* available.
    If you added this one on your system, do not install Homebrew as well. They
    fight with each other!

Then, install MacVim_ as follows:

..  code-block:: bash

    $ brew install macvim
    $ brew linkapps

Once this is done, MacVim_ should be present in the "Applications"folder on
your system.

Installing on Ubuntu Linux
==========================

This is pretty simple. The exact command depends on the version of Ubuntu you
are using:

..  code-block:: bash

    $ sudo apt-get install vim-gtk  (for GUI versions of Ubuntu)
    $ sudo apt-get install vim (for server versionsof Ubuntu)

Vim Configuration
*****************

Vim uses a control file to let the user customize how it works. This is an
important aspect of a good programmer's editor. The name and location of the
control file varies with the system. 

Windows Configuration
=====================

On windows you should see a file named **_vimrc** in the folder where you
installed the editor.

The default location will be something like **C:\Program Files\vim**. 

Mac/Linux Configuration
=======================

On these systems, the configuration file is located a file named **.vimrc** in
your user account home directory. The leading "dot" makes this file invisible
when you normally look at things in a directory. Use the **ls -al** command to
see all the files (including hidden files) 

Sample C0nfiguration
--------------------

At a minimum, add these lines to your configuration file:

..  code-block:: text

    set tabstop=4
    set shiftwidth=4
    set expandtab
    set nobackup

This will change any tabs you enter in code to four spaces, which seems to be
the most common setting in programming. It will also stop Vim_ from creating
backup files when you edit things. We will be using Github_, so we do not need
backups!

..  note::

    There are a huge number of other settings we really should use, and we will
    go over a few of them as the class proceeds. For now, just make sure these are
    set.

..  vim:ft=rst spell:
