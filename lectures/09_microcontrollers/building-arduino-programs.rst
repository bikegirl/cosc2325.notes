..  _arduino-build:

Building Arduino Programs with Make
###################################

..  include::   /references.inc

Behind the Arduino IDE is a tool set we should know reasonably well. The
standard GNU C/C++ compiler has been adapted to produce code for the AVR family
of processors. (Actually, the GNU tools handle many other processors and languages as
well. They have a nice modular design allowing parts to be replaced as needed!)

The AVR-GCC tools are packaged as part of the Arduino_ IDE, but they can also
be installed as a separate package on your favorite system. For our work, we
will use the tools that come with the IDE. This makes installation simpler, but
it complicates our ``make`` build system a bit. Specifically, the location of the
programs we need to use will need to be specified, since they will not be
available directly from the command line.

Makefiles
*********

If you are managing your own program build system, you should place a
``Makefile`` in each project folder you set up. In many projects this file is
just one (possibly big) file with all the rules and definitions needed to get
your code running. After you use this approach for a while, it will probably
strike you that managing your ``Makefile`` in a better way might help
streamline things.

Here is my goal for this setup:

..  literalinclude::    code/aBlink/Makefile
    :linenos:

There is nothing in this file that is not essential to our current project. 

The ``TARGET`` line identifies the final program "executable" file we will be
building. For AVR projects, the executable file is very different from those we
have seen up to now. This file will be a simple text file containing the bits
we need to load into the chip's flash program memory using a loader program.

The ``ASRCS`` line identifies all the assembly language files in this project
directory. They will all end in capital ".S".

The ``INTTBL`` line is new. We will use it later, when we explore interrupts.
For now, just make sure it is included in your assembly language projects.

The next two lines identify the exact AVR chip we are using and the frequency
of the clock on that board. For the Arduino_ UNO boards I provide in class,
these settings are correct. If you use your own boards, be sure to check these
settings.

Finally, we come to the critical part. Nothing beyond this point in the
``Makefile`` really changes from project to project. For that reason, I am
moving all remaining parts of the ``Makefile`` from this particular file, and
out of the project level ``Makefile`` and including everything else through
just one line.

There are two ways you can set up the remaining parts of the ``Makefile``. One
simply places the needed files in your project's ``include`` directory which
should be beside the directory holding your source code. The second way places
all the additional parts of the ``Makefile`` in a standard system directory. On
Linux and Mac systems, this directory is normally ``/ur/local/include``. This
directory does not exist on a PC, but I add it to my PC systems to make things
easier to manage.

Here are the additional files that make up the complete ``Makefile`` system for
Arduino projects:

    * AVRMakefile.mak
    * AVRBuildRules.mak
    * AVRMakeLinux.mak
    * AVRMakeMac.mak
    * AVRMakeWin.mak
    * AVRSpecialRegs.inc

Platform Specifics
==================

You may choose to work on a PC, a Mac, or even a Linux system. As an
instructor, I see all three platforms in my classes, even though we only
"officially" support Windows (and Windows 7 at that!) I decided to set up this
build system so it works on any of those platforms.

To deal with this, we need to isolate the parts of the build commands that
differ between platforms, and make sure we use the right settings for the
system we are using. 

The first problem is identifying the system we are using. This is actually not
that hard to do.

..  literalinclude::    code/include/AVRMakefile.mak
    :linenos:

On a PC system, a standard environment variable is set, and ``make`` can check this variable to see if it contains the string ``WIN_NT``. If so, we are running on a PC. For Linux and Mac systems, we need to get ``make`` to run a command fr us, and record the result. That cammand is ``uname -s`` which returns ``Linux`` on a Linux system, and ``Darwin`` on a Mac. This entire block of code lets ``make`` determine what system we are on, and includes a platform specific additional file with more rules.

As an example of this setup, let's examine the Linux file:

..  literalinclude::    code/include/AVRMakeLinux.mak
    :linenos:

Makefile Components
###################

Just for reference, here is the complete set of files needed for this build system:

:AVRMakefile.mak:

..  literalinclude::    code/include/AVRMakefile.mak

:AVRBuildRules.mak:

..  literalinclude::    code/include/AVRBuildRules.mak

:AVRMakeLinux.mak:

..  literalinclude::    code/include/AVRMakeLinux.mak

:AVRMakeMac.mak:

..  literalinclude::    code/include/AVRMakeMac.mak

:AVRMakeWin.mak:

..  literalinclude::    code/include/AVRMakeWin.mak

:AVRSpecialRegs.inc:

..  literalinclude::    code/include/AVRSpecialRegs.inc


