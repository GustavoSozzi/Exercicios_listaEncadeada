#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/*Escrever uma função que
contabilize o número de vogais presentes em um arquivo de texto.*/

int contar_vogais(FILE *arquivo) {
    int vogais = 0;
    int c;
    while ((c = fgetc(arquivo)) != EOF) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
            vogais++;
        }
    }
    return vogais;
}

int main(void) {
    FILE *arquivo_entrada;
    int vogais;

    arquivo_entrada = fopen("arquivo_entrada.txt", "r");
    if (arquivo_entrada == NULL) {
        printf("Erro ao abrir o arquivo de entrada\n");
        exit(1);
    }

    vogais = contar_vogais(arquivo_entrada);

    printf("O numero de vogais no arquivo e: %d\n", vogais);

    fclose(arquivo_entrada);

    return 0;
}
