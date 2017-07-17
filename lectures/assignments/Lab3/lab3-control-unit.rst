Lab3: Modeling the Controller
#############################

..  include::   /references.inc

Finally, we can put enough of a machine together to run some simple code. In
this lab, we will build a simple controller, one that follows the "four step"
process to add up a few numbers.

Here is the invitation link for the project repository:

    * `Lab3-Controller-Unit <https://classroom.github.com/assignment-invitations/577a6de7b79ebbc9e372472ec714de39>`_

..  note::

    This repo does not have starter code. You will need to create the folder
    contents using your last two labs as a guide. Just copy folders and files over
    as needed to set this up. The code should compile fine, assuming the last two
    projects ran. (see below)

Project Setup
*************

After you clone your project, set up the folders using your previous labs as a
guide. Copy in the **Makefile**, and all tests from your last two labs. (Those
classes should still run properly). You need to copy the header and
implementation files from your **Memory** class and your **ALU** class into
this project. You will create a new class for the **Controller**.

Create a dummy **main..cpp** (a variant of "Hello, World" will do).

Before you add any new code, run **make** and be sure all your old code still
runs and passes the tests you set up. When you get to this point, you are ready
to build new code!

Basic Controller Operation
**************************

The controller class will set up a fairly complete machine for you to run.  For
this lab, we will only implement a few basic instructions, enough to see the
machine in action.

The Controller constructor should create a memory object and an ALU object. It
will also need a few internal "registers" to do its work. Specifically, you
will need these:

    * PC - program counter
    * IR - instruction register
    * R1-R8 - General purpose 16_bit registers

Your controller will support a few  important "public" operations. 

    * run - start the simulation loop
    * load_code - load instruction memory from a text file
    * load_data - load data memory from a text file 

Running the Simulation
======================

The **run** method that takes no parameters, and simple starts the "four-step"
loop.

..  code-block::    c

    while(true) {
        fetch();
        decode();
        execute();
        retire();
    }

(You will need to tweak this code to deal with all requirements.

Tracking Time
=============

There are two time related values we need to track in this controller object.
The number of instructions processed, and the number of clock ticks consumed.

If memory was really fast, then these two values would be the same. However,
every time the controller needs to move data back and forth between the
processor and memory, we have to deal with that "wait" situation. Your memory
unit alrready has this set up, so the basic logic for tracking these two values
is pretty simple. Each pass through the four-step loop bumps the instruction
counter by one, and also increases the clock counter by one. Any memory access
encountered inside the loop may inject additional counts to the clock counter.
This will let us see the cost of accessing memory in our code.

A simple way to deal with this is to make the four step functions return a
clock count value if needed. Here is the idea:

..  code-block:: c

    instruction_count = 0;
    clock_count = 0;
    while(true) {
        clock_count += fetch();
        clock_count += decode();
        clock_count += execute();
        clock_count += retire();
        instruction_count++;
    }

In this simulation, each "step" will consume a minimum of one clock tick. That
means that one instruction takes at least four "ticks" to complete. A real processor
can do one instruction in as little as one tick, but we need to explore
pipelining to see how that works. For this lab, no pipelining is required.

When the simulation is completed, you should report these two values to the
user.

Loading Memory
==============

We need a simple way to get code and data into the simulator's memory. For this
project, we will use two text files, with one decimal number per line. The
exact values placed in these files will need to be figured out, and the
lectures on encoding instructions will help with this.

..  note::

    I added an example program which is sufficient for this lab. It only needs
    byte data.

The **load_code** routine is needed to load the instruction memory.  The
**load_data** routine does a similar thing with the program data memory. 

This lab can be limited to just byte data. You do not need to modify your
memory or ALU code, we will just ignore word data for this lab.

ALU Operations
==============

Unlike memory, the ALU is typically very fast, especially for simple integer
operations. We do not need to worry aout timing in this lab. You can assume
that all ALU operations happen n one clock tick.

 
Testing Your Class 
******************

I have included some example code in the **main.cpp** file. This code shows how
we can deal with options on the command line when we run the application. Look
this over, since we will use it later.

..  literalinclude::    main.cpp
    :linenos:
    :language: c
    :caption: main.cpp

You need to add tests to make sure your new Controller class operates properly.

Remember that this test code uses the Catch_ testing system. You will need to
set up a project, as discussed in class, so these tests run properly. You also
need to make sure the following commands work:

..  code-block:: bash

    $ make clean
    $ make
    $ ./test

You should see no errors when this sequence completes. If you get here, your
code works as specified. Guido and I will review the code itself to see if it
is written properly!

I will activate automatic testing on TravisCI_ as soon as I see your cloned repo
on Github_. Be sure to modify the badge link  in the project **README.rst**
file, so it shows your status.

