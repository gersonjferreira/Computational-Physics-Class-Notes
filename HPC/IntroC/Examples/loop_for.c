#include <stdio.h>

int main() {

    // i++ equiv: i=i+1
    // s += i equiv: s = s + i
    // s = 0 + 1 + 2 + 3 + ... + 10
    int s = 0;
    for (int i=0; i<=10; i++) {
        s += i;
    }
    printf("s=%d\n", s);

    // p = 1*2*3*4*5*6*...*10
    int p = 1;
    for (int i=1; i<=10; i++) {
        p *= i;
    }
    printf("p=%d\n", p);


    return(0);
}