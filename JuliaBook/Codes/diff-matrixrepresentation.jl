#diff = [1; 0; -1]; # sym
#diff = [1; -1; 0]; # fwd
diff = [0; 1; -1]; # bwd
x = 0:(pi/5):2pi;
f = sin(x);

g = conv(diff, f);

g = g[2:end-1];
plot(x, g)
