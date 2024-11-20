using PyPlot

x = linspace(0.0, 30.0, 300); # domain
f(x) = sin(x)./x; # example function

lambda = x[end]-x[1]; # period
k(n) = 2pi*n/lambda; # wave number

# define a function to caculate the coefficients $c_n$
c(n) = quadgk(x->f(x)*exp(1im*k(n)*x), x[1], x[end])[1]/lambda;

N = 10; # the sum will be $\displaystyle \sum_{n=-N}^N$
Ni = -N:N; # array of values of $n$
Ci = Complex{Float64}[c(n) for n=Ni]; # calculate the coefficients and store in an array

# combine the arrays to recover the approximate function
fa=sum(i-> Ci[i]*exp(-1im*k(Ni[i])*x), 1:(2*N+1))

clf(); 
subplot2grid((2,2),(0,0),colspan=2)
plot(x,f(x)); # pĺot the original function
plot(x, real(fa)) # and the one recovered with a finite sum of the Fourier series
xlabel(L"$ x $");
ylabel(L"$ f(x) $");

subplot2grid((2,2),(1,0))
vlines(Ni, 0, real(Ci));
scatter(Ni, real(Ci));
xlabel(L"$ n $")
ylabel(L"$ Re\{c_n\} $")

subplot2grid((2,2),(1,1))
vlines(Ni, 0, imag(Ci));
scatter(Ni, imag(Ci));
xlabel(L"$ n $")
ylabel(L"$ Im\{cn\} $")

tight_layout();
