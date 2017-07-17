Example CPUsim Program
######################

This is a simple example of a short piece of code that will add a few numbers,
then subtract one and output the final result.

Use this as a test of your simulator code for Lab 3. (It only uses byte data,
which is sufficient for this class. I will give extra credit if you handle word
data as well!)


..  code-block::    text

    ; data block (all bytes)

    Address     Data
    -------     ----
    0000        87
    0001        43
    0002        50

    ; code block (1 - 5 bytes per instruction)
    
    Address     Data
    -------     ----
    0000h       01h         ; MOV   R1, 0000
    0001h       10h,20h     ; modRM word
    0003h       0000h       ; address of item 1

    0005h       01h         ; MOV   R2, 0001
    0006h       11h,21h     ; modrm word
    0008h       0001h       ; address of item 2

    000ah       02h         ; ADD   R1, R2
    000bh       10h,11h     ; modRM (R1, R2)

    000dh       01h         ; MOV   R2, 0003
    000eh       11h,21h     ; modRM word
    0010h       0003h       ; address of item3

    0012h       03h         ; SUB   R1, R2
    0013h       10h,11h     ; modRM word

    0015h       16h         ; OUT   R1
    0016h       02h,00h     ; modrm

    0017h       17h         ' HLT

With any luck, the output should be 80.



