#include <stdio.h>
#include <stdlib.h>

/*

          Aula 184: O que é e como criar um ponteiro?

          Código escrito por Wagner Gaspar
          Maior de 2021
*/

int main(){

    char letra = 'f';
    char *p;

    p = &letra;

    printf("Valor de letra: %c\n", letra);
    printf("Endereco de letra: %p\n", &letra);
    printf("Valor de p: %p\n", p);
    printf("Endereco de p: %p\n", &p);
    printf("Valor apontado por p: %c\n", *p);

    return 0;
}
