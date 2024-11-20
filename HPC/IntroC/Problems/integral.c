#include <stdio.h>
#include <stdlib.h>
#include <math.h> // compilar com a opção -lm

float my_fun(float x) {
    float s = sin(x);
    return(s*s/M_PI);
}

float integrate(float a, float b, int n) {
    // seu código aqui
}

int main() {
    float a, b, res;

    a = 0.0;
    b = M_PI;
    res = integrate(a, b, 100);
    printf("The result is %f\n", res);

    res = integrate(a, b, 5);
    printf("The result is %f\n", res);

    return(0);
}