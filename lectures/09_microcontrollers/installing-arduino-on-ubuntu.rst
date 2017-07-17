..  _arduino-ubuntu:

Installing Arduino on Ubuntu
############################

..  include::   /references.inc

The Arduino_ website says that the version of the Arduino_ IDE available from
the Ubuntu Software application is way out of date. For that reason, they
recommend installing the package manually.

Download Files
**************

From the Arduino_ website download this file:

    * :download:`/files/arduino-1.8.3-linux64.tar.xz`

Unpack it using this command:

..  code-block:: bash

    $ cd Downloads
    $ tar xvf arduino-1.8.3-linux64.tar.xz

The files will be left in ``ardino-1.8.3``

Installing
**********

The program comes with an installer script that can be run to set up the system
for the local user. The program files will remain in the folder we just
created, and an application icon will be placed on the Desktop. Rather than
leave this setup in the Downloads folder. I choose to move it to a standard
system directory by doing this:

..  code-block:: bash

    sudo cp -R  arduino-1.8.3 /usr/share/arduino

Next, run the installer script:

..  code-block:: bash

    $ cd arduino-1.8.3
    $ ./install.sh

This will place the application icon on the desktop so you can launch it.

Testing the IDE
***************

With an Arduino attached to the USB port, make sure you can run the example
blink program using the IDE> This will tell you that the required software is
in place. From this point on, we can use the ``Makefile`` system to build our
projects.

USB Access Issues
*****************

..  note::

    I use VirtualBox_ on my Mac for this course. If you are usding VMware_
    Player, you will need to confirm that you can see the Arduino board when it
    is attached to your machine. You might have to modify the VM settings to
    make this happen.

My initial setup using VirtualBox_ did not work. I could see the USB device on
``/dev/ttyACM0``, but permissions were off.

These steps worked:

On the VirtualBox_ control menu, select ``Devices -> USB`` and make sure the
attached Arduino board is selected. This will make VirtualBox_ grab the USB
device and pass it through to the VM.

In the VM settings panel, you need to navigate to ``Ports --> Serial Ports``.

Set the controls as follows:

    * Enable Serial Port
    * Port Number: COM1
    * Port Mode: Host Device
    * Connect to existing pipe/socket
    * Path/Address: /dev/cu.usbmodem1411

..  warning::

    That last setting is correct on my Mac. Your port definition will be
    different, depending on your platform.

Next, start the VM and open up a terminal session.

..  code-block:: bash
    
    $ sudo adduser rblack dialout
    $ sudo apt-get remove modemmanager

(Use your user name in place of "rblack".)

I needed to reboot before this made a difference.

Once all this had been done, I was able to assemble and upload the demo code
from the ``ArduinoAsm`` repository on my Github account.

