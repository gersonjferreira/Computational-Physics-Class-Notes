#include <stdio.h>
 
int main() {
    // progressão aritimética
    // 1 + 2 + 3 + ... + 100 = 5050
    int pa = 0;
    for (int i=1; i<=100; i++) {
        pa += i;
    }
    printf("soma pa = %d\n", pa);

    return(0);
}