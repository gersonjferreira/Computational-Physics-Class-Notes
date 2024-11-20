diff1_forward(f, x, h) = (f(x+h)-f(x))/h;
diff1_backward(f, x, h) = (f(x)-f(x-h))/h;
diff1_symmetric(f, x, h) = (f(x+h)-f(x-h))/(2h);

f(x) = sin(x);

xgrid = 0:(pi/50):pi;
h = pi/5;
fwd = [diff1_forward(f, x, h) for x=xgrid]
bwd = [diff1_backward(f, x, h) for x=xgrid]
sym = [diff1_symmetric(f, x, h) for x=xgrid]

plot(xgrid, cos(xgrid); label="cos(x)")
plot(xgrid, fwd; label="forward")
plot(xgrid, bwd; label="backward")
plot(xgrid, sym; label="symmetric")
legend()
