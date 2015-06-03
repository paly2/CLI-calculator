#/bin/bash

gcc -o tcalc main.c calculatestring.c
cp tcalc /usr/bin/
echo "Done building."
