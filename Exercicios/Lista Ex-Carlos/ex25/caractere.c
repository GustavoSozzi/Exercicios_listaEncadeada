#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1000

int main(){

    FILE *arq;
    char nome_arquivo[MAX_LEN];
    char frase[MAX_LEN];
    int tamanho;
    int linhas=0, i;

    printf("\nNome do arquivo: ");
    scanf("%s", nome_arquivo);
    fflush(stdin);

    printf("\nDigite a frase a ser gravada: ");
    fgets(frase, MAX_LEN, stdin);
    fflush(stdin);

    tamanho = strlen(frase); //contando quantos caracteres tem a frase e retorna tamanho

    arq = fopen(nome_arquivo, "w");

    if(arq == NULL){
        printf("\nErro ao abrir o arquivo");
        exit(1);
    }

    for(i=0; i<tamanho;i++){
        fputc(frase[i], arq); //gravando caractere por caractere
    }

    fclose(arq);

    arq = fopen(nome_arquivo, "r");

    if(arq == NULL){
        printf("\nErro ao abrir o arquivo");
        exit(1);
    }

    while(fgets(frase, MAX_LEN, arq) != NULL){
        linhas ++;
    }

    printf("\nForam lidas: %d linhas", linhas);

    fclose(arq);

    return 0;

}


