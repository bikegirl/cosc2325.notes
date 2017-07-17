..  _avr-assembly:

Basic AVR assembly language
###########################

..  include::   /references.inc

The basic layout of a program file should look very familiar. 

    * Comments begin with a semicolon
    * We will declare labels as usual
    * Directives will be a bit different
    * Assembly files are named ``something.S`` (note the capital S)


Headers
*******

You should use a header to identify the file, and who created it.

..  literalinclude::    code/aBlink/aBlink.S
    :lines: 1-3

Put any additional documentation you need here as well.

Chip Definitions
****************

We need to define the I/O pins we will use for this project, and we need help
in mapping register names to actual locations in the system RAM. All of this is
controlled in a single configuration file we include in our program code with
this line:

..  literalinclude::    code/aBlink/aBlink.S
    :lines: 5

Here is the configuration file needed for our first program:

..  literalinclude::    code/aBlink/config.inc
    :linenos:

i.. note::
    
    The two include lines take care of defining the registers properly. The
    ``AVRSpecialRegs.inc`` file contains some definitions that take care of some
    peculiar rules for accessing some of the registers. When we use certain
    registers in our code, we will have to add a leading underscore to their names.
    This will be seen in the example code in these notes. Most example code written
    for the AVR in assembly language use an odd notation to deal with this
    issue. I found a cleaner way to handle the issue. Just be careful to use that
    underscore. The assembler will tell you if there is a problem.

Code layout
***********

This particular program oes not define any variables, so we do not need a data
segment in the code. These lines set up the code segment.

..  literalinclude::    code/aBlink/aBlink.S
    :lines: 7-10

The ``org`` tells the assembler to set up the code so it runs at address zero
in the program memory. When you reset the processor, it always begins execution
at this address.

Code layout
***********

..  literalinclude::    code/aBlink/aBlink.S
    :lines: 12-17

The first block of code sets up a stack so we can use subroutines. The stack
pointer is a 16 bit register that we can access in two parts (SPH and SPL).
Note those underscores in this code. 


Hello, World - Arduino style
****************************

The equivalent of "Hello, World: is simple on an Arduino:

    * Blink a light at some defined rate

We start off by initializing the I/O pins we will be using. Those were defined
in the ``config.inc`` file:

..  literalinclude::    code/aBlink/aBlink.S
    :lines: 19-20

Next, we set up a simple loop:

..  literalinclude::    code/aBlink/aBlink.S
    :lines: 22-25

See an unusual label here

    * labels can be numbers, references can say "f" (forward) or "b" (backward)
    * No more silly names needed

Initializing the chip
*********************

The initialization code is pretty simple:

    * We start by clearing the system FLAG register
    * we need to set up the system clock
    * We need to configure the output pin hooked up to the LED

Clearing the FLAG register
**************************

..  literalinclude::    code/aBlink/aBlink.S
    :lines: 27-28

* We leave the zero in ``r1`` for use whenever we need a zero
    * We have enough registers to sacrifice one!

Setting up the clock
********************

..  literalinclude::    code/aBlink/aBlink.S
    :lines: 29-31

We will go over this code later

Initializing the LED pin
************************

We need to configure the pin attached to the LED on the Arduino board so it is
an output pin. This code does that:


..  literalinclude::    code/aBlink/aBlink.S
    :lines: 33-35

Toggling the LED on/off
***********************

Finally, we blink!

..  literalinclude::    code/aBlink/aBlink.S
    :lines: 38-42

This is all the code we need - except for the delay code

Just for reference, here is the complete program:

..  literalinclude::    code/aBlink/aBlink.S
    :linenos:

..  vim:filetype=rst spell:
