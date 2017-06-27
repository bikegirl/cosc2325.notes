..  _hw5:

HW5: Working with RTL
#####################

After introducing the RTL scheme for defining the actions we want out system to
perform, let's try to describe a few new instructions.

In your Exam Lab, you were introduced to the idea of an instruction that
compares two data items (**CMP**). This instruction basically performs a subtraction, but
does not record the actual result. Instead, if the subtraction produces a zero,
it sets a "flag" bit in a special register we need to add to out machine:

    * *FLAGS* - a register containing bits with special meaning
        * *ZERO* - the result of the last compare was a zero
        * *SIGN* - records the left-most bit as a sign bit
        * *OVF* - if the result would not fit in the register, this records the "overflow"

For this homework, we will only consider the *ZERO* flag

Conditional Branch
******************

A conditional branch will change the program counter (instruction pointer) only
if the *ZERO* flag is set appropriately. We will create two instructions:

    * **JZ** dest - Jump if zero
    * **JNZ** dest - jump if not sero

With the **CMP** instruction, and an absolute branch **JMP** instruction, we
have seen that we can implement our basic structures using just theses simple
instructions.

Your Task
*********

Create RTL that describes how each of these teo conditional jump instructions
will work as we work through the four step process. (Be sure to note that
nothing happens if that is appropriate for any stage.

For your RTL, use the notation **FLAGS(ZERO)** to indicate that we are looking at
this one bit within the register. You can use this bit as a condition to
control the RTL action.

..  code-block:: text

    t0, FLAGS(ZERO): ...

This implies that at time zero, if *FLAGS(ZERO)* if true, we do the following transfer.

..  vim:ft=rst spell:
