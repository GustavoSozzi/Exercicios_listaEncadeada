#include <stdio.h>
#include <stdlib.h>

/*Declare um tipo registro nascido que contenha os seguintes dados: ID, nome, dia, mês,
ano, nome do pai, nome da mãe, sexo, telefone. Instancie um registro deste tipo. Crie
uma função para realizar leitura dos dados do teclado e preencha todos os campos com
os dados lidos. Crie também uma outra função que recebe como parâmetro um registro
do tipo nascido e salva o registro no arquivo reg_nascidos.txt (abra o arquivo no modo
anexo).*/

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


    Nascido nascidos[6];

    int i=0;

    FILE *arq = fopen("reg_nascidos.txt", "r");

    if(arq == NULL){
        printf("erro ao abrir arquivo\n");
    }

    while(!feof(arq)){
        fscanf(arq, "%d", &nascidos[i].id);
        fscanf(arq, "%s", &nascidos[i].nome);
        fscanf(arq, "%d", &nascidos[i].dia);
        fscanf(arq, "%d", &nascidos[i].mes);
        fscanf(arq, "%d", &nascidos[i].ano);
        fscanf(arq, "%s", &nascidos[i].NomePai);
        fscanf(arq, "%s", &nascidos[i].NomeMae);
        fscanf(arq, "%s", &nascidos[i].sexo);
        fscanf(arq, "%s", &nascidos[i].telefone);

        i++;
  }

  Recebe_Info(nascidos, arq);

}

void Recebe_Info(Nascido nascidos[], FILE *arq){

    int i;

    arq = fopen("apos1995.txt", "w");

    for(i=0; i<6; i++){
    if(nascidos[i].ano >= 1995){
            fprintf(arq,"%d\n", nascidos[i].id);
            fprintf(arq,"%s\n", nascidos[i].nome);
            fprintf(arq,"%d\n", nascidos[i].dia);
            fprintf(arq,"%d\n", nascidos[i].mes);
            fprintf(arq,"%d\n", nascidos[i].ano);
            fprintf(arq,"%s\n", nascidos[i].NomePai);
            fprintf(arq,"%s\n", nascidos[i].NomeMae);
            fprintf(arq,"%s\n", nascidos[i].sexo);
            fprintf(arq,"%s\n", nascidos[i].telefone);
    }

    }


}
