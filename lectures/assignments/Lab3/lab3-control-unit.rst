Lab2: Modeling the Controller
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

The controller class will set up a fairly complete machine for you to run. The
constructor should create a memory object and an ALU object. It will also need
a few internal "registers" to do its work. Specifically, you will need these:

    * PC - program counter
    * IR - instruction register
    * R1-R8 - General purpose 16_bit registers

Your controller will support a few  important "public" operations. 

    * run - start the simulation loop
    * load_code - load instruction memory from a text file
    * load_data - load data memory from a test file 

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

Loading Memory
==============

The **load_code** routine is needed to load the instruction memory. For this
project, the code will consist of the following data items:

    1. INST - a single byte with a code for ehte instruction
    2. REG - a single byte with a code for eth eregister used (0-7) [optional]
    3. LMEM - a 16-bit iteral or memory address

The code file is a simple text file with decimal numbers, one per line. Refer to the SImultor INstruction Set lecture for details on encoding gthe instructions. 


The **load_data** routine does a similar thing with the program data memory. 

8 or 16 bit data items are allowed, and it will be up to the instruction to
load them correctly. We will talk about this in class.

ALU Operations
==============

Unlike memory, the ALU is typically very fast, especially for simple integer
operations. We do not need to worry aout timing in this lab.

 
Testing Your Class 
******************

I have included some example code in the **main.cpp** file. This code shows how
we can deal with options on the command line when we run the application. Look
this over, since we will use it later. For now, you can leave this code alone,
or play with it if you like. 

..  literalinclude::    main.cpp
    :linenos:
    :language: c
    :caption: main.cpp

You need to add tests to make sure your new COntroller class operates properly.

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

I will activate automatic testing on TavisCI_ as soon as I see your cloned repo
on Github_. Be sure to modify the badge link  in the project **README.rst**
file, so it shows your status.

