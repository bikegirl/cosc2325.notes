.. _git-introduction:

Quick Introduction to Git
#########################

..  include::   /references.inc

Almost all professional software developers use some form of :term:`source code
control system` to manage their code and other materials important to a
project. In school, you hardly ever hear about this, and my goal is to change
that.

We will be using Git_ to manage the code you write for my classes. This tool,
written by the creator of Linux, `Linus Torvalds
<http://en.wikipedia.org/wiki/Linus_Torvalds>`_, is arguably the most popular
:term:`SCCS` tool around today. I have asked the lab techs to install it in the
classroom systems, and it should be available by the time we start working on
real lab work. Git_ is available on every platform, so you should be able to
install it on your personal machine with no problem.

Git Reference
*************

The best source of information about Git_ can be found in a book that you can
buy, or view online. I keep a PDF copy of this book in my DropBox_ directory,
so I can view it as needed. Here is the link to the book:

    * `Pro Git <http://git-scm.com/book/en/v2>`_

..  note::

    This book is not for raw beginners, so do not get carried away reading it.
    It is a good reference to Git_ and can help if you get stuck with the
    commands.

Installing Git
**************

Installing Git_ is pretty easy. Here is a link to the section in the Pro Git
book that covers what you need to do. 

    * `Installing Git
      <http://git-scm.com/book/en/v2/Getting-Started-Installing-Git>`_

..  note::

    Windows users should install the `msys` version of Git_ and use the
    `Git Bash` shell as your :term:`command line` tool. This will give you a
    Linux-like environment to work in and provides access to many Linux
    commands, even though you are working on Windows!

After you get Git_ on your system, make sure it works from the :term:`command
line`:

..  code-block:: text

    $ git --version
    git version 1.8.5.2 (Apple Git-48) 

(This is from my MacBook Pro).

Configuring Git
===============

Once you have Git_ installed on your system, there is a bit of basic
configuration you should do right away. The first is to identify yourself so
that all work you do can be tagged as coming from you. You do this setup with
Git_ itself:

..  warning::

    Do not do this step if you work on the ACC COmputer Studies Lab machines,
    only add this setup on your personal development systems.

..  code-block:: text

    git config --global user.name "John Doe"
    git config --global user.email "johndoe@example.com"

For work in my classes at ACC, you should use your ACC email address.

Git_ stores this information in a hidden file named `.gitconfig` located in
your `HOME` directory. Here is how you can check the file contents:

On Windows:

..  code-block:: text

    $ echo %USERPROFILE%
    $ type %USERPROFILE%\.gitconfig

On Linux/Mac:

..  code-block:: text

    $ cat $HOME/.gitconfig

Here is what I see, again on my Mac:

..  code-block:: text

    [user]
         name = Roie Black
         email = rblack@austincc.edu

Ignoring Files in Git
---------------------

Left to its own devices, Git_ will happily add files you really do not want to
be a part of your project. For example, if you add files while working with
Vim_, you end up with a file in your repository named" something.swp". Also, we
never want to include executable files in our repository.

So, how to we make sure this never happens.

The .gitignore file
...................

In your repository, in the same directory with the `.git` directory itself, you
can add a file named `.gitignore` that has file and directory name patterns we
want Git_ to ignore when it looks at your project. These files are very common
in the Git_ world, and some of them are huge, with patterns for things few of
us will ever run into. For our work, here is an example file you can use in
each project you set up, commented so you can see what each pattern is about.
The patterns, themselves, are a common way to refer to a group of names in the
system. 

:.gitignore:

..  code-block:: text

    # vim swap files
    *.swp

    # Common OS files
    .DS_Store

    # Python compiled files
    *.pyc

    # object files
    *.o

    # library files
    *.a

    # executable files
    src/hello

That last line names a specific file to ignore. You can specify the directory
where this file lives as shown in the example. This assumes you build the
executable in the `src` directory.

Adding .gitignore to your project
.................................

The safest way to make sure `.gitignore` is added to your project is to add it
explicitly:

..  code-block:: text

    $ git add .gitignore

This is a good idea for any "hidden" file that begins with a dot.

Basic Terminology
*****************

