/* 
Aula 235: Inserção em uma fila.

FIFO - First-In, First-Out - Primeiro a Entrar, Primeiro a Sair

237 - Como remover um elemento em uma estrutura de dados do tipo fila?

*/

# include <stdio.h>
# include <stdlib.h>

typedef struct no{
    int valor;
    struct no *proximo;
}No;

void inserir_na_fila(No **fila, int num){
    No *aux, *novo = malloc(sizeof(No));
    if (novo){
        novo->valor = num;
        novo->proximo = NULL;
        if(*fila == NULL) /* Se esse teste for verdadeiro, então eu jogo a comparação no main*/ 
            *fila = novo; /* se a fila estiver vazia recebemos o conteúdo que o nó vai apontar*/
            else{ /* Porém, ela só será vazia na primeira vez e na segunda será False, então precisamos 
            fazer um nó auxiliar para rodar o programa (aux), e receber o conteúdo desse ponteiro*/
                aux = *fila; /* aí precisamos percorrer a fila até chegar ao final*/
                while(aux ->proximo) /* enquanto isto for verdadeiro, o meu ponteiro vai caminhar na fila*/
                    aux = aux -> proximo; /* quando der False significa que o aux é o último nó da 
                    fila */
                aux ->proximo = novo;/*assim finalizamos o processo de inserir um elemento na nossa fila*/
            }
         
            
    }
    else
        printf("\nErro ao alocar memória. \n");
}

No* remover_da_fila(No **fila) {
    No *remover = NULL;

    if(*fila){ /*Verificar se a minha fila está vazia*/
        remover = *fila;
        *fila = remover->proximo; /*A fila tem que apontar para o próximo, ou seja, ela diminui em 1 unidade*/
    }
    else /* se for False significa que a fila está vazia*/
        printf("\tFila vazia\n");
    return remover; /* se tiver alguém na fila ela aponta e retorna o nó, se não ele foi iniciado com NULL
    e o ponteiro é NULL*/
}

int main(){
    No *fila = NULL; /* aí aqui recebemos o endereço da variável */

    return 0;
}
