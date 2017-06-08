TGTS    = sum1 sum2 sum3 sum4 sum5 sum6 sum7 sum8 sum9 sum10 sum11 sum12 sum13 sum14 sum15

all:    $(TGTS)

sum1:   sum1.c
	gcc -o $@  $<

sum2:   sum2.c
	gcc -o $@  $<

sum3:   sum3.c
	gcc -o $@  $<

sum4:   sum4.c
	gcc -o $@  $<

sum5:   sum5.c
	gcc -o $@  $<

sum6:   sum6.c
	gcc -o $@  $<

sum7:   sum7.c
	gcc -o $@  $<

sum8:   sum8.c
	gcc -o $@  $<

sum9:   sum9.c
	gcc -o $@  $<

sum10:   sum10.c
	gcc -o $@  $<

sum11:   sum11.c
	gcc -o $@  $<

sum12:   sum12.c
	gcc -w -o $@  $<

sum13:   sum13.c
	gcc -w -o $@  $<

sum14:  sum14.o
	gcc -o $@ $<

sum15:  sum15.o
	gcc -o $@ $<

%.o:    %.asm
	nasm -f macho -o $@ $<

clean:
	rm -f $(TGTS) *.o
