/*
    Aula 194: Exercício 3

    3) Crie um programa que contenha um array de inteiros com 10 elementos. Imprima o elemento e o 
       endereço de cada posição do array.
*/

#include <stdio.h>
#include <stdlib.h>

int main(){

    int i, vet[10] = {0,1,2,3,4,5,6,7,8,9};

    for(i = 0; i < 10; i++)
        printf("Endereco: %p\tConteudo: %d\n", vet + i, *(vet + i));

    return 0;
}
