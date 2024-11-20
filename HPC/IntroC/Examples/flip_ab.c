#include <stdio.h>
#include <stdlib.h>

// passar parâmetros por referência
void troca(int *x, int *y) {
    // c recebe conteúdo do ponteiro x, ou seja
    // recebe o conteúdo do endereço armazenado no 
    // ponteiro x
    int c = *x;
    *x = *y; // * indica conteúdos 
    *y = c;
}

int main() {
    int a = 1;
    int b = 2;

    printf("a=%d, b=%d\n", a, b);
    troca(&a, &b); // recebe endereços
    printf("a=%d, b=%d\n", a, b);

    return(0);
}