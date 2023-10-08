#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
    char nome_arquivo_entrada[50], nome_arquivo_saida[50];
    FILE *arquivo_entrada, *arquivo_saida;

    // L� o nome do arquivo de entrada
    printf("Digite o nome do arquivo de entrada: ");
    scanf("%s", nome_arquivo_entrada);

    // Abre o arquivo de entrada em modo de leitura
    arquivo_entrada = fopen(nome_arquivo_entrada, "r");

    // Verifica se o arquivo de entrada foi aberto com sucesso
    if (arquivo_entrada == NULL) {
        printf("Erro ao abrir o arquivo de entrada.\n");
        exit(1);
    }

    // L� o nome do arquivo de sa�da
    printf("Digite o nome do arquivo de sa�da: ");
    scanf("%s", nome_arquivo_saida);

    // Abre o arquivo de sa�da em modo de escrita
    arquivo_saida = fopen(nome_arquivo_saida, "w");

    // Verifica se o arquivo de sa�da foi aberto com sucesso
    if (arquivo_saida == NULL) {
        printf("Erro ao abrir o arquivo de sa�da.\n");
        exit(1);
    }

    // L� cada caractere do arquivo de entrada at� o final
    int c;
    while ((c = fgetc(arquivo_entrada)) != EOF) {
        // Substitui as vogais por '*'s e escreve no arquivo de sa�da
        if (tolower(c) == 'a' || tolower(c) == 'e' || tolower(c) == 'i' || tolower(c) == 'o' || tolower(c) == 'u') {
            fputc('*', arquivo_saida);
        } else {
            fputc(c, arquivo_saida);
        }
    }

    // Fecha os arquivos de entrada e sa�da
    fclose(arquivo_entrada);
    fclose(arquivo_saida);

    printf("Arquivo criado com sucesso.\n");

    return 0;
}
