#include <stdio.h>
#include <stdlib.h>
#include <math.h> // compile with -lm
#include <complex.h>
#include <fftw3.h> // compile with -lfftw3

// alias for double complex types
typedef double _Complex dcomplex;

int main() {
    int n;
    double *x, *k;
    dcomplex *fx, *fk;
    fftw_plan pfwd, pbwd;
    FILE *fp;
    double phi, theta;
    // parametros
    double dk, dx, x0 = 10.0;

    // alocar vetores
    n = 256;
    x = (double *) calloc(n, sizeof(double));
    k = (double *) calloc(n, sizeof(double));
    fx = (dcomplex *) calloc(n, sizeof(dcomplex));
    fk = (dcomplex *) calloc(n, sizeof(dcomplex));
    // alocar planos
    pfwd = fftw_plan_dft_1d(n, fx, fk, FFTW_FORWARD, FFTW_MEASURE);
    pbwd = fftw_plan_dft_1d(n, fk, fx, FFTW_BACKWARD, FFTW_MEASURE);

    // definindo x e f(x)
    // x = [-x0, x0), x_0 = -x0, x_n = +x0 = -x0+n*dx
    // dx = 2*x0/n
    dx = 2*x0/n;
    dk = 2*M_PI/(dx*n);
    for (int i=0; i<n; i++) {
        x[i] = -x0 + i*dx;
        fx[i] = exp(-x[i]*x[i]/2.0);
        // fix phase
        theta = (-M_PI/dx)*x[i];
        fx[i] *= cexp(-I*theta);
        // k = [-pi/dx, pi/dx)
        // dk = 2*pi/(dx*n)
        k[i] = -M_PI/dx + i*dk;
    }

    // aplica fft f(x) -> f(k)
    fftw_execute(pfwd);
    // fix norm
    for (int j=0; j<n; j++) {
        phi = 2*M_PI*j*(-x0)/(n*dx);
        fk[j] *= (dx/sqrt(2*M_PI))*cexp(-I*phi);
    }

    // multiplicar f(k) por -ik
    for (int j=0; j<n; j++) {
        fk[j] = I*k[j]*fk[j];
        phi = 2*M_PI*j*(-x0)/(n*dx);
        fk[j] *= cexp(I*phi);
    }

    // aplica fft f(k) -> f(x)
    fftw_execute(pbwd);
    // fix phase
    for (int j=0; j<n; j++) {
        theta = (-M_PI/dx)*x[j];
        fx[j] *= (sqrt(2*M_PI)/(n*dx))*cexp(I*theta);
    }

    // salvar num arquivo
    fp = fopen("derivada.dat", "w");
    for (int i=0; i<n; i++) {
        fprintf(fp, "%lf %lf %lf\n", x[i], creal(fx[i]), cimag(fx[i]));
    }
    fclose(fp);

    // free
    free(x);
    free(fx);
    free(fk);
    fftw_destroy_plan(pfwd);
    fftw_destroy_plan(pbwd);
    return(0);
}

