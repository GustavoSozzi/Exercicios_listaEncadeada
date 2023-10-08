#include <stdio.h>
#include <stdlib.h>

//Descreve veiculos de montadora

typedef struct{
    char marca[50];
    int ano_fabric;
    char cor[15];
    float preco;
}Carro;


int main(){

    Carro Carro; //atribuindo struct

    printf("Marca: ");
    scanf("%[^\n]s",Carro.marca);
    //fgets(Carro.marca, 49, stdin); //

    printf("Ano fabricacao: ");
    scanf("%d", &Carro.ano_fabric);
    scanf("%*c"); //limpando buffer

    printf("Cor: ");
    scanf("%[^\n]s", Carro.cor);
    //fgets(Carro.cor, 14, stdin);

    printf("Preco: ");
    scanf("%f", &Carro.preco);

    /******************************Saida de dados*/

    printf("\nMarca: %s", Carro.marca);
    printf("\nAno fabricacao: %d", Carro.ano_fabric);
    printf("\nCor: %s", Carro.cor);
    printf("\nPreco: %f", Carro.preco);

    system("pause");

    return 0;

}
