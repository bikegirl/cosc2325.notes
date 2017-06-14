C Program Tear-Down
###################

..  include::   /references.inc

..  image:: Edsger_Wybe_Dijkstra.jpg
    :align: center
    :width: 300

::

    "The programmer must understand the computer, because the computer will not
    understand the programmer" -- E. W. Dijkstra

You should know this man's name:

    * `Edsger W. Dijkstra <https://en.wikipedia.org/wiki/Edsger_W._Dijkstra>`_

Back when you first started learning about programming, you should have been
taught that there are three fundamental *structured* forms you had to learn.
They were the *Sequence* the *Decision* and the *Loop*. Blame Edsger for that.
In 1968, he wrote this now famous letter to the editor of the *Associaiton of
Computing Machinery Journal*:

    * :download:`Dijkstra68.pdf`

In this letter, Dijkstra proposed eliminating the **goto** statement, which was
an essential part of programming up until then. He had another idea. Dijkstra
coined the phrase *Structured Programming* as a replacement for the "harmful"
statement, and his paper caused quite a storm in the world of software
development. He also is considered one of the guiding forces who moved
*Software Engineering* in the mainstream of professions.

With apologies to his memory, I am going to violate the cardinal rule of modern
programming, and restore the **goto** statement - but only for one specific
reason.

..  warning::

    Never admit that you have used this statement in any gathering of
    programming professionals. They may lock you in a closet and throw away the
    key!

Simple C Program
****************

Let's put together a simple program that incorporates all three basic
structures. I am going to use **C** (not **C++**) since we do not need the
baggage of modern object-oriented programming. 

What should the program do? I know! Let's add up a bunch of numbers. Just to
add a twist, I am only going to add up every other number in a list of numbers.

Here is the code I came up with:

..  literalinclude::    code/sum1.c
    :linenos:

Now, this is not the finest example of a *C* program, but it does have all
three basic structures. I chose to use a *While Loop* since that is probably
the first loop you were introduced to. It also uses *Global Variables*,
something we are taught to avoid. We are using those to ensure that they show
up in the data segment for the final code. (If we defined them as local
variables in a function, they would be harder to find. We will learn about that
later!)

Other than that, this is pretty simple stuff. You should have no problem
getting this running:

..  code-block:: bash

    $ gcc -o sum1 sum1.c
    $ ./sum1
    1 0
    2 3
    3 3
    4 13
    5 13
    6 19
    7 19
    8 34
    9 34

..  note::

    Every version of this program that we create in this tear-down should
    produce exactly this same output. I will not repeat what you see above, but you
    should run the code and prove that for yourself!

Our Goal
********

What I want to do in this note is exactly what a compiler does to your program
code. I want to convert it into a form the modern Pentium processor can
understand. To accomplish this, I am not going to use a real compiler, and I
will not alter the simple fact that we will be looking at is a fully standard
compliant *C* program each time we make a change. My goal is to convert exactly
this program to one that *looks* so much like Pentium assembly language that
the final conversion to a real Nasm_ assembly language file is trivial! 

..  note::

    See what happens when you wake up a 3am with an idea in your head? The
    first draft of this idea was done by 4am!

The Processor Does Not Understand Structures
********************************************

The problem the processor has with this code is there is a lot of stuff going
on that it has no idea how to handle. Take the **while** line for example.
There is an *expression* inside some parentheses that needs to be evaluated
before we can even decide if we want to loop or not. Then there is the issue of
exactly where is the loop body. You see curly braces, the processor has no clue
what they mean. You know they surround that loop body! We need to tell the
processor where the loop starts and ends.

Based on our training, we know what will happen. We will evaluate that *logical
expression* inside the parentheses, see if it produces a **true** or **false**
and either branch around the loop body, or drop into the loop. When we get to
the end of the loop body, we will branch back up and evaluate that logical
expression all over. 

So, in designing the chip, the Pentium architects had to concoct *instructions*
that would cause the processor do what you *think* it should do when processing
this code. (It really is an illusion - there is no *while* in the chip!)

Branching
=========

Branching is absolutely vital to being able to create our structures. Well, not
the *Sequence*. That one is simple!

We need two kinds of branching statements, one conditional and one absolute. We
will use a conditional branch at the top of the loop, and an absolute branch at
the bottom.

Sorry, Edsger!
===============

I am going to be forced to use a **GOTO** statement now. Yes, even though you
are **NEVER** supposed to use it, it is still there. There are rules on exactly
where you can use this statement, but basically they make sense. We will add a
*Label* to some line in our code, and direct the processor to *GOTO* that
label. If we need a conditional branch, we will use an **if statement** to
control the **goto statement**.

