..  _lab7:

***********************
HW 7 - AVR Hello World
***********************

..  include::   /references.inc

As is the usual case, we need a kind of *Hello, World* project for your first
adventure in programming the AVR microcontroller. 

Your AVR Hello World code
*************************

The basic Arduino_ board is already configured with an LED we can make blink.
Based on the example code presented in the introductory microcontroller lecture
notes, your task is to build a program that blinks the single LED on the
Arduino_ in a pattern. The pattern will be this:

* on for 1/ second
* off for 1 second
* on for 1/2 second
* off for 1/2 second
* repeat this pattern continuously

..  warning::

    The material you need will come from several lectures, not just one. You
    should read through the lecture material to get a feel for what you need.

All times are approximate. You need to calculate the number of times you need
to loop to get close to this specification. We will look at your code running
with an oscilloscope to see how well it really does. 

You need to call a single delay procedure that delays for about 1/2 second -
call it multiple times if you need a longer delay. You are to run a three stage
delay loop like the one shown in class. 

Verify that this code works on the lab systems before you submit the final
project.

Hardware setup
**************

The circuit you need is nothing more than the basic Arduino_ with a USB cable.
Power up the board with the USB cable and you should be good to go!

What to turn in
****************

The usual!

