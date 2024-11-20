using PyPlot

xlst = linspace(0, 2pi, 7);
flst = sin(xlst);

function interp0(n, x, f)

    xnew = linspace(x[1], x[end], n);
    fnew = zeros(n);

    i = 1;
    for j=1:(length(x)-1)

        xa = x[j];
        xb = x[j+1];

        fa = f[j];
        fb = f[j+1];
        
	fav = fa;

        while i <= n && xnew[i] <= (xa+xb)/2.0
            fnew[i] = fav;
            i += 1;
        end
    end

    return xnew, fnew;
end

xnew, fnew = interp0(51, xlst, flst);

plot(xlst, flst, "o");
plot(xnew, fnew, "g.");
plot(xnew, sin(xnew), "y-");
