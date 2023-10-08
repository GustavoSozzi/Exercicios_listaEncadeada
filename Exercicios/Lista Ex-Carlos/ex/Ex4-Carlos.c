#include <stdio.h>

int main() {
    char nome_arquivo[100];
    printf("Insira o nome do arquivo: ");
    scanf("%s", nome_arquivo);

    FILE *arquivo = fopen(nome_arquivo, "r");
    if (arquivo == NULL) {
        printf("N�o foi poss�vel abrir o arquivo %s\n", nome_arquivo);
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

//Se voc� quiser utilizar o nome do arquivo sem aspas ou com outra extens�o, como "arquivo.txt", voc� pode fazer isso sem problema. A fun��o scanf() l� a string digitada pelo usu�rio e armazena-a na vari�vel nome_arquivo, independentemente de ser ou n�o uma string com aspas ou com extens�o.

//Por exemplo, se o usu�rio digitar "arquivo.txt" ou "arquivo" na linha de comando, a fun��o scanf() armazenar� essa string na vari�vel nome_arquivo e ela ser� usada como argumento para a fun��o fopen() na abertura do arquivo.

//Mas, � importante notar que, se o arquivo n�o existir ou estiver em uma pasta diferente da pasta do programa, o programa n�o conseguir� abrir o arquivo e exibir� uma mensagem de erro.