Git_ is a powerful tool, but we will use it in a simple way. Basically Git
tracks changes to the code you place under its control. By doing this, you can
"back up" to a previous version, if you decide the current version is messed
up. 

..  warning::

   Once you hand control of your files over to Git_ it is vital that you
   remember that, and do not resort to your normal ways of moving things
   around, deleting then, or renaming them. More on this later.

A directory under control of an :term:`SCCS` system is called a
:term:`repository`. Copies of this :term:`repository` can live on multiple
machines. The system we set up, and the work habits you learn, will make sure
that all copies are synchronized so you can work anywhere. This also works as a
backup system for your work, something a lot of us neglect to think about until
something bad happens!

Git_ maintains everything it needs to accomplish its magic in a hiddent
directory named ``.git`` at the top level of your project directory. You should
not touch anything in this directory. You can remove Git_ control by deleting
this directory, should that be necessary for some reason.

The Master Copy
===============

Git_ excels at managing files created by a team of programmers, so there will
be many copies of a project's files around. It is common for folks to keep a
`master copy` of project files on a server somewhere, but this is not really
necessary to use Git_.

In our school work, you will be storing your `master copy` on the GitHub_
server. For classwork, your projects will be managed as part of an
`organization` system set up by GitHub_ to allow instructors to control access
to class projects.  You will need an account on the GitHub_ system to use this
setup.

When using a server to manage your `master copy` it is vital to make sure yu
never leave a work session before you synchronize your work with that server.
If you do that faithfully, you will be able to use multiple machines, at
different locations, to work on your projects. 

The Working Copy
================

Your lab work will live in a directory you set up for this course. Everything
under that directory will be managed by Git_. The local copy is called a
:term:`working copy`, since that is where you do your work. We will use Git_
commands to move any changes you make to local files up to the master server. 

Your Basic Work Flow
********************

The day-to-day work pattern when using Git_ is fairly simple, but it is
important that you learn it and use it!

..  warning::

    It is best if all of these commands are run while you are working at the
    top level of your :term:`working copy`.

Setting Up a Repository
=======================

There are two basic ways you can get a :term:`working copy` of a project set
up. One involves starting from scratch on your local machine, and the other
involves pulling a copy of a :term:`repository` from a remote server.

Starting from Scratch
---------------------

To start from scratch, use this command while working at the root of your
project's directory structure:

..  code-block:: text

    $ git init

Git_ will create a single, hidden directory in the current folder (named
`.git`). You might not see this directory when you list files, but it is there.
On Mac and Linux systems you can see the directory with this command:

..  code-block:: text

    $ ls -al

On a PC, the command is different

..  code-block:: text

    $ dir /ah

..  note::

    If you ever want to remove this directory from Git_ control, simply delete
    this directory, Git_ will know nothing about it. 
    
This local directory is now the only copy around. If we want to set the system
up to synchronize with a remote server, we have a bit of work to do. 

Create the Server Repository
............................

Using GitHub_ Create a project repository, using the project name you have selected. 
See :ref:`github-introduction` for details.

Sync Your Local and Remote Copies
.................................

