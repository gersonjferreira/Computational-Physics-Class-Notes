#include <stdio.h>
#include <omp.h> // compilar usando -fopenmp

int main() {
    int n;

    // by default uses env OMP_NUM_THREADS
    omp_set_num_threads(4);

    #pragma omp parallel
    {
        n = omp_get_thread_num();
        printf("Hello from world %d!\n", n);
    }
   
    return(0);
}