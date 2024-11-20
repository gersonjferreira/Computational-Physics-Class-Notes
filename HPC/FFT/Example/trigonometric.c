#include <stdio.h>
#include <stdlib.h>
#include <math.h> // compile with -lm
#include <complex.h>
#include <fftw3.h> // compile with -lfftw3

typedef double _Complex dcomplex;

int main() {
    int n;
    dcomplex *fx, *fk;
    double xj, L, dx, k, k0, phi, nrm;
    fftw_plan plan;
    FILE *fp;

    // parameters
    n = 1000;
    L = 2*M_PI*200;
    dx = L/n;
    k0 = -M_PI/dx;

    // prepare fftw
    fx = (dcomplex *) calloc(n, sizeof(dcomplex));
    fk = (dcomplex *) calloc(n, sizeof(dcomplex));
    plan = fftw_plan_dft_1d(n, fx, fk, FFTW_FORWARD, FFTW_MEASURE);

    // prepare f(x) = sin(x)
    for (int j=0; j<n; j++) {
        xj = 0 + j*dx; // a=0
        phi = k0*xj;
        nrm = dx/sqrt(2*M_PI);
        fx[j] = nrm*cexp(-I*phi)*sin(xj); // q=1
    }
    
    // call the transform
    fftw_execute(plan);

    // print results
    fp = fopen("trigonometric.dat", "w");
    for (int j=0; j<n; j++) {
        k = k0 + 2*M_PI*j/L;
        fprintf(fp, "%lf %lf %lf\n", k, creal(fk[j]), cimag(fk[j]));
    }
    fclose(fp);

    free(fx);
    free(fk);
    return(0);
}

