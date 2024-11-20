# PROBLEM 1.1: representabilidade dos números

# PROBLEM 1.2

function bhaskara(a, b, c)
   delta = b^2 - 4a*c;
   delta = (delta>0.0) ? delta : convert(Complex{Float64}, delta);
   r1 = (-b+sqrt(delta))/(2a);
   r2 = (-b-sqrt(delta))/(2a);
   return (r1, r2);
end

root1, root2 = bhaskara(2.0, -2.0, -12.0);
println("The first root is ", root1)
println("The second root is ", root2)


# PROBLEM 1.3: rodando via "include" dentro da Julia você ainda tem acesso aos dados na memória. Rodando via linha de comando, o programa fecha depois do código. Então você deve salvar os dados no script.

# PROBLEMA 1.4: apenas verificar o que acontece com as váriaveis dentro das funções e quais são seus escopos.

# PROBLEM 1.5
using PyPlot

function psi(x, a)
    if ( abs(x) > a )
        return 1.0;
    end
    return (x/a)^2;
end

a = 10.0;
x = linspace(-2a,2a,100);
f = map((x)->psi(x,a), x);
plot(x, f)

# PROBLEM 1.6:

function fact(n::Int64)
    res = 1; # initialize the result as 1
    i = n;
    while i > 1
        res = res*i; # since n! = n · (n − 1) · (n − 2) · · · (1)
        i = i-1;
    end # end loop
    return res; # return the result
end

fact(4)

# PROBLEM 1.7: acho que esse é fácil

writedlm("test.dat", 10, ASCIIString);

# PROBLEM 1.8

list = randn(100000);
x,y = hist(list, 100);

plot(  (x[1:end-1] + x[2:end])/2,  y)

# PROBLEM 1.9: só usar a função cross, lembrar que tem q usar vetores coluna

# PROBLEM 1.10: a implementação é fácil. Mas pq funciona? Faça a figura do circulo (raio 1) inscrito no quadrado (lado 1)
# Olhe só pro primeiro quadrante.
# A probabilidade um ponto cair dentro do circulo é Pi/4.

vecin = [0.0 0.0];
vecout = [0.0 0.0];
Pn = 0;
in=0;
out=0;
x=1:1000;
for i=x
    r = rand(2);
    if norm(r) <= 1
        in += 1;
        vecin = [vecin; r[1] r[2]];
    else
        out += 1;
        vecout = [vecout; r[1] r[2]];
    end
    Pn = [Pn; 4*in/(in+out)];
end
#plot(Pn[2:end])
plot(log(abs(Pn[2:end]-pi)))
plot(log(1./sqrt(x)))

scatter(vecin[2:end,1], vecin[2:end,2], color="b")
scatter(vecout[2:end,1], vecout[2:end,2], color="y")
