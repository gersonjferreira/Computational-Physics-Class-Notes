using PyPlot

xlst = linspace(0, 2pi, 7);
flst = sin(xlst);

function interp1(n, x, f)

    xnew = linspace(x[1], x[end], n);
    fnew = zeros(n);

    i = 1;
    for j=1:(length(x)-1)

        xa = x[j];
        xb = x[j+1];

        fa = f[j];
        fb = f[j+1];
        
        m = [xa 1.0; xb 1.0];
        A, B = inv(m)*[fa; fb];

        while i <= n && xnew[i] <= xb
            fnew[i] = A*xnew[i] + B;
            i += 1;
        end
    end

    return xnew, fnew;
end

xnew, fnew = interp1(51, xlst, flst);

plot(xlst, flst, "o");
plot(xnew, fnew, "g.");
plot(xnew, sin(xnew), "y-");
