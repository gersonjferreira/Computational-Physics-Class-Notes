#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

// my computer: sudo lshw -C memory
// cache L1 = 128 kB, fits 128*1024/8 = 16384 floats = 8192 doubles
// cache L2 = 512 kB
// cache L3 = 4 MB

int main() {
    int n;
    double *a, *b, *c;
    // using sys/time.h to track time
    double secs;
    struct timeval start, stop;
    // save to file
    FILE *fp; // files are pointers

    // init seed for random numbers
    gettimeofday(&start, NULL);
    srand(start.tv_sec);

    // open file to write
    fp = fopen("prod_matrices.dat", "a");

    for (n=1000; n<=2000; n+=1000) {
        // allocate matrices of size n
        a = (double *) calloc(n*n, sizeof(double));
        b = (double *) calloc(n*n, sizeof(double));
        c = (double *) calloc(n*n, sizeof(double));

        // set values
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                a[i+n*j] = rand() % 100;
                b[i+n*j] = rand() % 100;
            }
        }

        // c = a*b
        gettimeofday(&start, NULL);
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                c[i+n*j] = 0.0;
                for (int k=0; k<n; k++) {
                    c[i+n*j] += a[i+n*k] * b[k+n*j];
                }
            }
        }
        gettimeofday(&stop, NULL);
        secs = (double)(stop.tv_usec - start.tv_usec) / 1000000 + (double)(stop.tv_sec - start.tv_sec);

        // print to screen
        printf("%d %f\n", n, secs);
        // print to file
        fprintf(fp, "%d %f\n", n, secs);
        fflush(fp); // save now!

        // free pointers before next allocation
        free(a);
        free(b);
        free(c);
    }

    // close file
    fclose(fp);

    return(0);
}