..  note::

    I am not going to teach you exactly how to use this statement, they would
    drum me out of teaching if I did that. Instead, I will show you what works, and
    leave it at that!

Let's modify the program so it does this:

..  literalinclude::    code/sum2.c
    :linenos:
    :lines: 12-22

Do you see how this is set up. We evaluate the logical expression and use that
to decide if we branch around the loop body. We have two **goto** statements
here, the absolute **goto** at the bottom of the loop body takes us back to the
place where we evaluate that expression again.

We managed to get rid of those ugly curly braces, and the **while statement**
and it still works as before.

Unfortunately, we got rid of one structure, but we used another structure in
its place. Now, we have two **if statements**. Hey, we are making progress here

Simplifying the Logical Expression
**********************************

Once again, we see a statement with some inner work to do. The first **if
statement** has a complex (!) expression to evaluate before it can decide what
to do. Let's pull that expression out of the statement and evaluate it first.
(This will cause us to introduce a new variable to store the result. I know,
let's call it **flag**:

..  literalinclude::    code/sum3.c
    :linenos:
    :lines: 7-23

Now, our conditional jump is much simpler. Let's do the same thing with the
second **if statement**:

..  literalinclude::    code/sum4.c
    :linenos:
    :lines: 12-23

Nothing Up My Sleeve!
*********************

Now for some trickery! We will use a feature of the **C** preprocessor called
*Macros* to change this code and make it look more like assembly language. One
step at a time.

The #define Macro
=================

A *Macro* is a text substitution trick. You may have seen something like this
in **C** code:

..  code-block:: c

    #define MAX 100
    ...
    if(count < MAX) ...

The macro associates the name **MAX** with all of the text beginning with the
first non-blank character after the name and continuing all the way to the end
of the line.

Here the *Preprocessor*, which actually reads your code first, will convert any
occurrences of **MAX** to 100 (by substituting that text following the name).
When the compiler finally gets the output from the *Preprocesser** the name
**MAX** is gone from your code! We will create two macros to hide part of our
current code, but when the smoke clears, the compiler will still see exactly
what you see now!

Converting to Pentium Instructions
**********************************

Here are our first macros, placed in a new file we will include named
**macros.h**:

..  literalinclude::    code/macros.h
    :lines: 1-3

Now, we can get rid of those two logical expressions and replace them with
something that looks like a Pentium **CMP** instruction. We can also replace
the conditional branches with something that looks like a **JZ** instruction,
and the absolute branch with something that looks like a **JMP** instruction:

..  literalinclude::    code/sum5.c
    :linenos:
    :lines: 13-25

Now that is nice! We are finally starting to see something more like assembly
code in this file!

..  note::
    
    If you really want to prove that the compiler still sees the same code, you
    can get **gcc** to show you what the preprocessor produced by doing this:

    ..  code-block:: bash

        $ gcc -E sum.c > sum.preprocessed

    ..  warning::

        If this is the first time you have looked at the output of the
        *Preprocessor* be warned, it is **UGLY**!

Incrementing and Absolute Branching
===================================

Let's get rid of the assignment that initializes **cnt**. We can also deal
with the simple **not** operation and the increment line:

..  literalinclude::    code/macros.h
    :lines: 5-6

With these, our code becomes this:

..  literalinclude::    code/sum6.c
    :linenos:
    :lines: 13-25

Wow!, only a few more lines to go! 

Declaring variables
===================

In this next step, let's change the data setup area. We define a few
uninitialized variables there, they need to change:

..  literalinclude::    code/macros.h
    :lines: 9-11

And here is the new code: 

..  literalinclude::    code/sum7.c
    :linenos:
    :lines: 8-11

We are using 32-bit integers in this code, which means **dwords** to the
processor.

Eliminating the outer "main" code
*********************************

You should know that the **main** function is required in **C**, and marks the
entry point for any **C** program. Since it is a *Function* it must be *called*
by something, and that something is actually the operating system (on your
behalf, after you cause the program to be run somehow). At the end of that
function, we need to return control to the operating system. We can do this by
marking the entry point with a proper name, and ending the function with a
**RET** instruction. Here is our new code:

..  literalinclude::    code/macros.h
    :lines: 13-14

And now, the modified program code:

..  literalinclude::    code/sum8.c

We have not really studied functions yet. They start with a label and end with
a *RET**, which is what we now see in our code!
 
Arrays 
******

We next need to consider dealing with that array! You should know that, basically,
an array is just a sequence of data blocks, all the same size, stored in
memory. In **C** (and (**C++**) we access an array using an *index variable* of
some sort. We are cheating and using our loop counter(**cnt**) for this access.
How will the processor deal with that? Well, the processor knows nothing about
arrays, but it can use a container holding an address (does the term *pointer*
pop into your mind) and use that to access some place in memory. We modify that
*index* and we access another element in the array. We run into a fundamental
problem here. Your indexes increment by one, but the actual addresses increment
by 4! (Why? Each integer in **C** takes four bytes to store, and addresses are
associated with each byte of storage!) When you code in **C** and use pointers,
the compiler knows how big the item is that the pointer refers to, so adding
one to the pointer is internally converted to adding 4 (the size of an
**int**).

..  warning::

    This may make our head hurt!

Here is a change to our code that uses pointers to access the elements in the
array:

..  literalinclude::    code/sum9.c
    :linenos:

If you are weak on pointers, do a little research before working this one out.
It still produces the same output. (Phew!)

Eliminating the Pointer Notation
********************************

All of that funky pointer notation needs to go away. Pointers are just address
holding variables, and the processor knows what to do with addresses. We will
see exactly what that code looks like later, but for now, let's create two more
macros to get rid of the array declaration, and the associated pointer
declaration:

..  literalinclude::    code/macros.h
    :lines: 16-17

..  warning::

    There is some tricky macro work going on here. Look into it if you like, we
    will not explore all that now.

And here is the new code using these:

..  literalinclude::    code/sum10.c
    :lines: 4-5

Now, the Hard Part
******************

We are down to three lines to convert Two are identical function calls, and the
last an ugly assignment statement. Both of these forms need to become more than
one line of assembly code, so we need to rearrange those lines a bit. To
simplify the output (in the assembly version), I am going to pull them out of
the main code and build a function that does the same thing.

..  literalinclude::    code/sum11.c
    :linenos:

Now, we can add another macro to replace those calls to **display**. We can
also introduce a couple of simple fake macros to mimic telling the assembler
what section of code we are working through:

..  literalinclude:: code/macros.h
    :lines: 19-25

And our new code:

..  literalinclude::    code/sum12.c
    :linenos:

..  warning::

    There will be warning about the format string not being a string literal.
    You can ignore that here.
 
Working through the print routine is fairly straightforward, but a bit tedious.
Basically, when we code in assembly language, each step we take is pretty
small.  This code is not ideal, but it should work.

That funny line replacing the assignment to sum is close to a form the Pentium
supports. We will study that later.

Wrapping Up the Translation
***************************

Here is the final macro file:

:macros.h:

..  literalinclude::    code/macros.h

And the final **C** file. 

..  literalinclude::    code/sum13.c
    :linenos:

It is nice that **C** is pretty loose about pasting white space in the code. I
moved all of the "operants" over where they are supposed to be in assembly
language!

This sure looks like assembly language to me! Not a trace of **C** code to be
seen. (Well, discounting those header lines at the top

What the compiler saw
=====================

Stripped of the preprocessor clutter and cleaned up a bit, this is the final code the compiler saw

..  literalinclude::    code/sum13.pre
    :linenos:

Nasm Version
************

Just for reference, here is a Nasm_ file that will do exactly what our new file
says to do. 

..  literalinclude::    code/sum14.asm
    :linenos:

If you look closely at these last two files, you will see one fundamental
difference tht I am not going to fix. (You might try that as an exercise).
There are several places where I am referencing variables in memory directly.
In fact, the assembly language moves some data into internal registers, and I
did not set up any of those in this example. Since the processor cannot
reference two memory items in the same line, those instances clearly need to be
fixed. That should be easy enough, but I have accomplished my basic goal in
what we see here.

What Instructions Did We Need
*****************************

It is worthwhile examining exactly what assembly language constructs we needed
from all those available in the Pentium to get this code running. Here is a
summary:

    * **ADD** - add two data items as integers
    * **CALL** - branch to a function
    * **CMP** - see how two data items relate
    * **INC** - increment a data item (very common action)
    * **JMP** - absolute branch
    * **JZ** - conditional branch
    * **MOV** - copy data from one place to another
    * **MUL** - multiply two data items as integers
    * **NOT** - logical compliment of a binary value
    * **RET** - return from a function

There are different forms of a few of these, but that is not many for a
moderate **C** program.

See! Assembly language is not so scary!
 


..  vim:ft=rst spell:
