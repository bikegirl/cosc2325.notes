Designing a Simulator 
#####################

..  include::   /references.inc

..  wordcount::

Real computers are made up of a (potentially large) number of very simple
digital components. These components are interconnected by wires, used to
transfer electrical signals between the components. Making the entire machine
function, we find a clock, triggering action in most (but not all) of those
components.

So, our simulator needs to work like the machine just described. If we want to
build a program that works like the real machine, we need to construct both
components and wires, and hook everything together somehow.

How can we do that.

Functions and Parameters
************************

In most of your programming, you shift the action from one block of code to
another using a subprogram call. That call transfers a set of parameters (data
values) between the modules that make up your program. That might seem to
provide a simple way to model a computer, and many beginning courses in
computer architecture do just that. Unfortunately, that gets us back to the
emulator style of program. 

The biggest problem with this approach is that the calling code needs to know
details about the called code so the call can happen. That call actually
triggers the called module into action! Furthermore, control returns to the
calling code after the call is finished. In a real computer circuit, each
component does some work, processing available input signals, and places output
signals on a set of output lines. That component has no idea where those input
lines came from, or where those output lines go, or why.  Obviously, each
output signal line heads off to another component, and each input line came
from some other component. But neither the sending component nor the receiving
component knows anything about each other. That makes for a very different kind
of program if we want to simulate the real machine.

Computer Components
*******************

There are two major classes of components we need to model in our simulator:

    * Digital components that perform some action on signals arriving at the component
    * Wires that transfer signals between components

As we have seen, the digital components can be further divided into either
"combinational" or "sequential" components.

Combinational Components
========================

Combinational components begin their internal work as soon as a signal reaches the input
side. In fact, you might view them as reacting continuously to whatever happens
on those input lines as time progresses. Fortunately (for us), most computer
circuits are designed so that signals change only at specific points in time,
and those points are defined by the master clock driving much of the overall
action.

While we can view the cock signal as something reaching all components,
combinational components do not really react to the clock. 

Here is a simple diagram representing a combinational component:

..  circuits::
    :align: center
    :width: 400
    :tikzopts: node distance=2cm, auto
    :tikzlibs: shapes, arrows

    \tikzstyle{component} = [rectangle,
        draw, text width=5em, text centered, 
        rounded corners, minimum height=4em, fill=green!30]
    \tikzstyle{line} = [draw, -latex']

    \node (pc) [component] {Component};
    \path [line] ([xshift=-2cm]pc.west) -- node [anchor=south] {inputs} (pc.west);
    \path [line] (pc.east) --  node[anchor=south] {outputs} ([xshift=2cm]pc.east);
    \path [line] ([yshift=-1cm]pc.south) node[anchor=east] {controls} -- (pc.south);

..  note::

    The action inside that transforming block can be defined by a Boolean
    expression. From that expression, we can derive the actual digital circuit
    needed to create this component. We will not be doing that in this class.
   
Modeling Combinational Components
---------------------------------

We will model combinational components using simple functions that perform some
data transformation each time they are activated. The big puzzle is this:

    How will we provide input signals to the component, and how will the
    component generate output signals when it it done?

    Oh yeah! And how do we trigger the component into action?

Signals
*******

We can model signals using simple integer numbers. We may need to restrict the
range of values used in those signals, which reflects the fact that a signal
may be one bit traveling over a single wire, or a set of bits traveling in
parallel over a set of wires we call a 'bus". Normally, a wire only has a
single "input" source (coming from some some component), but we can attach multiple components
to the output side of a wire. All components attached to the output side
receive the exact same signal. 

Modeling Signals
================

We can model a wire as a simple object that can hold a value for some amount of
time. The input side defines the value on the wire (or wires), and the output
side delivers that value when needed. (The attached components will ask the
wire for the current value. A wire is a super-simple combinational component.
It performs no transformation, and simply passes the input side to the output
side as needed. Nothing changes on that wire, until the component on the input
side decides to modify the value on the wire.

..  note::

    As you saw in your homework assignment, those signals actually travel over
    the wire at some fixed speed (the speed of light) which is fast, but
    measurable. Depending on how long the wire is, and how fast we want our clock to
    be, we will discover that the smaller we can make things, and the shorter the
    wires we can create, the faster signals to move to wherever they need to go.
    That is what has been driving the transistor count up, and the distance between
    those transistors down. Unfortunately, we are running into the physical limit
    on how small we can make things!

Sequential Components
*********************

Sequential components are harder to deal with. They also have an input side,
and an output side. They may also have some internal combinational components
that transform signals as they move through the device. However, they have
something inside that can store a "state" and hold onto that state until told
to change it. 

Here is a simple diagram showing such an arrangement of sub-components in a
typical sequential component.

..  circuits::
    :align: center
    :width: 500
    :tikzopts: node distance=2cm, auto
    :tikzlibs: shapes, arrows

    \tikzstyle{component} = [rectangle,
        draw, text width=5em, text centered, 
        rounded corners, minimum height=4em, fill=green!30]
    \tikzstyle{line} = [draw, -latex']
    \tikzstyle{register} = [rectangle,
        draw, text width = 2em, text centered,
        minimum height = 7em, fill=green!30]

    \node (ic) [component] at (0,0) {Input\\Comb};
    \path [line] ([xshift=-2cm] ic.west) -- node [anchor=south] {Inputs} (ic);
    \node (reg1) [register] at (3,0) { $R_{new}$ };
    \node (mid) at (3.5,-1) {};
    \node (reg2) [register] at (4,0) { $R_{old}$ };
    \path [line] (ic) -- (reg1);
    \node (oc) [component] at (6.5,0) {Output\\Comb};
    \path [line] (reg2) --  (oc);
    \path [line] (oc) -- node [anchor=south] {Outputs} ([xshift=2cm] oc.east);
    \path [line] ([yshift=-1cm]mid.south) node[anchor=east] {controls} -- (mid);

..  note::

    Formally, this is a version of a *Moore Machine* which you will run into
    when you study *Finite State Machines* in later courses. In a real Moore
    Machine, the current register output can be fed back to the input and be
    involved in the input combinational logic. We will not be using that for our
    work 

In this diagram, we see two internal combinational components that can alter
the incoming and outgoing signals. Those two blocks in the middle are where the
interesting action takes place. The side labeled :math:`R_{new}` is an arriving
signal that has been transformed by the first combinational block. It reaches
this part of the component and is held in an internal memory cell we call  a
"register". That value is not immediately passed along to the output side of
the component.  Instead, it is held there until a later event occurs.

On the other side of that inner register you see a part labeled :math:`R_{old}`. That
is another register holding the last value placed on the output side of the
register. There is effectively a barrier in the middle preventing the new value
from moving to the old value side. As long as we do not allow a transfer of
data across that barrier, the component will hold onto the current (old) output
value. Any other component reading that output side signal will see the same
old value. 

Hmmm, that sounds like a memory device of some sort. The internal register
holds onto the "state" of the memory cell until told to change it.

..  note::

    This is not exactly how things work, bu tit serves to make it easy to see
    below.

Crossing the Barrier
====================

Changing the output value occurs when a *control* signal arrives at the component
through that bottom control line. When the control signal arrives, the data on
the :math:`R_{new}`" side is copied over onto the :math:`R_{old}` side, and the output of
the device changes. That new value will be held until another control signal
comes along. 

Other Control Signals
---------------------

We might add additional control signals to make things work a bit differently.
For example, we might add an *enable* line that tells the component to respond
to the *control* signal, or ignore it. We might add a signal that effectively
disconnects the wires from the output side so that any attempt to read that
output value is blocked. That means the component cannot write a signal to the
attached wire until we "re-enable" the component later. (Why we might need such
things we will examine later).

Modeling a Sequential Component
===============================

Obviously, we will create a C++ class to model this component. This class must
provide the internal register (both old and new sides), and methods to load a
value from the incoming wire. That value needs to  pass through the
transformational inner components, and land in the :math:`R_{new}` state register.

The output side is similar. We might take that :math:`R_{old}` value and process it,
holding onto it until some one wants to read that value. Perhaps we will add a
second holding register that keeps the processed output value ready for passing
along to other components.

Triggering the action
*********************

Our initial design for the simulator can be viewed as a collection of
components interconnected by wires. Signals will have to start somewhere, and
one way to view this is to provide a constructor for the sequential components
that sets the :math:`R_{old}` side to some known state. (Sounds like a job for our
program loader!)

Once the system's sequential components have been loaded with initial values,
the real action starts. We will make something like a clock run using a simple
loop that simulates a clock "tick". That signal will trigger the movement of
data across that sequential component barrier. Providing a new output value. We
have a bit of chicken and egg situation here. How do we get those new values?

The answer is to begin the machine by passing all component outputs along to
the inputs of every component that gets to see each signal. Those signals move
through the combinational components and keep moving until they reach a barrier
of some kind. Then they stop and become available to cross the barrier when
triggered by the next system "tick". 

The Controller's Job
====================

Some component has to set all the control signals to make all of this happen.
Guess which component that will be?

The *Controler Component* is going to need to set all the control lines passing
to every sequential component in the right configuration so that when the tick
comes along, things will move across the barriers as we want.

Doing this involves figuring out which instruction we need to process
(actually, what step we are processing as well), then setting control signals
to make the right data items move along to the right places. No component
"calls" another component. Instead, each component places signals onto an output
wire, and those signals pass along, through combinational blocks and stall at
sequential barriers. There everything waits for a trigger event to happen to
move signals across the barrier and away we go on another step.

Phew!

Parallel Processing
*******************

In real computers, many signals are moving simultaneously along wires, and
through components. You probably never have written code that works this way.
Doing so involves "parallel Processing", and advanced programming concept.

Instead of actually doing this (which advanced simulators really do), we are
going to break time up into small chunks and simulate the passing of time by
looping over some inner processing code over and over. On each pass through this time
simulation loop, we will ask what should happen during that small chunk of
time. 

To do this properly, we will need to ask every component to check and see if it
has any work to do. Those that do will perform some action, those that do not
will simply remain in their current state. This is really a loop inside a loop.
At every increment in system time (controlled by the outer loop) we allow each
system component (object) to do something, or not, depending on what it is
supposed to do at that moment in time. The inner loop spins over every
component in the system so all of those components can do some work. The inner
loop does not advance the system time, which we track by a counter on the outer
loop. 

..  warning::

    Controlling the timing of all of this gets very messy, so we will approach
    this slowly. Initially, we will only allow a few components to do work on
    each pass through the loop, all the others will wait. By doing this, our machine
    will act more like the emulator code you wrote in earlier labs.


..  note::

    In using this technique to analyze how a computer works, we are simulating
    parallel processing using an old engineering concept, in fact, one I used to
    solve the equations of motion of air over an airplane on a supercomputer. Those
    equations were complex time dependent partial differential equations that told
    us how air would react over time. We broke up those equations using *Finite
    Difference* approximations to all of the "differentials" and ended up with a
    huge set of simple expressions to evaluate at each point in space. We simulated
    the passing of time in an outer loop, then used inner loops to calculate
    what just happened at every point in that huge grid of points in the air
    surrounding the airplane. The equations used were messy and the calculations
    slow. That is why we needed a supercomputer!

On each pass through our time loop, signals move along through some small
part of our system. For instance, We might start by asking all wires to
register their new state by reading the value from the input component attached
to that wire.  Maybe we then trigger all the components attached to a wire to
examine that new input and begin some internal processing.

If the component is combinational, those signals will end up on the output side
where they will find a wire ready to read that value on the next time
increment.

For sequential components, the new input signal passes along through the inner
transformation block and lands it in the "Reg New" container. We wil stop the
action there, and wait for another time loop to handle the transfer across the
inner barrier. Then, we can let the output side process the new value and
register that new value at the output point where a wire awaits.

Boy, this sounds complicated. It is when you are designing something as hairy
as a Pentium processor. For our simple machine it will not be so bad. In fact,
based on your emulator code, you already have a basic idea about how things
need to work. Our job is to make that happen.

My job is to guide you through example code to make all that happen!
 
Wish us both luck!

..  vim:ft=rst spell:
