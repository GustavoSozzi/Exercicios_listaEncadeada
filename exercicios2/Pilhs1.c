#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct NO
{
    int dado;
    struct NO *prox;
} NO;

typedef struct PILHA
{
    NO *topo;

} PILHA;

void empilha(PILHA *p, int dado)
{
    NO *ptr = (NO*)malloc(sizeof(NO)); //inicializando pilha

    if(ptr==NULL)
    {
        printf("\nerro ao alocar de nó");
        return;
    }
    else //------inserindo na pilha
    {
        ptr->dado = dado; //recebendo o dado;
        ptr->prox = p->topo; //proxima celula vai apontar para o topo
        p->topo = ptr; //o topo vai recer o ptr(dado);
    }
}

int desempilha(PILHA *p)
{
    NO *ptr = p->topo;
    int dado;
    if(ptr == NULL)
    {
        printf("\nPILHA VAZIA");
        return;
    }
    else
    {
        p->topo = ptr->prox;
        ptr->prox = NULL; //desligando o topo
        dado = ptr->dado;
        free(ptr);
        return dado;
    }
}

void imprimir(PILHA *p)
{
    NO *ptr = p->topo;
    if(ptr == NULL)
    {
        printf("Pilha vazia\n");
        return;
    }
    while(ptr!=NULL)
    {
        printf("\n%d", ptr->dado);
        ptr = ptr->prox;
    }

    printf("\n");
}

int main()
{
    PILHA *p1 = (PILHA*)malloc(sizeof(PILHA));
    p1->topo = NULL; // inicializa o topo da pilha como NULL

        empilha(p1, 8);
        empilha(p1, 7);
        empilha(p1, 6);
        empilha(p1, 5);
        empilha(p1, 4);

}
