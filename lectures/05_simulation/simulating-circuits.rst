Simulating Circuits
###################

..  include::   /references.inc

A computer system is just a very complex electronic circuit with billions of
parts. It should be simple to create a computer program that works the same way
as this "circuit", right. Yeah, right!

The problem is not the huge number of parts, most of those are grouped into
very simple assemblies, and those assemblies are further grouped into other
components that are pretty simple to model in software. The real problem is
managing a simulation where signals are moving around between components
following a maze if wires we use t connect all of the parts. We have some sense
that all of this wiring is making something happen over some period of time,
and we want to understand all of that well enough to build a model of the
system.

Fortunately, developers have been working on this idea for some time, and there
are a number of ways to deal with the issues. Since we are not really
interested in developing a world-class simulator, but just one suitable for
learning a bit about computer architecture, we will focus on one way to
simulate our system. We will use C++ and a few of its more powerful features to
get this simulator constructed.

Where do we start?
******************

We begin with a very simple view of the parts we want to model. As we have
mentioned before, electronic components fall into one of two basic categories:

    * Combinational - simple boolean algebra transforming machines

    * Sequential - machines that can hold onto a state until signaled to change that state.

We also need wires to move signals around between components. As those signals
travel, we will need a way to "route" them to the proper component. That means,
we need to add these parts to our tool set:

    * Wires - pass a signal between parts

    * Multiplexors = select one of several input sources for a wire

    * Demultiplexer - select one of several output paths for a single wire


If we can find a way to make all of these parts work together, we have a
foundation for building a simulator.

C++ Classes
===========

C++ was designed to help you create code that models a real thing (an object)
from the world your application lives in. Often these objects are real, human
world, things. Other times, they are just a management layer invented to group
other objects. C++ can surely handle building models of all of these basic
parts, and we will be doing that. But, we need to think about how these parts
work together in a real system before we charge off ans build code.

Electronic Circuits
*******************

A "circuit", by definition, runs in a loop. That implies that a signal
(electrons) must travel in a loop, beginning somewhere and arriving back at
that same point. In some circuits, the flow is continuous, as shown in this
Wikipedia image:

..  image:: LEDcircuit.png
    :align: center
    :width: 350

The electron flow is powered by the voltage source (a battery) and moves as
"current" along the wires. As electrons pass through that LED, the diode in that
device emits light. The squiggle object is called a "resistor", needed to keep
too many electrons from frying the LED.

In a computer circuit, we would show the same thing this way:

..  image:: DigitalLED.png
    :align: center
    :width: 350

In this diagram, we see an "input" point on the left, and a "ground" at the
bottom. The implication is that electrons will be arriving at this input point
as a logic "zero" or "one" and then flow through the circuit. (Actually, if the
signal is a "zero" no current will flow.) 

If that input signal was a "one", current will flow, lighting the LED, then
continue on  arriving at the "ground". From the ground point, they will flow
back to the power source completing the circuit.

Thinking about how this simple circuit works, we see that a simulation must
start at some point and follow the electrons as they flow through components.

We could model that in a sequential fashion:

..  code-block:: text

    START
        place signal at input point
        model signal passing along a wire
        model signal passing through the resistor
        model signal passing along a wire
        model signal passing through the LED
        report the signal value at the output point
    END

In this circuit, we might be interested in how much current was "consumed"
(transformed into heat) by the parts encountered on this route. For us digital
folks, we are really only interested in verifying that the LED did light up is
we put a "1" on the input line.

Slightly More Complex Circuits
==============================

Here is a more complex circuit:

..  image:: invFeedback.png
    :align: center

This circuit will not work in a simple, sequential manner. Instead, we need
something like this:

..  code-block:: text

    place a signal on the wire leading into the inverter
    LOOP START
        model the signal passing through the inverter
        place the signal on the wire exiting the inverter, and arriving 
            at the input of the inverter.
    END LOOP

..  note::

    There is a delay in the flow as the electrons pass through both the
    inverter and the wire. Of those two, the delay through the inverter is much
    more significant.

