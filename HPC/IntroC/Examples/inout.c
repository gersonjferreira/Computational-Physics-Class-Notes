#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    float x;
    FILE *arq;

    arq = fopen("inout.dat", "w");

    n = 200;
    for (int i=0; i<n; i++) {
        x = i*i/(n-1.0);
        // print to screen
        //printf("%d %f\n", i, x);
        // print to file
        fprintf(arq, "%d %f\n", i, x);
        //fflush(arq); // save now!
    }

    fclose(arq);
    
    return(0);
}