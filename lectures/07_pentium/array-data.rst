..  _array-data:

Array data structures
#####################

..  include::   /references.inc

* Arrays are just sequences of exactly the same kind of data
    * They are stored in sequential memory locations
    * The key to accessing them is knowing how big the elements are!

One dimensional arrays
**********************

* These are the most common
* We have already worked with arrays 
    * Set up a pointer to the first element (using a label)
    * Loop over the elements adding element size to the pointer each pass

Two dimensional arrays
**********************

* How do we store these things?
    * We can strip off successive rows (row major)
    * We can strip off successive columns (col major)

* C/C++ uses row major ordering

Example two dimensional storage
================================

In C/C++, we might declare an array like this:

* int ``myData[3][10];``
    * first index is the row number
    * second index is the column number

Data storage
************

The elements are stored sequentially this way:

* ``myData[0][0]``
* ``myData[0][1]``
* ``myData[0][2]``
* ... 
* ``myData[0][9]``
* ``myData[1][0]``
* ``myData[1][1]``

Locating a specific item using the indexes
******************************************

* Use the following formula to figure it out:
    * Access ``data[i][j]``

* displacement = (i * COLUMNS * ELEMENT_SIZE) + (j * ELEMENT_SIZE)
    * COLUMNS is the number of columns (or the width of a single row)
    * ELEMENT_SIZE is how big each item is in bytes.

Example code
============

Lets set up a two dimensional array and display the data: 

..  literalinclude::    code/array.asm
    :linenos:

The code here has to deal with calls to the I/O library that do not preserve registers.

* Here is the output:

..  code-block:: bash

    10, 20, 30, 40,
    50, 60, 70, 80,
    90, 100, 110, 120,

..  note::

    Droyou know how hard it is to put the commas only between values in this output?



