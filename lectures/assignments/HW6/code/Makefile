SRCS    = $(wildcard *.asm)
OBJS    = $(SRCS:.asm=.o)

BIN     = hello_nasm

.PHONY:	all
all:	$(BIN)

$(BIN): $(OBJS)
	gcc -o $@ $^

%.o:	%.asm
	nasm -f elf64 $< -o $@

.PHONY: clean
clean:
	rm -f $(BIN) $(OBJS)
