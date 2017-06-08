Travis CI Introduction
######################

..  include::   /references.inc

As a serious developer, you write your code using great tools, yo manage your
code with a tool like Git_, and you keep a master copy of your project files on
a server like Github_. You even us a testing framework, like Catch_, so you
know your code is working properly. Life seems great, and everything works.

However!

It Breaks on Linux
******************

Or,it breaks on Windows. Worse, it breaks only specific versions of some OS,
and not the one you use. 

Great, now I have a mess to fix.

Continuous Integration
**********************

Many developers work on their personal machines (even at work, if allowed).
They have complete control over the setup of those machines, and they know the
tools well. The problem with that is that the application needs to work on other
platforms as well. In commercial development environments, this problem might
not come up, all team workers have identical development systems. That is fine,
until you address the question as to where the customer will want to run your
code.

Odds are it will be in an environment different from yours!. You could set up a
machine exactly like the customer wants, and test things there, but that is
complicated and expensive.

With the advances in virtual machine technologies, you do not need to go out
and buy hardware. Instead, all you need to do is spin up a new virtual machine
with the right specs, nd install your code there for testing.

Simple, but you still need to do the setup work.

Wouldn't it nice if all you had to do was create a simple text file detailing
the machine you want, and it would magically appear for you to use. (And, it
would disappear when you are done testing). Oh, yeah! Let's make this service
free, right! Free is always good!


If you have access to such a setup, you can introduce a new aspect to your
development testing. Every time you reach a point where things seem stable, and
tests pass, install you code on the customer's test system and make sure it
works there. This process is not very hard. You push your changes to your server
(Github_), then go over to the customer machine, fire it up, and clone your
code onto that one (or "pull" it if it is already there from previous work).
Then run your tests again.

If everything works keep on developing and repeat this process.

This process is called "continuous Integration" because you are continuously
integrating you code into the final customer environment.

Hello, Travis CI
****************

The idea that we only need the customer virtual machine setup for a short time
struck developers in Germany. They set up a company named TravisCI_ to provide
a service developers can use for free (for open source projects, or for a fee
for commercial projects). The way it works is nice.

You add one file to your project, hosted on Github_ that describes the setup
you need and the commands you want to run when this machine is all set up. You
connect the TravisCI_ server to your Github_ repository, and every time you
push changes to Github_, TravisCI_ is notified of that event. TravisCI then
takes a peek at your setup file to see what you need, creates that virtual
machine for you, then clones your code into it. You get to control what
development tools you need to compile your code, and what tests commands you
want. TravisCI_ will build your project, then run the tests. It will send you
an email with the results. Once all of this has been done, it destroys the
virtual machine (and the code it cloned) and waits for you to push again!

Now, that is just cool! And it is all free (at least for us!)

Even better, if you want to you can define a "matrix" of environments, and
compilers, you want to run. (Let's see the client has three OS versions they
want, and four different compilers on each. That makes 12 virtual machines to
set up! Yikes, good thing they are free!)

Red Badge of Failure
********************

When all of the commands to build and test succeed, TravisCI_ creates a
special image file, called a "badge", that you can link into your README file in
your project repository. When you look at your project on Github_, you will see
that badge on the project page, since Github_ automatically displays the README
it it is written in |RST| (or Markdown, another simple markup language).

The "badge" is red if anything failed during this test run, and green if no
errors were detected. Many developers will not leave their workstations if the
badge is not green. Only then is it safe to stop working! I happen to be like
that, most of the time!)

Demonstrating TravisCI
**********************

For all lab projects in this class, I will activate the automatic testing
feature as soon as I see that you have your personal repository set up. Tests
will then run, and you should get the email results. The required setup file
(**.travis.yml**) is in the example code provided with each lab project). You
will have to edit your project README to put in your personal badge URL. We will
go over that in class.

