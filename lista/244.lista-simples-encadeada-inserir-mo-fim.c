/*
    Aulas 244: Lista Simplesmente Encadeada
    Como inserir no fim da lista?
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

// procedimento para inserir no fim da lista
void inserir_no_fim(No **lista, int num) {
    No *aux, *novo = malloc(sizeof(No));

    if(novo){
        novo->valor = num;
        novo->proximo = NULL;

        // é o primeiro?
        if(*lista == NULL)
            *lista = novo;
        else{
            aux = *lista;
            while(aux->proximo)
                aux = aux->proximo;
            aux->proximo = novo;
        }
        
    }
    else
        printf("Erro ao alocar memória! \n");
}
int main(){

    return 0;
}
