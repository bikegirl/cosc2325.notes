System Setup
############

..  include::   /references.inc

Hopefully, you own a relatively recent laptop, and use it in your classwork.
You can use the department lab systems, but you will be much more productive if
you keep your laptop handy

..  note::

    In my last adventure in graduate school, I chewed up three la[tops in three
    years at Texas State. I stopped buying that brand of PC, and switched to Macs.
    I still have all of them!

Course Tools
************

We will install a number of important tools on your personal computers for this
class. It is critical that you get this done as soon as possible (especially
for the summer term!) 

Running Linux
*************

We will do most if our course work in the Linux_ operating system. You dpo not
need to rebuild your computer for this! Instead, we will load a special program
called a *Virtual Machine Supervisor* and use that tool to create a second
computer totally living in a software application. Once that machine is running
on your computer, you will be able to install Linux and run that machine just
like it was a real second computer. The only thing you will notice is that it
runs in a window on your PC, and is a bit slower than it would be if you blew
Windows up and reloaded Linux_ directly. 

This is a very important part of life in the world of computers, so pay
attention to this part.

Before we get to that, we need to make sure you have a suitable machine.

Checking Your PC
================

You need a relatively new PC running a 64-bit processor to complete this
course. That machine must support something called "virtualisation", which
simply means it can let a program run that works closely with the processor to
set up a complete computer system in software!

Do not worry if this makes little sense now, we will learn more about this as
the course progresses. For now, you need to make sure your machine can do this.

Windows PC
----------

Most of you use a Windows PC for your work. Download the following program and
run it on your system:

    * :download:`/files/VMware-guest64check-5.5.0-18463.exe`

This simple program will tell you if your machine is up to the job. If it says
it is, we still might have issues getting it set up. There is a setting in your
system BIOS that controls this kind of support. Many manufactures enable this
feature by default, but your system may need to be manually configured.
Unfortunately, how you do this depends on the machine.

..  warning::

    If your computer says you can run 64 bit guests, but you have problems, see
    me ASAP! With a bit of help from Google, we can get into your BIOS control
    panel and turn this feature on.

    If your machine fails this test, you may need to use the CS lab systems, or
    I can give you access to a server I run for this course.

Mac PC
------

The odds are, your Mac will run a 64-bit *virtual machine* just fine. 

Linux PC
--------

You are already running Linux_, so relax!

Virtual Machine Supervisor
**************************

There are several VM managmenet tools available. Some are free, some you need to buy.

Windows PC
==========

The CS lab machines all have **VMware Workstation** installed. This one is excellent, but not free. 

..  note::
   
    As a registered student in a CS class, you can get this for free, but you
    need to let me know you want this.

You can also install the free **VMware Player** application. This one can be
used for free for non-commercial work, otherwise they want you to pay for a
license. 

Here is a link to the file you need:

    * :download:`/files/VMware-player-12.5.6-5528349.exe`

..  warning::

    Attempting to download these files using the ACC wireless setup may fail.
    They do not like downloading executable files.

Another good tool is **Oracle VirtualBox** I use this one on my systems all the
time, but we cannot get it running on CS lab machines.

Here is a link to get this program:

    * `VirtualBox <https://www.virtualbox.org/wiki/Downloads>`_

Mac PC
======

I recommend the VirtualBox_ tool (see above). There is also a commercial
version of VMware called **VMware Fusion** available.

The Linux OS
************

We will be using a release of the Linux_ software called Ubuntu_. The latest
release of this software is **Ubuntu 17.04** and it is freely available
from this link

    * `Ubuntu 17.04 LTS <https://www.ubuntu.com/download/server>`_

The CS lab machines have a GUI version of Ubuntu_ installed. We will not need
that for this term. You are free to use the Desktop edition of the OS if you
like, but all you really need is the Server version (which is much smaller).

..  note::

    When you use the server edition of Ubuntu_ he experience will be identical
    to what you will see when you access servers in the "cloud". I manage dozens of
    systems "out there" this way.

The file you will download is an **ISO** file, which can be used to burn a DVD.
You do not need to do that. Instead, we will use the **ISO** file directly when
we set up the VM.

INstalling the OS
=================

Here are some notes that will help you install Ubuntu_ in your new VM. These
notes cover the GUI edition of Ubuntu_. If you use the Server edition, the
process is nearly the same (except you use your keyboard, not the mouse for
most things). If you are running VirtualBox, the process is also almost the
same.

    * `Installing Ubuntu <UbuntuVM/VMSetup>`_

Installing the Tools
====================

Once you have your Linux_ system running, you need to install a few tools. Here is a link covering that:

    * `Installing Tools <UbuntuVM/InstallingTools>`_

..  vim:ft=rst spell:


