using ODE
using PyPlot

function trans(ek)
    k=sqrt(2*ek);
    x0=10;
    L=2*x0;
    xspan = linspace(0.0, L, 200);

    # barreira gaussiana
    v(x)=exp(-0.5*(x-x0)^2) 
    
    # dupla barreira gaussiana
    #v(x)=exp(-0.5*(x-x0/2)^2)+exp(-0.5*(x-3*x0/2)^2)

    rhs(x, y) = [y[2]; 2*(v(x)-ek)*y[1]];
    
    ic=[1.0; 0.0];
    x1, y1 = ode45(rhs, ic, xspan; points=:specified);
    psi1 = map(k->k[1], y1);
    dpsi1 = map(k->k[2], y1);
    
    ic=[0.0; 1.0];
    x2, y2 = ode45(rhs, ic, xspan; points=:specified);
    psi2 = map(k->k[1], y2);
    dpsi2 = map(k->k[2], y2);
        
    mat = [1 0 -1 0; 0 1 1im*k 0; psi1[end] psi2[end] 0 -exp(1im*k*L); dpsi1[end] dpsi2[end] 0 -1im*k*exp(1im*k*L)];
    vec = [1; 1im*k; 0; 0];
    sol = mat\vec;

    t = sol[4];

    return(abs(t)^2);
end

ek = linspace(0.0, 3.0, 2000);
tt = Float64[ trans(en) for en=ek ];

clf();
plot(ek, tt);
xlabel("Energy");
ylabel("Transmission Probability T")




