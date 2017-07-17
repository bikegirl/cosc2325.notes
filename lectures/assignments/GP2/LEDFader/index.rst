..  _led-fader:

LED Fader
#########

LED devices are simple on-off lights. Controlling them would seem to be pretty
simple. You hook one side up to an output pin, and the other to ground, and
write a "1" to that pin when you want to e light to be on.

There is a much cooler way to do this.

Pulse Width Modulation
**********************

In the microcontroller world, it is common to have a module that can be used to
do "pulse width modulation (PWM). Basically this scheme sends is series of
pulses to the pin, but it varies the amount of time the pin in on and off. In
any given block of time, If the pin is on more than it is off, it will look
brighter. If it is off more than it is on, it will look dimmer.

In the extreme, it will be full brightness if it is on all the time, and full
dark (off) if it is off all the time. We can smoothly vary the brightness
between those two extremes by controlling that pulse we send to the device.

Tri-Color LED
*************

Just varying the brightness of a single LED is interesting, but it gets more
interesting if we use a tri-color LED. This is basically a red, green, and blue
LED in one package. If we play the PWM trick on all three of these LED lights
at the same time, we can fool our eyes into thinking they are seeing a
different color. 

For this project, I will make a single color LED available, and a tri-color one
as well. Your job will be to write code that demonstrates this scheme for
manipulating the device.

..  vim:filetype=rst spell:
