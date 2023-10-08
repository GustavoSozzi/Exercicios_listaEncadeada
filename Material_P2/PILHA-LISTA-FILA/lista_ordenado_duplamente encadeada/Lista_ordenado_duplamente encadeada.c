#include <stdio.h>
#include <stdlib.h>

/*Altere a lista anterior para que seja uma lista duplamente encadeada*/
//lista duplamente encadeada

typedef struct no
{
    int num;
    struct no *ant;
    struct no *prox;
} Celula;

void inserir_ordenado(Celula *cabeca);
void imprimir(Celula *cabeca);


int main()
{
    int op;
    Celula *cabeca = (Celula*)malloc(sizeof(Celula));

    inicia_cabeca(cabeca);

    while(op != 3)
    {
        printf("\n1-inserir\n2-imprimir\n3-sair\n");
        scanf("%d", &op);

        if(op == 1)
        {
            inserir_ordenado(cabeca);
        }
        else if(op == 2)
        {
            imprimir(cabeca);
        }
    }


}

void inserir_ordenado(Celula *cabeca)
{

    Celula *novo = (Celula*)malloc(sizeof(Celula));
    Celula *anterior = cabeca;
    Celula *atual = cabeca->prox;

    if(novo==NULL)
    {
        printf("\nerro ao alocar memoria\n");
        exit(1);
    }

    printf("\nNovo elemento\n");
    scanf("%d", &novo->num);

    novo->ant = NULL;
    novo->prox = NULL;

    while(atual!= NULL && atual->num < novo->num)
    {
        anterior = atual;
        atual = atual->prox;
    }

    if (anterior == cabeca)   // inserir no início
    {
        cabeca->prox = novo;
        novo->ant = cabeca;
    }
    else     // inserir no meio ou no final
    {
        anterior->prox = novo;
        novo->ant = anterior;
    }

    if (atual != NULL)   // inserir no meio
    {
        atual->ant = novo;
        novo->prox = atual;
    }
    else     // inserir no final
    {
        anterior->prox = novo;
        novo->ant = anterior;
    }

}

void imprimir(Celula *cabeca)
{

    Celula *tmp;

    if(cabeca->prox==NULL)
    {
        printf("lista vazia");
        exit(1);
    }

    tmp = cabeca->prox; //recebe a 1 celula depois da cabeça

    while(tmp!=NULL) //enquanto nao chegou no final apontando para null
    {
        printf("\n%d", tmp->num);
        tmp = tmp->prox; //anda as celulas com prox;
    }

    printf("\n\n");


}

void inicia_cabeca(Celula *cabeca)
{
    cabeca->prox = NULL;
}
