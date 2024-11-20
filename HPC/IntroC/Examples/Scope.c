#include <stdio.h>

const int x = 10; // global

int test(int s) {
    int n = x*s;
    printf("n (test) is %d\n", n);
    printf("x (test) is %d\n", x);
    return(n);
}

int main() {
    int n = 5;
    printf("x (main) is %d\n", x);
    test(10);

    printf("x (main) is %d\n", x);
    test(10);

    return(0);
}