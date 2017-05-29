Git Introduction
################

..  _`Linus Torvalds`:            https://en.wikipedia.org/wiki/Linus_Torvalds
..  _Git:                         https://git-scm.com/

What? 

You just spent all day making changes to a major project that was working just
fine, and now nothing works! You need to go back to yesterday and start over.

Can you do that? 

Odds are the answer for many of you is: No! It will take another day to recover
from this disaster!

`Linus Torvalds`_ manages over 1000 programmers who contribute to the
Linux_ kernel code, the hert of Linux_. He certainly cannot afford to let any
one of those programmers break the project (which consists of hyndreds of
directories, and thousands of files, BTW!)

WHoe there were many tools available to help with this problem, he was not satisfied with any of them. So, likle any good programmer, he write his own. 

The tool he developed is called Git_, and today Git_ is one of the most popular *source code control system* tools around. BEst of all, it is free!

We will be using Git to manage all of the code you create for this class. With
any luck, you will never write another line of code that is not being managed
by Git, ever again!

..  note::

    Well, things do change. Maybe there will be a cooler tool that replaces
    Git_ some day!


The Gnu_ project has developed a collection of incredible free software
development and system management tools. If you do not know about `Richard
Stallman`_ and his `Free Software Foundation`_, you should look into it if you
indent to develop software seriously. Although most of these tools are now
associated with the Linux_ operating system, Richard initially set out to
produce a completely free version of the Unix operating system. Today, you can
find these tools on just about any platform.

We will be using the *Gnu Compiler collection (GCC_)* to develop projects for
this class. Specifically, we will use these major tools:

    * **gcc** - the Gnu "C" compiler

    * **g++** - The Gnu "C++" compiler

    * **make** - the Gnu build tool"

..  vim:ft=rst spell:
