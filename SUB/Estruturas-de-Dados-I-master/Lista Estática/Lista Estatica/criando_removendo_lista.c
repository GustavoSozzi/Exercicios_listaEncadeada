#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"


Lista *cria_lista(void){
    Lista *li;
    li = (Lista *)malloc(sizeof(struct Lista));
    if (li != NULL)
        li->qtd = 0;
    return li;
}

void libera_lista(Lista *li){
    free(li);
}

int tamanho_lista(Lista *li){
    if (li!=NULL)
        return li->qtd;
    else
        return (-1);
}

int lista_cheia(Lista *li){
    if (lista==NULL)
        return (-1);
    else
        return(li->qtd == MAX);
}
int lista_vazia(Lista *li){
    if (lista==NULL)
        return (-1);
    else
        return(li->qtd == 0);
}

}
