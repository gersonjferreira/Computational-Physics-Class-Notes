reset

#f(x) = a + b*x + c*x**2
#fit f(x) "dados4.dat" u 1:2 via a,b,c

n = 5

f(x) = a*x**n
fit f(x) "dados4.dat" u 1:2 via a,n

plot "dados4.dat", f(x)

