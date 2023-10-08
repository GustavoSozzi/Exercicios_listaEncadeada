#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/*Faça um programa que receba do usuário um arquivo texto e mostre na tela quantas letras são vogais e
quantas são consoantes.*/


int main() {
    char file_name[50], caractere_fornecido_pelo_usuario, c;
    int count = 0;

    printf("Entre com o nome do arquivo: ");
    scanf("%s", file_name);

    printf("Entre com o caractere: ");
    scanf(" %c", &caractere_fornecido_pelo_usuario);

    FILE *file = fopen(file_name, "r");

    if (file == NULL) {
        printf("Erro ao abrir arquivo!\n");
        exit(1);
    }

    while ((c = fgetc(file)) != EOF) {
        if (c == caractere_fornecido_pelo_usuario) {
            count++;
        }
    }

    printf("O caractere '%c' apareceu %d vezes no arquivo '%s'\n", caractere_fornecido_pelo_usuario, count, file_name);

    fclose(file);

    return 0;
}
