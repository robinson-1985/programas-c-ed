/*
    Aulas 243: Lista Simplesmente Encadeada
    Como inserir no início da lista?
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no *proximo;
}No;

// procedimento para inserir no início
void inserir_no_inicio(No **lista, int num) {
    No *novo = malloc(sizeof(No));

    if(novo){
        novo->valor = num;
        novo->proximo = lista; // o novo nó está apontando para o início da lista. 
        *lista = novo;
    }
    else
        printf("Erro ao alocar memória!\n");
}

int main(){

    return 0;
}
