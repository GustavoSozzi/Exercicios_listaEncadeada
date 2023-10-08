
/*Um arquivo texto possui uma matriz de
valores inteiros dentro dele. Os dois primeiros números são as dimensões da matriz (linhas e colunas),
enquanto o restante dos números são os valores de cada elemento da matriz. Escreva uma função que
receba o nome do arquivo e retorne o ponteiro para uma matriz alocada dinamicamente contendo os
valores lidos do arquivo*/

#include <stdio.h>
#include <stdlib.h>

int **lerMatrizDoArquivo(char *nomeArquivo, int linhas, int colunas) {
    FILE *arquivo = fopen(nomeArquivo, "r");
    fscanf(arquivo, "%d %d", &linhas, &colunas);
    int **matriz;
    matriz = malloc(linhas * sizeof(int*)); //alocando as linhas
    for (int i = 0; i < linhas; i++) {
        matriz[i] = malloc(colunas * sizeof(int)); //alocando as colunas
    }
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            fscanf(arquivo, "%d", &matriz[i][j]);
        }
    }
    fclose(arquivo);
    return matriz;
}

int main() {
    char *nomeArquivo = "matrix.txt";
    int linhas = 2, colunas = 2;
    int **matriz = lerMatrizDoArquivo(nomeArquivo, linhas, colunas);
    printf("Matriz:\n");
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%d", matriz[i][j]);
        }
        printf("\n");
    }
    // libera a memoria
    for (int i = 0; i < linhas; i++) {
        free(matriz[i]);
    }
    free(matriz);
    return 0;
}



