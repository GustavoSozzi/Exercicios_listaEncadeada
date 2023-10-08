#include <stdio.h>
#include <stdlib.h>

typedef struct _lista_{
    int dado;
    struct _lista_ *prox;
}listaencadeada;

listaencadeada *uniao_de_listas(listaencadeada *A, listaencadeada *B){
    listaencadeada *C = NULL, *aux;
    aux = A;
    while (aux->prox!=NULL){
        aux = aux->prox;
    }
    aux->prox = B;
    C = A;
    return C;
}
void insere(int valor, listaencadeada **li){
    listaencadeada *novo = (listaencadeada *)malloc(sizeof(listaencadeada));
    if (novo == NULL) return 0;
    novo->dado = valor;
    novo->prox = (*li);
    (*li) = novo;
}
void imprime(listaencadeada *C){
    listaencadeada *aux;
    aux = C;
    while (aux != NULL){
        printf("%d \n", aux->dado);
        aux = aux->prox;
    }
}

int main(){
    listaencadeada *A = NULL, *B = NULL;
    int i, valor = 0;
    for (i = 0; i < 3; i++){
        insere(valor, &A);
        valor++;
        insere(valor, &B);
        valor++;
    }
    listaencadeada *C = NULL;
    imprime(A);
    printf("\n------------\n");
    C = uniao_de_listas(A, B);

    imprime(B);
    printf("\n------------\n");
    imprime(C);
    return 0;
}
