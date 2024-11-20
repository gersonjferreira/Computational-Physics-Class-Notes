

set term cairolatex png standalone
set output "latex.tex"

set xlabel "$\\theta$ [rad]"

plot sin(x) title "$\\sin(\\theta)$"

set output
set term qt
