..  _addressing-modes:

Address modes
#############

..  include::   /references.inc

Effective Addresses
*******************

* We have been referring to a chunk of data using a label
    * This is an alias for a simple address

* We have also referred to memory indirectly
    * Using an address stored in a register (``mov rbx, [rdx]``)

* When we calculate the actual address, we call it an ``effective address``.
    * The Pentium can do several kinds of calculations
    * These are designed to access data structures!


Addressing modes
****************

In all of these modes, the actual address will be calculated using data stored
in the instruction and/or registers. Here are the combinations defined for the
chip:

* Register Addressing - data involves register memory
* Immediate Addressing - operand is included in the instruction
* Memory Addressing
* Direct Addressing [``disp``] - normal access, ``disp`` is the offset
* Indirect Addressing
* Register Indirect [Base]
* Based Addressing [Base + ``disp``]
* Indexed Addressing [(Index*scale) + ``disp``]
* Based-Indexed [Base + Index + ``disp``]
* Based-Indexed-Scaled [Base + (Index * scale) + ``disp``]

EA components
*************

In 64-bit mode, the calculations of an offset to a point in memory are
controlled by the following components:

* Displacement - an 8, 16, or 32 bit literal value
* Base - a 32 bit (or 64-bit) general-purpose register
* Index - a 32-bit (or 64-bit) general purpose register
* Scale - a value of 2,4,or 8 that is multiplied by the Index value

The use of 64-bit registers is controlled by a special bit in the chip.
Normally, the 32-bit registers are used. This gives a range of 4GB which is
normally enough.

The offset is normally calculated from the start of the memory available to the
chip. In the 64-bit processor all segment registers are effectively set to
zero.

RIP Relative offsets
====================

There is a special offset mode that calculates the distance from RIP to a point
in memory. This mode encodes a 32-bit displacement into the instruction. To
access this mode, we must tell the assembler to work this way by specifying
the ``DEFAULT`` directive:

..  code-block:: text

    DEFAULT REL     ; generate RIP relative offsets
    DEFAULT ABS     ; generate absolute displacements

..  note::

    Experimenting with these two settings generate identical code, so it looks
    like we can ignore this.




Examples of address modes
*************************

First, we need a chunk of data to track: 

..  code-block:: bash

    ; set up a data area
    segment     .data
    mydata      dq  0x1111111111111111
                dq  0x2222222222222222
                dq  0x3333333333333333
                dq  0x4444444444444444
                dq  0x5555555555555555
    
    segment     .bss
    mydata2     resq    1


Register addressing
===================

* This mode of addressing does not actually fetch from memory.
    * Registers are memory with simple names, not addresses


..  code-block:: bash

    mov     rax, rbx            ; only registers are involved

* Here the register is a data source, and destination

Immediate addressing
====================

* Our next addressing mode fetches data from the instruction stream
    * actually, from the instruction itself.

..  code-block:: bash
    
    mov     rax, mydata         ; immediate addressing


The literal address will be stored in the instruction stream for this instruction

Memory addressing
=================

* From this point on, we will actually be loading data from memory.
    * The actual address must be calculated from other values

* Let's start off with an easy fetch.

Direct addressing
=================

* This form of addressing includes the address in instruction

..  code-block:: bash

    mov     rax, [mydata]       ; direct memory reference - fetch
    mov     [mydata2], rax      ; direct memory reference - store

Indirect addressing
===================

* The next few addressing modes involve registers that hold values
    * Look for patterns of usage here

Register indirect
=================

* Here, we load an address into a register

..  code-block:: bash

    mov     rbx, mydata1        ; load the address into the register
    mov     rax, [rbx]          ; register indirect fetch

Based Indirect Addressing
=========================

* Here we use one register to point to the start of a block of data
    * Other components are accessed using an offset

..  code-block:: bash

    mov     rbx, mydata
    mov     rax, [rbx + 4]
    mov     rax, [rbx + 512]
    mov     rax, [rbx + 0xffff]
    mov     rax, [rbx - 0x28d]

Are any of these valid accesses? Where in memory would we end up?

Indexed Addressing
==================

Next up the complexity level is *Indexed Addressing*. This form of addressing
is typically used to access the elements of an array:

..  code-block:: bash

    mov     rsi, 0
    mov     rax, [mydata + rsi*8]
    inc     rsi
    mov     rbx, [mydata + rsi*8]

Here, we are using **esi** as an index register. 
    * the scale factor tells the processor we are accessing 64 bit data.

Based Indexed Addressing
========================

We can combine these last two examples and do a bit more complex addressing:

..  code-block:: bash

    mov     rbx, mydata
    mov     rsi, 0
    mov     rax, [rbx + rsi]
    mov     rcx, [rbx + rsi + 4]

The assembler can mix simple math in with these expressions as long as
everything ends up compatible with one of the addressing modes.

Based Indexed Scaled Indirect
=============================

This is the last one, I promise, and the most complex:

..  code-block:: bash
    
    mov     rbx, mydata
    mov     rsi, 0
    mov     rax, [rbx + rsi*8 + 8]
    inc     rsi
    mov     rcx, [rbx + rsi*8 + 8]

Why in the world would we want to do that? We will see in a moment:

* the base register (**rbx**) pointed to the start of the data area. 
    * The displacement (8) at the end moves forward 8 bytes
    * the index register (**rsi**) steps into the data one element at a time. 
    * we used a scale factor (8 again) to step along 8 bytes at a time.

Does any of this sound familiar?

Here is a sample program demonstrating the address modes discussed in this lecture:

..  literalinclude::    code/modes.asm
    :linenos:

Instruction Set Encoding
************************

With all of these different addressing modes available in the instruction set
for the Pentium, you might suspect that the actual encoding of instructions
gets pretty complex. The term "Complex Instruction Set Computer" was probably
invented to describe Intel chips!. 

Here is a reference that explains the encoding pretty well:

    * `Encoding Real x86 Instructions <http://www.c-jump.com/CIS77/CPU/x86/lecture.html#X77_0010_real_encoding>`_

