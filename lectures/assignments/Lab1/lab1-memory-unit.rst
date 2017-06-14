Lab1: Modeling Memory
#####################

..  _Catch: https://github.com/philsquared/Catch
  
The memory unit in a computer is conceptually a pretty simple component. In
this lab, we will build a C++ class to model memory in a simple way. Later, we
will add more features to this component.

..  note::

    This lab is a continuation of the work shown in this week's lab lecture.
    You should read through that before starting this assignment.

Here is the invitation link for the project repository:

    * `Lab1-Memory-Unit <https://classroom.github.com/assignment-invitations/d3032c6b2adfb9257d0b1762181ef801>`_

Basic Structure
***************

In most machines, memory is basically a byte-addressable array of storage. That
means every byte in the array has a unique "address" (think index) and each
byte holds just a single 8-bit data item. Memory has no idea what is in that
8-bits. The bits can represent anything.

In our model, we want to be able to read bits from this unit, and write bits to
this unit. Pretty simple. We can model the memory unit as a simple array C++
*unsigned char* variables.

This should be easy. But there is a catch.

Reading and writing is not as simple as you might expect. In the real memory,
we send the data to the memory unit over wires. Exactly how is something we will
explore later. We also provide "signals" telling the memory unit what to do. It
responds with "status"signals, and the data we requested (for read).

Here is a specification for the unit we need. It is provided as a C++ header
file defining the class you need to complete.

..  literalinclude::    /code/Memory/include/Memory.h
    :linenos:

We may need to alter this specification later. We will go over that in class.

Behavior
********

The methods defined in this class model the behavior of an object constructed
from our class. We have provided methods to **read** and **write** data in the
specification. Notice that these methods return nothing. Since it takes time for
the memory unit to do it's work, we need a way to model that delay time. In
this assignment, we will use a simple integer counter to indicate how long it
takes to do the required work. You will need to call the **ready** routine a
number of times to model this delay. Each call will return **false**, until the
correct delay is reached, then it will return **true**.

It turns out that memory is painfully slow when compared to the processor
itself. (Not as slow as something like a hard disk, though. That one is
glacially slow in the processor's view!)

Background Info
***************

Most computers work on one fundamental chunk of data. That chunk is most often
one of these sizes:

..  csv-table::
    :header: size, C++ Type

    8, uint8_t
    16, uint16_t
    32, uint32_t
    64, uint64_t

There are signed versions of these as well. For our memory module, we will use
these, since the memory has no clue about signed data. Bits is bits! To use
these data types you need to include the **cstdlib** header. 

Breaking Up Data
================

We need to be able to break up a big pile of bits into 8-bit chunks. C/C++ can
help here. Here is some code that will help

..  code-block:: c

    #include <stdio.h>

    int main( void ) {
        unsigned long x = 0x11223344;   // 32 bits

        printf("Shifty bits\n");
        printf("0x%08lx\n", x);
        printf("0x%08lx\n", x >> 8);
        printf("0x%08lx\n", x >> 16);
        printf("0x%08lx\n", x >> 24);
        printf("0x%08lx\n", (x >> 8) & 0xff);
    }

The ">>" is a right shift operator here (see it is not used just for input).
The "&" is a logical **AND** operation, which ends up stripping away all of the
bits in the variable except for the low 8-bits. Thisis called "masking" of the
unwanted bits. by shifting and masking, we can isolate the set of bits we want
and stuff them into a single 8-bit memory container.

Assembling Data
===============

Going the other way, we need to read the bytes and assemble a bigger data item.
This time, all we need to do is shift and add. We could also use the **OR**
operator ("|") to accomplish the same thing (faster, by the way):

..  code-block:: c

    x = byteval1 | (byteval2 << 8 ) | (byteval3 << 16) | (byteval4 << 24);

Think about that. Should it work? Better yet, try that out in the simple example above.

    
Testing Your Class
******************

We do not really need a main program for this lab, the class is intended to
live in a bigger project. However, we do need to setup a way to see if the
class works as specified. To do that, we will write tests that exercise the
class.  This is part of *Test Driven Development*.

Here is the test code that you are to use to check your work.

..  literalinclude::    /code/Memory/tests/test_memory.cpp
    :linenos:

This test code uses the Catch_ testing system. You will need to set up a
project,as discussed in class, so these tests run properly. You also need to
make sure the following commands work:

..  code-block:: bash

    $ make clean
    $ make
    $ make test

You should see no errors when this sequence completes. If you get here, your
code works as specified. Guido and I will review the code itself to see if it
is written properly!

Final Notes
***********

For this lab, the initial provided test is pretty lame. You are free to modify
this class specification, as you feel is needed to build something that really
works. 9hint, overloading **read** and **write** is surely a good idea. YYu are
also free to add/change the test code. Use the provided test function a a model
(look into the catch_ docs) and add at least one really good test for your
class.

