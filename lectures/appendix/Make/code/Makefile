# Makefile for hello2 (two part example)

FILES = \
        hello_main.c \
        hello_out.c

OBJS = $(FILES:.c=.o)
ASMS = $(FILES:.c=.s)

all:    hello2

hello2: $(OBJS)
		gcc -o hello $(OBJS)

asmfiles:   $(ASMS)

%.o:    %.c
		gcc -c $< -o $@

%.s:    %.c
		gcc -S $< -o $@

clean:
		rm -f *.o *.s

