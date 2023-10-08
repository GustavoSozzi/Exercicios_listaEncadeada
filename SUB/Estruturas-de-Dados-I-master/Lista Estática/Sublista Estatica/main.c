#include <stdio.h>
#include <stdlib.h>

#define MAX 6

typedef struct _INFO{
    char nome[20];
    int idade;
}info;
typedef struct _LISTA{
    int qtd;
    info dados[MAX];
}lista;

void criar_lista(lista **Li);
void sublista(int tam, int pos, lista *Li, lista **Li1);
void imprimir_lista(lista *Li, lista *Li1);
void destruir_lista(lista **Li);

int main(){
    lista *Li = NULL;
    lista *Li1 = NULL;
    criar_lista(&Li);
    criar_lista(&Li1);

    int i, pos, tam;
    for(i = 0; i < MAX; i++){
        printf("\nInforme o nome: ");
        fflush(stdin);
        fgets(Li->dados[i].nome, 20, stdin);
        printf("\nInforme a idade: ");
        scanf("%d", &Li->dados[i].idade);
        Li->qtd++;
    }
    printf("Informe o tamanho da sublista: ");
    scanf("%d", &tam);
    printf("Informe a posicao que inicia a sublista: ");
    scanf("%d", &pos);

    sublista(tam, pos, Li, &Li1);
    system("cls");
    imprimir_lista(Li, Li1);
    free(Li1);
    free(Li);


    return 0;
}
void criar_lista(lista **Li){
    *Li = (lista *)malloc(sizeof(lista));
    (*Li)->qtd = 0;
}

void sublista(int tam, int pos, lista *Li, lista **Li1){
    int i, k = 0;
    for(i = pos-1; i < pos+tam-1; i++){
        (*Li1)->dados[k] = Li->dados[i];
        (*Li1)->qtd++;
        k++;
    }
}

void imprimir_lista(lista *Li, lista *Li1){
    int i;
    printf("\tLista\n");
    for(i = 0; i < Li->qtd; i++){
        printf("->Nome %d: %s\n", i+1, Li->dados[i].nome);
        printf("  Idade: %d\n", Li->dados[i].idade);
    }
    printf("\n------------------------------\n");
    printf("\tSubLista\n");
    for(i = 0; i < Li1->qtd; i++){
        printf("->Nome %d: %s\n", i+1, Li1->dados[i].nome);
        printf("  Idade: %d\n", Li1->dados[i].idade);
    }
}

