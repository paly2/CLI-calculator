#/bin/bash

gcc -o tcalc main.c calculatestring.c functions.c -lm
cp tcalc /usr/bin/
echo "Done building."
