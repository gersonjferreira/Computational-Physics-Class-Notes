using PyPlot

w = 2pi;
b = 0.0;
g(x,v,t) = -(w^2)*sin(x)-b*v;
f(x,v,t) = [g(x,v,t); v];

x0 = 0.5pi;
v0 = 0.0;
y0 = [v0; x0];

tau = 1e-4;
tspan = 0:tau:5;

yt = y0;
y = y0;
for t=tspan[1:end-1]
    y = y + tau*f(y[2], y[1], t);
    yt = [ yt y ];
end
x = transpose(yt[2,:]);
v = transpose(yt[1,:]);

small = x0*cos(w*tspan);

clf();
plot(tspan, x; label="numerical");
plot(tspan, small; label="small oscillations");
legend();

#rhs(t, y) = f(y[2], y[1], t);
#tout, yout = ode78(rhs, y0, tspan; reltol=1e-16, abstol=1e-16);
#x2 = map(k-> k[2], yout);

#plot(tout, x2);
