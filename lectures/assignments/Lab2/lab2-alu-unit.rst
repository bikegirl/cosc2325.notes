Lab2: Modeling the ALU
######################

..  include::   /references.inc

Our next major component is the ALU. For this project, I am going to simplify
the machine a bit, and limit the machine to 8-bit  and 16-bit operations. We
are not trying to model a full Pentium in our simulator, a smaller machine will
do just fine.

Here is the invitation link for the project repository:

    * `Lab2-alu-Unit <https://classroom.github.com/assignment-invitations/b27246bf78cdace83866dc2461297783>`_

Basic ALU Operations
********************

The basic operations we need for this machine obviously include addition and
subtraction. Multiplication and division are a bit more complicated to model,
so we will leave them out for the time being. (We can always use addition and
subtraction to do multiplication and division, so this is not a serious
omission.

We do need to deal with the difference between signed and unsigned containers.
You will need to come up with a code for that.


We do have a few issues to deal with, though.

In your homework, you explored the range of values available for the standard
data types in C/C++. In this simplified machine, the biggest unsigned integer
we could put in a 16-bit container is 0xffff. What should happen if we add one
to that number?

The result is a 17 bit value, which will not fit in a 16-bit container. So the
answer must be zero. Obviously,this value is wrong, but it is correct as far as
the computer is concerned. That extra bit needs to be recorded somewhere, and
we will use a special status flag to indicate that we generated a "carry". 

You need to think how to model this behavior in C++ code. (Oneway is to do math
internally using a larger container, and test if the resultis too big. If so,
the carry flag must be set, and the result modified (by truncating it to
16-bits).

Here is the header file for the ALU:

..  literalinclude::    /code/ALU/include/ALU.h
    :linenos:

You may need to alter this specification. 

The "op" operand to the **execute** method is used to specify the operation you
want the ALU to perform. There will be four possibleoperations for now, two
each for signed and unsigned data. Lookover the sample code for one way to deal
with overflow (or underflow if subtractions). 

Behavior
********

Unlike memory, the ALU is typically very fast, especially for simple integer
operations. We do not need to worry aouttimingin thislab.
 
Testing Your Class 
******************

I have included some example code in the **main.cpp** file. This code shows how
we can deal with options on the command line when we run the application. Look
this over, since we will use it later. For now, you can leave this code alone,
or play with it if you like. 

The **test_alu.cpp** file has a start on testing for this component. You need
to add tests to make sure your class operates properly.

Here is the starter test code that you are to use to check your work.

..  literalinclude::    /code/ALU/tests/test_alu.cpp
    :linenos:

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

