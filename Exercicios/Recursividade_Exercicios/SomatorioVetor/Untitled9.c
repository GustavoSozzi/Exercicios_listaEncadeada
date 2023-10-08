#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float soma_vetor(float vet[], int tam);


int main(){

    float vet[10];
    int i;

    for(i=0; i<10; i++){
        printf("\nvalor: %d\n", i+1);
        scanf("%f", &vet[i]);
    }

    printf("\nCONTEUDO DO VETOR");

    for(i=0; i<10; i++){
        printf("\nvalor: %f", vet[i]);
    }

    printf("\nresultado soma: %f", soma_vetor(vet, 10));
}

float soma_vetor(float vet[], int tam){

    if(tam==0){
        return 0;
    }

     return vet[tam-1] + soma_vetor(vet, tam-1);
}

