CLI-CALCULATOR

A simple command-line calculator.

By paly2. 
Published with the GNU General Public License.


You can execute the "build.sh" script to build the calculator :
chmod +x build.sh
sudo ./build.sh
Or use the make command :
make

Examples of utilisations :
tcalc 12+8
=> 20
tcalc 12+8*2
=> 40
tcalc "12+(8*2)"
=> 28
tcalc 10.2*8
=> 81.600000
tcalc 7/2
=> 3
tcalc 7%2
=> 1
tcalc 7.0/2
=> 3.500000
tcalc "sqrt(2)"
=> 1
tcalc "sqrt(2.0)"
=> 1.1.414214
tcalc "pow(4,2)"
=> 16

Functions :
abs()
exp()
exp2()
log()
log2()
log10()
logb()
sqrt()
cbrt()
hypot(,)
sin()
cos()
tan()
asin()
acos()
atan()
sinh()
cosh()
tanh()
asinh()
acosh()
atanh()
pow(,)