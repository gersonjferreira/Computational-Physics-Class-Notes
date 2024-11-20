import Base:+
import Base:*
import Base:/
import Base:show

type numerr
    num
    err
end

±(a,b) = numerr(a,b);
show(io::IO, a::numerr) = println("(", a.num, " ± ", a.err, ")");

+(a::numerr, b::numerr) = numerr(a.num + b.num, sqrt(a.err^2 + b.err^2));
+(a::Any, b::numerr) = numerr(a + b.num, b.err);
+(a::numerr, b::Any) = numerr(a.num + b, a.err);

*(a::numerr, b::numerr) = numerr(a.num * b.num, sqrt( (b.num*a.err)^2 + (a.num*b.err)^2 ));
*(a::Any, b::numerr) = numerr(a * b.num, a*b.err );
*(a::numerr, b::Any) = numerr(a.num * b, a.err*b );

/(a::numerr, b::numerr) = numerr(a.num / b.num, (a.num/b.num)*sqrt( (a.err/a.num)^2 + (b.err/b.num)^2 ));
/(a::Any, b::numerr) = numerr(a / b.num, (a/b.num)*(b.err/b.num) );
/(a::numerr, b::Any) = numerr(a.num / b, (a.num/b)*(a.err/a.num) );

x = numerr(10, 1);
y = numerr(20, 2);

println("x = ", x)
println("y = ", y)

println("x+y = ", x+y)
println("2+x = ", 2+x)
println("y+2 = ", y+2)

println("2*x = ", 2*x)
println("y*2 = ", y*2)
println("x*y = ", x*y)

println("x/2 = ", x/2);
println("2/y = ", 2/y);
println("x/y = ", x/y);

println("(2x + y/3)*x/y = ", (2x + y/3)*x/y);

