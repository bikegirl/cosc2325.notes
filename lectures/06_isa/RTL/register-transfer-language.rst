..  _rtl:

Register Transfer Language (RTL)
################################

..  include::   /references.inc


Designers of digital systems have long grappled with the complexity of the
machines they design, and have developed a number of formal techniques to help
them do their design work. One of the tools they developed log ago was to talk
about the operation of digital machines by thinking in terms of the transfer of
data from component to component.

RTL is a very simple notation. We name each component using upper case
alphanumeric names, and show the transfer of data between components using
notation like this:

..  code-block:: text

       A <- B

This notation indicates that data available on register **B** are transferred
to register **A**. We assume that this transfer happens when a clock signal
occurs. The clock synchronizes the machine, and we indicate transfers at
specific ticks of the clock. A single function in the machine may take several
clock tocks to complete. We call each specific step a micro-operation, or
mu-op. 

We can indicate that the transfer only happens if some condition is met by
indicating the condition on the transfer line:

..  code-block:: text

    cond: A <- B

This transfer will only occur is ``cond`` is a ``1`` (true).

..  note::

    We often indicate the time of this transfer, using *t0* to indicate the
    start of the steps needed to complete this set of transfers. That time value is
    assumed to be "true" when the clock tick happens.

We can refer to certain bits within a register using b1..b2 as a subscript.
Since it is hard to show subscripts when typing simple text, so we will use
**R(b1..b2)** to indicate the bits within a register.

..  code-block:: text

    inst <- IR(12..15)         // means bits 12 to 15 in the IR register

Here are typical operations we might see in a digital machine:

Memory transfers
****************

Read 
====

..  code-block:: text

    AR <- address
    DR <- M[AR]

Write
=====

..  code-block:: text

    AR <- address
    DR <- value
    M[AR] <- DR         // store DR in memory at address in AR

ALU operations
**************

Math operations
===============

..  code-block:: text

    A <- B + C
    A <- B - C
    D <- D'             // ones complement
    D <- D' + 1         // twos complement

    E <- E + 1          // increment
    E <- E - 1          // decrement

Here, we use a quote character to indicate the NOT operation.

Logical operations
==================

..  code-block:: text

    E <- A and B        // logical and
    E <- A or B         // logical or
    E <- A xor B        // logical xor
    E <- A'             // complement

Shift operations
================

..  code-block:: text

    R <- shl R          // shift register left one bit position
    R <- shr R          // shift register right one bit position
    R <- ashl R         // arithmetic shift left one bit (accounts for sign)
    R <- ashr R         // arithmetic shift right one bit (accounts for sign)


Simple computer using RTL
*************************

Here is a set of registers we might use to implement a simple machine:

    +--------+-------+----------------------+------------------------------------------+
    | symbol | width | Name                 | Function                                 |
    +--------+-------+----------------------+------------------------------------------+
    | AR     | 16    | Address register     | Holds address to be accessed from memory |
    +--------+-------+----------------------+------------------------------------------+
    | PC     | 16    | Program Counter      | Holds address of next instruction        |
    +--------+-------+----------------------+------------------------------------------+
    | DR     | 32    | Data register        | Holds data moved to/from memory          |
    +--------+-------+----------------------+------------------------------------------+
    | AC     | 32    | Register 1           | General purpose register                 |
    +--------+-------+----------------------+------------------------------------------+
    | R2     | 32    | Register 2           | General Purpose register                 |
    +--------+-------+----------------------+------------------------------------------+
    | IR1    | 16    | Instruction register | Fetched instruction for decoding         |
    +--------+-------+----------------------+------------------------------------------+
    | IR2    | 32    | Second chunk of inst | Holds address or literal                 |
    +--------+-------+----------------------+------------------------------------------+
    | IN     | 32    | Input register       | Holds data from input device             |
    +--------+-------+----------------------+------------------------------------------+
    | OUT    | 32    | Output register      | Holds data to be written to output       |
    +--------+-------+----------------------+------------------------------------------+
    | ERR    | 1     | Error register       | Indicates error from ALU                 |
    +--------+-------+----------------------+------------------------------------------+

To formalize the action inside the processor as the instruction cycle operates,
we will use RTL to describe the action:

In each section, we will indicate specific clock ticks needed to complete the
action using ``tn``, where ``n`` is the clock cycle number. The cycle number is
indicated by ``S``, and we normally increment ``S`` after each mu-op. It is
possible to short circuit a sequence of operations by setting ``S`` to zero,
which starts the next mu-op cycle.

Fetch
=====

