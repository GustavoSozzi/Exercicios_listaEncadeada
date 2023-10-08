#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//programa que leia e mostre quantas linhas tem o arquivo tem

typedef struct
{
    int num;
    char nome[50];
}Arq;


void imprimir_arquivo(Arq prod[], int cont)
{
    int i;

    for(i=0; i<cont; i++){
        printf("\n%d", prod[i].num);
        printf("\n%s", prod[i].nome);
    }

}


int main()
{
    int linhas=0;
    int cont = 0;
    Arq prod[1000];
    FILE *arq = fopen("arquivo.txt", "r");

    if(arq == NULL)
    {
        printf("\nerro ao abrir arquivo");
        exit(1);
    }

     while(!feof(arq)){
        fscanf(arq, "%d", &prod[cont].num);
        fscanf(arq, "%[^\n]s", &prod[cont].nome);
        fflush(stdin);
        cont++;
    }

    imprimir_arquivo(prod, cont);

    return 0;
}
