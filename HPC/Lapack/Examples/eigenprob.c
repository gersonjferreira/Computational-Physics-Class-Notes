#include <stdio.h>
#include <stdlib.h>
#include <lapacke.h>

/********************************************
 * example: H.psi = E.psi with SSTEV
 * 
 * H = | 2 -1  0|
 *     |-1  2 -1|
 *     | 0 -1  2|
 * 
 ********************************************/

int main() {
    float d[3] = {2.0, 2.0, 2.0};
    float e[2] = {-1.0, -1.0};
    float z[9];
    int info;

    info = LAPACKE_sstev(LAPACK_ROW_MAJOR, 'V', 3, d, e, z, 3);

    printf("info = %d\n", info);

    printf("E = ");
    for (int i=0; i<3; i++) {
        printf("%f, ", d[i]);
    }
    printf("\n");

    printf("V = \n");
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            printf("%f, ", z[i*3+j]);
        }
        printf("\n");
    }
    printf("\n");
    


    return(0);
}