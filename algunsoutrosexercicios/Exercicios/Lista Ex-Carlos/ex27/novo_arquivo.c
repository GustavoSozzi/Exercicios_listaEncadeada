#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(void) {
    FILE *arquivo_entrada, *arquivo_saida;
    int c;

    arquivo_entrada = fopen("arquivo_entrada.txt", "r");
    if (arquivo_entrada == NULL) {
        printf("Erro ao abrir o arquivo de entrada\n");
        exit(1);
    }

    arquivo_saida = fopen("arquivo_saida.txt", "w");
    if (arquivo_saida == NULL) {
        printf("Erro ao abrir o arquivo de saída\n");
        exit(1);
    }

    while ((c = fgetc(arquivo_entrada)) != EOF) { //lendo enquanto nao chegar no final do arquivo
        if (!isspace(c)) { //verifica se o caractere esta em branco
            fputc(c, arquivo_saida); //escreve caractere por caractere
        }
    }

    fclose(arquivo_entrada);
    fclose(arquivo_saida);

    return 0;
}

