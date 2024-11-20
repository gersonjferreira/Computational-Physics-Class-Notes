using PyPlot
# RK2 solver receives the right hand side function,
# initial (t0) and final (t1) times, time-step (tau),
# and initial condition (function)
y0 explicitRK2(rhs, t0, t1, tau, y0)
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

# does not need rhs, implemented specifically for the ODE: dy/dt = −15y
function implicitRK2(t0, t1, tau, y0)
   tspan = t0:tau:t1;
   y = y0;
   yt = y0;
   for t=tspan[1:end-1]
      # explicit solution of the implicit rule for this particular ODE
      yt = yt*(1.0-15*tau/2.0)/(1.0+15*tau/2.0);
      y = [ y; yt ];
   end
   return tspan, y;
end

rhs(t,y) = -15*y; # defines the right hand side of the ODE
y0 = 1.0; # initial condition

tau = 1.0/10; # same tau for both methods
te, ye = explicitRK2(rhs, 0.0, 1.0, tau, y0); # calls explicit RK2
ti, yi = implicitRK2(0.0, 1.0, tau, y0); # calls implicit RK2

texact = 0:0.01:1;
exact = exp(-15*texact); # exact solution for comparison

clf(); # plot the results
plot(texact, exact; label="Exact");
plot(te, ye; label="Explicit");
plot(ti, yi; label="Implicit");
legend();
axis([0.0, 1.0, -1.5, 1.5]);

