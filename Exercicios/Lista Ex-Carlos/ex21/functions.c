/*Usando o arquivo
de texto produzido no exercício anterior, faça um programa que leia esse arquivo e realize as seguintes
tarefas (cada tarefa deverá ser executada por uma função): a) listar a primeira palavra de cada linha
par do arquivo; b) listar a última palavra de cada linha do arquivo. Cada conjunto de palavras deverá
estar precedido por um cabeça-lho adequado. Lembre que uma linha pode ter de uma a várias palavras.
Apresente, ao final do processamento, o número de linhas lidas do arquivo.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

int main(){

FILE *arq = fopen("text_file.txt", "r");
char par[50];

if(arq == NULL){
    printf("ERRO\n");
    exit(1);
}

int NumLinha;

int linha, linha1;

listar_primeira_palavra(arq);
listar_ultima_palavra(arq);



}

void listar_primeira_palavra(FILE *fp) {
    char linha[MAX_LENGTH];

    printf("Primeira palavra de cada linha par:\n");
    int linha_num = 1;
    while (fgets(linha, MAX_LENGTH, fp) != NULL) {  //enquanto nao chegou ao fim do arquivo le linha por linha;
        if (linha_num % 2 == 0) {
            char *primeira_palavra = strtok(linha, " \n"); // dividindo a string conforme a linha num incrementa, utilizando como delimitador o espaço e o caractere de nova linha (' ' e '\n')
            printf("Linha %d: %s\n", linha_num, primeira_palavra);
        }
        linha_num++;
    }

    printf("\nNumero de linha usada: %d", linha_num);


}

void listar_ultima_palavra(FILE *fp) {
    char linha[MAX_LENGTH];

    printf("\nultima palavra de cada linha:\n");
    int linha_num = 1;
    while (fgets(linha, MAX_LENGTH, fp) != NULL) {
        char *ultima_palavra = strtok(linha, " \n");
        char *palavra_atual = ultima_palavra;
        while ((palavra_atual = strtok(NULL, " \n")) != NULL) {
            ultima_palavra = palavra_atual;
        }
        printf("Linha %d: %s\n", linha_num, ultima_palavra);
        linha_num++;
    }

    printf("\nNumero de linhas lidas: %d", linha_num);
}
