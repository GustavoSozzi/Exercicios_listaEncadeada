/*Faça um programa que leia um arquivo texto
contendo uma lista de compras. Cada linha do arquivo possui nome, quantidade e valor unitário do
produto. O programa então exibe o total da compra.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct{

    char nome[50];
    int quantidade;
    float valor_unit;

}Lista;

void recebe_compra(Lista lista[]){

    int i;
    float total = 0.0;

    for(i=0; i<3; i++){
        printf("\nNome %s\n", lista[i].nome);
        printf("\nquantidade %d\n", lista[i].quantidade);
        printf("\nvalor unit: %f\n", lista[i].valor_unit);

        total += lista[i].quantidade * lista[i].valor_unit;

    }

    printf("\nTotal da compra: %.2f\n", total);


}


int main(){

int i=0;

Lista lista[3];

FILE *arq = fopen("listacompras.txt", "r");

if(arq == NULL){
    printf("erro ao abrir arquivo");
    exit(1);
}

while(!feof(arq)){
    fscanf(arq, "%s", &lista[i].nome);
    fflush(stdin);

    fscanf(arq, "%d", &lista[i].quantidade);
    fflush(stdin);

    fscanf(arq, "%f", &lista[i].valor_unit);
    fflush(stdin);

    i++;
}

recebe_compra(lista);


return 0;
}
