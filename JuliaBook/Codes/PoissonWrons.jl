using ODE
using PyPlot

# z axes
z = linspace(-1.0, 1.0, 1000);

# charge density
g = 0.01; # broadening
rho(z) = exp(-(z.^2)/(2*g^2))/(sqrt(2pi)*g);

# physical boundary conditions
y0 = -1.0;
y1 = +1.0;

# find ya
A1 = 1.0;
ic = [0.0; A1]; # = (0, A1)
rhs(z, y) = [y[2]; 0.0];
za, ya = ode45(rhs, ic, z; points=:specified);
ya = map(k->k[1], ya);

# find yb
A2 = 1.0;
ic = [A2; 0.0]; # = (A2, 0)
rhs(z, y) = [y[2]; 0.0];
zb, yb = ode45(rhs, ic, z; points=:specified);
yb = map(k->k[1], yb);

# find yp
B1 = 0.0;
B2 = 0.0;
ic = [B1; B2]; # = (B1, B2)
rhs(z, y) = [y[2]; -rho(z)];
zp, yp = ode45(rhs, ic, z; points=:specified);
yp = map(k->k[1], yp);

# coefficients and final solution
b = (y0 - B1)/A2;
a = (y1 - b*yb[end] - yp[end])/ya[end];
y = a*ya + b*yb + yp;

plot(z, y);
