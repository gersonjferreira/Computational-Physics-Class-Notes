using PyPlot

xlst = linspace(0, 2pi, 7);
flst = sin(xlst);

function interp2(n, x, f)

    xnew = linspace(x[1], x[end], n);
    fnew = zeros(n);

    i = 1;
    for j=1:2:(length(x)-2)

        xa = x[j];
        xb = x[j+1];
        xc = x[j+2];

        fa = f[j];
        fb = f[j+1];
        fc = f[j+2];
        
        m = [xa^2 xa 1.0; xb^2 xb 1.0; xc^2 xc 1.0];
        A, B, C = inv(m)*[fa; fb; fc];

        while i <= n && xnew[i] <= xc
            fnew[i] = A*xnew[i]^2 + B*xnew[i] + C;
            i += 1;
        end
    end

    return xnew, fnew;
end

xnew, fnew = interp2(51, xlst, flst);

plot(xlst, flst, "o");
plot(xnew, fnew, "g.");
plot(xnew, sin(xnew), "y-");
