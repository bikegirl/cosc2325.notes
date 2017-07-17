FILES   = \
        factorial.asm

OBJS    = $(FILES:.asm=.o)

factorial:  factorial.o
		gcc -o factorial factorial.o -lcosc2425

%.o:    %.asm
		nasm -f elf64 -o $@ $<

clean:
		rm -f *.o factorial


