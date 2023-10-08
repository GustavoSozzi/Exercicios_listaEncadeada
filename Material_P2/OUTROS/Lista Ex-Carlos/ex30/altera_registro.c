#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h> //para as funções logicas

#define TAM 100

typedef struct{
    int cod;
    char nome[TAM];
    char endereco[TAM];
    char fone[TAM];
}Registro;

void alterarRegistro(char *original, char *novo, int cod, Registro registro[]);

int main(){
      Registro registro[TAM];

      char arquivoOriginal[100];
      char arquivoNovo[100];
      int codigo;

      printf("Digite o nome do arquivo original: ");
      scanf("%s", arquivoOriginal);
      printf("Digite o nome do novo arquivo: ");
      scanf("%s", arquivoNovo);
      printf("Digite o codigo do registro a ser alterado: ");
      scanf("%d", &codigo);

      alterarRegistro(arquivoOriginal, arquivoNovo, codigo, registro);

    return 0;

}

void alterarRegistro(char *original, char *novo, int cod, Registro registro[]){

    FILE *arqOriginal = fopen(original, "r");
    FILE *arqNovo = fopen(novo, "w");
    bool alterouOk = false;
    int i=0;

    if(arqOriginal == NULL || arqNovo == NULL){
        printf("erro\n");
        exit(1);
    }

    while(fscanf(arqOriginal, "%d %s %s %s", &registro[i].cod, registro[i].nome, registro[i].endereco, registro[i].fone) == 4){
        if(registro[i].cod == cod){
            printf("\ndigite o novo endereço: ");
            scanf("%s", registro[i].endereco);
            alterouOk = 1;
        }
        i++;
    }

    for(int j=0; j<i; j++){
        fprintf(arqNovo, "%d %s %s %s\n", registro[j].cod, registro[j].nome, registro[j].endereco, registro[j].fone);
    }

    fclose(arqOriginal);
    fclose(arqNovo);

    if (!alterouOk) {
      printf("Nao foi encontrado registro com o codigo procurado.\n");
    }

}
