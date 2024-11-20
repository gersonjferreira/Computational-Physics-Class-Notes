
using PyPlot

L = 10.0;
c = L/2.0;
N = 100;
v0 = -10;

x = linspace(0, L, N);
h = x[2]-x[1];

t = -0.5*(-2*diagm(ones(N)) + diagm(ones(N-1),1) + diagm(ones(N-1),-1))/h^2;
v = v0*exp(-0.5*(x-c).^2);
vm = diagm(v);

evals, evecs = eig(t+vm);

subplot(211)
plot(x, v);

subplot(212)
plot(x, evecs[:,1]);
plot(x, evecs[:,2]);
plot(x, evecs[:,3]);
