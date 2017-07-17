..  _servo-actuator:

Servo Actuators
###############

..  image:: HiTec-HS-55.png
    :align: center


When you need a mechanical actuator to make something move, a simple servo can
do the job. These devices are very common in toys, radio-controlled models, and
in grown-up form, in huge robotic arms used in manufacturing these dys.
Basically they all work the same way. Some form of signal is sent to the
actuator, and it moves to a specified position somewhere in its range of motion.

The servos we will use in this lab are inexpensive hobby servos purchased in a
hobby shop here in town for about $10. These devices have three wires coming
out of them:

    * +5 - typically a red wire (they will work with power from the Arduino)
    * GND - typically a black wire
    * Signal - typically white wire

..  note::

    As with all projects, check the documentation for exact wiring information.
    You do NOT want to accidentally hook up a device with the power lines
    switched!

A minimal project using this device will include a program that causes the
servo to move through its available range of motion. 

..  vim:filetype=rst spell:
