#include <stdio.h>
#include <string.h>

/*Considere um
arquivo de texto, j� gravado, que cont�m um programa em uma determinada linguagem de programa��o.
Fa�a um programa que leia esse arquivo e identifique as unidades l�xicas dessa linguagem, listando
cada uma delas com sua identifica��o ao lado. As unidades l�xicas a considerar s�o:
� identificadores: iniciam por letra seguida por letras e/ou d�gitos;
� palavras reservadas: begin, end, if, then, else, var, repeat, until, while, do;*/

� s�mbolos especiais: �;�, �.�, �(�, �)�.
int Palavra_chave(char *mundo) {
    char keywords[10][10] = {"begin", "end", "if", "then", "else", "var", "repeat", "until", "while", "do"};
    int i;
    for(i = 0; i < 10; ++i) {
        if(strcmp(keywords[i], mundo) == 0) { //comparando as palavras lidas com palavras reservadas
            return 1;
        }
    }
    return 0;
}

int identificador(char *mundo) {
    if((mundo[0] >= 'a' && mundo[0] <= 'z') || (mundo[0] >= 'A' && mundo[0] <= 'Z')) {
        int i;
        for(i = 1; i < strlen(mundo); ++i) {
            if((mundo[i] >= 'a' && mundo[i] <= 'z') || (mundo[i] >= 'A' && mundo[i] <= 'Z') || (mundo[i] >= '0' && mundo[i] <= '9')) {
                continue;
            } else {
                return 0;
            }
        }
        return 1;
    }
    return 0;
}

int main() {
    FILE *fp;
    char filename[100], word[20];
    printf("Digite o nome do arquivo: ");
    scanf("%s", filename);
    fp = fopen(filename, "r");
    if(fp == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 0;
    }
    printf("UNIDADES L�XICAS:\n");
    while(!feof(fp)){
        fscanf(fp, "%s", word);
        if(Palavra_chave(word)) { //verifica se a palavra chave foi encontrada, se for 1 foi encontrado
            printf("%-15s Palavra Reservada\n", word);
        } else if(identificador(word)) { //verifica se e um identificador
            printf("%-15s Identificador\n", word);
        }
    }
    fclose(fp);
    return 0;
}
