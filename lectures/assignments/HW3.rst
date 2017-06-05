..  _hw3:

HW3: Exploring Data Types
#########################

..  include::   /references.inc

..  note::

    For any future homework assignments, you will not be finding one of those
    "invitation" links. All homework will be submitted by placing the work in a new
    folder (with a suitable name) in your "Homework" project folder. See
    :ref:`git-introduction` to get started working with Git_.

We want to gain a better understanding of how computers actually work. We have
to start somewhere, so let's begin by looking at data, and how it is
represented in our systems.

You should have the basic idea that all of your data ends up in that thing we
call :term:`memory` somewhere.  The question you probably
never gave much though to is exactly how is it stored there, and what does it
look like?

We will explore that in more detail later. For this homework assignment, I want
you to explore the basic data types supported by the language we will be using
to build out simulator. That language is C++.

The C++ language is defined in a precise way by a standards committee so
everyone can be sure they are using the same language, no matter what system
and compiler you use. Here is a copy of the latest standard document for C++
(specifically, C++14):

    * :download:`/files/C++14draft.pdf` 

What To Do
**********

You will build a simple single-file C++ program for this homework. You can do
this any way you want, as long as the source code file ends up in your Homework
repository in the folder named "HW3".

There are several "Fundamental Data Types" specified in the standard:

    * character types
    * signed integer types
    * unsigned integer types
    * boolean types
    * floating point types
    * void type
    * null-pointer type

Step1: Create Each Type
=======================

For all of the defined data types, create a line of code that sets up a simple
variable that can hold one of those types and gives it an initial value. 

Step2: Explore the Range of Values
==================================

Next, we want to explore the range of values each of those data types supports.
What is the largest value, and the smallest value that can be represented in
each one. It surprises many beginners that computers don't do math the same way
humans do math, and this is something you really need to understand as a
developer.

There is a standard tool to assist with this:

`* :ref:`std::numeric_limits <http://en.cppreference.com/w/cpp/types/numeric_limits>`_ 

..  warning::

    You might get your first look at a C++ feature called **templates** in
    this. The example code you see on the reference web page should show you all
    you need to know to do this assignment.

If you cannot get one of the not-so-common data types set up, just ignore that one and move on.

Submitting Your Work
********************

All you need to do to submit this homework, assuming you have managed to create
your ``Homework`` repository and cloned it to your workstation, is the
following:

Run these commands from a :term:`command prompt` while working at the top of
your ``Homework`` repository directory:

..  code-block:: bash

    $ git status
    $ git add . 
    $ git commit -m "finished homework 2"
    $ git push origin master

The message you provide (in quotes) on that *commit* line is recorded in a log,
and you should say something meaningful here. 

Use ``git status`` often to see what Git_ thinks about your project at any
time. 

Finally, after that `git push`` command, you should see messages indicating
your work is being transmitted to the GitHub_ server. Any time you interact with
that server you will need to provide your credential (your password). Notes on
setting up your personal machine (not the lab machine, I am afraid) so you do
not need to enter a password, will be available in the Appendix).

Once that completes, open up a web browser and check your project there. If you
see your new work on GitHub_ I can see it as well, and you are done!

..  note::

    I do not require it, but it is common to generate a "pull request" when
    your assignment is ready for grading
 
..  vim:ft=rst spell:
