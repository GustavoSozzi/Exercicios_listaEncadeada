#include <stdio.h>
#include <stdlib.h>

int main(){

int *array;
int n;

printf("tamanho vetor: ");
scanf("%d", &n);

array = (int *) malloc(n*sizeof(int));

if(!array){
    printf("\nnao foi possivel alocar a memoria\n");
    return 1;
}

free(array)



}
