..  _lab4:

Lab 4 - Number Conversion
#########################

..  include::   /references.inc

..  note::

    This is an individual project, but I recommend that you work with your team
    mates to figure this out. The invitation link for this project is here

    * `Lab 6  <https://classroom.github.com/assignment-invitations/3ef9596e94cd3b9f480d7d2ae9cb94c9>`_

In this lab, you will build subprograms in assembly language that can be called
from C/C++. Basically, we will implement three routines:

    * n_len - return the length of a string (this code is given)
    * n_dtoi - convert a string of decimal digit characters into an unsigned integer
    * n_btoi - convert a string of binary digits into an unsigned integer

The notation we will use is part of the new C++ standard:

    * digit+ - a string of normal decimal digits is a decimal number
    * 0b_11111 - is a binary number

C Prototypes
************

The C++ prototypes for these functions look like this:

:numbers.h:

..  literalinclude::    code/include/numbers.h
    :linenos:

Each of these functions will receive the address of the number strng in the
`RDI`` register, in keeping with the standard rules compilers follow for the
Pentium. The return address will be returned in the ``RAX`` register. 

To give you a start on this project, here is the ``main.cpp`` file I used for
testing:

:main.cpp:

..  literalinclude::     code/src/main.cpp

And here is the stub of the file you need ot create:

:numbers.asm:

..  literalinclude::    code/lib/numbers.asm
    :linenos:


The provided code is structured according to the :ref:`cpp-project-setup`
lecture, but this setup will build both C++ and Nasm assembly files. This
pattern will be used in later labs, so I recommnd setting things up this way.

Converting the characters
*************************

You may think that this is going to be hard, but with a little thought, it is
not so bad.

The key in this is that you need to use the ``MUL`` instruction and read up on
how that works.

..  warning::

    ``MUL`` wants you to load the ``RAX`` register with a value, then multiply
    that by something, including a literal value.
    
    ..  code-block:: text

        MOV     RAX, 12
        MOV     RDX, 10
        MUL     RDX
    
   After the ``MUL`` instruction,  ``RAX`` has the low 64 bits of the result,
   and ``RDX`` will have the high 64 bits, or will be set to zero if the number
   is smaller than 64 bits.

Here is the basic logic you need:

    * start off a register with a vaue of zero, I will use ``RAX``
    * fetch the leftmost digit from the string
    * convert it to a binary value (subtract the code for '0' to do that).
    * take the current value ``RAX`` and multiply it by 10. 
    * Add in the value of this digit to ``RAX``
    * repeat this process for the remaining characters until you hit the zero
      byte at the end of the string.

Obviously, the process for binary conversions is similar but you do not multiply
by 10, and your first character is not the first byte. You might want to check
to make sure the leading ``0b_`` characters are there.

Hints
*****

When you try out new instructions, I recommend building small programs that
test just those lines of code and as little else as you can. 
You can also use the example C++ code to make sure you are getting the right
values back.

You could also set up tests along the line of the test code shown in erlier
labs. Build a test function with some name, and just add that file in the
``lib`` folder. (be sure to update the header file). Add a new test file under
``tests`` and make sure you re getting the right values back.  Building small
code chunks like this is a good way not to trash your entire project while
testing something new.
