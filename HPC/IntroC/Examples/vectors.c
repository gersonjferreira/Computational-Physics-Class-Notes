#include <stdio.h>
#include <stdlib.h>

int prod_escalar(int *a, int *b) {
    int pe = 0;
    for (int i=0; i<3; i++) {
        pe += a[i] * b[i];
    }
    return(pe);
}

int main () {
    int *a = (int *) calloc(3, sizeof(int));
    int *b = (int *) calloc(3, sizeof(int));

    a[0] = 1;
    a[1] = 2;
    a[2] = 3;
    b[0] = 4;
    b[1] = 5;
    b[2] = 6;

    // print a e b
    for (int i=0; i<3; i++) {
        printf("a[%d] = %d, b[%d] = %d\n", i, a[i], i, b[i]);
    }

    printf("a.b = %d\n", prod_escalar(a, b) );

    return(0);
}