using ODE
using PyPlot

# z axes
z = linspace(-1.0, 1.0, 1000);

# charge density
g = 0.05; # broadening
rho(z) = exp(-(z.^2.0)/(2.0*g^2.0))/(sqrt(2.0*pi)*g);

odeRELTOL=1e-8;
odeABSTOL=1e-10;

clf();
subplot(311);
plot(z, rho(z));

# physical boundary conditions
y0 = -1.0;
y1 = +1.0;

# guess derivative
function guess(alpha, y0, y1)
    ic = [y0; alpha];
    rhs(z, y) = [y[2]; -rho(z)];
    za, ya = ode45(rhs, ic, z; points=:specified, reltol=odeRELTOL, abstol=odeABSTOL);
    ya = map(k->k[1], ya);
    return (ya[end]-y1)
end

alpha = linspace(-0.5, 3.0, 501);
yend = Float64[guess(a, y0, y1) for a=alpha];

subplot(312);
plot(alpha, yend);
grid("on");

if true
    da=1e-2;
    alpha = 0.0;
    zC = 1.0;
    while abs(zC) > 1e-3
        zL = guess(alpha-da, y0, y1);
        zC = guess(alpha, y0, y1);
        zR = guess(alpha+da, y0, y1);
        dz = (zR-zL)/(2*da);
        alpha = alpha - zC/dz;
        
        println("zc = $zC, alpha = $alpha");
    end

    ic = [y0; alpha];
    rhs(z, y) = [y[2]; -rho(z)];
    za, ya = ode45(rhs, ic, z; points=:specified, reltol=odeRELTOL, abstol=odeABSTOL);
    ya = map(k->k[1], ya);
    
    subplot(313);    
    plot(za, ya);
    grid("on");
end
