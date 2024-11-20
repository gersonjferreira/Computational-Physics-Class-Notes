#include <stdio.h>
#include <stdlib.h>

int fibonacci(int n) {
    // seu código aqui
}

// sequencia Fibonacci para referência
// 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584
int main() {
    int f;

    f = fibonacci(2);
    printf("O segundo número da sequência de Fibonacci é %d\n", f);

    f = fibonacci(5);
    printf("O quinto número da sequência de Fibonacci é %d\n", f);

    f = fibonacci(10);
    printf("O décimo número da sequência de Fibonacci é %d\n", f);

    return(0);
}