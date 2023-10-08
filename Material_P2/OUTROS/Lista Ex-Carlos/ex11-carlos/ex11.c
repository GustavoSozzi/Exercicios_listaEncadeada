#include <stdio.h>
#include <stdlib.h>

/*Escreva uma função que receba um vetor e
seu tamanho como parâmetros e salve-a em um arquivo texto de nome “vetor.txt”. Cada valor do vetor
deve ser salvo em uma linha do arquivo.*/

int main(){

int i, vet[500], tam;

printf("TAMANHO DO VETOR: ");
scanf("%d", &tam);

for(i=0; i<tam; i++){
    printf("ELEMENTO %d", i);
    scanf("%d", &vet[i]);
}

recebe_vetor(vet, tam);


}

void recebe_vetor(int vet[], int tam){

int i;
FILE *arq = fopen("vetor.txt", "w");

if(arq == NULL){
    exit(1);
}

for(i=0; i<tam; i++){
fprintf(arq, "%d\n", vet[i]);
}


}
