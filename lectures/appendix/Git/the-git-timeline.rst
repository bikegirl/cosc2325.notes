..  _git-timeline:

The Git Timeline
################

..  include::   /references.inc

Once you start using Git_ you discover that you can use it to work on several
machines in different locations to get your projects done. That is fine, but
you need to remember that you have to do things in a certain way to make things
work properly.

..  note::

    A very good guide to Git_ is the free book `Pro Git
    <https://progit2.s3.amazonaws.com/en/2015-01-30-9351e/progit-en.310.pdf>`_
    that you can download as a PDF file. Get a copy on your development system,
    or better yet, set up a Dropbox_ account and store it there!

Time Stamps
***********

Git_ manages changes to your project by creating something called "blobs" that
contain all changed files you created when you ran the `git commit` command.
Those blobs are actually what gets transmitted to the server when you run `git
push`. Each "blob" has a specific time stamp on it, and Git_ uses that
information to check to see if the machine you are sitting in front of has an
up-to-date copy of all project files.

You are the one who created a specific set of changes on any machine you use.
It is vital that when you walk away from a work session you make sure that the
server has the most current copy of the project. You must run `git push` before
you walk away, unless you are certain that the next work session will be on
that exact same machine.

Essentially, Git_ is creating a timeline of your project, and that timeline may
involve more than one development system. You did the work, and where you
worked is not that important. Remembering all of the changes you made is
important, though!

Master Copy
***********

We call the copy of the project that is stored on the server the "master copy"
for a reason. We need to trust that copy to always be the most up-to-date
version of the project around. The server supports looking at project files
using a web browser for this reason. Any member of the development team can
check the server to see the project files as they are after the last `git push`
from any team member. Furthermore, the entire team can "back up" and revert the
project to an earlier state if needed.

Hopefully, you will not need to do that for my classes, but if you feel you
need to, contact me for instructions. (Remember, we are using Git_ as
beginners, and you do not need to learn all about Git_ for this class!)

What does Git Add Do?
*********************

Git_ tracks everything you do in a special directory in your project directory
named `.git`. When you make changes, then run `git add`, you create a new blob"
that gets saved in something calls the "staging area" within that directory.
You can add more things to the staging area as you like. When you are finally
ready to send all of those changes to the server, you run `git push` to send
the entire set of changes to the server, creating a new time-stamp for the
project.

What does Git Push Do?
**********************

When you have a set of changes to your project in the staging area (using `git
add` commands). You send all of those changes to the server using `git push`.
The `-u` option you use when you set up the project the first time simply tells
the server that it is to track changes to this project. After that first push,
you leave that option off and use this command to push your work:

..  code-block:: text

    $ git push origin master

Setting up Multiple Systems
***************************

You can work on multiple systems if you like. All you need to do is get the
server set up with the project, get the project going on one machine and push
your work to the server successfully. Then on a second machine, do this:

..  code-block:: text

    $ git clone https://skcon.dyndns.org/rblack42/osxsetup.git

This will create a new working copy of your project on the current machine.
Everything needed will be in place to continue working on your project
(including the remote connection to the server!) Just remember to push your
work before moving on.

Multiple Machine Work-flow
==========================

Once you have multiple machines set up, you work like this:

    * `git pull` - to make sure your machine is in sync with the server

    * work as needed

    * `git add .` - add all changes to the project

    * `git commit -m "message"` - set a time-stamp for this set of changes

    * `git push origin master` - send the changes to the server

Notice that we start any session with `git pull` to make sure we are in sync
with the server before we do anything. Forgetting to do this can cause
problems, so be careful!

What can go Wrong?
******************

Everyone makes mistakes. There is not much we can do to stop you from goofing
up from time to time. Really learning how to work with a tool like Git_
involves learning how to get out of trouble. Here are a few of the most common
mistakes students make when they first start using Git_.

Wrong Remotes
=============

The `git remote` command connects a project under Git- management to a remote
server. There must be a home project on that server to connect to, so you need
to have set up an empty project on the server before you run this command. You
do that by logging in to the GitLab_ server for the class and clicking on the
`Create Project` button.

GitLab_ shows you a page with the instructions to follow to create a real
project on your workstation from scratch, or to connect one that already exists
to this new empty project. It is important to make sure that you click on the
menu item marked `HTTP` to see the correct instructions. The default
instructions are for a different form of communication with the server (`SSH`)
which we are not using for our work.

The important step in these instructions is when you type in the `git remote`
command. That step tells your local project exactly where the project will live
on the server. The thing you type in is a web :term:`URL`, specifying the web
page where you need to go to see the project in a web browser. If this gets
typed in wrong, modifying the connection is a bit complicated.

Checking Your Remote Setting
----------------------------

Suppose I used these commands when I set up a project on the GitLab_ server:

..  code-block:: text

    $ git remote add origin http://skcon.dyndns.org/rblack42/osxsetup.git

(This is a project stored in my account on the class server. You should replace
my user name with your own!)

You can see what the current remote setting is by running this command:

..  code-block:: text

    $ git remote -v
    origin	http://skcon.dyndns.org/rblack42/osxsetup.git (fetch)
    origin	http://skcon.dyndns.org/rblack42/osxsetup.git (push)

That "origin" term refers to the server. Make sure the URL is correct. 

Removing in Incorrect Remote
----------------------------

To remove an incorrect setting, do this:

..  code-block:: text

    $ git remote rm origin

You should now be able to enter the correct URL for the remote server project.

Getting out of Sync
===================

If you forget to push your work from one machine, then go to a second machine
and do some work and push some changes, when you return to the first machine
and try to do a push, Git_ will notice that your first machine is not up to
date. You will see a message indicating that you cannot push until you update
your machine with changes you do not have. You need to do this:

..  code-block:: text

    $ git pull origin

This brings down any changes recorded on the server that you do not have.
Hopefully, you have not been working on the changed files, because you might
step on yourself if so! (see below)

Conflicts 
=========

The worse thing you can have happen when using Git_ on your project is to work
on one machine and forget to push your changes to the server, then go to a
second machine and make changes there that mess up the work you did on the
first machine. When you remember to push your changes to the server, you will
end up with a situation where the two sets of modifications crash into each
other. This generates "conflicting" changes, and it is up to you to figure out
how to undo the damage! This can get messy and can be avoided by not letting
yourself get into this situation. If you are the only developer, this is easy1
Just make sure you never leave a work session without making sure your work is
safely on the server. However, if you are part of a team, conflicts can be a
fact of life.

(I will show how to resolve them later. For now, see me if you get into this
fix!)

..  vim:filetype=rst spell:

