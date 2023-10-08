#include <stdio.h>

/*int main(int argc, char *argv[]) {
    // verifica se o nome do arquivo foi passado como argumento
    if (argc < 2) {
        printf("Uso: line <nome_do_arquivo>\n");
        return 1;
    }
    char *nome_arquivo = argv[1];

    // abre o arquivo para leitura
    FILE *arquivo = fopen(nome_arquivo, "r");
    if (arquivo == NULL) {
        printf("Não foi possível abrir o arquivo %s\n", nome_arquivo);
        return 1;
    }

    // contador de linhas
    int linha = 1;
    char buffer[256];
    // lê linha por linha do arquivo
    while (fgets(buffer, sizeof(buffer), arquivo) != NULL) {
        printf("%d: %s", linha, buffer);
        linha++;
    }

    // fecha o arquivo
    fclose(arquivo);

    return 0;
}*/


int main(){

int *p, a=3;

p = &a;

printf("ENDERECO DE P: %p", &p);
printf("ENDERECO DE P: %p", &a);




}
