..  _procedures-resursion:

Subprograms and Recursion
##########################

..  include::   /references.inc

We have introduced the basics of assembly language on the Pentium, but
we need to go over subprograms a bit more.

In introducing the `ABI`, we learned the basic rules for oassing
parameters into subprograms, and we saw the rules that lay out what
regisrers you are to protect in the body of a subprogram. Let's put all
of that together and show how to write a subprogram that uses recursion.
That is sure to make sure you are managing the stack properly.

Factorial
*********

The easiest function we can use to demonstrate recursion is the
`factorial` function. It is defined as follows:

    * f(N) = N * F(N-1)
    *  f(0) = 1

WHile it is possible, and perhaps a better idea, to write this function
using a loop, mathematicians love the recursive definition you see
above. It is short, and hard to mess up. Setting up a loop might
introduce errors, especially given our habit of being "off by one" in
our loops!

Base Case
=========

The key to making this work is to test to see if you have been given the
`base case` before making that recursive call to yourself! You know the
answer if so, so you do not need to call another function for help. Here
is the basic logic in C/C++

..  code-block:: c

    int factorial(int val) {
        if val == 0) return 1;
        return val * factorial(val-1);
    }

General Case
============

The `general case` includes the recursive call, seen above.

Will this work? Do you see why I did not include an `else` clause (is it
needed?). Convince yourself that this will work before moving on the the
assembly language version.

factorial.asm
*************

Translating this to Nasm_ assembly is pretty easy. We already know where
to put the incoming pparameter, and where the result should go. The big
issue is managing the stack insode the function body!

Here is a start on our code:

..  code-block:: text

    ; factorial.asm - recursive factorial function

            segment .text
   n_factorial:
        push    rdi         ; save parameter
        mov     rax, rdi    ; copy into rax for return
        pop     rdi         ; recover rdi
        ret

Well, this obviously will not work! Actually, it will work, it just
returns the wrong answer. I can test this code using this C++ routine

..  literalinclude::    Factorial/src/main.cpp
    :linenos:

Running this code should give the correct (wrong) result:

..  code-block:: text

    $ ./factorial
    Lab 6 - Recursion
    Author: Roie R. Black
    Date  : Oct 31, 2016

    Enter a positive decimal number: 3
    You entered : 3
        The factorial of that number is: 3

Obviously, we need to do a bit more work.

Base Case
=========

The code is ready to handle the base case.

..  code-block:: text

    ; factorial.asm - recursive factorial function

            segment .text
    n_factorial:
        mov     rax, 1      ; prepare for base case
        cmp     rdi, 0      ; base case?
        jz      f_exit      ; jump if so
    ;
    gen_case:
        push    rdi         ; save parameter
        pop     rdi         ; recover rdi
    f_exit:
        ret

Notice that I pulled the stack operations to save the parameter into the
general case area. We do not need to worry about saving that value if we
wake up dealing with the base case!

Now, some of the tests will pass!

General Case
============

For the general case, we have already saved the incomping parameter on
the stack. We need to decrement that paameter and call ourselves
recursively. That part is easy. Once we get back, we can recover the
parameter, and use it to multiply the return value. Since that value is
already in ``RAX``, all we need to do is multiply by ``RDI``. The final
result will end up in ``RAX`` ready to return to the caller:

..  literalinclude::    Factorial/lib/factorial.asm
    :linenos:

The key to writing recursive functions is not to get caught up in that
recursive part. Yoyr focus is only on writing the code for the parameter
you have in hand when you wake up. If you protect registers as required,
and use the stack properly, then setting up the recursive cal is simple,
and it will give you the result you need ot complete the current call.

Bad Recursion
*************

Recursion makes things easy, but that simplicity comes at a price. For
small values of ``N``, this scheme can work well, but what if you asked
for ``f(100000)``? WOuld it work? And, even of it did, what is happening
on the stack while all those routines are waiting for the answer they
need.

Worse yet, think about things this way:

Suppose you need to calculate ``f(5)``. You would be calling ``f(4)``
and so on. If later you asked to calculate ``f(4)``, you already did
that work. Do you need to do it again? In the case of the `factorial`
function, that might not be an issue, but repeating work you have
already done is considered bad form in programming. You might seek
abother way to do things, and this is commonly done in advanced
algorithms.



