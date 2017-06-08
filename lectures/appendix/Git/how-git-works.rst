..  _how-git-works:

How Git Works
#############

..  warning::

    These notes are being edited now. They are incomplete, and will be modified
    as I work on them.

..  include::   /references.inc

:reference: http://www.sbf5.com/~cduan/technical/git/
:reference: http://git-scm.com/book/en/v1/Git-Internals

You do not really need to understand what will be discussed in this lecture to
use Git_, but it will help you better understand what each Git_ command
actually does.  That will better prepare you to use Git_ effectively.

The .Git Directory
******************

When you first start up a new Git_ :term:`repository`, Git_ creates a hidden
directory named `.git`. Let's look at an example:

..  code-block:: text

    $ mkdir example_project
    $ cd example_project
    $ git init
    $ ls -l .git
    total 24
    -rw-r--r--   1 rblack  staff   23 Aug 28 02:23 HEAD
    drwxr-xr-x   2 rblack  staff   68 Aug 28 02:23 branches
    -rw-r--r--   1 rblack  staff  137 Aug 28 02:23 config
    -rw-r--r--   1 rblack  staff   73 Aug 28 02:23 description
    drwxr-xr-x  11 rblack  staff  374 Aug 28 02:23 hooks
    drwxr-xr-x   3 rblack  staff  102 Aug 28 02:23 info
    drwxr-xr-x   4 rblack  staff  136 Aug 28 02:23 objects
    drwxr-xr-x   4 rblack  staff  136 Aug 28 02:23 refs    

Below, we will examine what each of these entries does in making Git_ work:

HEAD
====

The `HEAD` file contains information on where the currently checked out version
of the project is stored. The contents of that file are shown here::

    ref: refs/heads/master

Since there is no code in this project at present, this entry is pointing to
something that does not exist (yet).

branches
========

This directory is apparently no longer used, but it still there(and empty)

config
======

This file holds project-level configuration data

description
===========

The `description` file is where you can add a project description. This file is
used by the GitWeb_ interface included with Git_. This interface fires up a
local web server that can be used to explore the Git_ projects stored in a
common parent directory on your system. I maintain such a directory where I
keep all :term:`repositories` I clone from GitHub. On my MacBook Pro, this
command displays what is in that directory:

..  code-block:: text

    $ git instaweb --httpd=webrick

hooks
=====

Git_ monitors certain events that take place as you issue commands. You can ask
Git_ to run a script for many of these events, and developers use this feature
to enhance Git_ usefulness. A common example is to add a hook so that each
:term:`commit` triggers an automatic run of the project test suite. This can
make sure that changes do not break the project.

info
====

This directory keeps a project-wide exclude list that works even if there is no
`.gitignore` for the project.

objects
=======

This is the most important directory in your :term:`repository`. Git_ stores
the content of each version in special directories within this folder.

There are two basic kinds of objects in Git_:

    * `blobs`: these are compressed files containing version content

    * `trees`: These store directory information such as the file name,
      permission bits, and host directory location information about the
      version.

Both of these objects will be discussed in more detail below.

refs
====

For each :term:`commit` in the project, there will be an entry in the `refs`
directory indicating where that commit is located. We will see this in action
in an example coming up.

How Git handles Versions
************************

Formally, Git_ uses a :term:`content addressable file system` to store
information about each :term:`commit`. This file system is basically just a
directory tree with entries that have very strange names. Git_ creates a 40
character :term:`hash key` of the contents of objects it manages, and stores that
object in a file named using that key.

A Simple Example
================

To study how Git_ manages a real project, let's set up a simple one. Here is
the directory structure I require for student submitted work at |ACC|:

..  code-block:: text

    project_root
        |
        + - README.rst
        |
        + - ACADEMIC_INTEGRITY
        |
        + - src
        |   |
        |   + - hello.c
        |
        + - docs
            |
            + - Documentation.rst

Placing this directory under Git_ control can be done at any time. The project
directory could have been initialized when it was empty, or after this
directory structure was created from a template (this is how I set a project
up). The command for getting the directory under Git_ control is just:

    $ cd project_root
    $ git init
    $ git add .
    $ git commit -m "initial commit"


This creates the `.git` directory in the project root folder. A quick `git
status` command should show that the :term:`repository` is in a stable state.

