/*
            Aula 192: Exercício 1
    1) Escreva um procedimento que receba um vetor inteiro, seu tamanho e os endereços
    de duas variáveis inteiras, menor e maior, salve nestas variáveis o menor e o maior
    valor do vetor.

*/

#include <stdio.h>
#include <stdlib.h>

void maiorMenor(int *vet, int tam, int *menor, int *maior){
    int i;
    *menor = *vet;
    *maior = *vet;
    for(i = 1; i < tam; i++){
        if(*menor > *(vet + i))
            *menor = *(vet + i);
        if(*maior < *(vet + i))
            *maior = *(vet + i);
    }
}

int main(){
    int menor, maior, v[10] = {45,89,69,23,14,75,2,45,100,58};

    printf("Menor: %d\tMaior: %d\n", menor, maior);
    maiorMenor(v, 10, &menor, &maior);
    printf("Menor: %d\tMaior: %d\n", menor, maior);

    return 0;
}
