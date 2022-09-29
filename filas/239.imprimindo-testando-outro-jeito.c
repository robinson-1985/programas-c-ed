/*
Aula 239: Imprimindo e testando - Segunda versão

FIFO - First-In, First-Out - Primeiro a Entrar, Primeiro a Sair

237 - Como remover um elemento em uma estrutura de dados do tipo fila?

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int valor;
    struct no *proximo;
} No;

typedef struct
{
    No *prim;
    No *fim;
    int tam;
} Fila;

void criar_fila(Fila *fila)
{
    fila->prim = NULL;
    fila->fim = NULL;
    fila->tam = 0;
}

void inserir_na_fila(Fila *fila, int num)
{
    No *aux, *novo = malloc(sizeof(No));
    if (novo)
    {
        novo->valor = num;
        novo->proximo = NULL;
        if (fila->prim == NULL) // se a fila estiver vazia
        {
            fila->prim = novo;
            fila->fim = novo;
        }

        else // se a fila não estiver vazia
        {
            fila->fim->proximo = novo; /* o próximo do ponteiro fim aponta para o novo nó*/
            fila->fim = novo; // o ponteiro fim aponta para o novo nó
        }
        fila->tam++;/* essa linha será executada tanto no if quanto no else, por isto, ela fica fora*/
    }
    else
        printf("\nErro ao alocar memória. \n");
}

No *remover_da_fila(Fila *fila)
{
    No *remover = NULL;

    if (fila->prim)
    { /*Verificar se a minha fila está vazia*/
        remover = fila->prim;
        fila->prim= remover->proximo; 
        fila->tam--;/*A fila tem que apontar para o próximo, ou seja, ela 
        diminui em 1 unidade*/
    }
    else /* se for False significa que a fila está vazia*/
        printf("\tFila vazia\n");
    return remover; /* se tiver alguém na fila ela aponta e retorna o nó, se não ele foi iniciado com NULL
    e o ponteiro é NULL*/
}

void imprimir(Fila *fila)
{ 
    No *aux = fila->prim;
    /*Não preciso de dois nós, basta um ponteiro para acessar a fila aqui*/
    printf("\t------- FILA --------\n\t");
    while(aux)
    {
        printf("%d", aux->valor);
        aux = aux->proximo; /*Em algum momento vai chegar no valor nulo e finalizar*/
    }

    printf("\n\t------- FIM DA FILA --------\n");
}

int main()
{
    No *r;
    Fila fila;
    int opcao, valor;

    criar_fila(&fila);

    do
    {
        printf("\t0 - Sair\n\t1 - Inserir\n\t2 - Remover\n\t3 - Imprimir\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("Digite um valor: ");
            scanf("%d", &valor);
            inserir_na_fila(&fila, valor);
            break;
        case 2:
            r = remover_da_fila(&fila);
            if (r)
            { /* aqui ocorre o processo de remoção*/
                printf("Removido: %d\n", r->valor);
                free(r); /*liberando espaço da memória do r*/
            }
            break;
        case 3:
            imprimir(&fila);
            break;
        default:
            if (opcao != 0)
                printf("\nOpcao inválida!\n");
        }
    } while (opcao != 0);

    return 0;
}