Suppose we have a file named `hello.c` in our project folder, and we want to
store it in the Git_ internal database of objects (in the objects directory).
Here is the command to do that:

Here is a full directory listing (from my Mac) showing the files and folders
Git_ has created:
    
..  code-block:: text
    
    $ ls -lR .git 
    total 40 
    -rw-r--r--   1 rblack  staff   15 Aug 28 12:26 COMMIT_EDITMSG 
    -rw-r--r--   1 rblack  staff   23 Aug 28 12:26 HEAD
    drwxr-xr-x   2 rblack  staff   68 Aug 28 12:26 branches 
    -rw-r--r--   1 rblack  staff  137 Aug 28 12:26 config 
    -rw-r--r--   1 rblack  staff   73 Aug 28 12:26 description 
    drwxr-xr-x  11 rblack  staff  374 Aug 28 12:26 hooks 
    -rw-r--r--   1 rblack  staff  368 Aug 28 12:26 index 
    drwxr-xr-x   3 rblack  staff  102 Aug 28 12:26 info 
    drwxr-xr-x   4 rblack  staff  136 Aug 28 12:26 logs 
    drwxr-xr-x  12 rblack  staff  408 Aug 28 12:26 objects
    drwxr-xr-x   4 rblack  staff  136 Aug 28 12:26 refs
    
    .git/branches:
    
    .git/hooks: 
    total 80 
    -rwxr-xr-x  1 rblack  staff   452 Aug 28 12:26 applypatch-msg.sample 
    -rwxr-xr-x  1 rblack  staff   896 Aug 28 12:26 commit-msg.sample 
    -rwxr-xr-x  1 rblack  staff   189 Aug 28 12:26 post-update.sample 
    -rwxr-xr-x  1 rblack  staff   398 Aug 28 12:26 pre-applypatch.sample 
    -rwxr-xr-x  1 rblack  staff  1642 Aug 28 12:26 pre-commit.sample -rwxr-xr-x  1 rblack  staff  1352 Aug 28 12:26
    pre-push.sample -rwxr-xr-x  1 rblack  staff  4951 Aug 28 12:26
    pre-rebase.sample -rwxr-xr-x  1 rblack  staff  1239 Aug 28 12:26
    prepare-commit-msg.sample -rwxr-xr-x  1 rblack  staff  3611 Aug 28 12:26
    update.sample
    
    .git/info: total 8 -rw-r--r--  1 rblack  staff  240 Aug 28 12:26 exclude
    
    .git/logs: total 8 -rw-r--r--  1 rblack  staff  165 Aug 28 12:26 HEAD
    drwxr-xr-x  3 rblack  staff  102 Aug 28 12:26 refs
    
    .git/logs/refs: total 0 drwxr-xr-x  3 rblack  staff  102 Aug 28 12:26 heads
    
    .git/logs/refs/heads: total 8 -rw-r--r--  1 rblack  staff  165 Aug 28 12:26
    master
    
    .git/objects: total 0 drwxr-xr-x  3 rblack  staff  102 Aug 28 12:26 11
    drwxr-xr-x  3 rblack  staff  102 Aug 28 12:26 24 drwxr-xr-x  3 rblack
    staff  102 Aug 28 12:26 2c drwxr-xr-x  3 rblack  staff  102 Aug 28 12:26 36
    drwxr-xr-x  3 rblack  staff  102 Aug 28 12:26 4a drwxr-xr-x  3 rblack
    staff  102 Aug 28 12:26 a8 drwxr-xr-x  3 rblack  staff  102 Aug 28 12:26 b3
    drwxr-xr-x  3 rblack  staff  102 Aug 28 12:26 de drwxr-xr-x  2 rblack
    staff   68 Aug 28 12:26 info drwxr-xr-x  2 rblack  staff   68 Aug 28 12:26
    pack
    
    .git/objects/11: total 8 -r--r--r--  1 rblack  staff  113 Aug 28 12:26
    562a1d0204ed26378737a6dde6dfb8b6874af8
    
    .git/objects/24: total 8 -r--r--r--  1 rblack  staff  458 Aug 28 12:26
    192eed84bfb655b9b069786f55bb6def543191
    
    .git/objects/2c: total 8 -r--r--r--  1 rblack  staff  52 Aug 28 12:26
    2d29180a4d7c4b6a94575459f8e4c24c43b6ef
    
    .git/objects/36: total 8 -r--r--r--  1 rblack  staff  128 Aug 28 12:26
    8fd20d37a67e9a0002ea7d140fefa20dde6183
    
    .git/objects/4a: total 8 -r--r--r--  1 rblack  staff  155 Aug 28 12:26
    cdc21043c5d9d1485fa1ce0354cf996a378560
    
    .git/objects/a8: total 8 -r--r--r--  1 rblack  staff  62 Aug 28 12:26
    b801291d5a4c5fb773c72bb2cb596a1259f8c1
    
    .git/objects/b3: total 8 -r--r--r--  1 rblack  staff  97 Aug 28 12:26
    6b5fda34eadf37e1a55c2651b3b90a315fd45d
    
    .git/objects/de: total 8 -r--r--r--  1 rblack  staff  100 Aug 28 12:26
    2aab10f14e55159c059dbed1855da520a7f781
    
    .git/objects/info:
    
    .git/objects/pack:
    
    .git/refs: total 0 drwxr-xr-x  3 rblack  staff  102 Aug 28 12:26 heads
    drwxr-xr-x  2 rblack  staff   68 Aug 28 12:26 tags
    
    .git/refs/heads: total 8 -rw-r--r--  1 rblack  staff  41 Aug 28 12:26
    master
    
    .git/refs/tags:


That is a lot of stuff, and a lot of funny names for things, what is going on?

Naming Git_ Objects
*******************

Git tracks `objects` by calculating a 40 character :term:`hash key` for that
object, then breaking that string up into two parts. Here is an example:

..  code-block:: text

    $ git hash_object src/hello.c
    b36b5fda34eadf37e1a55c2651b3b90a315fd45d

That string of characters is based on a calculation done using every character
in the file. When Git_ saves that file, it breaks that string into two parts:
the first two characters are used to define a subdirectory under
`.git/objects`. The last 38 characters become the file name for that object.
Rather than storing the file in its original form, Git_ compresses the file to
save space (more on that later):

    $ ls .git/objects/b3
    6b5fda34eadf37e1a55c2651b3b90a315fd45d

Git_ created the 40 character :term:`hash` from the contents of that file, and
stored the file within the `objects` directory by breaking the name up into two
parts.  It creates a subdirectory of `objects` with the first two characters as
its name, then saves the actual file inside that directory named with the
remaining 38 characters of the hash value. The actual file is a compressed
version of the original file. We can recover its contents with this command:

..  code-block:: text

    git cat-file -p b36b5fda34eadf37e1a55c2651b3b90a315fd45d
    #include <stdio.h>

    int main(int argc, char ** argv) {
        printf("Hello, World!\n");
    }

..  note::

    Git_ calls this object a `blob`. It has no interest in what the contents
    are, just that hash value of the contents.

If you modify that file, the hash value of it will be different. Git uses this
to see if a file has been modified, rather than depending on file date stamps
as :term:`SCCS` systems have in the past. 
    
You may see a problem here. The object only stores the content of the file, not
the name of that file. Managing that part comes next.

Git Trees
=========

Git_ manages file names by creating a tree structure that parallels the system
directory structure of the project directory. 

A tree object contains information about an entire directory tree within the
:term:`repository`. For example, a typical student project for one of my
classes might look like this:


Git Blob Object Contents
************************

The final contents of a Git_ `blob` are created by doing a few steps:

Create a Header line
====================

Git_ creates a header that looks like this::

    header = "blob {content length}\0}


Git Blobs
=========

..  graphviz::

    digraph blob {
        rankdir=LR;
        node [shape=Mrecord];
        s1[label="{blob[fontsize=16]|Size}|{Content}"];
        s2[label="{tree|Size}|{blob|12342|README}|{blob|43598|LICENSE}"];
        s1 -> s2;
    }

Hope this turns out!


Managing a Git Repository With Python
*************************************

The GitPython_ project provides code for working with Git_ repositories at a
very low level. Refer to the project documentation for information on using the
library to manipulate Your `repo`.

..  vim:filetype=rst spell:
