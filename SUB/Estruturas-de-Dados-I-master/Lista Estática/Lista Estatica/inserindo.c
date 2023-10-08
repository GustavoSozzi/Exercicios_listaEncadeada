#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"

//Inserção
int insercao_no_final(Lista *li, struct aluno al){
    if(li == NULL || lista_cheia(li))
        return 0;
    li->dados[li->qtd] = al;
    li->qtd++;
    return 1;
}

int insercao_no_inicio(Lista *li, struct aluno al){
    if(li == NULL || lista_cheia(li))
        return 0;
    int i;
    for(i = 0; i < li->qtd; i++)
        li->dados[i+1] = li->dados[i];
    li->dados[0] = al;
    li->qtd++;
    return 1;

}
int insercao_ordenada(Lista *li, struct aluno al){
    if(li == NULL || lista_cheia(li))
        return 0;
    int k, i = 0;
    while(i < li->qtd && li->dados[i].matricula < al.matricula)
        i++;
    for(k = i; k < li->qtd; k++)
        li->dados[k+1] = li->dados[k];
    li->dados[i] = al;
    li->qtd++;
    return 1;
}
