#include <stdio.h>
#include <stdlib.h>
#include <math.h> // link with -lm

int main() {
    double theta;

    printf("Hello, the value of pi is %f\n", M_PI);
    
    theta = 30*M_PI/180.0;
    printf("Cos(30º) = %f", cos(theta));

    return(0);
}

