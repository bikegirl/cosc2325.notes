Computer Performance
####################

We all seem to want our machines to be fast, and we measure performance by how
fast the clock is for a start. But what really make a machine perform
effectively, and how do we improve things to get better performance out of one?

We will be examining much of the internal structure of a modern computer, but
speed will not be a big part of what we look at in this course. We will examine
a few tricks designers use to make things go faster, but our look at
performance will be somewhat limited.

Let's start off by looking at performance in a simple way.

Clock Speed
***********

The rate at which the processor clock "ticks" is measured in terms of the
number of times the clock switches from a "0" to a "1" and back again. One full
cycle of the clock is one "tick. 

The modern Pentium processor "ticks" at a rate of around 3-4 billion ticks per
second. The term we use for one cycle is a Hertz, named after a famous
physicist involved in the discovery of radio (see :cite:`DictRef6`)

Other processors cannot handle a clock going that fast, so they must go slower.
The Arm processor we will work with runs at about 1 GigaHertz (or GHz) - one
billion ticks per second, and the AVR chip we will also examine runs at 16
MegaHertz (MHz) or 16 million ticks per second.

To get a faster computer, why cannot we just run the clock faster?

The answer has to do with how fast signals move through component in the
machine. We will be looking at these components in some detail soon enough. For
not, just accept the fact that it takes time for a single switch (transistor)
to change from on to off. If we do not let that time pass, the machine starts
to fail, and gives flaky results. 

Tuning the design of a particular processor is something of an art form.
Engineers work very hard to create the fastest machine they can, but they
run into other limiting factors that may contribute to slowing the machine down.

Heat
****

As electrons move around, they generate heat. If we are not careful, that heat
can build up in an area of the chip, and cause things to fail. The Cray-1
supercomputer I worked on in the 1970s had a huge refrigeration unit that
pulled the heat out of the boards in the machine (hundreds of them). That
worked well enough, but Seymour Cray (see :cite::`dictRef7`), who designed the
Cray-1, wanted more speed. So the Cray 2, which powered the supercomputer
center I got to run in the early 1990s, ws cooled by putting the entire machine
in a canister full of an inert coolant! The whole machine ran while bathed in
this coolant!

..  image:: cray2.jpg
    :align: center

Those towers in the background were used in the cooling system, the coolant
circulated between the machine and those towers, just like the cooling system
in your car! 

Over-Clocking
==============

Some serious computer geeks like to push their machines harder than the
manufacturer planned. It turns out that most machines will run faster than the
speed printed on the boxes. These folks push the clock up to higher and higher
speeds to see if the machine still works properly. Some even install fancy
cooling systems to let them push the clock even faster. Chips can fail under
this kind of stress, but sometimes they can get much faster than expected. I am
not a real fan of doing this, since you never know if the machine is still
working at 100%, or about to go "poof" and not run again.

Other Performance Measures
**************************

Speed is not always the most important factor in measuring a machines
performance. Other factors are just as important, sometimes more so.

Power Consumption
=================

The fastest machines around usually are desktop systems (or "big iron" like
mainframes and supercomputers). The reason is simple. They need a lot of power
to go fast, and being powered from the wall is important there.

By machines that must run off of a battery cannot get speed and long running
times at the same time. Usually, they compromise speed to run longer. Modern
laptops do a pretty good job these days. My MacBook Pro can run over eight
hours on a charge, but it is not that fast. It only runs at around 1.6 GHz to
get that kind of battery life. I can push it up to over 3 GHz, but the battery
life goes way down if I do that!

Heat
====

As mentioned before, making machines fast makes them hot as well. I have had
laptop computers I did not ever want in my lap, they just got too hot! Again,
slowing them down makes them run cooler. A big part of the design of a chip
involves making sure the heat generating parts are spread over enough area that
cooling technologies can keep them running cool enough.

That Cray-2 I ran back in 1992 would literally melt if the coolant stopped
circulating. Since that machine cost over  $8,000,000, we sure did not want
that to happen - ever!

Keeping Parts Busy
==================

An interesting part of performance involves keeping all the parts busy. We have
dozens (hundreds) of components in our systems, and we really want all of them
to be working as much as possible, to maximize the processing being done.

The speed we are interested in here is not just a clock tick, it is effective
processing. Terms like "floating point operations per second (FLOPS) are used
her. My Cray-2 was the first machine to top one billion FLOPS, but todays
supercomputing machines can do a million times faster than that!

Parallel Processing
-------------------
  
You were trained to think sequentially. Do this, then do that! The modern
processor can do this and that (and several other things) at the exact same
time. However, letting it do that leads to all kinds of problems if not done
right. We will look at this topic in our studies. 

We are not quite ready to get into this topic in detail, but this overview will
get us started. We need to explore the inner workings of the machine before we
can examine ways designers work to speed them up,. Aspects of performance like
power consumption and heat control will be topics for an advanced course.

