#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//implementando uma fila estatica em C

#define TAM 3

typedef struct fila
{
    int dados[TAM];
    int fim;
} T_fILA;

void inicializarFila(T_fILA *f)
{
    int i;
    for(i=0; i<TAM; i++)
    {
        f->dados[i]=0;
    }

    f->fim = 0;
}

void enfileira(int dado, T_fILA *f)
{
    if(f->fim == TAM)
    {
        printf("fila esta cheia\n");
    }
    else
    {
        f->dados[f->fim] = dado;
        f->fim++;
    }

}

int desenfileira(T_fILA *f)
{
    int dado, i;
    if(f->fim == 0)
    {
        printf("fila esta vazia\n");
        return;
    }
    else
    {
        dado = f->dados[0];
        for(i=0; i<f->fim; i++)
        {
            f->dados[i] = f->dados[i];
        }

        f->fim--;
        return dado;
    }

}

void imprimeFila(T_fILA *f)
{
    int i;
    printf("imprimindo a fila\n");
    for(i=0; i<f->fim; i++)
    {
        printf("%d ", f->dados[i]);
    }

    printf("\n\n");

}
int main()
{

    T_fILA f1;

    inicializarFila(&f1);

    enfileira(10, &f1);
    enfileira(20, &f1);
    enfileira(30, &f1);

    imprimeFila(&f1);

    desenfileira(&f1);

    imprimeFila(&f1);
}
