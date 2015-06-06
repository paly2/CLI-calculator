all: tcalc
	cp tcalc /usr/bin/

tcalc: calculatestring.c calculatestring.h functions.c functions.h main.c
	gcc -o tcalc main.c calculatestring.c functions.c -lm

mrproper:
	rm -f tcalc
	rm -f /usr/bin/tcalc