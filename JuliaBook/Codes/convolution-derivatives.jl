using PyPlot

x = linspace(-5, 5, 101);
y = transpose(linspace(-5, 5, 101));
hx = x[2]-x[1];
hy = y[2]-y[1];

f = exp(-(x.^2)/2).*exp(-(y.^2)/2);

kernel = (1.0/(4*hx*hy))*[0.0 1.0 0.0; 1.0 0.0 -1.0; 0.0 -1.0 0.0];

df = conv2(kernel, f);
df = df[2:end-1, 2:end-1];

surf(x, y', df)


