#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Considere uma lista encadeada de inteiros. Implemente uma função que receba uma lista
encadeada e imprima todos os elementos da lista.*/

//celula é o No cabeca;

typedef struct no
{
    int codigo;
    struct no *prox;
} Celula;

void inicia(Celula *celula) //iniciando o no cabeca
{
    celula->prox=NULL; //iniciando no cabeca;
}

void inserir_inicio(Celula *celula)
{

    Celula *novo = (Celula*)malloc(sizeof(Celula)); //alocando memoria para um novo no;

    if(novo==NULL)
    {
        printf("\nerro ao alocar memoria\n");
        exit(1);
    }

    printf("Novo elemento: \n");
    scanf("%d", &novo->codigo);

    Celula *oldhead = celula->prox; //recebe o primeiro elemento da lista; oldhead(antiga cabeça);
    /*apontamos a cabeça da lista para nosso novo nó*/

    celula->prox = novo; //aponta para o novo
    novo->prox = oldhead; //apontamos nosso novo nó para o nó antigo
}

void inserir_fim(Celula *celula)  //recebendo a cabeca;
{
    Celula *novo = (Celula*)malloc(sizeof(Celula)); //alocando memoria retornando como ponteiro

    if(novo==NULL)
    {
        printf("\nerro ao alocar memoria");
        exit(1);
    }

    printf("Novo elemento: \n"); //inserindo o novo elemento
    scanf("%d", &novo->codigo);

    novo->prox = NULL;  //apontar para null pq novo sera o ultimo no

    if(celula->prox==NULL) //se a lista estiver vazia;
    {
        printf("\nMemoria vazia\n");
        celula->prox=novo; //aponta para o "novo" no
    }
    else
    {
        Celula *tmp = celula->prox; //apontando para o inicio da lista, ou seja a cabeca

        while(tmp->prox!=NULL)
        {
            tmp = tmp->prox;

        }

        tmp->prox = novo; //nao precisa ser alocada pois apenas aponta


    }


}

void exibir(Celula *celula)
{

    if(celula->prox==NULL)
    {
        printf("lista vazia");
        exit(1);
    }
    else
    {

        Celula *tmp;

        tmp = celula->prox;

        while(tmp!=NULL)
        {
            printf("\n%d", tmp->codigo);
            tmp = tmp->prox;
        }

        printf("\n\n");
    }

}



int main()
{

    Celula *celula = (Celula*)malloc(sizeof(Celula)); //alocando memoria e retornando tipo ponteiro
    int op;

    if(celula==NULL)
    {
        printf("SEM MEMORIA DISPONIVEL");
        exit(1);
    }

    inicia(celula);

    while(op!=4)
    {

        printf("Escola a opcao\n1-Inserir Inicio\n2-Inserir final\n3-imprimir\n");
        scanf("%d", &op);

        if(op==1)
        {
            inserir_inicio(celula); //nao precisa do &celula porque ja tem cabeca com ponteiro
        }
        else if(op==2)
        {
            inserir_fim(celula);
        }
        else if(op==3)
        {
            exibir(celula);
        }

    }

}


