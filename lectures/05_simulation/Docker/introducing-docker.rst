Introducing Docker
##################

..  include::   /references.inc

:Reference: http://www.ybrikman.com/writing/2015/05/19/docker-osx-dev/

So far this term, you have been working on a Linux virual machine installed on
your host computer. I hope you are beginning to see the value in being able to
set up a totally separate environment on your machine, even one that runs a
completely different opeating system. 

You are training to do software devleopment, and you have a machine you are
using for development available where you can do your work. In spite of the fact
that this school, and many businesses are Microsoft shops, it is a fact of life
that many times the environment where your software will run is not going to be
driven by Microsoft. 

So now what do you do?

With an introduction to virtual machines, the thought should hit you that you
can set up an environment exactly like the production one where the software
needs to run. You could develop in any environment you like, and then test the
code in the target VM production environment before delivering it. That should
work, and many folks do just that.

The only problem with this approach is that the VM puts a heavy load on your
development system, and everything might get slow enough to be annoying. This
becomes more obvious if the production environment needs support from other
components, like databases, and web servers. You might be able to create
multiple VM machines to set this up, but you will reach a limit. More memory
will help, but the bottom line is that VM testing is not ideal.

Enter Containers
**************** 

A VM is a complete software emulation of a real computer. In that emulation,
you load a complete operating system. That OS shares resources from the host,
like the screen, memory, and network adapters. It works pretty well in todays
systems. But if you have multiple VM machines running, you have multiple
operating systems installed as well. Perhaps each one is different. This is
getting out of control!

Suppose we remove the different operating systems from the equation, and assume
you need to set up three almost identical machines for your testing. I will
pick a typical web application as an example. One machine will host a Python
application, one will be a web server running Nginx_, and one will run a MySQL_
database server.  Let's make the single OS some version of Linux.

Suppose we take the VM engine in each one, and factor out the parts that are
identical on each one.We might really only need one copy of these parts if we
can figure out how to make that work. That one copy is sure to handle the
interface with the host operating system.

What is left on each VM are only those parts needed to handle the unique job of
a particular VM. One needs a nice Python environment, one needs only enough
extra support to run Nginx_, and the last, just enough to run MySQL_.

We will call the unique part of the system a "container". That container is
small, light, and is something we could easily install on top of an identical
base on a completely different machine. (We might need to tweak the host
interface if the new host is another system.)

Docker Containers
*****************

Welcome to the Docker_ project. The developers of Docker started a revolution
in how servers are managed. Today, Docker lives on thousands of machines,
world-wide. Not bad for a tool that is only a few years old.

What makes Docker really nice is that it runs on any machine, in one form or
another. Docker is mostly a Linux tool. However the base support engine can run
either natively on a suitable Windows or Mac system, or it can run inside a
normal virtual machine on those platforms as well. Your personal Windows system
probably needs to use the VM approach. So far, only the "professional" version
of Windows 8 or 10 are supported. Most 64-bit Macs, running newer OS-X versions,
will run without needing a VM as well. You can run Docker on a Linux system as well,
but you might be asking why you would want to do that.

Isolation Environments
**********************

A common problem you will face in software development is somethings called
"version hell". You have some tool installed on your system, but another
developer has a different version of that same tool on theirs (or maybe the
target environment needs a different version.) While you could just upgrade your
version, but struggling to keep all necessary machines in sync can get to be a
mess. 

The CS labs are an example of this. We install every tool needed for every
class on each lab machine. Getting that to run properly is a *major* headache! 

Docker lets us create a single environment for everything. We can develop our
code in the same environment we will use  for testing, and even field the final
production version using the same container as well. Even better, we can
install the exact version of everything needed in a container, without worrying
about what is installed on the host.

Docker has a lot more to offer, but I think you can see how useful this can be,
and why it is hugely popular today.

..  note::

    The one big issue is that you cannot run anything but a Linux environment
    in a container, at least now. However, this concept is so popular, you can bet
    that all vendors are working fast to find a way to put their favorite
    application environments into containers.

Oh! Did I mention, you can even use Docker on a $35 Raspberry Pi? (You do need
to use Pi binaries to do that, of course! You cannot plunk a Pentium code
container on top of a Raspberry Pi machine and run it.)

The Docker File System
**********************

Before we look at an example of Docker in action, e need to mention one clever
feature of docker. 

All virtual machine systems set up a simulated hard disk where files can be
stored for the VM. We manage that simulated hard disk using a file system of
some sort. There are several such systems available, and you might be able to
pick one, as is the case when you build up a custom Linux system.

