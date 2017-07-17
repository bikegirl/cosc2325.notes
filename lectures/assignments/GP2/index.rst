..  _gp2:

#################
Group Project Two
#################

..  include::   /references.inc

..  toctree::
    :hidden:

    8x8_LED_Display/index
    16x2_LCD/index
    HexKeyPad/index
    IRdecoder/index
    LEDFader/index
    PingSensor/index
    RotaryEncoder/index
    Servos/index
    TempHumidityProbe/index
    Pi3SenseHat/index
    AdafruitCircuit/index
    ProjectReport

Here is the invitation for the second groupproject:

    * `COSC2325-001 GP2 <https://classroom.github.com/g/Hk9YfNRX>`_


The second group project is designed to get you to look closely at a device
that needs to be controlled in a time-sensitive manner. The devices I am
letting you use in this project are simple, and that is on purpose. You are now
focused on exactly how the device is controlled, and what kind of signals you
need to generate or read to interact with that device. 

All projects will use the Arduino systems (well, I added one Pi3 project). For
some of these projects, you may have already played with the device. In this
project, you will not be using any library files you found to control that
device for anything but a reference.  You will write your own code, in assembly
language, to control the device.

Project Report
##############

Each group will prepare a project report on what they accomplished. They will
also demonstrate the project in class. Here are the requirements for the
report:

* :ref:`cosc2325-project-report`

Writing code for the component 
##############################

The programs needed to make these devices do something interesting are all to
be written in assembly language for the AVR processor on the Arduino_ board. We
will use the same development process used in lab projects, meaning that we
will be using the GNU assembler and Makefile system you use in the lab
projects.

The Available Devices
#####################

These are the devices I have available. 

    * :ref:`8x8led`

    * :ref:`16x2-lcd-display`

    * :ref:`membrane-keypad`

    * :ref:`ir-decoder`

    * :ref:`sonar-obstacle-detector`

    * :ref:`led-fader`

    * :ref:`rotary-encoder`

    * :ref:`servo-actuator`

    * :ref:`temp-humidity`

    * :ref:`pi3-sense-hat`

    * :ref:`adafruit-circuit`
