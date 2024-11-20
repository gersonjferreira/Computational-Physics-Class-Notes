using PyPlot

N=300000;
t=linspace(0, 30, N);
dt=t[2]-t[1];
w=linspace(0, 2pi/dt, N);

w0 = 2pi;
f=(1+0.5*randn(N)).*sin((1+0.001*randn(N)).*w0.*t);

n=1;
for i=1:(n-1)
    f += (1+0.5*randn(N)).*sin((1+0.001*randn(N)).*w0.*t);
end
f /= n;

g = fft(f);
s = log(abs2(g));


g2 = g.*(s .> 15);
s2 = log(1e-10+abs2(g2));
f2 = ifft(g2);

clf();
subplot(211)
n2 = Int(N/2);
plot(t[1:n2], f[1:n2])
plot(t[n2:end], real(f2[n2:end]));
xlabel(L"t")
ylabel(L"f(t)");

subplot(212)
plot(w-pi/dt, fftshift(s));
plot(w-pi/dt, fftshift(s2));
xlim([-3w0, 3w0]);
xlabel(L"\omega")
ylabel(L"\logS(\omega)");

tight_layout();