Docker uses something called a "layered" file system". What that means is that
docker stores a set of files in a way that they can be added to the actual file
system as a "layer" merging them into the full file system for use in a single
container as usual. Exactly how this is done is not important, since we use the
file system like any other.  But how Docker manages these layers is important.

A layer can be either read-write or read-only. Almost all layers Docker creates
are read-only. Only a single read-write layer is created for any container.
That single layer is where all system variables will end up. How Docker uses
these layers is what makes them interesting.
 
The Dockerfile 
==============

You create a container by writing a simple text file named **Dockerfile**. This
file identifies the underlying operating system version you want, then details
exactly how you want to set up this container for its intended role. Setting up
the container is called "provisioning" the system.

Each step in the provisioning process will be a single command in the
**Dockerfile**. The changes to the file system that result from any single
command are collected into a single managed layer. The layer is cached on the
host computer system, meaning that if you build the container twice, the layer
is only created once. On the second build, the layer is just pulled from the
cache, and added to the file system.

What this all means is that you can create new containers very fast, as long as
layers are in your local host machine cache. Suddenly building a VM for use in
testing is very easy and fast. Containers come and go as needed. This can be a
powerful development tool, and explains why Docker is getting so much
attention.

The Docker support system includes a public server, called `Docker Cloud`_ ,
where user-defined containers can be saved. This is much like the Github_
service. If you need a particular kind of container, odds are that someone has
already set one up, and you can "clone" that container from the `Docker Cloud`_
server and use it.  No setup required. You can even add your own customizations
to that container for your own purposes.

..  note::

    The International Docker Conference was held in Austin this Spring. It
    attracted several thousand developers, and some of what they are doing with
    Docker is just amazing. Managing a data center with 10,000 VM machines is a
    snap!  

Let's demonstrate Docker at work by building an example web application.

Building a Python Development System
************************************

Let's build an example Python web application to demonstrate the setup we just
described. We will end up with three containers in this example, one for the
application, one for the database server, and one for the web server. Setting
all this us is a breeze, thanks to a powerful Docker support system.

We start off as usual for anu project. Create a project folder, get it under Git_ control:

..  code-block:: bash

    $ mkdir PyApp
    $ get PyApp
    $ git init
    $ touch README.rst

..  note::

    That last command creates an empty file with the given name. (Actually, it
    changes the timestamp on that named file, if it already exists. This is handy
    when forcing make to rebuild a file.

We will set up a very small Linux system here. The project is solely for
developing a Python app, and does not need everything Linux has to offer. So,
we will use the alpine_ Linux distribution, which has been stripped down just
for this kindof situation. Don't worry, you do not need to install anything
manually, it is already available from `Docker CLoud`_:

First, let's make sure Docker is installed:

..  code-block:: bash

    $ docker --version
    Docker version 17.03.1-ce, build c6d412e

Next, we pull a copy of the base operating system into our local cache:

..  code-block:: bash
    
    $ docker pull Alpine
    Using default tag: latest
    latest: Pulling from library/alpine
    2aecc7e1714b: Pull complete 
    Digest: sha256:0b94d1d1b5eb130dd0253374552445b39470653fb1a1ec2d81490948876e462c
    Status: Downloaded newer image for alpine:latest

Docker_ uses "hash tags", which are just strings of he characters, to identify
layers in the cache. This is just like how Git marks a commit. We can attach
more human-friendly names to things, but we do not need that now.

Let's prove that we can get this Linux OS rulling on demand:

..  code-block:: bash

    $ docker run -it --rm alpine /bin/ash
    / # ls
    bin    etc    lib    mnt    root   sbin   sys    usr
    dev    home   media  proc   run    srv    tmp    var
    / # exit

Alpine does not load the normal tools, but you can add them if you like. The
user command shell is not *bash*, the one we use in Ubuntu, instead it is a
minimal version called *ash*. All we are interested in here, it that we are
running in a Linux environment. 

The **--it** connects our host terminal session with the terminal session
inside the VM. When the VM is running, our console is talking to Alpine_. The
**--rm** tells Docker_ to destroy this container, when we are finished with it.
(The cached copy of things is still around, so we can build it again when
needed)

Obviously, we do not wan to manually enter a bunch of cryptic Docker_ commands
to run things. Instead,, we will build a control file to manage all the
actions.

her is our first **Dockerfile**:

..  code-block:: text
    :caption: Dockerfile

    from Alpine

