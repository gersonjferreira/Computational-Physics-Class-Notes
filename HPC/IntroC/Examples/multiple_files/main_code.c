#include <stdio.h>
#include <stdlib.h>

// library with auxiliary functions for my code
#include "aux_functions.h"

int main() {
    int a = 15;
    int b = 3;
    int m;

    printf("before: a=%d, b=%d\n", a, b);
    troca(&a, &b); // switch a and b
    printf("after: a=%d, b=%d\n", a, b);

    m = maior(a, b); // returns largest
    printf("Largest is: %d\n", m);

    return(0);
}