using PyPlot

n = 601; # 64
x = linspace(-15.0, 15.0, n);
dx = x[2]-x[1];
k = linspace(-pi/dx, pi/dx, n);

f = exp(-x.^2)

x0 = 10;
ft = fftshift(fft(f)) .* exp(-1im*x0*k);
g = ifft(ifftshift(ft));

clf(); # the plot is shown in Fig. 4.1
subplot2grid((2,2),(0,0),colspan=2)
plot(x,f); # plot the original function
plot(x, real(g)) # and the approximated one
plot(x, imag(g)) # and the approximated one
xlabel(L"$x$");
ylabel(L"$f(x)$ and $g(x)$")

subplot2grid((2,2),(1,0))
plot(k, real(ft));
xlabel(L"$k$")
ylabel(L"$Re\{\tilde{f}(k)\} $")

subplot2grid((2,2),(1,1))
plot(k, imag(ft));
xlabel(L"$k$")
ylabel(L"$Im\{\tilde{f}(k)\} $")

tight_layout();


