Simulator Instruction Set
#########################

In order for our simulator to run a real program, we need to examone the code
it will process. We already know that code will be a simple set of buinary
numbers, but we have not established exactly what those numbers will look like. 

Since our simulator is storing data as a set of bytes in memory, it makes sense
to begin by encoding instructions as a single byte. That will allos up to 256
different instructions, more than enough for our purposes.

Some instructions we will use should be pretty obvious by now. We have a memory
unit that can store bytes, words, etc, and we have an ALU that can add and
subtract both bytes and words. Let's start off with these simple instructiorns:

    * MOV - move data (actually, we will copy a byte)
    * ADD - add two bytes
    * SUB - subtract two bytes
    * HALT - stop the processor

Encoding Instructions
=====================

We need a way to encode our instructions.

We could assign a number to each of these instructions, but managing those
numbers is a pain. Furthermore, using numbers in your code will upset
Guido, so let's use a C++ **enumeration** instead:

..  code-block:: c

    enum Instructions {
        HALT,
        MOV,
        ADD
        SUB,
    }

An enumeration ends up just a way to create a name for a simple number. The
actual data values are simple integers (starting with zero).

You use this new enumeration like so:

..  code-block:: c

    Instruction inst;
    inst = HALT;
    switch(inst) {
        case HALT:
            running = false;
            break
        case ADD:
        ...
    }

Using this feature of C++, extending the instruction set is pretty easy, and
the code is much easier to follow!

Put this enumeration in a header file, and include it whereever it is needed in
your project code.

Register Enumeration
====================

You can use a similar scheme to write code for eht registers.

Instruction Operands
********************

The set of instructions we want to start with is small, but there are
complications to consider.

MOV
===

We are going to follow the Intel standard approach to writing assembly
language. When you have two operands in an instruction, the first one is called
the **destination** and the second one is called the **source**. Generally,
when both operands are needed for the instruction, and the **source** will be
destroyed (overwritten) by the operation.

We have to deal with the possible kinds of operands the **MOV** instruction
will allow. Basically these are possible:

    * move a byte from a register to memory
    * move a byte from memory to a register
    * move a word from a register to memory
    * move a word from memory to a register

How do we tell what is going on? Well, in a line of assembly code, the operands
will have notation indicating what each operand is. Register references will be
obvious, but we need to be careful about memory references. Programmers will be
using names, which appear as labels in the code. These labels are translated
into addresses by the assembler, so the addresses are what will find their way
into the code. As a start, we will only allow the **MOV** instruction ot access
memory locations, meaning that the memory reference is to the container at the
specified address.

Sizing Data
-----------

If our machine allows moving both bytes and words, we have a problem. Those are
two different operations, and should be coded somehow so the controller can
figure out what kind of data to use.

One approach is to specify unique instructions for each possibility. ANother is
to add a field in the instruction that specifies the size of the data involved.
We will use this second approach to keep things a bit simpler.

In our next lecture, we will outline the encoding we can use for this simple simulator.

