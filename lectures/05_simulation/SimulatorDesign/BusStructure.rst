..  _bus-structure:

Simulator Bus Structure
#######################

When we draw a diagram of the internals of a machine, we use a lot of
rectangular shapes and lines running between them. The rectangles define
a digital component of some sort, with a standard pattern:

..  circuits::
    :align: center
    :width: 250
    :tikzopts:  node distance=2cm, auto
    :tikzlibs:  shapes, arrows

    \tikzstyle{component} = [rectangle,
        draw, text width=5em, text centered, 
        rounded corners, minimum height=4em, fill=green!30]
    \tikzstyle{line} = [draw, -latex']

    \node (pc) [component] {Component};
    \path [line] ([xshift=-2cm]pc.west) -- node [anchor=south] {inputs} (pc.west);
    \path [line] (pc.east) --  node[anchor=south] {outputs} ([xshift=2cm]pc.east);
    \path [line] ([yshift=-1cm]pc.south) node[anchor=east] {controls} -- (pc.south);

In this diagram, each component has three sets of signals connected to
it. On the left, we have data signals coming into the component. On the
right, results will be headed out to other devices. The control lines
determine exactly what happened inside the component. Typically, those
controls include the clock signal, and all actions are synchronized to
that. For this discussion, we will not show the control lines for
everything, but will show the essential lines needed by the device.

Working through the Cycle
*************************

To make sure the machine we are designing will actually function, we need
to walk through a typical four-step cycle, and see what data bits move where.
We will start off with the *fetch* step.

Fetch
=====

We need to use the current value stored in the *Program Counter* (*PC*)
to access part (or all) of an instruction stored in the *Instruction
Memory*. We will use a Harvard Architecture in this design, to prevent
accidentally fetching some data and causing the machine to go off who
knows where!

Here is the start of our machine design:

..  circuits::
    :align: center
    :width: 100
    :tikzopts:  node distance=2cm, auto
    :tikzlibs:  shapes, arrows

    \tikzstyle{component} = [rectangle,
        draw, text width=5em, text centered,
        rounded corners, minimum height=4em, fill=green!30]
    \tikzstyle{line} = [draw, -latex']

    \node [component] at (0,0) (pc){Program Counter};
    \node [component] at (0,-2.5) (im) {Instruction Memory};
    \path [line] (pc) -- node [anchor=east] {addr} (im);

Simple so far. The actual number of signal lines passing between these
two components depends on the size of the basic group pf bits the
processor uses. Early machines, used 8 bits, modern processors use
64-bits! (That is a lot of wires).

Once the *Instruction Memory* unit gets the required data ready, it will
place it on the output lines  and those data bits will travel to the
*Decoder* for step two.


..  circuits::
    :align: center
    :width: 100
    :tikzopts:  node distance=2cm, auto
    :tikzlibs:  shapes, arrows

    \tikzstyle{component} = [rectangle,
        draw, text width=5em, text centered,
        rounded corners, minimum height=4em, fill=green!30]
    \tikzstyle{line} = [draw, -latex']

    \node [component] at (0,0) (pc){Program Counter};
    \node [component] at (0,-2.5) (im) {Instruction Memory};
    \path [line] (pc) -- node [anchor=east] {addr} (im);
    \node [component] at (0,-5.0) (decode) {Decoder};
    \path [line] (im) -- node [anchor=east] {inst} (decode);

That completes the *fetch* step.

Decode
======

Decoding involves analyzing the instruction delivered to the *Decoder*
input. Typically, the instruction is packed into *bit fields* so breaking
it apart is fairly easy. The *Decoder* will need to consult a table of
rules that tell it if there are more bits to fetch. For our simple
machine, we will ignore that possibility for now, and assume that all
instructions are a fixed size. (We will use 32 bits for our machine).

What fields do we need to decode? If the machine is going to do math, we
need to identify the two operands, and the specific instruction we want
the *ALU* to process. We also need to compute the size of the
instruction so we can update the *Program Counter*. So, there are four
basic parts to decode in our setup. Before we detail those fields, we
need to consider where we are going to get the operand data values from.

Almost all processors are constructed with a set of internal
*registers*, which are just memory cells with names rather than numbers.
Internally, we can assume that there are some number of them available,
and we will call the memory area where they are constructed a *Register
File*. The actual memory used for this area is extremely fast, much
faster than other memory in the system.

We have a problem identifying two operands in one instruction. The size
of available *Data Memory* dictates the number of bits we need to create
an address for that memory. Combine that with the number of bits to
identify the register, if needed, and we run into limits on what we can
encode in 32 bits. Let's try this:

    * Instruction (5 bits will give us a total of 32 instructions

    * Operand 1 - must be a register, let's use 4 of them, so two bits
        are needed to select the particular one.

    * Operand 2 - can be either a register, or data memory address. We
        have used up 9 bits, leaving 23 bits for the address. That will
        reach  more memory than we need for our purposes.

Here are the decoded signals, ready to move on to other components. Here
is a start on where those signals go:


 ..  circuits::
    :align: center
    :width: 400
    :tikzlibs:  shapes, arrows

    \tikzstyle{component} = [rectangle,
        draw, text width=5em, text centered,
        rounded corners, minimum height=4em, fill=green!30]
    \tikzstyle{line} = [draw, -latex']

    \node [component] at (0,0) (pc){Program Counter};
    \node [component] at (0,-2.5) (im) {Instruction Memory};
    \path [line] (pc) -- node [anchor=east] {addr} (im);
    \node [component] at (0,-5.0) (decode) {Decoder};
    \path [line] (im) -- node [anchor=east] {inst} (decode);
    \node [component] at (3,-7)(rf) {Register File};
    \node [component, right of=rf, node distance=4cm] (dm) {Data Memory};
    %  op1 to RF
    \path [line] (decode) |- node [anchor=south west] {op1}(rf);
    % op2 to DM
    \path [line] (decode) -| node [anchor=west] {op2}(dm);


Updating the PC
---------------

We have not shown the *size* field yet. If we keep this a fixed size,
things get easier, but we still have to add this size to the current
*PC* and write it back into the *Program Counter* register. If these
calculations are complicated, we might use the *ALU* we are about to add.
But, since this machine just needs to add a fixed number to *PC*, we
will show a simple *adder* that does the job:

..  circuits::
    :align: center
    :width: 400
    :tikzopts:  node distance=2cm, auto
    :tikzlibs:  shapes, arrows

    \tikzstyle{component} = [rectangle,
        draw, text width=5em, text centered,
        rounded corners, minimum height=4em, fill=green!30]
    \tikzstyle{line} = [draw, -latex']

    \node [component] at (0,0) (pc){Program Counter};
    \node [component] at (0,-2.5) (im) {Instruction Memory};
    \path [line] (pc) -- node [anchor=east] {addr} (im);
    \node [component] at (0,-5.0) (decode) {Decoder};
    \path [line] (im) -- node [anchor=east] {inst} (decode);
    \node [component] at (3,-7)(rf) {Register File};
    \node [component, right of=rf, node distance=4cm] (dm) {Data Memory};
    %  op1 to RF
    \path [line] (decode) |- node [anchor=south west] {op1}(rf);
    % op2 to DM
    \path [line] (decode) -| node [anchor=west] {op2}(dm);

    % pc update
    \node [component] at (3,-1) (add) {Add};
    \path [line] ([yshift=0.5cm]decode.east)
        -| node [anchor=north] {size} (add);
    \path [line] (0,-1) -- (add);
    \path [line] (add) |- (pc);

..  note::

    You might notice that we have not provided a path from the *Decoder*
    to *Register File* for operand 2. We will discuss that in a later
    lecture. For now, it looks like we can only operate on one register and
    a memory address.

We have not shown the decoded  *instruction* field, but we will do that
when we add the *ALU* next

Execute
=======

Now that we have all the basic data needed to actually perform a
calculation, it is time to add the *Arithmetic/Logic Unit*. Thie
standard symbol for this component like like this:

..  circuits::
    :align: center
    :width: 400
    :tikzopts:  node distance=2cm, auto
    :tikzlibs:  shapes, arrows

    \tikzstyle{component} = [rectangle,
        draw, text width=5em, text centered,
        rounded corners, minimum height=4em, fill=green!30]
    \tikzstyle{line} = [draw, -latex']

    \node [component] at (0,0) (pc){Program Counter};
    \node [component] at (0,-2.5) (im) {Instruction Memory};
    \path [line] (pc) -- node [anchor=east] {addr} (im);
    \node [component] at (0,-5.0) (decode) {Decoder};
    \path [line] (im) -- node [anchor=east] {inst} (decode);
    \node [component] at (3,-7)(rf) {Register File};
    \node [component, right of=rf, node distance=4cm] (dm) {Data Memory};
    %  op1 to RF
    \path [line] (decode) |- node [anchor=south west] {op1}(rf);
    % op2 to DM
    \path [line] (decode) -| node [anchor=west] {op2}(dm);

    % pc update
    \node [component] at (3,-1) (add) {Add};
    \path [line] ([yshift=0.5cm]decode.east) 
        -| node [anchor=west] {size} (add);
    \path [line] (0,-1) -- (add);
    \path [line] (add) |- (pc);
 
    % alu
    \draw [fill=blue!20](2,-9) --++ (2,0) --++ (1,-1) --++ (1,1) --++ (2,0)
        --++ (-2,-2) --++ (-2,0) -- cycle;
    \coordinate [label=below:$d1$] (d1) at (3,-9);
    \coordinate [label=below:$d2$] (d2) at (7,-9);
    \coordinate [label=above:$result$]  (result) at (5,-11);
    \coordinate [label=ALU] (alu) at (5,-10.5);

    % instruction bus
    \draw (decode.west) --++ (-1,0) --++ (0,-5);
    \path [line] (-2,-6) |- node [anchor=east] {inst} (3,-10);

    % alu input data
    \path [line] (rf) -- (d1);
    \path [line] (dm) -- (d2);

t this point, we have calculations happening! All we need to do to
complete this overview is find a way to save the results of the
calculation.

Retire
======

We actually have two choices here. We can put the result back in a
register, or we can put it back in memory.  We wull show a path to both
units. FIguring out how to direct the result to the right place is
something we will explore when we design our instruction set soon.

..  circuits::
    :align: center
    :width: 400
    :tikzopts:  node distance=2cm, auto
    :tikzlibs:  shapes, arrows

    \tikzstyle{component} = [rectangle,
        draw, text width=5em, text centered,
        rounded corners, minimum height=4em, fill=green!30]
    \tikzstyle{line} = [draw, -latex']

    \node [component] at (0,0) (pc){Program Counter};
    \node [component] at (0,-2.5) (im) {Instruction Memory};
    \path [line] (pc) -- node [anchor=east] {addr} (im);
    \node [component] at (0,-5.0) (decode) {Decoder};
    \path [line] (im) -- node [anchor=east] {inst} (decode);
    \node [component] at (3,-7)(rf) {Register File};
    \node [component, right of=rf, node distance=4cm] (dm) {Data Memory};
    %  op1 to RF
    \path [line] (decode) |- node [anchor=south west] {op1}(rf);
    % op2 to DM
    \path [line] (decode) -| node [anchor=west] {op2}(dm);

    % pc update
    \node [component] at (3,-1) (add) {Add};
    \path [line] ([yshift=0.5cm]decode.east)
        -| node [anchor=west] {size} (add);
    \path [line] (0,-1) -- (add);
    \path [line] (add) |- (pc);

    % alu
    \draw [fill=blue!20](2,-9) --++ (2,0) --++ (1,-1) --++ (1,1) --++ (2,0)
        --++ (-2,-2) --++ (-2,0) -- cycle;
    \coordinate [label=below:$d1$] (d1) at (3,-9);
    \coordinate [label=below:$d2$] (d2) at (7,-9);
    \coordinate [label=above:$result$]  (result) at (5,-11);
    \coordinate [label=ALU] (alu) at (5,-10.5);

    % instruction bus
    \draw (decode.west) --++ (-1,0) --++ (0,-5);
    \path [line] (-2,-6) |- node [anchor=east] {inst} (3,-10);

    % alu input data
    \path [line] (rf) -- (d1);
    \path [line] (dm) -- (d2);

    % alu back to registrs or dm
    \path [line] (5,-11) --(5,-12) -- (9,-12)
        -- (9,-5.5) -- (3,-5.5) --(rf);

    % hilight joins
    \draw [red, ultra thick] (7,-5.5) circle [radius=5pt];
    \fill (7,-5.5) circle [radius=2pt];
    \draw [red, ultra thick] (0,-1) circle [radius=5pt];
    \fill (0,-1) circle [radius=2pt];

There are two places in this diagram where we need to think about how
electrons move. We want them to move from an output to the next input, so
the question is simple. Is this bus going to work properly.

The junction at the top, where the *PC* data is moving to the
*Instruction Memory* unit also goes to the update adder at the same
time. This will work, and it means that as the *IM* is working on
returning the instruction, the adder has part of what it needs to
update. What is missing it the *size* piece, which will not be available
until the *decoder* gets done. Is this going to work? Timing studies will
need to happen to figure this out. For now we will let this stand.

The second junction is more difficult. We have the results from the
*ALU* following a path that eventually runs into the path from the
*decoder* to the *data memory* unit. This kind of situation is not going
to work, since we have two signals colliding with each other. The
solution is to add a *multiplexor* that will decide which signal reaches
the *data memory*. We will explore this problem later. For now, it looks
like things can reach places they need to be.

Controls
********

We have not shown all the control lines needed to make all of this
really work. Doing that would really make this diagram messy, so I left
those off. Just remember that the control unit, synchronized by the
system clock,is generating signals that determine exactly what each
comoonent does with its inpur signals, and what results get placed on
that components output for the next cycle.

..  vim:filetype=rst spell:


