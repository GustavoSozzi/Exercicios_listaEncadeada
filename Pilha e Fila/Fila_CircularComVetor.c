#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//implemente uma fila circular de inteiros utilizando vetores, devera ser implementado as operacoes enfileirar e desenfileirar

#define N 5

//S POSICAO INICIAL
//T POSICAO FINAL

int desenfileire(int *vet, int *s)
{

    int x;

    x = vet[*s];
    (*s)++;

    if(s == N+1) //se esta cheio
    {
        (*s) = 1; //adiciona no comeco
    }

    return x;
}

void enfileira(int *vet, int y, int *t)
{

    vet[*t] = y;
    (*t)++;

    if(*t = N+1) //se esta cheio
    {
        t=1; //volta e adiciona no comeco
    }

}
int main()
{
    int vet[N];
    int s = 0, t = 0, qtd = 0;

    enfileira(vet, 5, &t);
    enfileira(vet, 6, &t);
    enfileira(vet, 7, &t);
    enfileira(vet, 8, &t);

    printf("%d\n", desenfileire(vet, &s));
    return 0;
}
