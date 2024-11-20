#include <stdio.h>
#include <stdlib.h>
#include <lapacke.h>
#include <time.h>

int main() {
    double *d;
    double *e;
    double *z;
    int info;
    clock_t t0, t1;
    FILE *fp;

    for (int n=3; n<=2500; n+=100) {
        d = (double *) calloc(n, sizeof(double));
        e = (double *) calloc(n-1, sizeof(double));
        z = (double *) calloc(n*n, sizeof(double));

        for (int i=0; i<n-1; i++) {
            d[i] = 2.0;
            e[i] = -1.0;
        }
        d[n-1] = 2.0;

        t0 = clock();
        info = LAPACKE_dstevd(LAPACK_ROW_MAJOR, 'V', n, d, e, z, n);
        t1 = clock();

        printf("%d %lf\n", n, (double) (t1-t0)/CLOCKS_PER_SEC);
        fflush(stdout);

        if (n == 2403) {
            fp = fopen("evecs.dat", "w");

            // Aij = a[i*lda + j] ROW MAJOR
            for (int i=0; i<n; i++) {
                fprintf(fp, "%lf %lf %lf\n", z[i*n+0], z[i*n+1], z[i*n+2]);
            }

            fclose(fp);
        }


        free(d);
        free(e);
        free(z);
    }

    return(0);
}