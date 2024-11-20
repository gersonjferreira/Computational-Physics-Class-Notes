using PyPlot

dx=0.5;
L = 10pi;
x = -L:dx:L
dx = x[2]-x[1];
n = length(x);
y = exp(-x.^2);

f = fftshift(fft(y))/n;
q = pi*linspace(-1.0/dx, 1.0/dx, n);

clf();
plot(q, abs(f), "-o")
v = axis();
axis([-20.0, 20.0, v[3], v[4]])
