Docker Development Workflow
###########################

..  include::   /references.inc

:Reference: `Development Best Practices <https://success.docker.com/Architecture/Docker_Reference_Architecture%3A_Development_Pipeline_Best_Practices_Using_Docker_EE>`_
        

To demonstrate using Docker_ in a software develpment project, we will set up a
simple "Hello,World" application using C++ and Docker.

The project code will be written on a development system, using conventional
tools like Vin, Git_, but the code will be compiled and run inside a Docker_
container.

Basically, we need to address these four components in setting up our DOcker
container:

    1. A base operating system (Alpine_ Linux)

    2. Development configuration (tools, dependencies)

    3. User files (project source code)

    4. Commands to execute (compile/run)

All of these requirements can be set up using a **Dockerfile**

The Dockerfile
**************

The first requirement is a basic operating system to use. We will use Alpine_
Linux, a small system designed for use in containers.

..  code-block:: text

    FROM alpine:latest

This will set up the container with the latest version of Alpine_ available.
The actual operating system image will be downloaded from the `Docker Hub`_.

Next, we need to install a few tools needed to build our project. The package manager in Alpine_ is called **apk**. Here is what we need to update the system with our needed qdevelopment tools:

..  code-block:: text

    RUN apk update && \
        apk add \
            gcc \
            musl-dev \
            make \

These lines add the required build tools needed to compile the project code. We will be using Make_ to do that actual build work. 

To get the user files into the container, se will copy them in. We colud set up the container so a directory on our workstation is mapped into the container as a *Volume*, but we will not do that here. Instead, we will build the container, install the current code, and destroy it when we are done.

..  code-block:: text

    COPY app/ app/
    WORKDIR app/

We will not run any commands as part of the build for this project. Instead, we will open up a *shell* and do the build manually.

Managing with Make
******************

Here is a project Makefile we can use to demonstrate the development workflow.

..  literalinclude::    cpp_dev/Makefile

With this file in place, (and with our **Dockerfile** in place), we need the sample application and the build **Makefile** to complete this setup:

..  literalinclude cpp_dev/app/hello.cpp
    :caption:   app/hello.cpp
    :linenos:

..  literalinclude::    cpp_dev/app/Makefile
    :caption:   app/Makefile
    :linenos:

Here is the sequence of steps I used to test this application. This process is not fully automated, we will explore doing that later:

..  code-block:: bash

    $ make build
    docker build -t cpp_dev .
    Sending build context to Docker daemon   12.8kB
    Step 1/4 : FROM alpine:latest
     ---> 7328f6f8b418
    Step 2/4 : RUN apk update &&     apk add         g++         make         musl-dev
     ---> Running in 5f4634bdcdec
    fetch http://dl-cdn.alpinelinux.org/alpine/v3.6/main/x86_64/APKINDEX.tar.gz
    fetch http://dl-cdn.alpinelinux.org/alpine/v3.6/community/x86_64/APKINDEX.tar.gz
    v3.6.2-20-g5e4c1165ae [http://dl-cdn.alpinelinux.org/alpine/v3.6/main]
    v3.6.2-23-g2d40d8bc3a [http://dl-cdn.alpinelinux.org/alpine/v3.6/community]
    OK: 8436 distinct packages available
    (1/18) Upgrading musl (1.1.16-r10 -> 1.1.16-r13)
    (2/18) Installing libgcc (6.3.0-r4)
    (3/18) Installing libstdc++ (6.3.0-r4)
    (4/18) Installing binutils-libs (2.28-r2)
    (5/18) Installing binutils (2.28-r2)
    (6/18) Installing gmp (6.1.2-r0)
    (7/18) Installing isl (0.17.1-r0)
    (8/18) Installing libgomp (6.3.0-r4)
    (9/18) Installing libatomic (6.3.0-r4)
    (10/18) Installing pkgconf (1.3.7-r0)
    (11/18) Installing mpfr3 (3.1.5-r0)
    (12/18) Installing mpc1 (1.0.3-r0)
    (13/18) Installing gcc (6.3.0-r4)
    (14/18) Installing musl-dev (1.1.16-r13)
    (15/18) Installing libc-dev (0.7.1-r0)
    (16/18) Installing g++ (6.3.0-r4)
    (17/18) Upgrading musl-utils (1.1.16-r10 -> 1.1.16-r13)
    (18/18) Installing make (4.2.1-r0)
    Executing busybox-1.26.2-r5.trigger
    OK: 159 MiB in 27 packages
     ---> efaf25b38468
    Removing intermediate container 5f4634bdcdec
    Step 3/4 : COPY app/ app/
     ---> 28f0e73a9285
    Removing intermediate container c569748e488c
    Step 4/4 : WORKDIR /app
     ---> 82a78163ccd1
    Removing intermediate container a83f30736f8e
    Successfully built 82a78163ccd1
    Successfully tagged cpp_dev:latest

..  code-block:: bash

     make shell
    docker run -it cpp_dev /bin/ash
    /app # ls
    Makefile   hello.cpp
    /app # make
    g++ -c -o hello.o hello.cpp
    g++ -o app hello.o
    /app # ./app
    Hello from Dockerland!
    /app # exit

If we modify the application code, we will need to rebuild the container using this setup. That is not done automatically, so we need to run "make build" and "make shell" to see the changes.

That is enough to demonstrate using DOcker in a simple development workflow.

