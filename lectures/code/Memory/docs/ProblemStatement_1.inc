Deconstruct the Problem Statement
*********************************

1.  Build a C++ class that models a memory module. 

2.  The actual memory is an array of bytes (unsigned 8-bit integers). 

3.  The address we will use in this module is an unsigned integer used directly
    as the index into the memory array. 

4.  The module needs to support a **read** and **write** operation. 

5.  All data and address information needed in these operations must be passed
    through the parameter list for the methods created. 

6.  The *write* operation will involve a data item to store and an address
    where the data item is to be saved.  

7.  We will allow the following types of data to be stored in memory:

    * unsigned 8-bit integers
    
    * unsigned 16-bit integers
    
    * unsigned 32-bit integers
    
    * unsigned 64-bit integers

8. The *read* operation needs an address and an integer indicating how big an
    item to read from that address (see above). 

9.  The **read** operation does not return the data directly. 

10. Instead, a separate method will  be used to return the value. 

11. Call that method **read_valid**. 

12. Its operation is defined next.

13. The memory module has an interesting feature. 

14. It takes time to complete the required operations.  

15. The user will define two constants to model this time: one for *read*
    operations, and one for *write* operations.  

16. These constants will be set when a memory object is created from this
    class. 

17. Both **read** and **write** return no value (void).

18. Following a call to either **read** or ** write** the user must call a
    boolean method named **ready** which indicates that the previous operation
    has finished. 

19. The user will need to call this method repeatedly until it returns
    **true**. 

20. Only then can another memory operation be attempted.
 
21. For the read** operation, the actual data can be retrieved (after **ready**
    returns **true**) by calling a function named **read_valid**. 

22. This method always returns a 64-bit unsigned integer, but the returned data
    will be the size indicated on the previous **read**. 

23. If **read_valid** is called before **ready** returns **true** the value
    returned is always zero (which is not really valid)

