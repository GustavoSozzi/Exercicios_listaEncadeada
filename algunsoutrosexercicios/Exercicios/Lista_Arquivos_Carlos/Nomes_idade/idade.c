#include <stdio.h>
#include <stdlib.h>

int main() {
    int ano_corrente, ano_nascimento, idade;
    char nome[41], arquivo_entrada[51], arquivo_saida[51];
    FILE *entrada, *saida;

    // Lê o ano corrente e o nome dos arquivos de entrada e saída
    printf("Digite o ano corrente: ");
    scanf("%d", &ano_corrente);

    printf("Digite o nome do arquivo de entrada: ");
    scanf("%s", arquivo_entrada);

    printf("Digite o nome do arquivo de saída: ");
    scanf("%s", arquivo_saida);

    // Abre o arquivo de entrada em modo de leitura
    entrada = fopen(arquivo_entrada, "r");

    // Verifica se o arquivo de entrada foi aberto com sucesso
    if (entrada == NULL) {
        printf("Erro ao abrir o arquivo de entrada %s\n", arquivo_entrada);
        exit(1);
    }

    // Abre o arquivo de saída em modo de escrita
    saida = fopen(arquivo_saida, "w");

    // Verifica se o arquivo de saída foi aberto com sucesso
    if (saida == NULL) {
        printf("Erro ao abrir o arquivo de saída %s\n", arquivo_saida);
        exit(1);
    }

    // Lê cada linha do arquivo de entrada e escreve a linha correspondente no arquivo de saída
    while (fscanf(entrada, "%40s %d", nome, &ano_nascimento) == 2) {
        idade = ano_corrente - ano_nascimento;

        if (idade < 18) {
            fprintf(saida, "%s menor de idade\n", nome);
        } else if (idade > 18) {
            fprintf(saida, "%s maior de idade\n", nome);
        } else {
            fprintf(saida, "%s entrando na maior idade\n", nome);
        }
    }

    // Fecha os arquivos
    fclose(entrada);
    fclose(saida);

    printf("Arquivo de saída criado com sucesso!\n");

    return 0;
}
