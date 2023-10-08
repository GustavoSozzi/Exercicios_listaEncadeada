#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Considerando um
arquivo de texto já gravado, escreva uma função lógica que receba esse arquivo como parâmetro e
verifique se, no texto, aparece a palavra ‘SENHA’*/


#define MAX_LEN 1000

int main() {
    FILE *arq;
    char nome_arquivo[MAX_LEN];

    printf("\nNome do arquivo: ");
    scanf("%s", nome_arquivo);

    arq = fopen(nome_arquivo, "r");
    if (arq == NULL) {
        printf("\nErro ao abrir o arquivo");
        return 1;
    }

    Procura_Senha(arq);

    return 0;
}

int Procura_Senha(FILE *arq){

     char frase[MAX_LEN];
     int achou = 0;

     while (fgets(frase, MAX_LEN, arq) != NULL) {
        if (strstr(frase, "SENHA") != NULL){ //busca por ocorrencia em uma determinada substring
            achou = 1;
            break;
        }
    }

    if (achou) {
        printf("\nA palavra 'SENHA' foi encontrada no texto.");
    } else {
        printf("\nA palavra 'SENHA' não foi encontrada no texto.");
    }

    fclose(arq);

    return 0;


}



