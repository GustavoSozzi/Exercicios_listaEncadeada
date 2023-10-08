
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// fila com lista encadeada com cabeça

typedef struct fila
{
    int num;
    struct fila *prox;
} FILA;

typedef struct
{
    FILA *ini;
    FILA *fim;
} PIVO;

FILA *novoNo() // retorna o novo nó para enfileirar, também característico de cabeça;
{
    FILA *novo = (FILA*)malloc(sizeof(FILA));
    novo->prox = NULL;

    printf("\nnovo valor: \n");
    scanf("%d", &novo->num);

    return novo;
}

void enfileirar(PIVO *pivo)
{
    FILA *novo = novoNo(); // recebe o retorno do ponteiro novo nó;

    if(pivo->ini == NULL) // se esta vazia a lista
    {
        pivo->ini = novo;
        pivo->fim = novo;
    }
    else
    {
        pivo->fim->prox = novo; // atualizando ultimo elemento aponta para novo; conectando o ultimo nó ao novo nó;
        pivo->fim = novo; // atualizando o ponteiro para ser o ultimo nó;
    }
}

int desenfileirar(PIVO *pivo)
{
    if(pivo->ini == NULL)
    {
        printf("\nunderflow vazio\n");
        return -1; // alterei a função para retornar um valor int em vez de void, para facilitar o uso em outros locais
    }
    else
    {
        FILA *aux = NULL;

        aux = pivo->ini;
        pivo->ini = pivo->ini->prox; // atualizando o ponteiro para o segundo nó, tornando-o o primeiro
        int num = aux->num; // salva o valor do nó que será desenfileirado

        free(aux); // libera o espaço de memória do nó removido
        return num; // retorna o valor do primeiro nó da fila
    }
}

void imprimir(PIVO *pivo)
{
    FILA *aux = pivo->ini;

    while(aux!=NULL)
    {
        printf("\n%d", aux->num);
        aux = aux->prox; // atualizando a variável aux para o próximo elemento da lista
    }
}

void liberar_fila(FILA *fila)
{
    if(fila!=NULL)
    {
        liberar_fila(fila->prox);
        free(fila);
    }
}

int main()
{
    PIVO pivo;
    pivo.ini = NULL;
    pivo.fim = NULL;
    int i;

    for(i=0; i<10; i++)
    {
        enfileirar(&pivo);
    }

    int num_desenfileirado = desenfileirar(&pivo);
    printf("O valor desenfileirado foi: %d", num_desenfileirado);

    imprimir(&pivo);
    return 0;
}
