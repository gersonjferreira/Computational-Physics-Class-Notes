#include <stdio.h>
#include <stdlib.h>

int main() {
    // s1 é var. normal
    // se é ponteiro, armazena endereços
    char s1 = 'g'; // s1 recebe conteúdo 'g'
    char *s2 = &s1; // s2 recebe endereço de s1

    printf("s1 = %c\n", s1);
    *s2 = 'h'; // no endereço salvo em s2, atribua 'h'
    printf("s1 = %c\n", s1);

    return(0);
}