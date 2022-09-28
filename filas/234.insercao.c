/* 
Aula 235: Inserção em uma fila.

FIFO - First-In, First-Out - Primeiro a Entrar, Primeiro a Sair

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

int main(){
    No *fila = NULL; /* aí aqui recebemos o endereço da variável */

    return 0;
}