The problem here is that this circuit has no stable state, it "oscillates", and
the signal on the wire changes from a "zero" to a "one", over and over until we
stop the simulation.

We had to start this simulation out somehow. We must assign an initial value to
the inverter input to get things started. How do I choose that starting value.
In this simple circuit, the starting value is actually not important, since it
will still oscillate, but in other circuits, that inital value might be important.

Simulating this circuit must happen over some amount of time. How long is up to
the user. In this simple circuit, two passes through the loop is enough to see
what is going on. But how should we develop the simulator code?

Modeling Time
*************

This oscillating circuit changes over time. So, our simulator code must follow that
circuit over time as well. Although some electronic circuits are continuously
changing over time, our digital circuits are much better behaved. We can
"sample" the circuit at the right moments in time and model what is happening.

For example, suppose it takes an inverter 1ns to respond to a change in input value
(and generate a new output value). We can set up our simulation so changes on
the input happen no more often that, say, every 2ns. That will allow the part time
to reach a stable new value, and we can calculate the output using simple Boolean
Algebra to figure out the new value:

..  code-block:: c

    out = !in;

..  note::

    The actual signal on that output line while that first nanosecond was
    passing might not be anything digital at all.

Our model code for the inverter might be as simple as this:

..  code-block:: c

    bool inverter(bool input) {
        time += 2;
        return !input;
    }

In this code, we are updating a global time variable to indicate that this
device took some time to do the internal processing. 

Now, we can build a simple simulator for this circuit:

..  literalinclude::    code/inv_feedback.cpp
    :linenos:

Here is the output of this simulator:

..  code-block:: text

    t000: 1
    t002: 0
    t004: 1
    t006: 0
    t008: 1
    t010: 0
    t012: 1
    t014: 0
    t016: 1
    t018: 0

Here is an output that is even neater. It looks like an oscilloscope display:

..  code-block:: text

    Inverter Feedback Simulator
    -_-_-_-_-_


I will let you think about how that was generated!

The idealized action of this inverter looks like this:

..  image:: inv_zero_delay.png
    :align: center

Here, we are assuming that the inverter generates the required output with no
delay, That is not actually possible, but it greatly simplifies simulation.

A more realistic picture of what happens looks like this:

..  image:: inv_delay.png
    :align: center

In this diagram, we assume the input changes instantaneously, and the inverter
reacted to that in a realistic manner. Notice that the time to reach the new
output level is different for zero-to-one transitions, than it is for
one-to-zero transitions.  Timing at this level is very complicated, and we will
be ignoring that in this class, but we will not ignore the simple fact that it
takes some small amount of time to reach the new output value. For simplicity,
we will set that delay to some fixed value for the component, and not worry
about the real world values.

I hope you see that timing in our simulation is pretty important.

Circuits with multiple paths
============================

Here is another problem we face in building simulators:

..  circuits::
    :align: center
    :tikzopts: circuit logic US
    :tikzlibs: circuits.logic.US,calc

    \node (a) at (0,0) {A};
    \node (b) at (0, -0.6) {B};
    \node (c) at (4,-0.5) {C};

    \node [not gate] at ($(a) + (1,0)$) (g1) {g1};
    \node [and gate] at (3, -0.5) (g2) {g2};

    \draw (a) -- (g1.input);
    \draw (g1.output) -- ([xshift=0.2cm]g1.output) |- (g2.input 1);
    \draw (b) -- (g2.input 2);

    \draw (g2.output) -- (c);

    
How do we build a model of that?

Let's start off by defining the values at each Rgate input in this circuit. In
a real circuit, every wire has a value as soon as power hits the circuit. The
problem is that we may not know exactly what that value will be. In this
circuit, if we start off with ``A`` and ``B`` set to zero, eventually, the
output ``C`` will be zero as well. What about other possible input values?

Here is a simple table showing what happens if each gate has a delay of one
cycle before the output properly reflects the input. The wire between gates
``g1`` abd ``g2`` are labeled ``w1``.

