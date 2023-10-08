#include <stdio.h>
#include <stdlib.h>

typedef struct no{

    int valor;
    struct no *proximo;

}No;

no* inserir(no *inicio, int x){

    no *novo = malloc(sizeof(No));
    if(novo){
        novo->valor = x;
        novo->proximo = inicio;
    }

    return novo;

}
int main(){

No x;

x.valor = 50;

return 0;

}

/*void DescobrirValores(int *v, int *me, int *ma, int tam){

    int i;

    *me = v[0];
    *ma = v[0];

    for(i=1; i < tam; i++){
        if(v[i] < *me)
            *me = v[i];

        if(v[i] > *ma)
            *ma = v[i];


    }
}


int main(){

int valor=10, vet[] = {50,10,250,500,25}, maior, menor;
int *p;

DescobrirValores(vet, &menor, &maior, 5);


printf("Menor: %d\nMaior: %d", menor,maior);


return 0;

}*/
