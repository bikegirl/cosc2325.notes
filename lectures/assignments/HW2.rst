..  _hw2

Homework 2: Time for a Time Out!
################################

..  include:: /references.inc

We need to understand some time sensitive terminology, and get a feel for
speed!

In this course, you are going to see just how fast things move inside your
system. To make sense of this, you will do a bit of research on the Internet to
come up with the numbers. 

How to do this homework
***********************

..  warning::

    Get in the habit of reading assignments carefully. There are many things you
    need to do to complete each assignment properly. If needed, take a red pen and
    underline every requirement in this assignment. Before you submit it for
    grading, review your list and check off every line you underlined to be sure you
    did the job correctly.


To complete this homework, you will need to dig some numbers out from the Web,
and calculate other numbers. For each number you use as an answer, I want a
reference (URL) showing where you found the information, or the expression you
evaluated with the calculator (something like 5280*12). Show that information
in parentheses after your answer. If you get several answers from a single
reference, include that reference only once.

Some background
***************

First, it is important to understand that our computers are driven by
electricity, which you might think of as the flow of electrons through wires.
Actually, it is the movement of an electromagnetic wave that is important, not
the movement of electrons themselves. In doing your research, you might
discover that electrons do not move much, but those waves really fly! 

What You Need to Determine
**************************

..  warning::

    You will need a calculator to do this work, in addition to data from the
    Web!

Here are the pieces of information I want you to locate. You need to edit the
places where `<??>` is shown below. (leave the angle brackets in place,they are
used in grading):

Basic measurement units:
========================

    * 1 meter = <??> inches

    * 1 mile = <??> feet 
      
    * 1 mile = <??> meters

    * Circumference of the Earth = <??> miles


Basic terminology
=================

We prefix numbers in the world of science with some basic terms. Determine what
these mean:

    * `yotta` something = <??> times something
    
    * `kilo` something = <??> times something

    * <??> something = 100 times something
    
    * <??> something = 10 times something

    * something = something (duh!)

    * `milli` something = 1/<??> of something

    * `micro` something = 1/<??> of something

    * `nano` something = 1/<??> of something

    * <??>something = 1/1000000000000 of something

From Physics
============

* What is the speed of light 
  
    * = <??> mps (miles per second)

    * = <??> kps (kilometers per second)

Speed of Electronic Signals
===========================

Assuming electronic waves move through wire at the speed of light:

* How far an electronic signal can move through a wire:

    * In one nanosecond = <??> inches

    * In one microsecond = <??> feet

    * In one millisecond = <??> miles
    
    * In one second = <??> miles

    * In one second = <??> times around the Earth!

From our World of Processors
============================

One last piece of the puzzle. I would like to see if you can figure out how
fast a signal moves between transistors in a typical Pentium processor. To
figure that out, we need to figure out how far apart they are. We will keep
this simple.

We will look at numbers for the Intel Haswell line of processors.
Unfortunately, most manufacturers use the metric system to report how big (or
small) things are, so all of the numbers in this section will be in meters (or
smaller). 

Dig out data for the Haswell Processor. Specifically, use this version:

    * Intel i7-7700, 7th Generation Pentium chip

        * Manufacturing Process = <??>nm

        * Transistor Count = <??> transistors

        * Die Size: <??>mm^2

Lookup this information on the chip:

    * Number of cores = <??>
    
    * Number of threads = <??>

    * Maximum (turbo) clock frequency = <??> GHz.

    * Maximum memory = <??> GB.

Assuming that the chip is square, and that there are, say, 1,400,000,000 transistors
on the chip, we can take the square root of 1.4 billion to see how many
transistors must be on each side of the square. If the actual chip has a
surface area of 264 square millimeters, figure out how long each side is, and
using your numbers from above, figure out how long it takes for an electronic
signal to move the distance between two adjacent transistors. (Be sure to check
the equation you used to figure this out. Many students mess this one up!)

    * Distance between transistors = <??> nanometers.

As a check (ballpark, at least), see if your calculations match the
manufacturer's current technology. They report their ability to squeeze
transistors together in nanometers. Are your numbers close?

..  note::

    Remember that there must be room for all the "wires", actually called
    traces, needed to move signals from one place to another. So, it might seem
    like there is plenty of room left for that, in actual fact, we are reaching
    the limits on how small we can manufacture things. That is, unless we come
    up with a new technology!

Finally, calculate the time it will take for an electron to move between two
adjacent transistors.

    * Time to move electrons between adjacent transistors = <??> picoseconds.

Counting up
***********

As a last bit of trivia, lets see how big a 64-bit integer really is.

The current Pentium processor uses 64-bit "registers". Assuming your processor is
ticking away at a rate of 2.7 GHz, how long will it take to reach the biggest
number the register can hold (Hint: the biggest number is 2^64 - 1):

    * Time until the register hit the maximum value = <??> years

References
**********

Remember to include documentation on your sources.

What to turn in
***************

Use this guide to help you format your homework:

    * `reStructuredText Quick Start
      <http://docutils.sourceforge.net/docs/user/rst/quickstart.html>`_.

You will write this up using your programming editor of choice. Make sure your
file ends with en extension of `.rst` when you add this work to your homework
repository.

When you have uploaded your file to the GitHub_ server, check out the file
using your web browser. It will be formatted so it looks like a nice web page.
Do not get carried away with this for now. This markup language is designed to
be simple to learn and use, and it leaves your text file readable, even without
processing. As long as the file ends with a `.rst` extension, GitHub_ will
automatically convert the page to HTML so it looks nice in your browser.

I want YOU to be proud of the quality of your work! Using good tools will help
you get to this point!

reStructuredText_ is rapidly becoming a standard in documenting software
projects. While it was originally developed to document Python language, it is
increasingly being used elsewhere. The tool most often used to process
documentation for large projects is Python Sphinx_. We will take a look at this
tool a bit later in the course.

..  vim:filetype=rst spell


..  vim:ft=rst spell:
