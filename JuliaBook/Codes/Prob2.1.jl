using PyPlot

#f(x)=sin(x); xmin = 0; xmax = pi; sol = 2.0;
#f(x)=cos(x); xmin = 0; xmax = pi; sol = 0.0;
#f(x)=exp(x); xmin = 0; xmax = 1.0; sol = e-1;
f(x)=exp(-x); xmin = 0; xmax = 1.0; sol = 1-1/e;

res=Float64[];
ilist=5:5:1000;
for i=ilist
    x = linspace(xmin, xmax, i);
    dx = x[2]-x[1];
    res = [res; sum(f(x))*dx];
end

plot(ilist, log(abs(res-sol)))

