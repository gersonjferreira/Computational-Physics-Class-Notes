# do not reset due to reread
# to call this code, use:
# > reset
# > ix = 0
# > load "animate.gp"

if (ix == 0) {
    set term gif animate delay 10
    set output "animate.gif"
}

max = 2*pi
f(x) = sin(x)
dx = max/100
set xrange [0:max]

ix = ix + dx
set object 1 rectangle at ix,f(ix) size 0.1, 0.1
plot f(x)

if (ix < max) reread

set output
reset
