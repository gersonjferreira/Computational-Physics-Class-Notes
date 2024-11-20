#include <stdio.h>
#include <math.h>

int main() {
    int n = 5;
    float x = 0.1;
    double y = 0.1;

    printf("The value of n = %d\n", n);
    printf("The value of x = %f\n", x);
    printf("The value of y = %f\n", y);

    printf("Now with more digits:\n");
    printf("The value of x = %0.30f\n", x);
    printf("The value of y = %0.30f\n", y);

    printf("Their sizes in memory\n");
    printf("n has %d bytes, integers have %d bytes\n", sizeof(n), sizeof(int));
    printf("x has %d bytes, floats   have %d bytes\n", sizeof(x), sizeof(float));
    printf("y has %d bytes, doubles  have %d bytes\n", sizeof(y), sizeof(double));

    if ( fabs(y-0.1) < 1e-10 ) {
        printf("ok\n");
    } else {
        printf("falhou\n");
    }

    return(0);
}