..  _simplifying-circuits:

Algebraic Circuit Design
########################

..  include::   /references.inc

..  wordcount::

It is easy to see the connection between Boolean Algebra and digital circuits.
What takes some work is seeing how to use math to simplify what might be a very
complex digital system. We will take a peek at that process in this section.

We want our machines to do the job they are intended to do, be affordable, be
cool while doing their job, and consume as little energy as possible. Actual
design of modern systems is a messy compromise involving all of these
constraints. We will not worry about any of the constraints except correctness,
and we will use George's math to do that!

Multiplexors
************

Much of the design of a computer system involves routing signals, traveling
over wires between gates, to the right place at the right time. How do we
control where a signal goes?

A wire is a pathway for electrons to move along. Single wires are simple to
understand, but what if we want to control the destination?

The smallest routing component would have a two input lines and one output
lines. We want to control (select) which input line will pass on to the output
signal line. To do that, we need at least one addition input line. We will call
this a *control line*. 

If we need to select the signal from more than two different input lines, we will
need more control lines. If we use three control lines, we can select among
eight different input lines. Here is a diagram showhing an 8-way
*multiplexor*:

..  circuits::
    :align: center
    :width: 300
    :tikzlibs:  calc

    \draw (0,0)coordinate (O)--++(30:1)coordinate (A)--++(90:4)coordinate (B)--++(150:1)coordinate (C)--cycle;
    \draw ($(A)!0.5!(B)$)--++(0:1)node[right]{$F$};
    \draw ($(O)!0.5!(A)$)--++(-90:1)--++(180:2)node[left]{$b$};
    \draw ($(O)!0.25!(A)$)--++(-90:0.5)--++(180:1.75)node[left]{$a$};
    \draw ($(O)!0.75!(A)$)--++(-90:1.5)--++(180:2.25)node[left]{$c$};
    \foreach \y/\t in {0.1/1,0.2/2,0.3/3,0.4/4,0.5/5,0.6/6,0.7/7,0.8/8} {
    \draw ($(C)! \y*1.1 !(O)$)--++(180:1) node[left] {$X \t$};}



We will use these gadgets a lot in our simple system design work!

Demultiplexors
**************

We might run into the opposite problem as well. Suppose we have several
possible output lines, and we want to route the single input to one of them.
Again we need control lines, but this time they are used to select the right
output. Here is a graphic showing this component: 

..  circuits:: 
    :align: center
    :width: 300
    :tikzlibs:  calc

    \draw (0,0)coordinate (O)--++(150:1)coordinate (A)--++(90:4)coordinate (B)--++(30:1)coordinate (C)--cycle;
    \draw ($(A)!0.5!(B)$)--++(180:1)node[left]{$X$};
    \draw ($(O)!0.5!(A)$)--++(-90:1)--++(0:2)node[right]{$b$};
    \draw ($(O)!0.25!(A)$)--++(-90:0.5)--++(0:1.75)node[right]{$a$};
    \draw ($(O)!0.75!(A)$)--++(-90:1.5)--++(0:2.25)node[right]{$c$};
    \foreach \y/\t in {0.1/1,0.2/2,0.3/3,0.4/4,0.5/5,0.6/6,0.7/7,0.8/8} {
    \draw ($(C)! \y*1.1 !(O)$)--++(0:1) node[right] {$F \t$};}


Designing a Binary Adder
************************

Let's consider how we create a circuit that can add two binary digits. The
circuit we want to design needs two input bits and produces one output bit.
However, to be a general device we need to consider what to do if the result is
more than one bit big (does two come to mind?). In this case, we generate a
zero for the output, and let that extra bit be another output bit that will go
to the next stage in a higher level adder. We call this the *carry-out* bit.

Of course, as soon as we admit *carry-out*, we need to consider including that
in our addition as well. Now, we call this signal *carry-in*. 

So, in summary, we have a component that has three inputs and two outputs. We
need to define how it is to work, and a simple way to do that is to build a
simple truth table:

    +-------------+-------------+----------------+-----------+-----------------+
    | :math:`D_1` | :math:`D_2` | :math:`C_{in}` | :math:`R` | :math:`C_{out}` |
    +=============+=============+================+===========+=================+
    | 0           | 0           | 0              | 0         | 0               |
    +-------------+-------------+----------------+-----------+-----------------+
    | 0           | 0           | 1              | 1         | 0               |
    +-------------+-------------+----------------+-----------+-----------------+
    | 0           | 1           | 0              | 1         | 0               |
    +-------------+-------------+----------------+-----------+-----------------+
    | 0           | 1           | 1              | 0         | 1               |
    +-------------+-------------+----------------+-----------+-----------------+
    | 1           | 0           | 0              | 1         | 0               |
    +-------------+-------------+----------------+-----------+-----------------+
    | 1           | 0           | 1              | 0         | 1               |
    +-------------+-------------+----------------+-----------+-----------------+
    | 1           | 1           | 0              | 0         | 1               |
    +-------------+-------------+----------------+-----------+-----------------+
    | 1           | 1           | 1              | 1         | 1               |
    +-------------+-------------+----------------+-----------+-----------------+

Generating the Expression
=========================

One scheme for generating the *Boolean Expression* for this table is called
*Sum of Products*. 

In this simple scheme, we look at each output column and generate an expression
for that result. We only look at those rows where the output is a "1". For
those rows, we form a "product" representing the entries in that row, then we
"sum" all such products for every row where there is a "1". Phew!

