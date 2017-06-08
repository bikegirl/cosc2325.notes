..  _glossary:

Glossary
########

..  include::   /references.inc

..  glossary::
    :sorted:

    Combinational
        A circuitis combinational if it produces a new output any time theinput
        changes. There is a delay as the signals wotk their way through the circuit.

    Sequential
        A circuit is sequential if itheoutputs depend on a clock signal, and a
        previous state stored in the circuit. The state is usually stored in some kind
        of register.

    Propogation Delay
        The time it takws for outputs to reach a stable value when inputs
        change. 

    Domain Name
        Servers on the Internet are all part of some registered domain, which
        has a name associated with it. I own `pylit.org` for example. The last
        part is used to brand the kind of domain I am part of, in this case a
        non-profit organization. The first part is often chosen to identify the
        company involved. You can add a machine name to the front of this
        name. Often `www` is tacked on to identify a web server where the
        companies website is found.

    DNS
    Domain Name Service
        A phone book like service that maps domain names, like ``www.pylit.org``,
        to an IP address.

    DDNS
    DynDNS
    Dynamic DNS
        A service that updates :term:`DNS` tables used by Internet services to
        map domain names to addresses. These services are helpful if your
        network address changes often, as it might if you are working from home
        and want to set up a server.

    URL
    Uniform Resource Locator
        The specific location of a web "resource", which is normally a web
        page, but can be a file or anything that your browser can download to
        your system using the web protocol named `HTTP`. 

    CAS
    Content Addressable File System
        A scheme used by Git_ to store documents based on a hash code generated
        from a file's contents. The hash code is used to form a directory name
        where the file is stored.

    VM
    virtual machine
    virtual machines
        A program that emulates a real machine accurately enough to run real
        programs for that machine. 

    Code of Conduct
        Every profession has a defined set of rules they expect members of that
        profession to follow. Most of the time, these rules are common sense,
        but they are defined to make sure every member understands what the
        profession seeks to present itself to the public. You are expected to
        know these rules and follow them when you join the profession. Look
        into each profession's primary organization for guidance. For computer
        folks, this is probably the `Association for Computing Machinery
        <http://www.acm.org>`_.


    SCCS
    Source Code Control System
    Source Code Control Systems
        Distributed Source Code Control Systems
        A tool used to track changes to all files involved in a development
        project. Most such tools use a central server. The distributed tools
        can function with no server as long as team members can communicate
        directly over the Internet. Typical tools are Subversion_ and Git_

    Refactor
        Modify a programs code to improve its quality without changing how it
        works. This is a clean-up step in development designed to keep ugly
        code out of a project, and use best-practices in how code is presented.

    Comment
    Comments
        Short chunks of text added to program code that seeks to explain when
        is going on. Far too often, this text just repeats what the code
        actually says, making them useless. Comments should explain the "why" of
        a block of code.

    Shell
    Command Prompt
        The "old fashioned" way of controlling a computer. On Windows systems,
        this involves opening a window where you can type in commands. On Mac
        and Linux systems, you open up a :program:`Terminal` program.

    Repo
    Repository
    Repositories
        A file system that serves as a database for a source-code
        control system like Subversion_ or Git_.

    Working Copy
    Working Copies
        When using an :term:`SCCS` system, the copy maintained on a remote
        server is usually treated as a master copy. Any local copies are called
        :term:`working copies`. When you leave any work session, you should try
        to make sure the remote and working copies are identical. This will
        prevent problems later!  

    Directory
    Directory Tree
        The :term:`operating system` on most computers, today, uses tree-like
        structure to store files.  The top of this tree, called the root of the
        tree, is a directory (or folder as Microsoft want us to call it). The
        name of this directory is either "/" on a Linux/Mac system, or "\" on a
        Windows system.

        A Directory is a container that can hold either files (objects that
        contain only data, such as text, images, of other binary data) or other
        directory objects (called subdirectories). Subdirectories have names
        that follow the rules for the :term:`operating system`.  Any directory
        or subdirectory can hold files of further subdirectories, giving the
        entire file system a (upside down) tree-like structure.

    Master Copy
    Master Server
        Development teams usually set up a server for use by the team. A copy
        of the project files is kept on this server and all team members make
        sure to synchronize their work with this server. We :term:`push` your
        changes to the server, and :term:`pull` changes down from the server,
        so we can see work done by other members of the team.  Command Line A
        simple text line on your screen where you can type in a :term:`command`
        to the operating system.

    Push
    Pull
        When working with an :term:`SCCS` :term:`master server`, we
        :term:`push` your changes to the server, and :term:`pull` changes down
        from the server, so we can see work done by other members of the team.  
    
    Parameter
    Parameters
        Values passed to a sub-program for it to use in it's work.

    Commit 
    Commits
        :term:`push` to a remote server.

    Clone
        Create a copy of files living on a remote server for your local use.
        This creates a :term:`working copy` of the project. You may (or may
        not) have rights to make changes and :term:`push` them back up. It is
        common to :term:`clone` project hosted on services like GitHub so you
        can use the code or study it. You can update your local copy at any
        time to keep up with changes in the project.

    Command Line 
        A simple text line on your screen where you can type in a
        :term:`command` to the operating system.
 
    Command 
        A series of space-separated text items handed to the operating system.
        The first of these items is the name of some program (which may be
        internal to the operating system) you want to run. The rest of the
        items are called :term:`parameters` which are processed by the program
        and control exactly what that program does. 

    Cookie
        A small file containing information needed to reconnect you to a web
        server automatically. Cookies often store log in credentials. It is
        vital that you never allow your personal cookies to be saved on a
        public machine. Doing so gives others complete access to your accounts.
        Parameter Parameters A block of text (no spaces allowed, unless the
        block is enclosed in quotes) that is passed to a program or a
        sub-program. If passed to a program and there are more than one
        parameter needed, they are usually separated by spaces. If passed to a
        sub-program, they are usually separated by commas.
    
    Diff
    Difference
        A tool can read two files and show the differences between them. It can
        also create a `patch` file that can be used to convert one of them into
        the other.

    Open-Source
        An open-source project is freely made available to the public in source
        code form. Such projects are usually protected by a license of some
        kind, designed to protect the rights of the author(s).

    OPC
    Other People's Code
        You should study code written by other folks, especially those who seem
        to do the job well. Eventually, you will learn how to write well
        respected code and become the author of what others read. Just make
        sure you give credit for anything you decide to incorporate into your
        projects, and respect the license that goes with the code.

    Problem Statement
        Every programming project should start with a problem statement that
        you analyze to see exactly what you are supposed to create. Your job is
        to create a solution to some problem. You may need to go to the
        originator of the statement to clarify things, and you should do this
        rather than guess at what is really wanted. 

    OOP
    Object Oriented Programming
        A design technique where the fundamental program components model
        objects from the real world the application is to serve.

    Mock Object
    Mock Objects
        A program component that implements the interface to a complex
        subsystem sufficiently well to enable testing of code that uses the
        real subsystem. 

    Change Script
    Change Scripts
        This is a chunk of code that can be used by an appropriate tool to
        convert one product into another one. These scripts are the heart of
        :term:`source code control systems`. The Unix tool :program:`diff` is
        used to create such scripts. 

    Old School
        The place where old methods were learned. These methods are any methods
        not accepted as modern by current workers.

    Revision
    Revisions
        Another term for `version`. A :term:`revision` captures the state of a
        collection of assets (files) at a particular moment in time.
        :term:Source Code Control Systems` track the changes from one
        :term:`revision` to another by creating :term:`change scripts` that can
        convert the older version to the newer one.

    TDD
    Test Driven Development
        A software development process where any change to the code is
        preceded by the creation of a test that will demonstrate the operation
        of the code after the change is made. The development process becomes
        one of generating code that passes the test.

    Test Driven Design
        A fictitious design technique where we practice :term:`TDD` with no
        design in mind. This might be a bottom-up technique where interesting
        subassemblies get produced that might be useful in a larger project.
        Basically, this seems like a bad idea.

    Unit
    Unit Test
    Unit Tests
        A unit is a basic component of a program. Typically this is one
        function or a class. We test these units to verify that they work as we
        intend.

    Side Effects
        Functions usually operate as self contained blocks of code. They get
        information from the outside world through the parameter list, and
        produce results that are returned to the caller as return values. If
        the function modifies anything in the outside world as it performs its
        task, these are called side effects. Generally, these are bad things,
        and should be avoided.

    Acceptance Tests
    System Tests
    User Tests
        Testing of the complete application to confirm that it meets the
        project specification

    Integration Tests
        Tests of a set of units to confirm that they work together properly.

    Regression Test
    Regression Tests
        Testing to make sure a project is moving forward, not backward. 

    Refactoring
        Rewriting your code to make it simpler, and easier to understand
        without changing how it works. Your :term:`regression tests` will tell
        you if you are doing this right!

    Baby Step
    Baby Steps
        A software development process that focuses on making very small
        changes to your code, followed by a quick test using the compiler to
        make sure you can run your code, and a run that generates output you
        can inspect to see how your changes are working. The key to this is
        doing this sequence often.

    Commit
    Commits
        The process of generating a marker that records the state of a project
        at that moment in time. :term:`SCCS` systems generate a :term:`change
        script` that can be used to restore your project to the exact form is
        has at this moment, even as the project continues on in its
        development.

    Content Addressable File System
        A system that stores objects with names based on the contents of those
        objects. Used by Git_ internally to store version information.

    Blasting Code
    Blast Code
        An :term:`old school` method of software development. This method
        involves long sessions of writing code with few attempts to test the
        code. The result is often long sessions fixing typing mistakes,
        followed by long sessions with a debugger trying to figure out why
        things do not work.

    Debugger
        A software development tool that is used to step a program one line at
        a time, then allows the developer to inspect the internal state of the
        machine as the program runs. They are a vital, and often under-used
        tool in programming.

    Tag
    Tags
        A special marker used to identify particular :term:`revisions` in a
        software development process.

    State
    States
        The exact configuration of a collection of items that make up some
        system. That set of items can grow or shrink over time, and individual
        items may be changed. At any moment in time, the entire collection is
        in some configuration. 

        The operation of many systems can be described exactly by a sequence of
        specific changes from one state to the next. Such a system is called a
        :term:`Finite State Machine`.

    Finite State Machine
        A system whose operation is defined as a set of :term:`states` and
        transitions from one :term:`state` to the next. 

    Branch
    Branches
        A fork in the development road where a new feature is developed
        separate from the main line of development. Eventually this new line of
        development will be :term:`merged` back into the main line.

    Master Branch
        The primary development branch in a project managed with a :term:`SCCS`.

    Merge
    Merged
        Combining two distinct development procedures into one. This may result
        in :term:`conflicts` that must be resolved.

    Conflict
    Conflicts
        A situation where two different versions of a single project asset
        exist. The differences must be resolved before the asset can continue
        to exist in the combined project.

    Literate Programming
        I form of documentation where program fragments are included in a
        literate document designed to explain how a program is developed. Those
        fragments are extracted from the documentation and combined into a
        normal form that can be processed by programming tools. This is the
        exact opposite of traditional documentation where the code is littered
        with :term:`comments` that try to accomplish the same thing. These
        :term:`comments` are often neglected and become meaningless. 

        The creator of this concept is Donald Knuth. If you claim to be a
        software developer, you owe it to yourself to read his work.

    VirtualHost
        A configuration used by Apache_ to manage web servers controlling
        multiple websites

    VPS
    Virtual Private Server
        A :term:`virtual machine` set up on a remote server in such a way that
        a user can use the :term:`VM` as a private serer. This arrangement is
        commonly used by companies to make more effective use of physical
        servers. Multiple :term:`VPS` systems can run on one physical machine.
        Companies like Rackspace_ and Amazon_ offer access to such systems.

    VM
    Virtual Machine
        A program running on a host computer that emulates a real machine well
        enough that operating systems and applications can run inside them.
        This effectively isolates the environment inside the :term:`VM` from
        the host computer.

    WSGI
    Web Server Gateway Interface
        A standard protocol used to host Python applications on web servers 

    Context Menu
        On most systems, when you :kbd:`right-click` on something, you bring up
        a menu that is sensitive to the context of the thing you are pointing
        to. That menu lets you perform tasks common to that thing!

    Syntax
        The formal rules that define how to write a construct in a particular
        programming language. These rules are simple and precise.

    Semantics
        A properly written programming language construct causes the computer
        to do something. Exactly what that something is is called the semantics
        of that construct. You must understand the semantics in order to make
        sure you use that construct properly. This is called picking the right
        tool for the job!

    Compile
    Compiler
    Compilers
        When we process a program written in a high-level programming language,
        the tool we use is called a :term:`compiler`. That tool converts our
        program into the :term:`machine language` the processor actually
        understands.. We say we :term:`compile` our programs.

    Assemble
    Assembler
    Assemblers
        When we process a program written in :term:`Assembly Language`, we use
        a tool called an :term:`assembler` to convert the program into
        :term:`machine language` the processor actually understands. We
        :term:`compile` our programs.

    Machine Language
    Machine Code
        The :term:`low-level` binary language a particular processor
        understands.  :term:`Machine Language` is a set of very simple
        instructions that the processor can :term:`execute`. These languages
        are designed by the processor manufacturer, and are unique to that
        processor (or processor family). Usually that manufacturer designs an
        Assembly Language to go along with their :term:`machine language`, but
        you are not required to use that language. As long as your
        :term:`assembler` generates correct :term:`machine language`, your code
        can run on that processor.

    Assembly Language
        A human readable form of :term:`machine language`. An :term:`assembler`
        converts code written in this language into :term:`machine language`.
        These languages are processor specific.

    High-Level Language 
        Most programming languages are designed to help humans instruct a
        machine in how to solve some problem. These languages do not care what
        processor they will run on, and are called `machine independent`.  You
        use a :term:`compiler` designed to convert your high-level code into
        :term:`machine language` for a particular processor. Different
        :term:`compilers` support different machines.

    Drag and Drop
        A modern method of constructing programs, or executing commands by
        dragging an icon on the screen and dropping it onto another place.
        Learning how all of this works can make you highly productive!

    Execute
    Executes
    Executable
    Executable File
        In spite of the negative connotations of the term, we say a computer
        :term:`executes` a program. The program that can be run is called
        :term:`executable`.

    Link
    Linking
    Linker
        A phase in transforming your program into a final :term:`executable`
        file where one or more :term:`object files` are combined with system
        libraries` to build a final :term:`executable` file. The tool that does
        this work is called a :term:`linker`.
        

    Object file
    Object files
        A file containing :term:`machine code` for a particular machine, but
        missing some references needed to build an :term:`executable file`.
        Several :term:`object files` are combined, resolving the missing
        references to build a program. Usually, some of those unresolved
        references are resolved by searching a :term:`system library` that
        accompanies the transformation tool (:term:`compiler`) or the
        :term:`operating system`. Only when there are no :term:`unresolved
        references` can your program actually :term:`execute`.

    High-Level
    High-Level Language
    High-Level Languages
        A language designed to be compiled into a :term:`low-level` form like
        :term:`machine language` is called a :term:`high-level language`. Such
        languages are designed to be :term:`machine independent`. C++ is a
        :term:`high-level language`.

    Low-Level
    Low-Level Language
    Low-Level Languages
        A language that is very primitive, often tied to a specific processor.
        :term:`Assembly language` and :term:`Machine language` are
        :term:`low-level languages`.

    Unresolved Reference
    Unresolved References
        When you try to link your program and there are references to items
        that cannot be found, we say these are :term:`unresolved references`.
        The final :term:`executable file` cannot be constructed in this case.
        System Library System Libraries Files containing code needed by a
        program to actually complete the transformation of a :term:`high-level`
        language into :term:`machine language`. In these libraries, we find
        code for input and output, code needed to interface with the
        :term:`operating system`, etc.

    SSD
    Solid State Drive
        Most hard disks use a rotating metal disk coated with a magnetic
        material that records the zeros and ones. A modern (and a bit
        expensive) alternative is to use electronic circuits similar to flash
        memory, but much faster, to store the bits. Since these drives are much
        faster than traditional hard disk drives, some systems use them to
        store the operating system, so the machine boots fast. If you have
        enough money, an :term:`SSD` might be the only drive you have.

    DotFiles
        Many programs keep settings in a hidden file in the user's :term:`home
        directory`. Exactly what these file hold depends on the program. It is
        common to manage these files in some way. I keep mine on my GitHub_
        account at https://github.com/rblack42/dotfiles.

    OS
    Operating System
        All general purpose machines need a piece of software to manage the
        hardware of the system. Typically, these programs provide a user
        interface to make controlling the machine simple. No on buys a system
        just for the :term:`OS`. Instead, you pick an :term:`OS` based on the
        applications you need to use to do real work (or play) on that system.

    Flow Chart
        A form of diagram showing the logic of a program. These diagrams have
        been around for almost as long as computers have been available. They
        are a great way (but not the only way) to visualize how your program
        will "flow" and think about what will happen when you run the program.

    Syntax
        This is a term referring to exactly what a statement in a programming
        language looks like when written in a program.

    Context Free
        A programming language must be defined in such a way that figuring out
        what should come next (:term:`tokens`) can be figured out without
        studying the context in which the :term:`token` appears.

    Syntax Analysis
    Syntax Analyzer
        The process of examining each construct in your program to make sure it
        is properly formed. Only when this is true can the analysis tool move
        on the :term:`semantic analysis` to figure out what each construct
        means. The tool that checks the syntax is called a :term:`syntax
        analyzer`, usually part of a :term:`compiler`.

    System Library
        A file containing references needed by programs to connect to operating
        system of language specific functions.

    Syntax Diagram 
    Railroad Diagram 
        A visual representation of a rule in :term:`EBNF`. These rules define
        the :term:`syntax` of a language.

    Semantics
        This term refers to the meaning of a construct in a programming
        language. Only a construct that passes the :term:`syntax analysis`
        phase of transformation has any meaning.

    Semantic Analysis
        The process of taking a properly formed construct in a programming
        language and converting it into another form the has the same meaning
        as the original construct. Typically, a tool like a :term:`compiler`
        transforms your high-level code into :term:`machine language` the
        processor can actually run.

    EBNF
    Extended Backus-Naur Form
        A notation used to define the :term:`syntax` of a programming language.
        The notation is designed to be :term:`context free` meaning there are no
        places where figuring out what comes next in a program depends on the
        context of the program. Usually, the rules can tell what is coming next
        by simple looking at the next :term:`token` in the program

    Token
    Tokens
        In :term:`syntax analysis`, your program is broken up into a number of
        :term:`tokens`, a term describing one item that is "indestructible" in
        the language. For example the keyword "if" is a single token, so is an
        integer number, or a curly bracket, or the ">>" symbol used in C++.

    Machine Dependent
    Machine Independent
        Languages are either specific to a processor (:term:`low-level
        languages`) or independent of any processor (:term:`high-level
        languages`).

    Provisioning Tool
    Provisioning Tools
        These programs help system administrators install and manage systems by
        automating the previously tedious process they used to perform. There
        are several tools in this category: Puppet_, Chef_, and Ansible_ are
        all popular :term:`open-source` today. 

    Hidden File
        Most operating systems "hide" file names that start with a dot ".".
        These normally contain configuration information that should not be
        modified unless you know what you are doing You need to use a special
        command to display these files when generating a directory list.

    Camel Case
        A naming convention where the name is made up of multiple words, each
        with the first letter capitalized, and spaces removed. For example:
        `CamelCase`.

    Real World
        A fictitious place everyone claims exists. In this world things work
        perfectly (or at least better than in your present world!)

    Hash
    Hash Key
        A string of characters generated using a has function that is applied
        to all of the content of some object. These strings are often used to
        detect if the object has been altered in any way.

    Style Guide
        A document specifying the style to be used to projects in some
        organization. These guides lay out how program code should be
        presented, how variable names are formed, or how files should be
        organized to meet standards everyone in the organization will follow.
        Some of these guides can be extensive, others, very informal.

    reStructuredText
        A simple markup language designed to make documentation readable with
        no processing. Processing tools like SPhinx_ can turn documents written
        in this markup into HTML or PDF output that looks very nice!

    Professional Image
        You have an image on the Web. Like it or not, this image follows you
        everywhere, even into the first job interview. Are you proud of that
        image? May folks post the most outrageous junk on their FaceBook pages,
        thinking no one but their "Friends" look at it. Not so! Unfortunately,
        your potential employer might check you out and not like what they see.
        Your choice. I recommend making sure you look like someone others want
        to employ, or at least someone who does more with their lives than just
        keep everyone informed about every aspect of your life on FaceBook!
        YMMV!

    Gravatar
        A service that will provide your image when you log into a number of
        web sites. That image can be viewed by others to make sure they
        recognize the you they are communicating with. I consider using such a
        service part of setting up a :term:`professional image`.

    Avatar
        A graphical representation of a user. Often an image, but it can be a
        cartoon-like character as well. To make the web more personal (and less
        anonymous), sites like Gravatar_ help users show their chosen avatar on
        many web sites. I consider this usage part of setting up a
        :term:`professional image`.

    Continuous Integration
        A testing technique where a project is automatically tested on a number
        of build systems to verify that the project is running properly. By
        testing automatically, developers can spot major problems that cause
        errors on specific platforms quickly.

    NTP
    Network Time Protocol
    Network Time Synchronization
        Servers on the Internet with access to very accurate (usually based on
        atomic vibrations) time signals, keep track of the current time and can
        report that time to your system using a simple protocol. Most machines
        connected to the Internet can be set up to synchronize their view of
        the current time with these servers. (The software can even account for
        the time it takes for those signals to reach your machine!)

    Interrupt
    Interrupts 
    Interrupt Handler
        Processors normally run programs using a simple four step process
        called "Fetch-Decode-Execute-Store". When the machine is at the point
        where it is about to fetch another :term:`instruction`, a signal can
        stop the action, and cause the machine to jump to a block of code that
        handles the signal. The signal is called an interrupt, since it
        interrupts the normal flow of a program. The code that deals with the
        signal is called an :term:`Interrupt Handler`. Hopefully,
        :term:`interrupts` are short enough that the interrupted program does
        not notice the delay!

    Texas Four-Step
        All computer processors use a four step process to do their work. The
        four steps are called :term:`Fetch`, :term:`Decode`, :term:`Execute`,
        and :term:`Store` (or :term:`Retire`.

    Fetch
    Fetched
        Using a special register called an :term:`Instruction Pointer` (or
        :term:`IP`, the processor reaches into the system memory at the address
        designated by the :term:`IP` register and fetches a defined number of
        bytes which form all or part of the next :term:`Machine Instruction` to
        be processed.

    Instruction
    Instructions
    Machine Instruction
    Machine Instructions
        A single instruction that a given processor can :term:`execute` is
        called a :term:`machine instruction`, or just an :term:`instruction`. A
        set of :term:`Machine Instructions` make up a :term:`Machine Language`

    Instruction Pointer
        Processors use a special :term:`register` to keep track of the address
        in memory where the next :term:`machine instruction` to be processed
        can be found. This :term:`register` is called the :term:`instruction
        pointer`, or just the :term:`IP` register.

    Register
        A place inside the processor where data can be stored. There will be a
        number of such places in each processor Instead of addresses, these
        locations will have names. We refer to those names in assembly language
        programming.

    Decode
        After the processor has :term:`fetched` part of an instruction, it
        decodes that part to determine what additional information it needs to
        do its work. If it needs more data from memory, that data will be read
        from memory into internal registers. As part of this step, the complete
        size of the instruction is calculated, and the :term:`IP` register is
        updated to point to the next instruction in memory.

    Execute
    Execution
        We call the act of actually processing something in a computer
        `executing` that something. The something can be a single
        :term:`Machine Instruction`, or a complete program. We are a brutal
        race of beings, aren't we?

    Store
    Retire
    Retirement
        Once a single :term:`Machine instruction` has been completed, any new
        data produced by that instruction needs to be written to a final
        storage location, clearing the processor to move on to the next
        instruction. We say we :term:`store` that data, or :term:`retire` the
        instruction.

    Over-Clock
    Over-Clocked
        It is possible to program the clock on some systems so it runs faster
        than advertised by the manufacturer. You might get more speed out of
        your system by doing this, but you also might reach a point where the
        signals are not getting where they need to be in time, and the results
        are totally unpredictable.

    Latency
        The delay between when an action is started and when it completes. In
        computing, this is usually measured in clock cycles.

    
    Data Alignment
        Modern processors work best when data is aligned so that the data item
        fits in a natural data chunk the processor will fetch. Misalignment
        problems occur when a single data item requires two memory accesses to
        access.

    Accessor
    Mutator
        Methods that can access a private attribute. These methods control
        access to the attributes and can enforce value validation to make sure
        the attribute is properly constrained.

    API
    Application Programming Interface
        A collection of methods that provide the public interface to a
        subsystem used in your application. 

    Home Directory
        Most operating systems create a directory you are to use for all of
        your files on that system. This directory is tied to the user account
        you log into when you access that system. On Windows, this is the
        directory where your "My Documents" folder is found, usually a place
        like ``C:\Users\username``. On Linux systems the directory will be in
        ``/home/username``. On Macs, it will be in ``/Users/username``.

    IP
        Internet Protocol. This term refers to the "dotted-quad" number
        assigned to your machine when it is connected to a standard network.
        You can determine your "IP number" by running `ipconfig` on a PC, or
        `ifconfig` on either a Mac or Linux system.

    IDE
    Integrated Development Environment
    Integrated Development Environments
        A collection of common programmer's tools integrated into a single
        application with features that can greatly speed up program
        development. Unfortunately, typical IDE systems are complex and may not
        support all the languages you use, or be available on all the platforms
        you use.
        
    GUI
    Graphical User Interface 
        A user interface were the mouse and windows are
        used to control applications. 

    System path
        Most operating systems search for files to execute by examining
        directories listed in a system variable called the ``PATH``. 
        
    Script
        Programs designed to control computers are often called scripts. Most
        scripts are written using simple languages like `bash` on a Linux
        system or Python.

    System Clock
        The master timing device on all computers. The processor uses the clock
        to synchronize the execution of machine instructions.

    Voltage
        This is a measure of the "force" driving electricity through a circuit.
        Think of pressure in a water pipe.

    Current 
        This is the flow of electrons through a circuit. Moving electrons
        generate heat and electromagnetic waves as a by-product of this motion.

    Environment Variable
    Environment Variables
        Named strings managed by the command line processor. These strings are
        available to programs and are commonly used to set up data for a
        variety of purposes. 

..  vim: set filetype=rst spell