..  csv-table::
    :widths: 5,5,5,5,5
    :header: T, A, B, w1, C

    t0, 0, 0, 0, 0
    t1, 0, 0, 1, 0
    t2, 0, 0, 1, 0
    
We are now in a stable state. Let's change ``B`` instead:

..  csv-table::
    :widths: 5,5,5,5,5
    :header: T, A, V+B, w1, C

    t0, 0, 1, 0, 0
    t1, 0, 1, 1, 0
    t2, 0, 1, 1, 1
    t3, 0, 1, 1, 1

Again, we are in a stable state.

One more try:

..  csv-table::
    :widths: 5,5,5,5,5
    :header: T, A, V+B, w1, C

    t0, 1, 0, 0, 0
    t1, 1, 0, 0, 0
   
Here, we end up stable right away. No further changes will happen.

The point of al of this is the circuit operates differently depending on the
input values. If we need to know what happens at precise moments in time, we
need to be careful to let the circuit stabilize before we ask what value is on
any particular wire.

So, how do we build a model of this circuit?

Event Driven Simulation
***********************

In a circuit like this, and in more complex circuits, we need to approach the
simulation from a different angle. We still want to set up a loop, but we want
that outer loop to examine the circuit when we know things are stable. We will
need to run an inner loop to let all the components reach their final state.
The problem involves figuring out how many inner loop cycles we need before we
see stability.

When the circuit is stable, there are no changes on any generated input, and
all outputs remain fixed at a value we can figure out using Boolean
Expressions. To see if any signals have changed in this inner loop, we need to
track the old and new values on each input to check for changes. That means we
need to store those old values for the comparisons. 

Here is a short example for this circuit (which really only has one input that
might change, the one on the internal wire):

..  literalinclude:: code/event_loop.cpp
    :linenos:

The output from this code looks like this:

..  code-block:: text

    $ ./test
          |A|B| |W|C| |W|C|
          ----- ----- ----
    t0:   |0|0| |1|0| |1|0|
    t1:   |1|0| |0|0|
    t2:   |0|1| |1|1| |1|1|
    t3:   |1|1| |0|0|
    t4:   |0|0| |1|0| |1|0|
    t5:   |1|0| |0|0|
    t6:   |0|1| |1|1| |1|1|
    t7:   |1|1| |0|0|
    t8:   |0|0| |1|0| |1|0|
    t9:   |1|0| |0|0|

The first two columns are the fixed inputs we are applying to the circuit.
Following those, we see the generated results on the wire (**W**), and the
final output (**C**). If there is more than one result pair, that means we
triggered a new look, since an internal input changed.

The inner "event loop" keeps checking the circuit to see if new results mean
that we need to re-examine those gates that may have already been simulated. In
a real circuit, the timing may mean that the gate was on its way to generating
a result when an input changed. That change then works through the component,
and all previous results are discarded. Unfortunately, in real life, the output
side may show that old result for a brief time, before the new result shows up.
This is called a "hazard" and designers have to worry about these. Fortunately
for us, we will not be dealing with those issues.

This is sufficient background for our purposes. We will be building a simulator
that works basically this way. All components will be examined in a loop to see
if they need to be triggered to generate a result. In some cases, we may
trigger those components again because an input changes as a result of a
previous pass. 

You should note that there was no feedback in this circuit. WHat would happen
if there was?

Actually, the technique will work as shown, but we need to examine all inputs.
In the previous example, we held the initial inputs fixed for the simulation.
The problem with a circuit with feedback is that we may experience
oscillations, something we saw earlier. Detecting that situation is more comple
than we need at this point in our study.

Sequential Circuits
*******************

The examples above only considered combinational components. We need to look at
what happens when we add a sequential component to our curcuit.

Basically, a sequential component acts like a gate. The signals stall at the
barrier between the old and new values available on the interhnal register. ON
the input side of the sequential component, we allow the input to trigger a new
calculation of a possible new register value, but on the output side, that new
value will not be seen until the clock arrives at the sequential component. At
that point, whatever value is on the new value side is passed over to become
the new output value, and the circuit continues processing.
 
..  vim:ft=rst spell: 



 
