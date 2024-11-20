#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int mc_count(int N) {
    float x,y;
    int nin;

    // init seed with current time
    unsigned int seed = time(0);

    nin = 0; // number of points found inside circle
    for (int i=0; i<N; i++) {
        x = (float) rand_r(&seed)/RAND_MAX; // between 0.0 and 1.0
        y = (float) rand_r(&seed)/RAND_MAX; // between 0.0 and 1.0
        nin += (x*x + y*y < 1); // true = 1, false = 0
    }
    return(nin);
}

int main() {
    int Ntot = 1000000000;
    int Nins;
    clock_t t0, t1; // to measure time
    double dt; // total time
    
    // start to measure time
    t0 = clock();
    // run Ntot samples
    Nins = mc_count(Ntot);
    // stop time
    t1 = clock();
    dt = (double) (t1-t0)/CLOCKS_PER_SEC;

    // print results
    printf("Pi = %f\n", 4.0*Nins/Ntot);
    printf(" t = %f s\n", dt);

    return(0);
}
