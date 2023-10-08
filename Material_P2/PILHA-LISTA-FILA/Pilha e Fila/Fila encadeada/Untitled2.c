#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No
{
    int dado;
    struct No *prox;
} No;

typedef struct FILA
{
    No *ini;
    No *fim;
} FILA;

void enfilerar(int dado, FILA *f) //inserindo no final
{
    No *ptr = (No*)malloc(sizeof(No));
    if(ptr == NULL)
    {
        printf("\nerro de alocacao\n");
        return;
    }
    else
    {
        ptr->dado = dado;
        ptr->prox = NULL;

        if(f->ini == NULL) //se esta vazia
        {
            f->ini = ptr;
        }
        else //se a lista ja tem elementos, ira adicionar no final do no
        {
            f->fim->prox = ptr;
        }

        f->fim = ptr;
    }
}

int desenfileira(FILA *f) //retirando do começo
{
    No *ptr = f->ini; //recebe o inicio;
    int dado;

    if(ptr != NULL)
    {
        f->ini = ptr->prox;
        ptr->prox = NULL;
        dado = ptr->dado;
        free(ptr);
        if(f->ini == NULL)
        {
            f->fim = NULL;
        }
    }
    else
    {
        printf("fila vazia\n");
    }

    return dado;
}

void imprime(FILA *f)
{
    No *ptr = f->ini;

    if(ptr != NULL)
    {
        while(ptr!=NULL)
        {
            printf("\n%d ", ptr->dado);
            ptr = ptr->prox;
        }
    }
    else
    {
        printf("\nfila vazia\n");
    }
}

int main()
{
    FILA *f1 = (FILA*)malloc(sizeof(FILA));

    f1->ini = NULL;
    f1->fim = NULL;

    if(f1 == NULL)
    {
        printf("\nerro de alocação\n");
        exit(-1);
    }
    else
    {
        enfilerar(10, f1);
        enfilerar(20, f1);
        enfilerar(30, f1);
    }

    desenfileira(f1);

    imprime(f1);

}
