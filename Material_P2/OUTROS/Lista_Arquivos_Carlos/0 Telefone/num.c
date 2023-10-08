#include <stdio.h>
#include <stdlib.h>

int main() {
    char nome_arquivo[50], nome[50], telefone[20];
    FILE *arquivo;

    // Lê o nome do arquivo
    printf("Digite o nome do arquivo: ");
    scanf("%s", nome_arquivo);

    // Abre o arquivo em modo de escrita
    arquivo = fopen(nome_arquivo, "w");

    // Verifica se o arquivo foi aberto com sucesso
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo %s\n", nome_arquivo);
        exit(1);
    }

    // Lê os nomes e telefones do usuário e os escreve no arquivo
    while (1) {
        // Lê o nome
        printf("Digite um nome (ou '0' para sair): ");
        scanf("%s", nome);

        // Verifica se o usuário quer sair
        if (strcmp(nome, "0") == 0) {
            break;
        }

        // Lê o telefone
        printf("Digite o telefone: ");
        scanf("%s", telefone);


        // Escreve o nome e telefone no arquivo
        fprintf(arquivo, "%s %s\n", nome, telefone);
    }

    // Fecha o arquivo
    fclose(arquivo);

    printf("Arquivo criado com sucesso!\n");

    return 0;
}
