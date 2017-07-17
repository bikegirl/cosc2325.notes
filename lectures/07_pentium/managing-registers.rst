..  _managing-registers:

Managing Registers
##################

As you start to write assembly language programs, the first thing you find
yourself worrying about (after figuring out how to lay out your code files) is
which registers to use, and when to use them.

We indicated that registers are a precious resource, and the system will be as
fast as it can be when work is done with those registers. So, we need to figure
out the basics of picking and using registers.

General Registers
*****************

The Pentium provides 16 registers labeled "general purpose" registers:

    * RAX, RBX, RCX, RDX, RBP, RSI, RDI, RSP, R8-R15

By now, you should realize that ``RSP`` is pretty important in managing
subprograms, so in general, do not mess with that one, unless you are careful.
More on that later.

That leaves a bunch of registers you can work with. However, since all real
programs have subprograms in them, we need to be careful when we use certain
registers. The reason? There are rules!

Application Binary Interface
****************************

To make sure object files produced by different language tools and different
languages can interoperate, there are standard rules for how registers are
used when you call subprograms, pass in parameters, and return values. Certain
registers are used to pass parameters to subprograms, and also for return
values. The rules differ with operating system, so you need to do some research
to learn about all of the variations.

For Linux, the rules are defined in this document:

    * :download:`mpx-linux64-abi.pdf`

For our work, we can summarize how these registers are used as follows:

..  csv-table::
    :header: REG, Param, Preserve

    RAX, 1st return, No 
    RBX,,Yes
    RCX, 4th in, No
    RDX, 3rd in & 2nd return, No
    RBP,,Yes
    RSI, 2nd in, No
    RDI, 1st in, No
    RSP, Stack pointer, Yes
    R8, 5th in, No
    R9, 6th in, No
    R10,, No
    R11-15,,yes

There is a convention for using ``RBP`` to track where the stack pointer was
when a subprogram wakes up. You see this pattern in most programs:

..  code-block:: text

    sublabel:
            push    rbp
            mov     rbp, rsp
            ...
            mov     rsp, rbp
            pop     rbp
            ret

What it going on? 

Basically, we are saving the caller's current value of ``RBP`` on the stack, so
we can restore it later. Then we copy the value of the stack pointer at that
moment in ``RBP``. We will use that value later to locate parameters that "may"
be passed in by the caller, who can push items on the stack before a call. This
is dangerous territory, since messing up with the stack can break your program.
The pattern at the end of the subprogram restores the caller's ``RBP`` register
just before we return.

Working with Parts of Registers
*******************************

Something you might run into from time to time is the need to work with parts
of a register. As an example (something you can use in this weeks lab project),
suppose you are forming a 64 bit value from an 8-bit one. Here is some code you
could use:

..  code-block:: text

    ;
            xor     rax, rx     ; cheap way to zero a register
            mov     bl, '4'     ; get the aSCII code for 4 in bl
            sub     bl, '0'     ; bl now has a binary 4 in it
            mov     al, bl      ; rax now holds a 64-bit 4

Why does this work?

The ``XOR`` trick is the most common way to zero out any register. The rules
for ``XOR`` say that only one of the two values must be a 1 for the result to
be a 1 in any bit location. Since all bits are identical, the result will be
all zeros, which is what we want.

We start off by creating a proper 64-bit sero value in ``RAX``. After we
convert the 8-bit character code into an 8-bit binary value, we write that
value into the low 8 bits of the ``rAX`` register.

It is important that you can visualize what you just did. You modified only
part of the ``RAX`` register, but you know all the other bits are untouched,
and you have the final value you want. The result is the proper 64-bit value we
need.

In assembly language, you need to pay attention to the register aliases you
picjk t work with containers of all possible sized. These aliases leve the rest
of the full register untouched. As a reminder, bere are the aliases for the
``RAX`` register

    * AL - low 8 bits
    * AH - bits 8-15 (weird, I know, ask Intel why)
    * AX - low 16 bits
    * EAX - low 32 bits
    * RAX - full 64 bits

Protecting Registers
********************

You will run out of registers in a lot of cases, and want to use them even
though they hold something important. 

Registers are "global variables", and you need to remember that when you write
assembly language code. You cannot just take possession of a register and use
it, since you need to be sure some other part of the program is not currently
using that register for some other purpose. 

A common way to protect the current value stored in a register while you use
that same register for something else looks like this:

..  code-block:: text

    ; RAX is important, do not lose it
    push    rax     ; save that important value on the stack
    mov     rax, 10 ; set in a new value
    ; do some work
    pop     rax     ; your important value is back!

The stack is a nice place to temporarily save things, and restore them later.
There is one important rule in doing this , though:

..  warning::

    Make sure for every "push" you write, there is a matching "pop" in the
    block of code you are writing. DO not get things mixed up, or chaos will
    result.

If you want to protect several registers this way, you need to "pop" in the
reverse order:

..  code-block:: text

    push    rax
    push    rbx
    ;
    pop     rbx
    pop     rax

This should make sense if you think about it!

Using the stack is not as fast as just using registers, but it a common
programming tactic.  Just heed that warning, especially when you use
subprograms. If the stack is not in the correct shape when you hit a ``RET``
instruction, your program is off into outer space!

Loop Counters
=============

Let's see a common case where we might want to use the same register for two
different purposes: nested loops!

Most programmers (and the compiler) use ``RCX`` as a counter register. This is
especially true in simple loops. Suppose you want to set up a loop that spins
exactly five times. You can do this:

..  code-block:: text

    ; example one level loop using RCX as a counter
            mov     rcx, 5
    loop1:
            ; do some work here
            dec     rcx
            jnz     loop1
            ; you are out of the loop here

Basically, inside the loop body, ``RCX`` will have values of 5, 4, 3, 2, and 1 as
the loop runs. Once we decrement it and it hits zero, the conditional branch
will fail, and we fall out of the loop.

..  note::

    Notice that ``RCX`` is not counting up, and cannot be used as an index into
    an array. This loop form is common when you do not need to use the counter,
    and know exactly how many times you want the loop to run.

Now, suppose that inside this loop, we want to set up an inner loop that spins
ten times. Here is a solution involving the stack:

..  code-block:: text

    ; example two level loop using RCX as a counter for both loops
            mov     rcx, 5
    loop1:
            ; do some work here in outer loop
            push    rcx     ; save current counter on stack
            ;
            ; it is safe to use RCX now
            mov     rcx, 10
    loop2:
            ; do some work in the inner loop
            dec     rcx
            jnz     loop2
            pop     rcx     ; restore old counter from stack
            dec     rcx
            jnz     loop1
            ; you are out of the loop here

This code needs some study to convince yourself that it will work properly!

Registers and Subprograms
*************************

If we follow the ABI, them we need to set up certain registers with the
parameters we want to send down into those subprograms when we call them. That
table above tells you how this is done. Most subprograms nly return a single
value in cases where the value returned is going to be used in some expression.
For instance a function like this:

..  code-block:: C

    int sqrt(double val);

Will wake up with that "double" parameter (a 64-bit value) in the ``RDI``
register. Once it is done figuring out the square root, it will load that value
into the ``RAX`` register immediately before the code returns to the caller.
That setup is not the last line before the ``RET``, it happens before the
standard subprogram return code shown earlier.

The calling code is responsible for loading the correct registers with the
parameters. If you examine a C/C++ function prototype, the order in which the
parameters are loaded matches the order in the prototype. The ABI details all
of that!

