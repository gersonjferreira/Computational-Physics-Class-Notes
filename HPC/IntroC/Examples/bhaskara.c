#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void bhaskara1(float a, float b, float c, float *x1, float *x2) {
    float delta;
    delta = b*b - 4*a*c;
    *x1 = (-b + sqrt(delta))/(2*a);
    *x2 = (-b - sqrt(delta))/(2*a);
}

float *bhaskara2(float a, float b, float c) {
    float delta;
    float *r = (float *) calloc(2, sizeof(float));
    delta = b*b - 4*a*c;
    r[0] = (-b + sqrt(delta))/(2*a);
    r[1] = (-b - sqrt(delta))/(2*a);
    return(r);
}

void bhaskara3(float a, float b, float c, float *rs) {
    float delta;
    delta = b*b - 4*a*c;
    rs[0] = (-b + sqrt(delta))/(2*a);
    rs[1] = (-b - sqrt(delta))/(2*a);
}

int main() {
    float a, b, c;
    float r1, r2;
    float *r;
    float r3[2];

    a = +1.0;
    b = -5.0;
    c = +6.0;

    bhaskara1(a, b, c, &r1, &r2);
    printf("1) soluções = %f, %f \n", r1, r2);

    r = bhaskara2(a, b, c);
    printf("2) soluções = %f, %f \n", r[0], r[1]);
    free(r);

    bhaskara3(a, b, c, r3);
    printf("3) soluções = %f, %f \n", r3[0], r3[1]);

    return(0);
}