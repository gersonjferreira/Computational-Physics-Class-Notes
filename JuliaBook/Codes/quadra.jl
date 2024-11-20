f(x) = sin(x);

function trapezoildal(g, a, b, n)
	dx = (b-a)/(n-1.0);
	xi(i) = a + (i-1.0)*dx;
	res = 0.0;	
	for i=1:(n-1)
		res += 0.5*(g(xi(i+1))+g(xi(i)))*dx
	end
	return res;
end

trapezoildal(f, 0, pi, 3)

trapezoildal(f, 0, pi, 20)

trapezoildal(f, 0, pi, 100)

quadgk(f, 0.0, pi)

f(x) = 1/sqrt(x)
quadgk(f, 0.0, 16)

f(x) = exp(-(x^2)/2)/sqrt(2);
quadgk(f, -Inf, Inf)



