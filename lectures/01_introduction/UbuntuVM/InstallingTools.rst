..  _ubuntu-tool-install:

Installing Tools in Ubuntu
##########################

..  include::   /references.inc

..  _`git-introduction`:  /courses/general/Git/index.html
..  _`installing-vim`:    /courses/general/Vim/index.html

Once you have your :term:`virtual machine` set up with a version of Ubuntu_
Linux, you need to add the tools we need for this course. 

This is actually not too hard to do! After logging into your machine, type in
these commands:

..  code-block:: text

    sudo apt-get install build-essential
    sudo apt-get install nasm
    sudo apt-get install git-core
    sudo apt-get install vim-gtk

This will get the basic tools installed. We still have a bit of setup work to
do, but this is the minimum you need to do to get working. 

Many tools need additional configuration files to be set up before you can
really get to work. These commands have done none of that. Of the set we
installed here, both Git_ and Vim_ typically need more work. That will be
discussed in the notes on each package. (See `git-introduction`_ and
`installing-vim`_).


..  vim:filetype=rst spell:
