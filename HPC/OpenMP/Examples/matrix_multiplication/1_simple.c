#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void mat_mul(float *A, float *B, float *C, int n) {
    // multiply O(n^3)
    for (int l=0; l<n; l++) {
        for (int c=0; c<n; c++) {
            C[l+n*c] = 0.0;
            for (int k=0; k<n; k++) {
                C[l+n*c] += A[l+n*k] * B[k+n*c];
            }
        }
    }
}

int main() {
    clock_t t0, t1; // to measure time
    float *A, *B, *C;

    for (int n=3; n<500; n++) {
        // allocate matrices
        A = (float *) calloc(n*n, sizeof(float));
        B = (float *) calloc(n*n, sizeof(float));
        C = (float *) calloc(n*n, sizeof(float));

        // init matrices with random numbers
        for (int i=0; i<n*n; i++) {
            A[i] = (float) rand()/((float) RAND_MAX);
            B[i] = (float) rand()/((float) RAND_MAX);
        }

        // start clock
        t0 = clock();
        // call matrix multiplication
        mat_mul(A, B, C, n);
        // end clock
        t1 = clock();

        // print time
        printf("%d %lf\n", n, (double)(t1-t0)/(CLOCKS_PER_SEC));

        // free matrices
        free(A);
        free(B);
        free(C);
    }

    return(0);
}