..  code-block:: text

    t0: AR <- PC            // move program counter to address register
    t1: DR <- M[AR]         // retrieve data from memory (16 bits)
    t2: IR1 <- DR           // move data to IR for decoding

Decode
======

..  code-block:: text
    
    t0: inst <- IR1[12-16],  //  decode bits in IR
        reg1 <- IR1[9-11],
        mode1 <- IR1[6-8],
        reg2 <- IR1[3-5],
        mode2 <= IR1[0-2],
        I =  IR1[17]        // this is new, we will add this bit to indicate we need an operand
   
    t1: I?: AR <- PC        // place progrmam counter in address register
    t2: I?: DR <- M[AR]     // retrieve memory contents into data register
    t3: I?: IR2 <- DR       // store data in IR2

Execute
=======

Obviously, this is where all the hard work is going to happen. We will
demonstrate one particular instruction to show how this works. 

Consider a move from memory to a register:

..  code-block:: text

    t0: AR <- IR2                       // move operand address to address register
    t1: DR <- M[AR]                     // move data into data register
    t2: R1 <= DR                        // move data from data register into final register

Let's try an instruction that uses the ALU

Consider adding R1 and the contents of memory 

..  code-block:: text

    t0: AR <- IR2
    t1: DR <- DM[AR]
    t2: DR <- R1 + DR

What gives? We did not mention moving data to the ALU at all! Actually, we can
drop to this level is needed:

..  code-block:: text

    t0: AR <- IR2           // move data address to address register
    t1: DR <- DM[AR]        // fetch data at that address
    t3: ALU.OP1 <- DR, 
        ALU.OP2 <-R1, 
        ALU.code <- inst    // send both operands to the ALU
    t4: DR <- ALU.RES       // return the result to the data register

Here, we have identifies the three ports on the ALU. ALU1, and ALU2 are inputs, and ALU.RES is the result register.

Retire
======

We left the final result in the DR register in these last operations. Retire
moves those data to their final home:

..  code-block:: text

    t0: AR <- IR2               // move data address into address register
    t1: DM[AR] <- DR            // transfer data registe to memory

Designing with RTL
******************

RTL specifies what must happen in the machine, without saying exactly how we
must design the system. As an example of how this works, consider this setup:

..  code-block:: text

    R1 <- IN
    R2 <- IN
    R3 <- R1 + R2
    R2 <- R3

From this we can identify the circuit needed to implement this machine:

We will need a demultiplexer to gate signals from IN to either R1 or R2, and we
need an adder with two inputs and a single output to produce the sum. Finally,
we will need a multiplexor to route either the adder output or R3 into R2.

Here is the first diagram we can generate from this RTL.

..  graphviz::

    digraph G {
        IN -> R1;
        IN -> R2;
        R1 -> ADD;
        R2 -> ADD;
        ADD -> R3;
        R3 -> R2;
        { rank=same; R1; R2; R3 }
    }

There is are easy to spot problems with this diagram. We have IN transferring
to multiple registers, and multiple inputs arriving at R2. We introduce
additional devices to isolate these problems:

..  graphviz::

    digraph G {
        DEMUX [ shape=box ];
        MUX [ shape=box ];
        
        IN -> DEMUX;
        DEMUX -> R1;
        DEMUX -> MUX;
        MUX -> R2;
        R1 -> ADD;
        R2 -> ADD;
        ADD -> R3;
        R3 -> MUX;
        { rank=same; R1; R2; R3 }
    }

In this implementation, each register has a clear single input from some
device, and its output goes to a single device. All we need to do is add
clocking and selector signals for those signal routine components, and we can
build this machine!

RTL Timing Analysis
*******************

It is possible to assign delays into this design system, and study the various
paths the signals will take as the machine runs. Specifically, we can find the
longest path in such a system, and from that, calculate how fast we can run the
clock that drives the system. 

Since we are not actually designing the components needed to make the machine
work, we will limit our use of RTL specification to just defining how the data
moves between components. Each multiplexor or demultiplexer needed to properly
route signals between components will need control lines to make the
selections. All of these control signals must be derived from the combination
of the instruction and the operands selected. All of that information is
determined during the decode step.

Fortunately, for our simple simulation, we will not worry about routing signals
through such devices, but will simply use procedure calls to model how the
signals move from place to place. The decoding logic will tell us which next
component gets the signals after any given component completes its work.

We could use the new simulation scheme to do a better job of modeling all of
this, but we will stick to our simple four-step approach, and just simulate the
basic instruction flow. 

We will look at the final simulator project next.

..  vim:filetype=rst spell:
