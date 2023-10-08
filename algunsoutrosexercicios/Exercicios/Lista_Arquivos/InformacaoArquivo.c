#include <stdio.h>
#include <stdlib.h>

/*Faça agora o processo inverso. Declare um registro e suponha que todas as informações do
registro estejam armazenadas no arquivo. Crie uma função que receba como parâmetro
um registro do tipo nascido e leia os dados do arquivo reg_nascidos.txt e preencha
todos os campos do registro.*/


typedef struct{
   int id;
   char nome[50];
   int dia;
   int mes;
   int ano;
   char NomePai[50];
   char NomeMae[50];
   char sexo[10];
   char telefone[30];
}Nascido;



int main(){

    Nascido nascido[4];

    Recebe_Struct(nascido);


}

void Recebe_Struct(Nascido nascido[]){

    int i;

    FILE *arq = fopen("oi.txt", "r");

    if(arq == NULL){
        printf("NAO FOI POSSIVEL ABRIR O ARQUIVO\n");
        exit(1);
    }
    else{
        while(!feof(arq)){ //enquanto nao chegar no final do arquivo
            fscanf(arq, "%d", nascido[i].id);
            fscanf(arq, "%s", nascido[i].nome);
            fscanf(arq, "%d", nascido[i].dia);
            fscanf(arq, "%d", nascido[i].mes);
            fscanf(arq, "%d", nascido[i].ano);
            fscanf(arq, "%s", nascido[i].NomePai);
            fscanf(arq, "%s", nascido[i].NomeMae);
            fscanf(arq, "%s", nascido[i].sexo);
            fscanf(arq, "%s", nascido[i].telefone);
        }

    }

}
