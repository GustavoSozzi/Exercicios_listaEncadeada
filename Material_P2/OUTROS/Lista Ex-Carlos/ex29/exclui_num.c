#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Escrever um procedimento para
excluir um valor de um arquivo de inteiros, gerando um novo arquivo sem esse valor. O acesso ao
arquivo deverá ser puramente sequencial.*/

int main(){

    FILE *arq_entrada = fopen("entrada.txt", "r");
    FILE *arq_saida = fopen("saida.txt", "w");
    int valor;

    if(arq_entrada == NULL){
        printf("erro\n");
        exit(1);
    }

    if(arq_saida == NULL){
         printf("erro\n");
         exit(1);
    }

    printf("Valor a ser excluido do arquivo: ");
    scanf("%d", &valor);

    Exclui_valor(arq_entrada, arq_saida, valor);

    return 0;
}

void Exclui_valor(FILE *entrada, FILE *saida, int valor){

    int num;
    while(!feof(entrada)){ //enquanto nao chegou no final do arquivo
        fscanf(entrada, "%d", &num);
        if(num !=valor){
            fprintf(saida, "%d\n", num);
        }
    }

}


