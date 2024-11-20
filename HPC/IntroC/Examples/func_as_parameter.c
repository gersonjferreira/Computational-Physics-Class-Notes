#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float my_fun(float x) {
    float s = sin(x);
    return(s*s/M_PI);
}

float integrate(float (*f)(float), float a, float b, int n) {
    float dx = (b-a)/(n-1);
    float sum, x;

    sum = 0.0;
    for (int i=0; i<n; i++) {
        x = a + i*dx;
        sum += (*f)(x)*dx;
    }
    return(sum);
}

int main() {
    float a, b, res;

    a = 0.0;
    b = M_PI;
    res = integrate(my_fun, a, b, 100);
    printf("The result is %f\n", res);

    return(0);
}