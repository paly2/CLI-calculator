all: tcalc

tcalc: calculatestring.c calculatestring.h main.c
	gcc -o tcalc main.c calculatestring.c functions.c -lm
	cp tcalc /usr/bin/

mrproper:
	rm -f tcalc
	rm -f /usr/bin/tcalc