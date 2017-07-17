..  _hw6:

HW6: Pentium Hello
##################

..  include::   /references.inc

We need a simple "Hello, World" exercise to make sure you can build an assembly
language program for the Pentium. Don't worry, this will be pretty simple.

This assignment is not asking you to write any original assembly language, it
is just to make sure you can set things up and get a program running.

Check Nasm Install
******************

In you virtual machine, check that Nasm_ has been installed:

..  code-block:: bash

    $ nasm -v
    NASM version 2.10.09 compiled on Dec 29 2013

If you do not see this, do this to fix the problem:

..  code-block:: bash

    $ sudo apt-get install nasm

Create the Code File
********************

Here is you basic program file:

..  literalinclude:: code/hello.asm
    :linenos:

And here is a **Makefile** that will build your application:

..  literalinclude::    code/Makefile

Once these two files are present on your system, run the program to make sure
everything is working properly.

Your Real Task
**************

So far, all of this is cut-and-paste (well, watch out for the Tab requirement in
the Makefile). Let's see if you can modify this code to make it do something
unique.

Study the code in the basic file. Can you see tha pattern used to generate the
output? Add lines of code to make this print out the following lines:

..  code-block:: text

    Student: Your name
    Course: COSC2325-00x
    Semester: Spring, 2017

Nothing too hard there. Once you have your code showing this poutput, you are
done! Add the final code to your repo and push it to GitHub_.

..  vim:ft=rst spell:
