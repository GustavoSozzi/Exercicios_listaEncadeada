
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// fila com lista encadeada com cabe�a

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

FILA *novoNo() // retorna o novo n� para enfileirar, tamb�m caracter�stico de cabe�a;
{
    FILA *novo = (FILA*)malloc(sizeof(FILA));
    novo->prox = NULL;

    printf("\nnovo valor: \n");
    scanf("%d", &novo->num);

    return novo;
}

void enfileirar(PIVO *pivo)
{
    FILA *novo = novoNo(); // recebe o retorno do ponteiro novo n�;

    if(pivo->ini == NULL) // se esta vazia a lista
    {
        pivo->ini = novo;
        pivo->fim = novo;
    }
    else
    {
        pivo->fim->prox = novo; // atualizando ultimo elemento aponta para novo; conectando o ultimo n� ao novo n�;
        pivo->fim = novo; // atualizando o ponteiro para ser o ultimo n�;
    }
}

int desenfileirar(PIVO *pivo)
{
    if(pivo->ini == NULL)
    {
        printf("\nunderflow vazio\n");
        return -1; // alterei a fun��o para retornar um valor int em vez de void, para facilitar o uso em outros locais
    }
    else
    {
        FILA *aux = NULL;

        aux = pivo->ini;
        pivo->ini = pivo->ini->prox; // atualizando o ponteiro para o segundo n�, tornando-o o primeiro
        int num = aux->num; // salva o valor do n� que ser� desenfileirado

        free(aux); // libera o espa�o de mem�ria do n� removido
        return num; // retorna o valor do primeiro n� da fila
    }
}

void imprimir(PIVO *pivo)
{
    FILA *aux = pivo->ini;

    while(aux!=NULL)
    {
        printf("\n%d", aux->num);
        aux = aux->prox; // atualizando a vari�vel aux para o pr�ximo elemento da lista
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
