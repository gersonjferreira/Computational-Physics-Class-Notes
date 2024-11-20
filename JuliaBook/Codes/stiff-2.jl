using PyPlot
using ODE

function explicitRK2(rhs, t0, t1, tau, y0)
   tspan = t0:tau:t1; # sets the time span
   y = y0; # stores solutions in y
   yt = y0; # yt is the auxiliary for the iterations
   for t=tspan[1:end-1]
      # explicit RK2 rule:
      yt = yt + tau*rhs(t+tau/2, yt+0.5*tau*rhs(t, yt));
      y = [ y; yt ]; # stores solutions
   end
   return tspan, y;
end

function implicitRK2(rhs, t0, t1, tau, y0)
	tspan = t0:tau:t1;
	y = y0;
	yt = y0;
	for t=tspan[1:end-1]
	   yold = yt;
		ynext = yt + tau*rhs(t, yt);
		k = 0;
      while abs(ynext-yold) > 1e-6*ynext && k < 50000
         #println("k = $(k), delta = ", abs(ynext-yold));
         yold = ynext;
   		ynext = yt + tau*rhs(t+tau/2.0, (yt+ynext)/2.0); 
   		k += 1;
		end
		yt = ynext;	
		y = [ y; yt ];
	end
	return tspan, y;
end

rhs(t,y) = y^2 - y^3; 
y0 = 0.0001;

tau = (2.0/y0)/10000; # same tau for both methods
te, ye = explicitRK2(rhs, 0.0, 2/y0, tau, y0); # calls explicit RK2
ti, yi = implicitRK2(rhs, 0.0, 2/y0, tau, y0); # calls implicit RK2

tout, yout = ode23s(rhs, y0, 0.0:(2/y0));

clf();
plot(te, ye; label="Explicit");
plot(ti, yi; label="Implicit");
plot(tout, yout; label="ODE");
legend();
axis([0.0, 2/y0, -0.1, 1.5]);



