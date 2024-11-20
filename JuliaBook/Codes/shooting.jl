using PyPlot
using ODE

# phi = [y; v]
rhs(t, phi) = [phi[2], -abs(phi[1])];
#rhs(t, phi) = [phi[2], -phi[1]^2];

tspan = [0.0; 4.0];
alist = linspace(-0.25, 3.0, 1000);
yend = Float64[];
vend = Float64[];
for a=alist

    ic = [0.0; a];
    tout, phiout = ode45(rhs, ic, tspan; points=:specified);
    y = map(k->k[1], phiout);
    v = map(k->k[2], phiout);

    yend = [yend; y[end]];
    vend = [vend; v[end]];
end

clf();

subplot(211);
plot(alist, yend);
grid("on");
xlabel("v0")
ylabel("y(4)")

aa = Float64[]
yy = Float64[]
for i=2:length(yend)
    if (yend[i-1] <= -2 <= yend[i]) || (yend[i] <= -2 <= yend[i-1])
        aa = [aa; alist[i]];
        yy = [yy; yend[i]];
    end
end
scatter(aa, yy)

subplot(212);

ic = [0.0; aa[1]];
tspan = linspace(0.0, 4.0, 50);
tout, phiout = ode78(rhs, ic, tspan; points=:specified);
y = map(k->k[1], phiout);
v = map(k->k[2], phiout);

plot(tspan, y);

ic = [0.0; aa[2]];
tspan = linspace(0.0, 4.0, 50);
tout, phiout = ode45(rhs, ic, tspan; points=:specified);
y = map(k->k[1], phiout);
v = map(k->k[2], phiout);

plot(tspan, y);

grid("on")
xlabel("x")
ylabel("y(x)")


