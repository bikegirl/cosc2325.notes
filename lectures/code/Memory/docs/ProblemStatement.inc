The Problem Statement
*********************

Build a C++ class that models a memory module. The actual memory is an array of
bytes (unsigned 8-bit integers). The address we will use in this module is an
unsigned integer used directly as the index into the memory array. The module
needs to support a **read** and **write** operation. All data and address
information needed in these operations must be passed through the parameter
list for the methods created. 

The *write* operation will involve a data item to store and an address where
the data item is to be saved.  We will allow the following types of data to be
stored in memory:

    * unsigned 8-bit integers
    * unsigned 16-bit integers
    * unsigned 32-bit integers
    * unsigned 64-bit integers

The *read* operation needs an address and an integer indicating how big an item
to read from that address (see above). The **read** operation does not return
the data directly. Instead, a separate method will  be used to return the
value. Call that method **read_valid**. Its operation is defined next.

The memory module has an interesting feature. It takes time to complete the
required operations.  The user will define two constants to model this
time: one for *read* operations, and one for *write* operations.  These
constants will be set when a memory object is created from this class. 


Both **read** and **write** return no value (void).

Following a call to either **read** or ** write** the user must call a boolean
method named **ready** which indicates that the previous operation has
finished. The user will need to call this method repeatedly until it returns
**true**. Only then can another memory operation be attempted.
 
For the read** operation, the actual data can be retrieved (after **ready**
returns **true**) by calling a function named **read_valid**. This method
always returns a 64-bit unsigned integer, but the returned data will be the
size indicated on the previous **read**. If **read_valid** is called before
**ready** returns **true** the value returned is always zero (which is not
really valid)


