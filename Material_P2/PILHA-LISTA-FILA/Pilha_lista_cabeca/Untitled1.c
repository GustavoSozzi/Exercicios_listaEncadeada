#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//pilha na lista encadeada com celula cabeca

//pilha cheia == tam-1;

typedef struct pessoa
{
    int codigo;
    char nome[100];
    struct pessoa *prox;
} Celula;

void empilhar(Celula *celula)
{
    Celula *novo = (Celula*)malloc(sizeof(Celula));

    if(novo==NULL)
    {
        printf("\nerro ao alocar");
        exit(1);
    }

    printf("\nDigite o novo codigo codigo: ");
    scanf("%d", &novo->codigo);
    fflush(stdin);

    novo->prox = NULL;

    printf("\ndigite o nome: \n");
    scanf("%[^\n]s", novo->nome);

    Celula *tmp = celula; //neste codigo nao foi feito celula->prox para que entre no while, pois iniciamente tmp ira apontar para null, no caso lista vazia;

    while(tmp->prox != NULL)
    {
        tmp = tmp->prox;
    }

    tmp->prox = novo; //adiciona ao final da lista;

    printf("\nelemento empilhado com sucesso\n");

}

void desempilhar(Celula *celula)
{
    if(celula->prox == NULL) //verificando se esta vazia a pilha
    {
        printf("\npilha vazia");
    }

    Celula *atual = celula->prox; //recebe o primeiro elemento da cabe�a
    Celula *ant = celula;

    while(atual->prox != NULL)
    {
        ant = atual;
        atual = atual->prox;
    }

    ant->prox = atual->prox; //anterior ira apontar para o penultimo
    //atual apontando para o ultimo elemento da lista antes da desempilhacao

    printf("Removido-> %d - %s\n", atual->codigo, atual->nome);

    if(ant == celula && ant->prox == NULL) // se removeu o �ltimo elemento, atualiza a cabe�a da lista
    {
        celula->prox = NULL;
    }

    free(atual);
}

void imprimir(Celula *celula)
{
    if(celula->prox == NULL)
    {
        printf("\npilha vazia\n");
    }

    Celula *aux = celula->prox;

    while(aux!=NULL)
    {
        printf("\n%d-%s ", aux->codigo, aux->nome);
        aux = aux->prox;
    }


}

void liberar(Celula *celula)
{
    Celula *aux = celula->prox;

    while(aux!=NULL)
    {
        free(aux);
        aux = aux->prox;
    }
}


int main()
{
    Celula *celula = (Celula*)malloc(sizeof(Celula));
    celula->prox = NULL;

    int op=0;

    if(celula == NULL)
    {
        printf("\nerro ao alocar memoria");
        exit(1);
    }

    while(op!=4)
    {
        printf("\n1-empilhar\n2-desempilhar\n3-imprimir\n4-sair\n");
        scanf("%d", &op);

        if(op == 1)
        {
            empilhar(celula);
        }
        else if(op == 2)
        {
            desempilhar(celula);
        }
        else if(op == 3)
        {
            imprimir(celula);
        }
    }

    liberar(celula);
}

