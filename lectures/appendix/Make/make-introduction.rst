..  _make:

Make - the programmer's best friend
###################################

After building a few programs by hand, you quickly long for the days when all
you had to do was push a button to build a project. Actually, when you pushed
that button in a typical :term:`IDE`, you were invoking one of the oldest and
most powerful tools used to construct real programs, ``make``.

What is Make?
*************

Simply stated, ``make`` is a program used to "make" programs. It is a tool
that issues a set of commands for you when you build a program involving
multiple steps, so you do not have to type those commands in manually.

If that was all ``make`` did, it might be handy, but hardly "powerful". What
makes ``make`` unique is that you describe how programs are constructed out
of the component parts, then ``make`` figures out what to do automatically.
How it does this is interesting.

How Make Works
**************

``Make`` is driven by something called `dependencies`, which are
basically the parts needed to construct any program component.

Take a simple ``C`` program like "Hello, World". That program is probably
present in a single file named something like ``hello.c``. To build the
executable file from this source file, we have a few steps to work through. 

Here is our test file:

..  literalinclude::    code/hello.c
    :language:  c

The first thing we need to do is process the source file into an object file
named something like ``hello.o``. The command to do this step looks like
this:

..  code-block:: text

    gcc -c -o hello.o hello.c

Here we invoke the ``C`` compiler to process the ``hello.c`` file and build
the ``hello.o`` file from it. This only works if the source file has no
errors.

In this step, we say the ``hello.o`` is dependent on ``hello.c``. With no
``hello.c`` around, we cannot build ``hello.o``.

In the next step, we link the object file to build the final executable. Here
is the command:

..  code-block:: text

    gcc -o hello hello.o

..  note::

    This is a Linux example, the final executable has no extension

Here, the executable ``hello`` is dependent on ``hello.o``. If ``hello.o`` is
not around, we cannot build the final executable file.

Makefiles
*********

To use ``make`` to manage all this, we need to create a simple text file
containing information needed to describe this process we just went through
manually. Here is a start:

..  code-block:: make

    # Makefile for hello.c

    FILES = hello.c

Pretty simple so far, huh?

We name this file ``Makefile`` (no extension) and place it in the directory
with the other project files (``hello.c`` in this case).

Comments can be included, beginning with the sharp character.

The next line looks like an assignment statement, but it simple sets up a
name for a bunch of text after the equal (and a bit of white space). The text
continues to the end of the line. 

..  warning::

    When you type lines like this, be careful not to put extra spaces after
    the last character on the line. That can cause problems.

The next line we will add looks a bit strange:

..  code-block:: make

    OBJS = $(FILES:.c=.o)

In a ``Makefile``, you cause the ``make`` program to use a named chunk of
text by surrounding the name in parentheses and putting a leading "$" in
front. So, $(FILES) would become ``hello.c`` in this file. However, ``make``
can do a neat trick. Here the stuff after the colon is a substitution
mechanism. In the example, and text that ends with ".c" will become ".o" when
this stuff is expanded by ``make``. The net effect of all this is to create
another line that could have been written as follows:

..  code-block:: make

    OBJS = hello.o

While this looks silly here, in a more complex program is will save a bunch of
typing!

Let's add another similar line:

..  code-block:: make

    ASMS = $(FILES:.c=.s)

As before, this produces a list of assembly sourse files we might like to see:

    ASMS = hello.s

Again, in a larger project thsi wuld produce a space separated list of assembly
files for the entire project!


Targets
*******

``Make`` calls something it can build a ``target``. We can ask ``make`` to do a
bunch of things, but for now, we want to build our program. The rules we will
define next set up that process. Be careful in this section, there is one funny
quirk of ``make`` we must deal with.

Targets begin with the name of something, usually a file name we want to build,
but that something can just be a name of some operation we might want to do.
Start this section with the name ``all`` like this:

..  code-block:: make

    all:    hello

In this example, the name of the target is ``all``, and it is the first such line
in the file. ``Make`` will automatically try to build the first target it finds
in the file. In this case, we are saying that this name ``depends`` on
``hello``. If ``make`` is managing this project and ``hello`` is already in the
current directory, it is possible we have no work to do, so ``make`` might do
nothing. More on that later.

Normally, ``hello`` will not exist, so ``make`` wants to know how to build it!

Here is a new rule that will build the program:

..  code-block:: make

    hello:  $(OBJS)
            gcc -o hello $(OBJS)


..  warning::

    See that indented line where the command is shown. The first character on
    that line must be a ``tab`` character. or ``make`` will complain. This is
    the quirk! If you are editing in the :term:`virtual machine` with ``vim``,
    you type ``ctrl-v`` followed by the ``tab`` to enter the character assuming
    you are expanding tabs as I recommended.

This line tells ``make`` how to manufacture ``hello`` out of the dependencies
listed on the line after the colon. In this file, the ``$(OBJS)`` expands to
just ``hello.o``. If ``hello.o`` is around, all we need to do is to run the
command shown, substituting for the ``OBJS`` string. That is exactly what we
types manually to do the last step. Technically, we just invoked the linker to
build our executable file.

Great, but how do we get ``hello.o`` constructed?

Implicit rules
**************

One of the most powerful things that ``make`` can do is generate its own rules
if you provide a pattern. Here is an example. It does look a bit weird.

..  code-block:: make

    %.o:    %.c
        gcc -c $< -o $@

In this funny rule, any file ``make`` needs that is named ``something.o`` can
be constructed out of a dependent file named ``something.c``. If
``something.c`` is around, the command we execute is shown with two place
holders for the expanded names. In this example

* ``$<`` will be replaced by ``something.c``
* ``$@`` will be replaced by ``something.o``

The cool thing about rules like this is that any time you need a file like
``xxx.o``, the same rule will build it out of ``xxx.c``. All you need to do is
add ``xxx.o`` as a dependency and ``make`` will take care of things.

Make is smart!
**************

Once the required rules are in place to build a program, ``make`` does more
than just issue the commands to rebuild it. It looks at the time-stamps on
all the dependencies of every program component it knows how to build and
determines if it needs to reprocess anything. Think about it. If you did not
change the source file, the object file built from it will be newer than the
source file. The executable built from the object file will be newer than the
object file as well. ``Make`` can see that if you delete the executable, all
it needs to do is re-link the current object file to rebuild the missing
executable. There is no need to recompile the source, since it is older than
the current object file. This kind of power speeds up building a complex
project involving hundreds of files by only processing the bare minimum
needed to get the program constructed!

A more complex example
**********************

Let's break up our simple "Hello, World" program into two parts:

Here is ``hello_main.c``

..  literalinclude::    code/hello_main.c
    :language: c

And, here is ``hello_out.c``:

..  literalinclude::    code/hello_out.c
    :language: c

Here is a more complex ``Makefile`` that builds the program, and generates
assembly language listings for the files.

..  literalinclude::    code/Makefile
    :language: make