Once that server :term:`repository` has been set up, note the URL assigned for
that project (it will display after you set it up. Here are the commands I used
to set up a project named `cosc2425labs`:

..  code-block:: text

    $ cd cosc2425labs
    $ git remote add origin https://github.com/rblack42/cosc2425labs.git
    $ git push -u origin master

..  note::

    Where is says "rblack42" above, you will use your GitHub_ account name. Use
    your own project name for that last part. GitHub_ adds `.git` to repository
    names on their system.

    Also note that ``-u`` on the `push` commnd. You only do this one thime, the
    first time you push your code to the server. Afterthat, eave off that
    option.

Once these commands complete, your local :term:`working copy` knows exactly
where the :term:`master copy` is located, and will use that information when
you do the `push` command in a later work session.

..  warning::

    Several students have mistyped that remote command, and that causes a mess.
    There are Git_ commands to fix this, but be careful at this point.

Fetch from a Server
-------------------

If you have already set up a :term:`repository` on GitHub_, or want a local
copy of a project on GitHub_ you can :term:`clone` a copy of that project by
doing this:

..  code-block:: text

    $ git clone <repository URL>

The URL will depend on the server.  I do this a lot, when I want to see the
code for a project hosted on GitHub_.

..  note::

    If you ever get your local :term:`working copy` messed up, you can simply
    delete the entire directory and clone a new copy from the GitHub_ server. If
    you think there are files in your old, messed up copy, then rename the
    directory, clone a new copy, then copy the files you need from the old
    directory system into the new one. Git_ will see these files as either new
    files, or modifications to old files. When you do a "git add .", all your
    work will be updated.


When this command competes, you will have a copy of all files, including the
`.git` directory. Depending on the server setup, you may have rights to modify
the project on the server as well. For projects on GitHub_, this is seldom the
case, unless you ask the project manager to give you those rights.

Normal Work Session
===================

Once you have a local :term:`working copy` of your project files, and a
:term:`master copy` on a server somewhere, the following commands make up your
day-to-day work:

Start Your Session
------------------

Assuming you are using a :term:`master server`, and you might have changes to
your files from a work session done on another machine. The first thing you
need to do is to :term:`pull` a copy of anything changed on the server to your
local machine:

..  code-block:: text

    $ git pull

This command must be run while you are working at the top level of your
:term:`working copy`.

Check the status of your Working Copy
.....................................

At any time, you can check to see what Git_ thinks about the state of your
project. This command will show any modified files, any new files, and notify
you of anything you have deleted.

..  code-block:: text

    $ git status


Do Your Work
------------

You do not need to do anything special to modify files in your project. Git_
will note that they have been modified when you check the local status.

Creating New Files
..................

You can create a new file normally. Start your editor, and do a final
:menuselection:`Save As` to save the file in your project :term:`repository`.
Any new file you create will be unknown to Git until you specifically add it to
the project. (See below)

Deleting Files
..............

While you `could` just delete a file, Git_ remembers that the file was part of
the project, and will recreate it as soon as you try to synchronize with the
server. What we want to do is tell Git_ that we no longer want that file in the
current project. By doing things this way, if we later want to go back to a
time when the file was needed, Git_ will bring it back to the state it had way
back then.

Here is the right way to delete a file or directory

..  code-block:: text

    $ git rm -f <filename>
    $ git rm -rf <directory name>

You will need to :term:`commit` these changes before sending them to the server
(see below).  

Moving Files 
............

The same general comments apply when we move files. We need to tell Git_ about
the changes:

..  code-block:: text

    $ git mv <filename> <new file path>
    $ git mv <directory name> <new directory path>

By the way, renaming a file is an identical process to moving it. Git_ will move
(copy) the file to a new name, then delete the old copy.

Changing Files
..............

You can edit any file in the system as you normally would. There are no special
commands to use here


Tell the Server
---------------

Once we are at a point where it makes sense to :term:`push` your changed code
to the server, you must do a few steps.

Normally, we never put code on the server that does not work. Of course, you
may have to do that from time to time, but in a real project, expect to get
yelled at if your changes break the entire project!

Add your Changes
................

From the top level directory of your project, you can add any new files (and
tell git you are happy with any changes) by doing this:

..  code-block:: text

    $ git add .

(Remember to add that final dot!)

If you checked the status before doing this, a new status command will show
files ready to be sent to the server.

Commit the Changes
..................

Before you do this, you must :term:`commit` the changes to the project. This is
a milestone event, but one you should do often, so you can go back in time if
needed. The command to use here is this:

..  code-block:: text

    $ git commit -m "log message"

Get in the habit of entering a message saying what the work was all about since
your last :term:`commit`.

Push to the Server
..................

The final step is to :term:`push` your changes to the server. This is done like
this:

..  code-block:: text

    $ git push origin master

The `origin` term refers to the remote server set up for this project. Git_
remembers all the details about how to connect to that machine. The `master`
term refers to the main branch in the project. Git_ lets you work on several
`branches`, usually made to develop some variation of the project for a special
need. We will not be creating any branches in this class, so we always use
`master` here.

Check the Server
................

At this point the server should have your new code. If your server has a web
interface, you can use your web browser to look over the code you sent up and
make sure things look right.

GitLab
******

If you are interested in setting up a system similar to GitHub_ for private
use, look into GitLab_. I have an installation of this running in my home
office for private use and testing.


