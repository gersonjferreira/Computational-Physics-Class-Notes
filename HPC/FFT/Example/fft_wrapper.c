#include <stdio.h>
#include <stdlib.h>
#include <math.h> // compile with -lm
#include <complex.h>
#include <fftw3.h> // compile with -lfftw3

// alias for double complex types
typedef double _Complex dcomplex;

void fft_forward(int n, double *k, double *x, dcomplex *fx, dcomplex *fk, fftw_plan plan) {
    double theta, phi;
    double dx = x[1]-x[0];
    double x0 = x[0];
    double k0 = k[0];
    // fix phase of f(x) before applying FFT
    for (int j=0; j<n; j++) {
        // fix phase
        theta = k0*x[j];
        fx[j] *= cexp(-I*theta);
    }
    // execute the FFT plan f(x) -> f(k)
    fftw_execute(plan);
    // fix phase and norm on f(k)
    for (int j=0; j<n; j++) {
        phi = 2*M_PI*j*x0/(n*dx);
        fk[j] *= (dx/sqrt(2*M_PI))*cexp(-I*phi);
    }
}

void fft_backward(int n, double *k, double *x, dcomplex *fx, dcomplex *fk, fftw_plan plan) {
    double theta, phi;
    double dx = x[1]-x[0];
    double x0 = x[0];
    double k0 = k[0];
    // fix phase of f(k) before applying FFT
    for (int j=0; j<n; j++) {
        phi = 2*M_PI*j*x0/(n*dx);
        fk[j] *= cexp(I*phi);
    }
    // execute the FFT plan f(k) -> f(x)
    fftw_execute(plan);
    // fix phase and norm on f(x)
    for (int j=0; j<n; j++) {
        theta = k0*x[j];
        fx[j] *= (sqrt(2*M_PI)/(n*dx))*cexp(I*theta);
    }
}

int main() {
    int n;
    double *x, *k;
    dcomplex *fx, *fk;
    fftw_plan pfwd, pbwd;
    FILE *fp;
    // parametros
    double dk, k0, dx, x0;

    // alocar vetores
    n = 256;
    x = (double *) calloc(n, sizeof(double));
    k = (double *) calloc(n, sizeof(double));
    fx = (dcomplex *) calloc(n, sizeof(dcomplex));
    fk = (dcomplex *) calloc(n, sizeof(dcomplex));
    // alocar planos
    pfwd = fftw_plan_dft_1d(n, fx, fk, FFTW_FORWARD, FFTW_MEASURE);
    pbwd = fftw_plan_dft_1d(n, fk, fx, FFTW_BACKWARD, FFTW_MEASURE);

    // definindo x e k
    //
    // x = [-x0, x0), x_0 = -x0, x_n = +x0 = -x0+n*dx
    // dx = 2*x0/n
    x0 = 10.0;
    dx = 2*x0/n;
    //
    // k = [-pi/dx, pi/dx)
    // dk = 2*pi/(dx*n)
    k0 = -M_PI/dx;
    dk = 2*M_PI/(dx*n);
    //
    for (int j=0; j<n; j++) {
        x[j] = -x0 + j*dx;
        k[j] = k0 + j*dk;
    }

    // definindo f(x)
    for (int i=0; i<n; i++) {
        fx[i] = exp(-x[i]*x[i]/2.0);
    }

    // aplica fft f(x) -> f(k)
    // ja corrige phase e norma
    fft_forward(n, k, x, fx, fk, pfwd);

    // multiplicar f(k) por -ik para obter a derivada
    for (int j=0; j<n; j++) {
        fk[j] = I*k[j]*fk[j]*cexp(-I*5*k[j]);
    }
    
    // aplica fft f(k) -> f(x)
    // ja corrige phase e norma
    fft_backward(n, k, x, fx, fk, pbwd);

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

