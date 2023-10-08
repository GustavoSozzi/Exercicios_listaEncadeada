#include <stdio.h>

int main() {
    char nome_arquivo[100];
    printf("Insira o nome do arquivo: ");
    scanf("%s", nome_arquivo);

    FILE *arquivo = fopen(nome_arquivo, "r");
    if (arquivo == NULL) {
        printf("Não foi possível abrir o arquivo %s\n", nome_arquivo);
        return 1;
    }

    int linhas = 0;
    int caractere;
    while ((caractere = fgetc(arquivo)) != EOF) {
        if (caractere == '\n') {
            linhas++;
        }
    }

    printf("O arquivo %s possui %d linhas\n", nome_arquivo, linhas);

    fclose(arquivo);
    return 0;
}

//Se você quiser utilizar o nome do arquivo sem aspas ou com outra extensão, como "arquivo.txt", você pode fazer isso sem problema. A função scanf() lê a string digitada pelo usuário e armazena-a na variável nome_arquivo, independentemente de ser ou não uma string com aspas ou com extensão.

//Por exemplo, se o usuário digitar "arquivo.txt" ou "arquivo" na linha de comando, a função scanf() armazenará essa string na variável nome_arquivo e ela será usada como argumento para a função fopen() na abertura do arquivo.

//Mas, é importante notar que, se o arquivo não existir ou estiver em uma pasta diferente da pasta do programa, o programa não conseguirá abrir o arquivo e exibirá uma mensagem de erro.
