Extra Credit Research Projects
##############################

..  include::   /references.inc

In case you feel you need some extra points to help offset exam grades you are
not happy with, here are some research projects you can work on to earn some
extra credit. The points available can be up to a full letter grade, but only
if you do a really good job putting together a project report. One or two pages
of notes will earn some points, but not that many. Treat this like a
professional research project and write a professional report to get full points.

You will need to make a short presentation on your project on the last day of
class, when we have the final group project presentations. 

Project Requirements
********************

Each project will need to be documented using Microsoft Word or
reStructuredText, if you want to try that. You should include figures you snarf
from the internet (properly, you should note where you got them). The report
should have the following sections:

* Introduction - explain what the project is seeking to do

* Research - where did you find the information needed to complete the project

* Experiments - what experiments did you conduct. What were you trying to find
  out? If you produce code for this project, include the code and explain how
  you set it up and ran it.


* Results - what were your findings

* Conclusions - why would any of this material be of interest to an assembly
  language programmer?

Of course, you should make the report presentable, and run it through the spell
checker at least!  You can use your document to make your presentation, or set
up a PowerPoint presentation. All material should end up checked in to your
GitHub "ExtraCredit" (which will be available soon) repository to get the extra
credit.

..  note::

    this is an individual effort, not a team effort. do your own research and
    come up with your own results.

Here are the research projects:

how does multi-core work
************************


When your processor has multiple cores, you might wonder how it boots up and
how each core gets assigned something to do. This project seeks to explore that
issue.

Basically, you need to research what really happens when a multi-core processor
first powers up, and find out how we can set up individual programs for each
core to process. You should focus on the pentium processor, although you can
look into the Arm for this if you choose.

Here is an Intel document on multi-core architecture that explains things
pretty well. It is a bit dated, but still good reading.

    * :download:`intelmulticorespec.pdf`

You should build some example code that shows how we can get the processor to
run a program on a specific core in your machine. This can be done in C/C++ and
these is code on the Internet showing how to do this. Demonstrate your code in
the Linux VM. (Hint, you will need to configure your VM to use at least two
processors for this to work. Those settings can be made while the machine is
powered down.)

Booting your PC
***************

Without worrying about all the cores in your machine, it is possible to build
am assembly language boot loader for your system that does nothing but fire up
the machine and say something on the system console (like "hello, world"? Nah,
that is too obvious!). All of this must be done in 512 bytes.

This project involves getting a boot loader installed in a virtual machine disk
image, then booting that virtual machine to see our message. There are many
example projects that do this, and several of them use the Nasm_ assembler.

Exploring Intel Micro-Ops
*************************

Intel is pretty quiet about what actually goes on inside the chip, especially
when it comes to the micro-operations used to actually do the work inside the
machine. Lately, though, a number of researchers have constructed
"cycle-accurate" simulators for the Pentium family of chips, and these
simulators set up what they think is a good approximation of the
micro-operations actually at work in the chip. One such simulator is MARSSx86_,
which is hosted on Github_.


This project will explore those micro-ops and describe how they
work. You can get the needed information from the PTLsim manual:

    * :download:`PTLsimManual.pdf`

Of course, the code itself is a good source for information, although it is a
very complex C++ program. The code you need to examine is in the
``core/ooo-core`` subdirectory, and in ``x86/uopimpl.cpp``.

You do not need to study all the micro-operations listed here, just those that
we have studied in this class. Specifically, those needed to implement the
standard structures and do some simple math and logic operations on data.

Experimenting with an assembly-language OS
******************************************

..  _BareMetal: http://www.returninfinity.com/baremetal.html
..  _MikeOS:    http://mikeos.berlios.de/

There are a few open-source projects seeking to write complete operating
systems in assembly language. Two are worthy of note, so this project will
attempt to get at least one of them running in a virtual machine. Fortunately
for us, both projects are using Nasm_ as their assembler.

MikeOS_ is a 16 bit operating system. That means the OS is severly limited in
that it can only work in one megabyte of RAM, and the processor is kept in real
mode. Still, it is an interesting study in simple operating system design.

The BareMetal_ project is building a 64-bit OS using pure assembly language.
This project is pretty advanced, with support for networking running. 

The goal of this exercise it to get at least one of these OS programs running
using a virtual machine.  The documentation for MikeOS_ shows how to set up a
test system using a VM like VirtualBox_.  I found notes on the Internet for
using two VirtualBox VM systems to run the BareMetal_ OS. You work on the code
in one VM running Linux, and boot the OS into another VM which has no OS
installed. The bare VM uses PXE booting to pull the OS from the first VM.
Setting all this up is described in `this document
<https://github.com/ReturnInfinity/BareMetal-OS/blob/master/docs/PXE%20Booting.md>`_.
Getting this setup working will require access to a 64 bit development system
like your laptop or home desktop. The lab machines will not work! 

Exploring a Real-Time AVR OS
****************************

The power of a simple 8-bit microcontroller might surprise you. There are many
operating systems available for the AVR chip, written in C/C++/Assembly
available for you to explore.  Here are a few examples found during a quick
Google search:

    * https://github.com/mbcrawfo/avr-kernel

    * https://github.com/kororos/AvrX

    * https://people.ece.cornell.edu/land/courses/ece4760/TinyRealTime/index.html

Your task here is to set up an example project and see if you can get one of
these projects running. You do not need to do much, just blink a set of LED
lights at different rates will suffuce. I can provide the ahrdware if you need
help.

