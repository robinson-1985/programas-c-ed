/*

    Aula 231: Como descobrir se uma expressão matemática está mal formada?

    3 * [(5 - 2) / 5]
    3 * (5 - 2) / 5] <-- ao testar com esta expressão o programa trava. Descobriu o motivo?
    
*/

# include <stdio.h>
# include <stdlib.h>

typedef struct no{
    char caracter;
    struct no *proximo;
}No;

No* empilhar(No *pilha, char valor){
    No *novo = malloc(sizeof(No));

    if(novo){
        novo->caracter = valor;
        novo->proximo = pilha;
        return novo;
    }
    else
        printf("\tErro ao alocar memoria!\n");
    return NULL;
}

No* desempilhar(No **pilha){
    No *remover = NULL;

    if(*pilha){
        remover = *pilha;
        *pilha = remover->proximo;
    }
    else
        printf("\tPilha vazia\n");
    return remover;
}

void imprimir(No *pilha){
    printf("\n\tPILHA\n");
    while(pilha){
        printf("\t%c\n", pilha->caracter);
        pilha = pilha->proximo;
    }
    printf("\tFIM PILHA\n\n");
}

int forma_par(char f, char d){
    switch(f){
    case ')':
        if(d == '(')
            return 1; // bem formada
        else
            return 0; // mal formada
        break;
    case ']':
        if(d == '[')
            return 1; // bem formada
        else
            return 0; // mal formada
        break;
    case '}':
        if(d == '{')
            return 1; // bem formada
        else
            return 0; // mal formada
        break;
    }
}

int identifica_formacao(char x[]){
    int i = 0;
    No *remover, *pilha = NULL;

    while(x[i] != '\0'){
        if(x[i] == '[' || x[i] == '(' || x[i] == '{'){
            pilha = empilhar(pilha, x[i]);
            imprimir(pilha);
        }
        else if(x[i] == ']' || x[i] == ')' || x[i] == '}'){
            remover = desempilhar(&pilha);
            if(remover){
                if(forma_par(x[i], remover->caracter) == 0){
                    printf("\tEXPRESSAO MAL FORMADA!\n");
                    return 1; // expressao está mal formada
                }
                free(remover);
            }
            else{
                printf("\tEXPRESSAO MAL FORMADA!\n");
                return 1; // expressao está mal formada
            }
        }
        i++;
    }
    imprimir(pilha);
    if(pilha){
        printf("\tExpressao mal formada!\n");
        return 1;
    }
    else{
        printf("\tEXPRESSAO BEM FORMADA!\n");
        return 0;
    }
}

int main(){
    char exp[50];

    printf("\tDigite um expressao: ");
    scanf("%49[^\n]", exp);
    printf("\nExpressao: %s\nRetorno: %d\n", exp, identifica_formacao(exp));
}
