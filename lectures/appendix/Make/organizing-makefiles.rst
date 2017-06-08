..  _organizing-makefiles:

Organizing Makefiles
####################

..  include::   /references.inc

I do a lot of development on my systems, and use Make_ for most projects. Yes,
I know there are better tools around for building, but I teach beginners, and
Make_ is a tool they need to learn about, so I do a lot of work with it.

I also work on all three major platforms, since I have students coming into my
classes with all kinds of systems, so I try to set up projects that will work
anywhere, as long as the basic tools are installed and working properly!

This note shows how I set up a Make_ system that helps keep project
``Makefile`` files as simple as possible. I do this by removing parts of the
``Makefile`` that should not change to a known location, and including those
parts as needed in project files.

System PATH Settings
********************

..  note::

    This note is vendor neutral, meaning it should work on any system. In
    examples I will use this notation:

        - ``$`` is the command line prompt.

        - ``/`` is is used for directory path separators, even on PC.

        - (No drive letter id shown in path strings, add this on PC as needed).

An important part of working at the :term:`command prompt` is making sure all
of your main tools can be launched easily. That means making sure that the
system search ``PATH`` variable includes the places where your tools are
installed. 

On all of my systems (PC included) I set up a common structure:

Project Layout
**************

Part of this setup depends on having a standard layout for any project. The
pattern I use is fairly common:

..  code-block:: text

    project_name/
        |
        +- docs/ - holds all project documentation
        |
        +- tests/ - holds all project test code
        |
        +- src/ - holds all application code
        |
        +- lib/ - for any library code needed by the project
        |
        +- bin/ - this is where build files will be located
        |
        +- include/ - any header files will live here

While this layout is best suited for C/C++ projects, it works for Python
projects as well (with a few tweaks). 

..  vim:filetype=rst spell:

