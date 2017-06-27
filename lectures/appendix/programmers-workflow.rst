C++ Development Workflow
########################

..  include::   /references.inc

When you are learning how to be a professional software developer, there are
many new habits you need to develop. Learning anything new always involves
things like this.

Programming is not just sitting down in front of a computer and pounding away
on a keyboard to see what you can build. That habit may have gotten you through
your first programming courses, but THAT HAS TO STOP NOW!

We need a”workflow”. One that will lead to well written software your employer
can stand to include in some important project, It aso keeps Guido away from your door!)

TL;DR
*****

OK, fine! You don’t have time for all this, your code is late and are not interested in any of this. Just wait, You will be soon enough. I found an interesting post you should read:

	* `Technical Debt <https://m.vladalive.com/how-to-deal-with-technical-debt-33bc7787ed7c>`_

An Example Workflow
*******************

Here are the steps you should be following in developing out code:

Think
=====

Design
======

Project Setup
=============

    * Source Code - Github_

    * Documentation - Sphinx (or at lease |rst|).

TDD
===

Where do your tests come from? For any module (or unit if you prefer) thst you
creaste, there are three things you are concerned with:

    * Preconditions - what must be true before your code will run (parameters)
    * Execute - do the action
    * Postconditions - assert that certain things are true

Your tests come from the first and third. They take the form of something
called "behavior driven testing":

::
    If I have these preconditions, and I do this action, I should see this
    result.  Test for the results you are after.

    `cucumber-cpp <https://github.com/cucumber/cucumber-cpp>`_

code
====

Think again
===========

Check Code Quality
==================

    * `cppcheck <http://cppcheck.sourceforge.net/>`_

    * `valgrind <http://valgrind.org/>`_

debug
=====

If you use TDD, you will find that you do not do much of this!

Repeat until ready
==================

Loop back an continue using these steps until you are satisfied enough to stop.
 
More Quality Checks
===================

profilers:

    * Valgrind (slow)
    * gprof <http://www.math.utah.edu/docs/info/gprof_toc.html>`_


coverage mechanisms

    `gcov/lcov <https://codeflu.blog/2014/12/26/using-gcov-and-lcov-to-generate-beautiful-c-code-coverage-statistics/>`_

Think some more
===============


Your job is to put all of this together into a pattern that becomes your new
working habit. SOme developers get so hooked on this, they get upset if any
step gets skipped. Guido is a wizard at all of this!

