#include <stdio.h>
#include <stdlib.h>
#include <string.h> //iremos utilizar para ordenacao dos nomes

#define TAM 3


typedef struct{
    char nome[30];
    float notas[TAM];
    float media[TAM];
}Notas;

int main(){

int i, j, op;
int soma;
char busca[50];

Notas N[TAM];

for(i=0; i<TAM; i++){
    printf("Nome: ");
    scanf("%[^\n]s", N[i].nome);
    scanf("%*c");
    soma=0;
    for(j=0; j<TAM; j++){
        printf("notas: ");
        scanf("%f", &N[i].notas[j]);
        scanf("%*c");
    }
}

//while(op != 4){

printf("\nEscolha as opcoes\n1-Classificacao\n2-Pesquisar Aluno \n3-Apresentar todos os aprovados e reprovados\n4-Sair: \n");
scanf("%d", &op);
scanf("%*c");

switch (op)
{

case 1:
    for(i=0; i<TAM;i++){
        printf("\nNome: %s", N[i].nome);
    for(j=0; j<TAM; j++){
        printf("\nNota: %f", N[i].notas[j]);
}

    }
    break;
case 2:

    printf("Nome da busca: ");
    scanf("%[^\n]s", N[]);


}





}









/*printf("Entre com o nome para buscaa: ");
    scanf("%[^\n]s", busca);
    scanf("%*c");
    for(i=0; i<TAM; i++){
        if(strcmp(busca, N[i].nome)==0);
        printf("%s", N[pos].nome);

        printf("Media de: %f", N[i].media[]);

        break;
    }*/






