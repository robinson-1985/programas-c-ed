# include <stdio.h>
# include <stdlib.h>

// Aula 191: o que é ponteiro para ponteiro?

int main(){

    int A = 100, *B, **C; // quando utilizo ** é o ponteiro para ponteiro

    B = &A; // B vai apontar para o endereço da variável A
    C = &B; // c vai apontar para o endereço da variável B

    printf("Endereço de A: %p\tConteudo de A: %d\n", &A, A); 
    printf("Endereço de B: %p\tConteudo de B: %p\n", &B,B); 
    printf("Conteúdo apontado por B: %d\n", *B);
    printf("Endereço de C: %p\tConteudo de C: %d\n", &C,C);
    printf("Conteúdo apontado por C: %d\n", **C);  


    return 0;
}