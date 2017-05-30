Course Topics
#############

An interesting way to visualize the topics we will be studying in this course
is something called a "Mindmap", a tool designed to show how topics are broken
down into subtopics, and further broken down into subsubtopics. THis way of
visualizing things helps show how topics are related.

The learning objectives for this course are given here:

   1.  Explain contemporary computer system organization.

   2.  Describe data representation in digital computers.
    
   3.  Explain the concepts of memory hierarchy, interrupt processing, and input/output mechanisms.

   4.  Measure the performance of a computer system.

   5.  Design and develop assembly language applications.

   6.  Explain the interfaces between software and hardware components.

   7.  Explain the design of instruction set architectures.

   8.  Develop a single - cycle processor.

   9.  Explain the concept of virtual memory and how it is realized in hardware and software.

   10.  Explain the concepts of operating system virtualization


To build the `mindmap`, we need to reduce these topics to a simpler form:

    1. Computer Architecture

    2. Data Encoding

    3a. Memory Heirarchy

    3b. Interrupts

    3c. Input/Output

    4. Performance

    5. Assembly Language

    6. Controlling Hardware

    7. Instruction Sets

    8. System Design

    9. Virtual Memory

    10. OS Virtualization

Here is the topic map we will follow:

..  circuits::
    :align: center
    :width: 600
    :tikzlibs: mindmap

    [root concept/.append style={concept color=blue!20, minimum size=2cm},
        level 1 concept/.append style={level distance=7cm, sibling angle=40},
        mindmap]
    \node [concept] {Computer\\Architecture \&\\Machine Language}
        [clockwise from=90]
        child [concept color=red!50] {node [concept] {Number\\Systems} 
            [clockwise from=170]
            child {node [concept] {Decimal} }
            child {node [concept] {Binary} }
            child {node [concept] {Hexadecimal} }
        }
        child [concept color=blue!50] {node [concept] {Data\\Encoding} 
            [clockwise from=100]
            child {node [concept] {Integers} }
            child {node [concept] {Floats} }
            child {node [concept] {Text} }
        }
        child [concept color=green!50] {node [concept] {Architecture\\Basics} 
            [clockwise from=40]
            child {node [concept] {Von Neumann} }
            child {node [concept] {Clocks} }
            child {node [concept] {Four Step\\Cycle} }
        }
        child [concept color=red!50] {node [concept] {System\\Design} 
            [clockwise from=10]
            child {node [concept] {Basic\\Components} }
            child {node [concept] {RTL} }
            child {node [concept] {HDL} }
            child {node [concept] {ISA} }
        }
        child [concept color=blue!50] {node [concept] {Asssembly\\Language} 
            [clockwise from=-40]
            child {node [concept] {Pentium} }
            child {node [concept] {Data} }
            child {node [concept] {Code} }
            child {node [concept] {Procedures} }
        }
        child [concept] {node [concept] {Memory\\Heirarchy} 
            [clockwise from=-75]
            child {node [concept] {Technologies} }
            child {node [concept] {Caches} }
            child {node [concept] {Vistual\\Memory} }
        }
        child [concept color=orange!50] {node [concept] {Measuring\\Performance} 
            [clockwise from=-125]
            child {node [concept] {Simulation} }
            child {node [concept] {Code Analysis} }
        }
        child [concept color=blue!50] {node [concept] {Hardware\\Control} 
            [clockwise from=-135]
            child {node [concept] {Interrupts} }
            child {node [concept] {Memory Mapping} }
            child {node [concept] {I/O Ports} }
        }
        child [concept color=yellow] {node [concept] {OS Virtualization} 
            [clockwise from=160]
            child {node [concept] {Desktop} }
            child {node [concept] {Docker} }
        };
    
