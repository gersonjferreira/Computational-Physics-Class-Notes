using PyPlot
using ODE

gamma = 0.001;
#gamma = 0;

w0 = 2pi;
g(x,v,t) = -(w0^2)*sin(x) -gamma*v;
f(x,v,t) = [g(x,v,t); v];

x0 = 0.999pi;
v0 = 0.0;
y0 = [v0; x0];

tspan = linspace(0, 6000, 1000000);

rhs(t, y) = f(y[2], y[1], t);
tout, yout = ode45(rhs, y0, tspan; points=:specified);
xout = map(k-> k[2], yout);

clf();
subplot(311);
plot(tout, xout);

subplot(312);
dt=tout[2]-tout[1];

w = linspace(0, 2pi/dt, length(tout));
z = fft(xout);
plot(w-pi/dt, abs(fftshift(z)))
xlim(-3pi,3pi);

subplot(313);
s0=20;
nw = Int(length(w)/s0);
zw = zeros(nw);
s=1:s0;
for i=s
    data = xout[(1:nw) + (i-1)*nw];
    w = linspace(0, 2pi/dt, length(data));
    z = fft(data);
    zw = [zw  abs(fftshift(z))];
end
zw = zw[:, 2:end];
pcolormesh(s, w-pi/dt, log(zw));
ylim(-3pi,3pi);
tight_layout()

#plot(w-pi/dt, abs(fftshift(z)));
