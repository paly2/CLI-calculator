#/bin/bash

gcc main.c calculatestring.c -o tcalc -g
cp tcalc /usr/bin/
echo "Done building."