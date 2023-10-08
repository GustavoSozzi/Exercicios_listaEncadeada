#include <stdio.h>
#include <stdlib.h>
/*Fa�a um programa que receba do usu�rio um arquivo texto e mostre na tela quantas linhas esse arquivo
possui.*/

int main(){

    FILE *arq = fopen("arquivo.txt", "r");

    if(arq==NULL){
        printf("erro\n");
        exit(1);
    }

    int cont=0;
    char linha[500];

    while(fgets(linha, 500, arq) != NULL){ //quando o final do arquivo for alcan�ado
        cont++;
    }

    printf("Esse arquivo tem: %d linhas\n", cont);

    fclose(arq);
    return 0;
}
