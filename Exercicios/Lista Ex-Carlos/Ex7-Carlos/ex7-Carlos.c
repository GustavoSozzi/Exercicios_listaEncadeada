/*Elabore um programa no qual o usuário informe
o nome de um arquivo texto e uma palavra, e o programa informe o número de vezes que aquela palavra
aparece dentro do arquivo.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ContaOcorrencias(FILE *arq, char *procura){

        char conteudo[500];
       int cont=0;
    char *delimiters = " ,.-;!?";
           while (!feof(arq)) {
        if (fgets(conteudo, 500, arq) != NULL) {
            int tamanho = strcspn(conteudo, "\n");
            memset(conteudo + tamanho, '\0', 1);
            char *ocorrencia = strstr(conteudo, procura);
            while (ocorrencia != NULL) {
                cont++;
                ocorrencia = strstr(ocorrencia + 1, procura);
            }
        }
    }

    return cont;



}

int main(){

    FILE *arq;
    char leitor[500];
    char procura[500];

    printf("Nome do arquivo: ");
    scanf("%499s",leitor);
    fflush(stdin);

    arq = fopen(leitor, "r");
    if(arq == NULL){
        printf("\nErro ao abrir arquivo");
        exit(1);
    }

    printf("Buscar palavra de repetido no arquivo: ");
    scanf("%499s",procura);
    fflush(stdin);

    int ocorrencias = ContaOcorrencias(arq, procura);

    printf("A palavra %s ocorre %d vezes", procura, ocorrencias);
    fclose(arq);
    return 0;
}
