#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"

int remove_inicio(Lista *li){
    if(li == NULL || lista_cheia(li))
        return 0;

    int i;
    for(i = 0; i< li->qtd - 1; i++)
        li->dados[i] = li->dados[i+1];

    li->qtd--;
    return 1;

}
int remove_lista_elemento(Lista *li, int mat){
    if(li == NULL || lista_cheia(li))
        return 0;

    int k, i = 0;
    while(i < li->qtd && li->dados[i].matricula!=al.matricula)
        i++;
    if(i+1 == li->qtd)
        return 0;
    for(k = i; k < li->qtd - 1; k--)
        li->dados[k] = li->dados[k+1];
    li->qtd--;
    return 1;

}
