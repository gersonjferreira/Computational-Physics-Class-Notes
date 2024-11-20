#include <stdio.h>

int main() {
    int a = 0;
    int b = 1;
    int c;
    
    printf("%d\n", a);
    printf("%d\n", b);
    for (int i=2; i<=10; i++) {
        c = b + a;
        a = b;
        b = c;
        printf("%d\n", c);
    }

    return(0);
}