reset
set term qt font ",12" enhanced

# a 2D Gaussian
f(x,y) = exp(-x**2/2) * exp(-y**2/2)

set xrange [-5:5]
set yrange [-5:5]
unset key

# number of points
set isosamples 50,50

# check options: at s, at b, map
set pm3d map

#set hidden3d front
#set contour surface
#set cntrparam levels 25

splot f(x,y)
