CPUsim Instruction Encoding
###########################

Here are the encodings we will use for the simulator project (Lab 3)

..  note::

    You do not need to implement all of the instructions listed here, just
    those mentioned in the lab assignment. We will add others from this set if
    time allows.

Instruction Encodings
*********************

The controller will fetch a single byte during the *Fetch* phase. The
instruction will have these codes:

..  csv-table::
    :header: Mnemonic, Code, ModRM
    :Widths: 6, 4, 3

    UNDEF,0,0
    MOV,1,1	
    ADD,2,1		
    SUB,3,1		
    MUL,4,1		
    DIV,5,1		
    AND,6,1		
    OR,7,1		
    XOR,8,1		
    NOT,9,1		
    JMP,10,1		
    CMP,11,1		
    JE,12,1	
    JNE,13,1		
    JG,14,1		
    JGE,15,1		
    JL,16,1		
    JLE,17,1		
    CALL,18,1	
    RET,19,0		
    POP,20,1		
    PUSH,21,1		
    OUT,22,1		
    HLT,23,0

The **ModRM** field is a Boolean value indicating that the instruction needs to
fetch an additional word during decode. Based on that word, there may be an
additional word to be fetched as well. (see below)

ModRM Fields
************
	
The ModRM word is encoded with four fields:

    * Mode1 (4 bits)
    * Register number (4 bits)
    * Mode2 (4 bits)
    * Register number (4 bits)

Note that not all bit values available in these fields are valid. Any invalid
fields should be ignored (use the default in a switch statement to deal with
this)

Here are the encodings needed:

Mode1 Field
===========

This field identifies the kind of operand in the first position

..  csv-table::
    :header: Mode1, Meaning	

	0,No Opr1 (implies no Opr2 as well)	
	1,Opr1 is a register (code is in the next 3 bits)	
	2,Opr1 is a byte address (Memory reference - address is in the next word)	
	3,Opr1 is a word address (Memory reference - address is in next word)

Register (Reg) Field
====================

..  csv-table::
    :header: Reg, Meaning
	
    0,R1	
	1,R2	
	2,R3	
	3,R4	
	4,R5	
	5,R6	
	6,R7	
	7,R8	

Mode2 Field
===========

This field identifies the kind of operand in the second position (if any).

..  csv-table::
    :header: Mode2, Meaning	

	0,No Opr2	
	1,Opr1 is a register (code is in next 3 bits)	
	2,Opr2 is a byte address (Memory reference - address is in next word)	
	3,Opr2 is a word address (Memory reference - address is in next word)	
	4,Opr2 is a byte literal (value is in next word)	
	5,Opr2 is a word literal (value is in next word)	
			
Implementation Notes
********************

Registers are all 16 bits wide. 

If you load a byte into a register, you need to zero fill the rest of the
register. 

No instruction allows two memory references, or a memory reference and a
literal value. That would imply that we need two additional words, and we will
only allow 1, so the maximum size for any instruction is 5 bytes.

If operand 1 specifies a memory reference (codes 2 or 3), then the second
operand (if needed) must refer to a register.

For the **CALL**, **POP**, **PUSH**, and **OUT** instructions, the **Mode1**
field should be used. That means we cannot use literals as the single operand
in these instructions.

You should probably set up separate methids (with switch statements) do handle
processing these fields. Your main instruction decoding routines can use a
(large) switch statement to define which fields are needed. There is a lot of
detail in this code, but the process is pretty simple.

If a literal is used in the second operand, the first operand must refer to a
register.

Coming up with the data files
*****************************

For testing, you need to create some test code. The code and **ModRM** data
needs to be a single positive integer number, one per line. If the data item is
a literal number, it can be signed, but pay attention to the allowable range of
values if you are going to specify a byte literal. 

You can figure out the **ModRM** values by converting each field into a hex
character, then using a programmer's calculator to convert the resulting four
character hex value to a decimal number. (I used a simple Excel spreadsheet to
calculate the values needed. Just set up formulas to multiply the four fields
by the power of 16 needed to combine the values. See me if your Excel skills
are rusty! (This tool is amazingly handy for many things you never expected yto
use it for!)

If you want to use a single file to set up both code and data, use some insane
number to mark the boundary between the two sections. That way, a simple loop
that reads the data file can start off loading memory from the code section,
then switch to the data area and load the data there. I used byte values for
all data items, and figured out the two numbers using Excel again. 

Testing Your Controller
***********************

We need a way to test the controller without needing a lot of data files to
load memory. You should test one instruction at a time. However setting tht up
gets tricky if you keep methods private (as you should in real life, unless
they are needed by the user.

In researching testing in C++ applications, there seems to be two camps. One
says never test private methods. YOy should only test the public interface to
your class. The private functions are implementation details the user should
not know about. These folks do not test private functions directly.

The second camp says this is silly. You need to test all of your code, but
doing this gets messy if you want to test a private method (like **fetch** for
example). One solution to this dilemma is to create *Friend* functions that
can access private methods. Doing this is messy, especially for new C++
programmers. 

For our work, we will temporarily silence Guido and make all methods and
attributes in the Controller class public. (Yes Guido will be pitching a fit,
but we need to test things!) Then you can load set up your test code as
follows:

    * load memory with one instructions worth of data for the test.

    * call any class method and verify that internal attributes get set
      properly. 

This class needs a lot of tests if we implement all the instructions. For Lab
3, you do not need to implement all of them, just those that exercise the ALU
and Memory units. We will implement other instructions later.



