Deconstruct the Problem Statement
*********************************

1.  memory is an array of bytes (unsigned 8-bit integers). The index is the address.

2.  Provide these methods:

    * **void read(int address, int size)**
    * **void write(int address, int data)** 
    * **int read_valid(void)**.
    * **bool ready(void)** 

3.  We will allow the following types of data to be stored in memory:

    * unsigned 8, 16, 32, or 64-bit integers
    
4.  The constructor needs at least twoparameters: **read-time** AND **write_time**.
   
5.  Following a call to either **read** or ** write** the user must call a
    **ready** which indicates that the previous operation has finished. 

6.  The user will need to call this method repeatedly until it returns
    **true**. 

7.  Only then can another memory operation be attempted.
 
8.  For the read** operation, the actual data can be retrieved (after **ready**
    returns **true**) by calling a function named **read_valid**. 

9.  **read_valid** always returns a 64-bit unsigned integer, but the returned data
    will be the size indicated on the previous **read**. 

10. If **read_valid** is called before **ready** returns **true** the value
    returned is always zero (which is not really valid)

