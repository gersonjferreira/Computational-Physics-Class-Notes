#include <stdio.h>
#include <stdlib.h>
#include <lapacke.h>

/********************************************
 * example: solving a linear system A.X=B, X=?
 * 
 * A = | 2 -1  0|
 *     |-1  2 -1|
 *     | 0 -1  2|
 * 
 * B = |0|
 *     |1|
 *     |0|
 * 
 * A.X = B, solving for X should give
 * 
 * X = |0.5|
 *     |1.0|
 *     |0.5|
 * 
 ********************************************/

int main() {
    float A[9] = {2.0, -1.0, 0.0, 0.0, 2.0, -1.0, 0.0, 0.0, 2.0};
    float B[3] = {0.0, 1.0, 0.0};
    float X[3]; // = ?
    int ipiv[3];
    int info;

    info = LAPACKE_ssysv(LAPACK_ROW_MAJOR, 'U', 3, 1, A, 3, ipiv, B, 1);

    printf("info = %d\n", info);

    printf("X = ");
    for (int i=0; i<3; i++) {
        printf("%f, ", B[i]);
    }
    printf("\n");

    printf("ipiv = ");
    for (int i=0; i<3; i++) {
        printf("%d, ", ipiv[i]);
    }
    printf("\n");

    printf("A = \n");
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            printf("%f, ", A[i+j*3]);
        }
        printf("\n");
    }
    printf("\n");

    return(0);
}