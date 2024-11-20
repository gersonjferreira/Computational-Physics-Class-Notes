#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h> // compile with "-fopenmp" and use "export OMP_NUM_THREADS=4"

int mc_count(int N) {
    float x=0, y=0;
    int nin=0;  // number of points found inside circle
    
    // init seed with current time
    int this_thread = omp_get_thread_num();
    int total_threads = omp_get_num_threads();
    unsigned int seed = time(0) + this_thread + total_threads;

    for (int i=0; i<N; i++) {
        x = (float) rand_r(&seed)/RAND_MAX; // between 0.0 and 1.0
        y = (float) rand_r(&seed)/RAND_MAX; // between 0.0 and 1.0
        nin += (x*x + y*y < 1); // true = 1, false = 0
    }
    return(nin);
}

int main() {
    int Ntot = 1000000000;
    int Nsplit = 10;
    int Nins;
    clock_t t0, t1; // to measure time
    double dt; // total time
    
    // start to measure time
    t0 = clock();
    
    Nins = 0;
    #pragma omp parallel for reduction(+:Nins)
    for (int i=0; i<Nsplit; i++) {
        Nins += mc_count(Ntot/Nsplit);
    }   
    
    // stop time
    t1 = clock();
    dt = (double) (t1-t0)/CLOCKS_PER_SEC;

    // print results
    printf("Pi = %f\n", 4.0*Nins/Ntot);
    printf(" t = %f s\n", dt);

    return(0);
}
