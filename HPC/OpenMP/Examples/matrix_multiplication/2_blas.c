#include <stdio.h>
#include <stdlib.h>
#include <cblas.h>
#include <time.h>

// cblas do not include on their cblas.h, but it is implement
// so we need to declare as extern
// can also be set with env OMP_NUM_THREADS=n
extern void openblas_set_num_threads(int);

void mat_mul(float *A, float *B, float *C, int n) {
    cblas_sgemm(CblasColMajor, CblasNoTrans, CblasNoTrans, n, n, n, 1, A, n, B, n, 0, C, n);
}

int main() {
    clock_t t0, t1; // to measure time
    float *A, *B, *C;

    // for small matrices, 1 thread is enough
    openblas_set_num_threads(1);

    for (int n=3; n<2000; n++) {
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