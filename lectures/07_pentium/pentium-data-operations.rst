..  _pentium-data-ops:

Pentium Data Operations
#######################

..  include::   /references.inc

We will start off explorint the Pentium by setting up data and moving it
around. All of this is done with Nasm_ directives, and data movement
instructions.

Defining Constants
******************

* We declare names as constants to make them easier to understand
    * We can also use the name multiple times in our code
    * values can end up in instruction as an operand

* Constants only exist as your code is processed
    * Each reference is used as needed by the assembler
    * Constant value may appear multiple times in final code

The EQU directive
=================

* This directive enters a name and value into the ``symbol table``
    * A reference uses the defined value

..  code-block::    text
    
    K       EQU     1024
    TenK    EQU     10 * K

* No memory is allocated by this directive

* The value assigned cannot be changed in the code

A Variable constant
===================

* A ``constant`` that can be changed in the code uses this directive:

..  code-block:: text

    K       EQU     1024
    %assign bufsize 10*K
    ...
    %assign bufsize 32*K

There is a case insensitive variant:

..  code-block:: text

    %iassign    BUFFSIZE    15*K

The code preprocessor
=====================

* As with C/C++, a preprocessor examines your code first
    * The final result is passed to the real assembler

..  code-block:: text

    %define PI 3.1415926

This scheme is really just text-substitution

..  code-block:: text

    %define ListContent [List]

The final code must make sense to the assembler!

The ``location counter``
========================

* The assembler tracks the next available memory location for each block
    * The location address is stored in ``$``

..  code-block:: text

    String  DB  'This is a very long string',0
    lString EQU $ - String

This is handy for calculating how much memory was allocated since a previous
label was defined.

Generating listings
===================

We normally do not care where variables (labels) are located

However, we can add an option to the assemble step to find out:

..  code-block:: text

    nasm -f elf64 -l hello.lst

The listing file will show how names are being used in your code.


..  _defining-data:

Defining Data
*************

All programs manipulate

    * Constants - data that does not vary
    * Variables - data that is not constant (HA!)

We need to define all of this

    * We declare our data

Two kinds of data
=================

We distinguish between

    * Data with an initial value
    * Data that begins with no predefined value

In assembly language, we do not worry about data types

We only worry about the size of the data containers

    * BYTEs, WORDs, DWORDs, QWORDs

Data segments
=============

In Nasm programs we define a block of memory for a specific kind of data

    * The blocks are called segments:
        * ``.text`` - code block
        * ``.data`` - initialized data
        * ``.bss`` - uninitialized data

    * These blocks can appear multiple times in a program
        * they end up grouped together in the final program

Initialized data declarations
-----------------------------

    * The basic declaration format:
        * Label directive value

    * The label is just a name we will use to refer to the item
        * It ends up as an address in memory

    * The directive specifies the size of the data item
        * DB - define byte
        * DW - define word
        * DD - define double
        * DQ - Dairy Queen  (actually: define QWORD)

Example initialized data block
------------------------------

..  code-block:: text

    segment .data

    var1    db  100
            db  -200        ; two's complement encoding (no label)
    var2    dw  0
    var3    dq  0

* You must ensure the value will fit in the container

Uninitialized data declarations
-------------------------------

    * No initial value is required
        * Be sure to initialize before use, though!

    * Format is similar to initialized
        * Label directive count (number of containers needed)

    * Directives are:
        * RESB - reserve BYTE
        * RESW - reserve WORD
        * RWSD - reserve DWORD
        * RESQ - reserve QWORD

Example uninitialized data declarations
---------------------------------------

..  code-block:: text

    segment .bss
    
    Total   RESB 1
    Zero    RESW 2
    Junk    RESQ 4
    
* In this case, the number refers to the number of blocks allocated
    * The label is the address of the first byte allocated

Strings are a special case
==========================

    * Strings are so common they are treated differently

..  code-block:: text

    Bird    DB  'R','o','b','i','n'

    Bird    DB  'Robin'

* You can use either single or double quotes

Including quotes in strings
---------------------------

..  code-block:: text

    SQuote  DB "Fred's house"
    DQuote  DB  'Fred "Hulk" Jones'

Or escape the quote:

..  code-block:: text

    Sample  DB 'This string\'s length is 25'

Adding a newline to a string
----------------------------

The codes needed to end a line (in Windows) are

    * Carriage-return (0dh)
    * Line-feed (0ah)
    * (Linux uses a line-feed only)

..  code-block:: text

    CString DB  'String with endline",0dh,0ah,0

Referencing names
=================

    * All labels are translated into addresses by the assembler

    * We distinguish between
        * The address of a container
        * The value stored in that container

    * The machine does not track the size of the container
        * The program needs to track this
        * Remember, no data types are defined!

Example references
------------------

..  code-block:: text

    mov     rax, list       ; load the address of ``list`` in rax
    mov     al, [list]      ; load the first byte from ``list`` into al

Note the use of the square brackets in that last example. They look like a
container holding the label. This is your clue that we are talking about what
is in memory at that location.

The size of the data item moved is determined by the size of the destination

..  code-block:: text

    mov     ah, [list]
    mov     al, [list + 1]

The assembler can do simple math as it processes your file

More examples
-------------

What is this code doing?

..  code-block:: text

    List    resb    100
    Laddr   DQ      List

* The assembler records names as declared, and assigns an address to each
    * The assembler uses a ``symbol table`` to track names
    * References are looked up, and the address is used in code


Moving Data
***********

Now that we know how to set up the data area, we need to look at the
instructions that can move data from place to place. Oddly enough, the first
instruction we will examine is the `MOV` instruction

MOV_
====

This instruction has a lot of different formats. The basic instruction is
described in the Intel references like this:

..  code-block:: text

    MOV DEST, SRC

Where `DEST` are generally any of these:

    * r/m8 - an 8-bit register or memory location
    * r/m16 - a 16 bit register or memory location
    * r/m32 - a 32-bit register or memory location
    * r/m64 - a 64-bit register of memory location

`SRC` can be any of the above plus:

    * imm8 - a literal 8-bit value
    * imm16 - a literal 16 bit value
    * imm32 - a literal 32-bit value
    * imm64 - a literal 64-bit value

The size of the literal value is determined by looking at where you say you
will put the value. 

..  code-block::    text

    mov     eax, 10

This will place a 32 bit binary value 10 into the EAX register. The literal
value has to fit in the designated register.

Combinations
============


Not all combinations of the `SRC` and `DEST` options are possible. The size of
the choice must be identical for both `SRC` and `DEST`. That means an
instruction like this is illegal:

..  code-block:: text

    MOV     RAX, DL

The source operand refers to an 8-bit register, and the destination register is
a 64 bit register. 

No Memory to Memory Moves
-------------------------

There is no instruction in the Pentium that allows both operands to refer to
memory locations. That means that only one of the operands can refer to a
memory location:

..  note::

    When you want the processor to work with the `contents` of a memory location
    you place the reference to that location in square brackets:

    ..  code-block:: text

        var1    dq  0
        ...
        mov     rax, [var1]

How Do We Move Bits?
--------------------

Obviously, we cannot really move bits around. What actually happens, according
to Intel is this:

..  code-block:: text

    DEST <-- SRC

What this means is that the value currently stored in the `SRC` location is
`copied` to the `DEST` location. When that completes, the original contents of
the `DEST` location are gone, replaced with an exact copy of the bits currently
in the `SRC` location.

Reference
=========

Here are the pages from the Intel Documentation covering this instruction:

    * :download:`MOV.pdf`


..  vim:filetype=rst spell:

