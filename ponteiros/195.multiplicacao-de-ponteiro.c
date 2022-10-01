/*
    Aula 195: Exercício 4

    4) Considere a seguinte declaração: int A, *B, **C, ***D. Escreva um programa que leia a variável 
    A e calcule e exiba o dobro, o triplo e o quádruplo desse valor utilizando apenas os ponteiros B, 
    C e D. O ponteiro B deve ser usada para calcular o dobro, C o triplo e D o quádruplo.
*/

#include <stdio.h>
#include <stdlib.h>

int main(){

    int A, *B, **C, ***D;

    printf("Digite um valor: ");
    scanf("%d", &A);

    B = &A;
    C = &B;
    D = &C;

    printf("O dobro de %d e: %d\n", A, 2 * *B);
    printf("O triplo de %d e: %d\n", A, 3 * **C);
    printf("O quadruplo de %d e: %d\n", A, 4 * ***D);

    return 0;
}
