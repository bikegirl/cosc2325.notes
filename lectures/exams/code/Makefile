# Makefile for exam1lab

TARGET  = exam1

FILES 	= $(wildcard *.c)
OBJS	= $(FILES:.c=.o)
ASMS	= $(FILES:.c=.s)

# tools
CPP	= gcc
RM	= rm -f

all:	$(TARGET) $(ASMS)

$(TARGET):	$(OBJS)
	$(CPP) -o $@ $^

%.o:	%.c
	$(CPP) -c -o $@ $<

%.s:	%.c
	$(CC) -S -masm=intel $< -o $@

clean:
	$(RM) $(OBJS) $(TARGET)
