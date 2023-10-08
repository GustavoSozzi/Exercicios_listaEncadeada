/*Faça um programa no qual o usuário informa o nome do arquivo e uma palavra, e retorne o número de
vezes que aquela palavra aparece no arquivo*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 50

int main() {
    char nome_arquivo[50], palavra[MAX_WORD_LENGTH];
    FILE *arquivo;
    int ocorrencias = 0;

    // Lê o nome do arquivo
    printf("Digite o nome do arquivo: ");
    scanf("%s", nome_arquivo);

    // Lê a palavra a ser buscada
    printf("Digite a palavra a ser buscada: ");
    scanf("%s", palavra);

    // Abre o arquivo em modo de leitura
    arquivo = fopen(nome_arquivo, "r");

    // Verifica se o arquivo foi aberto com sucesso
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo %s\n", nome_arquivo);
        exit(1);
    }

    // Lê cada palavra do arquivo e conta as ocorrências da palavra buscada
    char buffer[MAX_WORD_LENGTH];
    while (fscanf(arquivo, "%s", buffer) == 1) {
        if (strcmp(buffer, palavra) == 0) {
            ocorrencias++;
        }
    }

    // Fecha o arquivo
    fclose(arquivo);

    // Exibe o número de ocorrências da palavra buscada
    printf("A palavra '%s' apareceu %d vezes no arquivo '%s'\n", palavra, ocorrencias, nome_arquivo);

    return 0;
}

