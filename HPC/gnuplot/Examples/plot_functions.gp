reset

# define the terminal and its properties:
# enhanced text mode:
#   - format strings as x^2 = x², x_0...
#   - choose font locally:
#       {/Times something}
#       {/Arial some text}
#       {/Symbol greek letters, etc}
# 
# interactive terminals: qt, wxt, ...
# figure terminals: png, gif, svg, ...
set term qt font ",16" enhanced

set xrange [-10:10]
set xlabel "{/Symbol q} [rad]"
set ylabel "f({/Symbol q})"
# legend position
set key outside top right font ",10"

# number of points
set samples 1000

set style function lines

f(t,w) = sin(w*t)**2 * exp(-t**2)

# plot always at the end
#plot sin(x) title "seno" lw 3 
#replot cos(x) title "coseno" lw 3 

plot f(x, 1) lw 3, f(x,3) lw 3


