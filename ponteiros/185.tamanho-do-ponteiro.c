/*

          Aula 185: De quanta memória um ponteiro precisa?

          Código escrito por Wagner Gaspar
          Maior de 2021
*/

#include <stdio.h>
#include <stdlib.h>

int main(){

    int *ponteiro1;
    char *ponteiro2;
    float *ponteiro3;

    printf("Tamanho: %d\n", sizeof(ponteiro1));
    printf("Tamanho: %d\n", sizeof(ponteiro2));
    printf("Tamanho: %d\n", sizeof(ponteiro3));

    return 0;
}
