using PyPlot

D = 1;
v = 1;

L = -10;
N = 100;
x = linspace(-L, L, N);
dx = x[2]-x[1];
k = linspace(-pi/dx, pi/dx, N);

ux0 = exp(-x.^2);
uk0 = fftshift(fft(ux0));

ukt(t) = exp((-1im*v*k-D*k.^2)*t).*uk0;
uxt(t) = ifft(ifftshift(ukt(t)));
clf();
plot(x, ux0);
plot(x, uxt(1));
plot(x, uxt(2));
plot(x, uxt(3));

# test derivada
#uk = 1im*k.*uk0;
#ux = real(ifft(ifftshift(uk)));
#diff = -2*x.*ux0;
#clf();
#plot(x, ux);
#plot(x, diff);


