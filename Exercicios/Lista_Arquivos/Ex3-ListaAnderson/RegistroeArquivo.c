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

Nascido Preenche_Registro(){

    Nascido bb;

    printf("\nEntre com a id do nascido: \n");
    scanf("%d", &bb.id);
    scanf("%*c");

    printf("Nome do recem nascido: ");
    scanf("%[^\n]s",bb.nome);
    scanf("%*c");  //limpando buffer do teclado, para n dar erro em entrada de dados

    printf("Dia nascimento: ");
    scanf("%d", &bb.dia);

    printf("Mes nascimento: ");
    scanf("%d", &bb.mes);

    printf("Ano nascimento: ");
    scanf("%d", &bb.ano);
    fflush(stdin);


    printf("Nome do pai: ");
    scanf("%[^\n]s", bb.NomePai);
    scanf("%*c");

    printf("Nome da mae: ");
    scanf("%[^\n]s",bb.NomeMae);
    scanf("%*c");

    printf("Sexo: ");
    scanf("%s", bb.sexo);
    scanf("%*c");

    printf("Telefone: ");
    scanf("%s", bb.telefone);
    scanf("%*c");

   return bb;

}

void Recebe_regitro(Nascido bebe){

   FILE *arq = fopen("reg_nascidos.txt", "w");

   if(arq == NULL){
        printf("Não foi possivel abrir o arquivo\n");
   }
   else{
        fprintf(arq,"\nNome: %s", bebe.nome);
        fprintf(arq,"\nAno nasc: %d", bebe.ano);
        fprintf(arq, "\nMes nasc %d", bebe.mes);
        fprintf(arq, "\nDia nasc: %d",bebe.dia);
        fprintf(arq,  "\nSexo: %s", bebe.sexo);
        fprintf(arq,"\nNome mae: %s", bebe.NomeMae);
        fprintf(arq, "\nNome pai: %s",bebe.NomePai);
        fprintf(arq, "\nTelefone: %s",bebe.telefone);

   }

}


int main(){

    Nascido bebe = Preenche_Registro();
    Recebe_regitro(bebe);

    printf(" id: %d", bebe.id);
}