Let's make typing in these rules a bit easier by using simple names like A and
B for the inputs, C for :math:`C_{in}, and O for :math:`C_{out}`. We will also
indicate the compliment of a value using a *tilde* (sim) instead of a bar over
the name.

Our product term will use the column name directly if we see a "1" in the row,
and an inverted name (like :math:`\overline{A}` or simA) if we see a "0". For the above
table, we end up with these two expressions:

..  math::

    R = {\sim}A{\sim}BC + {\sim}AB{\sim}C + A{\sim}B{\sim}C + ABC


Make sure you see how this was formed. It is pretty easy, once you get the hang
of the process!

..  math::

    O = {\sim}ABC + A{\sim}BC + AB{\sim}C + ABC

Since this gives us two separate expressions, the final circuit is actually
two, independent circuits joined together. The signals will flow into each
chunk, through the gates needed to generate the final output. The trick is to
see how this circuit comes together.

Obviously, we could generate the circuit directly from this pair of
expressions, We would have a TON of "AND" and "OR" gates to do this. Can we
simplify this expression before we shop for parts?

More XOR Rules
**************

Let's use this scheme to produce new rules involving the **XOR** operator. Here
is our *truth table* again:

..  csv-table::
    :widths: 10,10,10,10
    :header:  Op, in1, in2, out

    **XOR**, 0, 0, 0
    , 0, 1, 1
    , 1, 0, 1
    , 1, 1, 0

According to our new technique, here is the *Boolean Expression* needed to
implement this table using only **AND** and **OR**:

..  math::

    O = {\sim}AB + A{\sim}B

Or, put another way:

..  math::

    A - B = {\sim}AB + A{\sim}B

Let's generate one more rule: {\sim}(X - Y)

Here is the truth table:

..  csv-table::
    :widths: 10,10,10,10
    :header:  Op, in1, in2, out

    **NXOR**, 0, 0, 1
    , 0, 1, 0
    , 1, 0, 0
    , 1, 1, 1

Which gives this expression:

..  math::

    O = {\sim}X{\sim}Y + XY

Or:

..  math::

    {\sim}(X - Y) = {\sim}X{\sim}Y + XY



Boolean Math
************

Here is a summary of all the rules of *Boolean Algebra* we need to do
simplification:

..  csv-table::

    :math:`{\sim}({\sim}X)`, :math:`\equiv`, X,(1)
    X + 0, :math:`\equiv`,X,(2)
    X + 1, :math:`\equiv`,1,(3)
    X + X, :math:`\equiv`,X,(4)
    :math:`X + {\sim}X`, :math:`\equiv`, 1, (5)
    X - 0, :math:`\equiv`,X,(6)
    X - 1, :math:`\equiv`,:math:`{\sim}X`,(7)
    X - X, :math:`\equiv`,0,(8)
    :math:`X - {\sim}X`, :math:`\equiv`,1,(9)
    X * 0, :math:`\equiv`,0,(10)
    X * 1, :math:`\equiv`,X,(11)
    X * X, :math:`\equiv`,X,(12)
    :math:`X * {\sim}X`, :math:`\equiv`,0,(13)
    X * Y, :math:`\equiv`,Y * Y,(14)
    X + Y, :math:`\equiv`,Y + X,(15)
    X - Y, :math:`\equiv`,Y - X,(16)
    :math:`{\sim}(X - Y)`, :math:`\equiv`, :math:`{\sim}X{\sim}Y + XY`, (17)
    (X * Y) * Z, :math:`\equiv`,X * (Y * Z),(18)
    (X + Y) + Z, :math:`\equiv`,X + (Y + Z),(19)
    (X - Y) - Z, :math:`\equiv`,X - (Y - Z),(20)
    (X + Y) * Z, :math:`\equiv`,(X * Z) + (Y * Z),(21)
    (X * Y) + Z, :math:`\equiv`,(X + Z) * (Y + Z),(22)
    :math:`{\sim}X * {\sim}Y`, :math:`\equiv`,:math:`{\sim}(X + Y)`,(23)
    :math:`{\sim}X + {\sim}Y`, :math:`\equiv`,:math:`{\sim}(X * Y)`,(24)
    X - Y, :math:`\equiv`, :math:`{\sim}XY + X{\sim}Y`,(25)

That is a fairly complete set of rules we can use to manipulate any *Boolean
expression* we run into. Learning how to do this takes practice, the same way
learning normal algebra took practice back when you did that!

Let's work on the result part of the circuit and see what we get:

..  csv-table::

    :math:`R = {\sim}A{\sim}BC + {\sim}AB{\sim}C + A{\sim}B{\sim}C + ABC`

    :math:`R = {\sim}A({\sim}BC + B{\sim}C) + A({\sim}B{\sim}C + BC)`,(19)

    :math:`R = {\sim}A*(B-C) + A{\sim}(B - C)`

    R = A - (B - C)


The final expression for the carry out signal looks like this:

..  csv-table::

    :math:`O = {\sim}ABC + A{\sim}BC + AB{\sim}C + ABC`

    :math:`O = {\sim}ABC + A{\sim}BC + AB{\sim}C + ABC + ABC + ABC` (4)

    :math:`O = ({\sim}A + A)BC + ({\sim}B + B)AC + ({\sim}C+C)AB`

    :math:`O = BC + AC + AB`

Both of these expressions lead to a very simple circuit with far fewer
components than we would have used by just applying the original expressions!



