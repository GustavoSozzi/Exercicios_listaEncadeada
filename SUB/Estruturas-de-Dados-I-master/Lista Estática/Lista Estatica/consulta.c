#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"

int consulta_lista_posicao(Lista *li, int pos, struct aluno *al){
    if(li == NULL || pos<=0 || pos > li->qtd)
        return 0;
    *al = li->dados[pos-1];
    return 1;
}

int consulta_lista_conteudo(Lista *li, int mat, struct aluno *al){
    if(li == NULL)
        return 0;

    int k, i = 0;
    while(i < li->qtd && li->dados[i].matricula!=al.matricula)
        i++;

    if(i+1 == li->qtd)
        return 0;

    *al = li->dados[i];

    return 1;
}
