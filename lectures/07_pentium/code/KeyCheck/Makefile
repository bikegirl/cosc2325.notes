AFILES   = \
        factorial.asm

CFILES	= \
		 get_kb.c \
		 print_int.c

AOBJS   = $(AFILES:.asm=.o)
COBJS	= $(CFILES:.c=.o)
OBJS	= $(AOBJS) $(COBJS)

factorial:   $(OBJS)
		gcc -o $@ $^

%.o:    %.asm
		nasm -f elf64 -o $@ $<

%.o:	%.c
		gcc -c $< -o $@

clean:
		rm -f *.o factorial


