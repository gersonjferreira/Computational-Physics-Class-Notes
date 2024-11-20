#include <stdio.h>
#include <stdlib.h>

int main() {
    int n = 3; // nxn

    int *msimples = (int *) calloc(n*n, sizeof(int));
    for (int l=0; l<n; l++) {
        for (int c=0; c<n; c++) {
            msimples[c + n*l] = c;
        }
    }

    for (int l=0; l<n; l++) {
        for (int c=0; c<n; c++) {
            printf("%d ", msimples[c+n*l]);
        }
        printf("\n");
    }

    return(0);
}