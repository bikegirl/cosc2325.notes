FILES = test_mov.c test_mov2.c rdtsc.c freq.c
EXECS = test_mov test_mov2 freq

OBJS	= $(FILES:.c=.o)

all: $(EXECS)

test_mov:	$(OBJS)
	gcc -o $@ test_mov.o rdtsc.o

test_mov2:	$(OBJS)
	gcc -o $@ test_mov2.o rdtsc.o

freq:	$(OBJS)
	gcc -o $@ freq.o rdtsc.o

%.o:	%.c
	gcc -c -o $@ $<

clean:
	rm -f $(EXECS) $(OBJS)
