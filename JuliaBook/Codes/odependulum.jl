using PyPlot
using ODE

w = 2pi; # frequency, period for small oscillations T = 2pi/w
g(x,t) = -(w^2)*sin(x); # r.h.s. of Newton's 2nd law
f(x,v,t) = [g(x,t); v]; # r.h.s. of linearized ODE

x0 = 0.5pi; # initial angular displacement
v0 = 0.0; # inicial angular velocity
y0 = [v0; x0]; # initial vector for linearized ODE

tau = 1e-4; # time step
tspan = 0:tau:5; # time range

# the rhs function is our implementation of $\bm{F}(t,\bm{y})$ from $\text{Eq. \eqref{eq:ode}}$
rhs(t, y) = f(y[2], y[1], t);
tout, yout = ode45(rhs, y0, tspan; points=:specified);
x = map(k-> k[2], yout); # extract x from yout

small = x0*cos(w*tspan); # exact solution for small oscillations

# plot numerical and exact solutions for comparison
clf(); 
plot(tspan, x; label="numerical");
plot(tspan, small; label="small oscillations");
legend();
