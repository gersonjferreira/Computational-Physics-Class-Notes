using PyPlot

mc(x,y) = (x^2+y^2 <= 1.0)?4.0:0.0;

function Rn(n)
    res=0.0;
    for i=1:n
        res += mc(rand(), rand());
    end
    return res/n;
end	

x = 50:100:1000000;
list = Float64[Rn(n) for n=x];

erro = abs(list-pi)/pi;

clf();
plot(log(x), log(erro));
plot(log(x), -0.5*log(x));
