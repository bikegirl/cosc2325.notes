..  _cpusim-isa:

Designing the CPUsim ISA
########################

After introducing the basic concepts of machine instructions, we are in a
position to define the instructions we will implement in our final version of
the CPUsim machine. (We will be switching to real hardware next!)

The particular instruction set supported by a processor is called the
*Instruction Set Architecture* (ISA for short). The actual selection of
specific instructions is something the designers of a processor ponder a
lot. Each instruction should support something going on in the world the
processor will support. Obviously, if a chip is to support general
purpose programming in a language like C++, we need to be able to make
the machine perform tasks that mimic what programmers are trained to
think the machine is doing. (Note: what it actually does might be
something different, as long as what happens matches that programmer's
view of how things work.

IF-THEN-ELSE
************

As an example of this, let's consider how programmers view what is going
on in an (IF-THEN-ELSE statement. Here is a diagram you probably were
shown when you first were introduced to this statement:

..  circuits::
    :align: center
    :width: 400 
    :tikzlibs: shapes, arrows
    :tikzopts: node distance=2cm, auto

    \tikzstyle{process} = [rectangle,
        draw, text width=5em, text centered,
        rounded corners, minimum height=4em, fill=green!30]
    \tikzstyle{line} = [draw, -latex']
    \tikzstyle{decision} = [diamond, draw , fill=blue!20,
        text width=4.5em, text badly centered,
        node distance=3cm, inner sep=0pt]


    \node [decision] at (3,0) (question){Question};
    \node [process] at (0,-2) (False) {False Process};
    \node [process] at (6,-2) (True){True Process};

    \path[line] (question.west) -| node [anchor=east] {$F$} (False);
    \path[line] (question.east) -| node [anchor=west] {$T$} (True);
    \coordinate (end) at (3,-4);
    \path [line] (True) |- (end);
    \path [line] (False) |- (end);
    \path [line] (end) -- (3,-5);

We need to create some instructions that let us implement the logic of
this diagram. Obviously, we cannot construct this diagrma with code
sitting side by side, we need to stack things up vertically, so we can
lay it in memory. Let's redraw this flow:

..  circuits::
    :align: center
    :width: 250 
    :tikzlibs: shapes, arrows
    :tikzopts: node distance=2cm, auto

    \tikzstyle{process} = [rectangle,
        draw, text width=5em, text centered, 
        rounded corners, minimum height=4em, fill=green!30]
    \tikzstyle{line} = [draw, -latex']
    \tikzstyle{decision} = [diamond, draw , fill=blue!20,
        text width=4.5em, text badly centered, 
        node distance=3cm, inner sep=0pt]


    \node [decision] at (0,0) (question){Question};
    \node [process] at (0,-2) (True){True Process};
    \node [process] at (0,-4) (False) {False Process};

    \path[line] (question.west) -- 
        node [anchor=south] {$F$} (-2,0) -- (-2,-4) -- (False);
    \path[line] (question.south) -- node [anchor=west] {$T$} (True);
    \coordinate (end) at (0,-6);
    \path [line] (True) -- (-4,-2) |- (end);
    \path [line] (False) -- (end);
    \path [line] (end) -- (0,-7);

Now, we see that we need a way to cause the processor to skip over some
chunks of code. To do this we need a way to mark a location in memory
where an instruction is located. The way we do this is to name that
location with something like a variable anme, only we call it a *label*.
Once we know the name of a location, we want to add an instruction that
will *jump* from the normal next instruction flow, to this new location.
The instruction typically used to do this is called a *JUMP* (often
shortened to *JMP*).

How this works is simple: During *decode*, we update the *program counter*
as usual, which would send the processor to the very next instruction.
We do not want that to happen, so we need to change the *program
counter* so it holds the address at the place we want it to go. We will
put a label on that place, and the fiull instruction will be this:

..  code-block:: text

    JMP label

(Actually, we *could* specify the address directly, rather than use this
label, but it would be easier for us poor humans if we used names, and
let our processing tool deal with the actual addresses.

This *absolute* branch is fine for part of this diagram, but we need to
consider how we are going to handle that decision, which offers two
possible paths through other code.

We will use a simple *Compare* (typically shortened to *CMP* )
instruction to compare two data values. The implementation of this will
just subtract one operand from abother without changing either one, so
the full instruction will look like this:

..  code-block:: text

    CMP op1, op2

Now, if we perform this subtraction there are only three possible
outcomes:


    * op1 - op2 = 0  (the two ops were equal)

    * op1 - op2 > 0  (op1 is bigger than op2)

    * op1 - op2 < 0  (op2 is bigger than op1)

We will have to record the result of this subtraction someplace, and
typically that is done in a special regiater called a *Flag* register.
(We will study that one later).

Now, we can introduce another kind of branch instruction, this one
called a *conditional branch*. This one may or may not branch depending
on the result of the question we asked and how what compare instruction
produced. 

Suppose you wanted to see if the two operands were equal. You want to
know if the result was zero or not. We could introduce a conditional
branch instruction that looks like this:

..  code-block:: text

    JZ labe;

If the result of the compare was zero, we will branch to that label. If
not, we fall through to the next code in line. 

..  note::

    You might notice that if we want the true code to come before the
    false code in our stream of instructions, we need to branch around the
    true part to get to the false part. So in implementing a test if they
    are equal, we really want to use aan opposite branch to take us to the
    false part. If they were equal, we just want to fall into the code for
    the true condition. Something like this:

..  code-block:: text

    ;
            CMP op1, op2
            JNZ label
            true stuff sits here
            ...
            JMP ifend
    label:  false stuff sits here
            ...
    ifend:

In this example, I have a label sitting in space with no code on the
line. This is usually allowed, and it means the label is actully
referring to the address of the very next instruction. We will see more
of this when we look at real assembly language.

By the way, what do you thinks *JNZ* means? 

Implementing the *conditional branch* instruction is easy. We update
the *program counter* as usual, but when we do the *execute* step, we
need to check the results of that previous *compare* operation. If we
want to branch, we update the *program counter* with a new value, if we
do not want to branch, we will simply leave it as it was, and the next
instruction in line will be processed. That is what makes it
*conditional*. (the check of the *Flag* register!)

With this overview of how deciding what instructions to add to our
machine, let's consider a starting set

Initial ISA
***********

There are tyically a few major categories of instructions we want to add
to our *instruction set*:

Data Movement
=============

    * MOV   dest, source

        * Source: literal, memory address, or register contents

        * Destination: memory address or register


Arithmetic
==========

    * ADD - basic integer addition (signed)

    * SUB - basic integer subtraction (signed)

    * MUL - basic integer multiplication (signed)

    * DIV - basic integer division (signed)

All of these instructions will specify two operands, source and destination.
The final result will be stored in the destination operand, 

We could add unsigned, but for our example machine, this is not necessary.

Logic
=====

    * AND - boolean AND operator (bitwise)

    * OR - boolean OR operator (bitwise)

    * XOR - boolean Exclusive OR (bitwise)

    * NOT - compliments all the bits

Again, these instructions will require two operands: source and destination.
The final result will be stored in the destination.

Note that all of these operations really need to be considered as operating o
unsigned data. When we perform these *logical operation, we line up the
two operands and apply the truth table rules for each pair of bits, and
record the result in the final destination. This is pretty handy when we
deal with *packed* data, where one chunk of memory actually holds
several small chunks all merged together in a bit stream. We will use
this in a later lecture.


Comparison
==========

We will need a compare instruction as part of asking questions!

    * CMP  dest source

The comparison will perform a subtraction, but the destination will not be
altered. Instead, we will record the result in a status flag set.

Control Instructions
====================

Unconditional Branch
--------------------

We will provide the classic "jump" instruction

    * JMP   dest

Conditional Branch
------------------

We will provide a selection of conditional branch instructions. All will need a
single operand specifying the address of the branch:


    * JE - jump if equal

    * JNE - jump is not equal

    * JL - jump if less

    * JG - jump if greater

    * JLE - jump if less or equal

    * JGE - jump if greater or equal

In all of these forms, the comparison operation should be done right before the
branch. The subtraction will be source - destination, and the result follows
from that operation. If the source is smaller than the destination, the result
will be "less"

Procedures
==========

We will need to provide *call* and *return* instruction:

    * CALL dest

    * RET

But how will these work. A call is just like any other branch, except
for one thing. We know that when we reach the end of a procedure, we are
supposed to *return* to where we were when we made that call. (Actually,
to the instruction right after the call!). Where are we to return?

If you think about it, the answer is sitting right in the *program
counter* after the decode step. We know where we want to return to
(eventually), but id we change the value of the *program counter* to
make the machine branch to the procedure, we will lose that *return
address*. The trick we do is to use that *stack* memory we have been
working with. This time, we do not use the stack for numbers, instead,
we record (push) return addresses, so we can retrieve them later. After
we save the return address, we overwrite the *program counter* with the
address of our procedure (another label is ised here).

The return is then very simple. There are no operands, so this
instruction is very small. When we execute it, all we need to do is pop
the return address off of the stack, and write that address into the
*program counter*. Bingo! We are back where we needed to be.

If you think about is, using the stack this way lets one procedure call
another one. As long as we hit the *return* instruction at the end of
each procedure, everything will work out fine! Cool!


Miscellaneous Instructions
==========================

Finally, we will need stack instructions to provide a way to send parameters to
procedures:

    * PUSH  source

    * POP   destination

We can also use registers to send data to a procedure. In practice, both
techniques are used.

That should be  basic set we can do some work with.

ISA Implementation
******************

Each of these instructions should be easy to implement, once we figure out how to
specify each one. As we discussed earlier, our basic assembly language rules
cover all the instruction forms we see in this overview. All we need to do is
document exactly how each instruction needs to work, nd decide how to store
those status flag data values.

Encoding Instructions
=====================

We can easily assign a simple integer code to each instruction, but we have a
problem when we have operands. There are several "addressing modes" to consider,
and the operands provide options forms involving literals, memory references, or
register references. We need a way to encode those parts as well. 

A typical solution is to combine an instruction code with a set of operand
codes to lay out exactly what form we are using in a program. Exactly how we do
this encoding is something we will explore in our next lecture!



..  vim:filetype=rst spell:

