#include <stdio.h>
#include <stdlib.h>
#include <math.h> // compilar com a opção -lm

int main() {
    float a = 0.1;
    float b = 3.0;
    float c = a*b;
    
    printf("a = %0.15f\n", a);
    printf("b = %0.15f\n", b);
    printf("c = %0.15f\n", c);

    // jamais faça if com equivalência de floats ou doubles
    if (c == 0.3) {
        printf("c vale 0.3\n");
    } else {
        printf("c não vale 0.3\n");
    }

    // o correto é assim: verificar se |c - 0.3| < número pequeno
    // aqui 1e-4 é 10 elevado a -4 e abs é a função módulo
    if (abs(c - 0.3) < 1e-4) {
        printf("c ta pertinho de 0.3\n");
    } else {
        printf("c não deve ser 0.3\n");
    }

    return(0);
}