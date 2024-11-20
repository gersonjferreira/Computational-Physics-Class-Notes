#include <stdio.h>
#include <stdlib.h>
#include <lapack.h>
#include <time.h>

int main() {
    float *d;
    float *e;
    float *z;
    int info;
    clock_t t0, t1;
    // lapack
    char jobz = 'V';
    int lwork, liwork;
    float *work;
    int *iwork;
    //

    for (int n=3; n<=2500; n+=100) {
        d = (float *) calloc(n, sizeof(float));
        e = (float *) calloc(n-1, sizeof(float));
        z = (float *) calloc(n*n, sizeof(float));

        for (int i=0; i<n-1; i++) {
            d[i] = 2.0;
            e[i] = -1.0;
        }
        d[n-1] = 2;

        //
        lwork = 1 + 4*n + n*n;
        liwork = 3+5*n;
        work = (float *) calloc(lwork, sizeof(float));
        iwork = (int *) calloc(liwork, sizeof(int));
        //

        t0 = clock();
        LAPACK_sstevd(&jobz, &n, d, e, z, &n, work, &lwork, iwork, &liwork, &info);
        t1 = clock();

        printf("%d %lf\n", n, (double) (t1-t0)/CLOCKS_PER_SEC);
        fflush(stdout);

        free(iwork);
        free(work);
        free(d);
        free(e);
        free(z);
    }

    return(0);
}