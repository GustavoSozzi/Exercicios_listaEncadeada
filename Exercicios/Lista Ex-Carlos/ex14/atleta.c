#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nome[50];
    char esporte[30];
    int idade;
    float altura;
}Atleta;

int main(){

Atleta atleta[5];

int i;

FILE *arq = fopen("atleta.bin", "wb"); //escrevendo um arquivo binario

if(arq == NULL){
    exit(1);
}

for(i=0; i<5; i++){
    printf("NOME: \n");
    scanf("%s", &atleta[i].nome);
    fflush(stdin);

    printf("ESPORTE: \n");
    scanf("%s", &atleta[i].esporte);
    fflush(stdin);

    printf("IDADE: \n");
    scanf("%d", &atleta[i].idade);

    printf("ALTURA: \n");
    scanf("%f", &atleta[i].altura);
}

    fwrite(atleta, sizeof(Atleta), 5, arq);

    fclose(arq);
    printf("Os dados dos atletas foram salvos em atletas.bin\n");
    return 0;


}
