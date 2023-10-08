#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXTAM 100

typedef struct
{
    int item[MAXTAM];
    int topo;
} Tpilha;

void Tpilha_inicia(Tpilha *p)
{
    p->topo = -1;
}

int tPilha_vazia(Tpilha *p)
{
    if(p->topo == -1){
        return 1;
    }
    else{
        return 0;
    }
}

int TPilha_cheia(Tpilha *p)
{
    if(p->topo == MAXTAM-1)
    {
        return 1;
    }
    else{
        return 0;
    }
}

void Tpilha_insere(Tpilha *p, int x)
{
    if(TPilha_cheia(p)==1)
    {
        printf("\noverflow\n");
    }
    else
    {
        p->topo++;
        p->item[p->topo] = x;
    }
}

int Tpilha_retira(Tpilha *p)
{
    int aux;
    if(tPilha_vazia(p)==1)
    {
        printf("\nunderflow\n");
    }
    else
    {
        aux = p->item[p->topo];
        p->topo--;

        return aux;
    }
}

int main()
{
    Tpilha *p = (Tpilha*)malloc(sizeof(Tpilha));

    Tpilha_inicia(p);
    int aux;

    Tpilha_insere(p, 1);
    Tpilha_insere(p, 2);
    Tpilha_insere(p, 3);

    aux = Tpilha_retira(p);
    printf("\nSAIU: %d ", aux);
    aux = Tpilha_retira(p);
    printf("\nSAIU: %d ", aux);

    free(p); // Libera a memória alocada
    return 0;
}
