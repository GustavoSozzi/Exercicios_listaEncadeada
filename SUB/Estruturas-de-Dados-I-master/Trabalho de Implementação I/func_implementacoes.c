#include <stdio.h>
#include <stdlib.h>
#include "assinaturas.h"


void menu(){

        printf("\t\t MENU");
        printf("\n[1] - Ler Matriz M1");
        printf("\n[2] - Ler Matriz M2");
        printf("\n[3] - Multiplicar M1 por M2");
        printf("\n[4] - Multiplicar M1 pela transposta de M2");
        printf("\n[5] - Imprimir a Matriz transposta de M1");
        printf("\n[6] - Imprimir uma linha de M1");
        printf("\n[7] - Imprimir uma coluna de M1");
        printf("\n[0] - Sair");
}

int **ler_Matriz(int *lin, int *col){
    /*
        Como foi passada por referencia, o numero de linhas pode ser alterado pelo usuário, sem uma função
        que retorne o numero de linhas, de maneira análoga para as colunas
    */
    int **M, i, j;
    /*Foi criado um rótulo chamado início*/
    inicio:
    printf("\nInforme a quantidade de linhas: ");
    scanf("%d", &(*lin));
    printf("\nInforme a quantidade de colunas: ");
    scanf("%d", &(*col));
    /*Teste para verificar se os valores não são válidos*/
    if((*col)<=0 || (*lin)<=0){
        printf("\nValores da coluna nao sao validos\n");
        /*
            Se não forem, o usuário é informado, e acontece um salto com o comando goto para o rótulo início, assim o usuario
            informa novamente os valores da linha e da coluna
        */
        goto inicio;
    }
    /*Aloca a matriz*/
    M = (int **)malloc((*lin)*(sizeof(int *)));
    if(M==NULL){
        printf("\nNao foi possível alocar");
        system("pause");
        exit(1);
    }
    for (i = 0; i < (*lin); i++){
        M[i] = (int *)malloc((*col)*(sizeof(int)));
        if(M[i]==NULL){
            printf("\nNao foi possível alocar");
            system("pause");
            exit(1);
        }
    }
    /*Lê os valores da matriz*/
    printf("\nInforme os elementos da matriz: ");
    for (i = 0; i < (*lin); i++){
        for(j = 0; j < (*col); j++){
            printf("\nM[%d][%d]: ", i, j);
            scanf("%d", &M[i][j]);
        }
    }
    system("pause");
    system("cls");
    return M;
}
void multiplicar_M1_M2(int **M1, int **M2, int n, int m, int p, int q){

    int i, j,k;
    int **Matriz_Produto;
    /*Produto entre M1 e M2, se as colunas de M1 e as linhas de M2 forem iguais*/
    if (m == p){
        /*Aloca a matriz produto*/
        Matriz_Produto = (int **)malloc(n*sizeof(int *));
        if(Matriz_Produto==NULL){
            printf("\nNao foi possível alocar");
            system("pause");
            exit(1);
        }

        for (i = 0; i < n; i++){
            Matriz_Produto[i] = (int *)malloc(q*sizeof(int));
            if(Matriz_Produto[i]==NULL){
                printf("\nNao foi possível alocar");
                system("pause");
                exit(1);
            }
        }
        for(i = 0; i < n; i++){
            for(j = 0; j < q; j++){
                Matriz_Produto[i][j] = 0;
                for (k = 0; k < p; k++){
                    Matriz_Produto[i][j] += (M1[i][k]*M2[k][j]);
                }
            }
        }
        /*Imprime a matriz produto*/
        printf("M1 x M2 = \n");
        for(i = 0; i < n; i++){
            for(j = 0; j < q; j++){
                printf("%d\t", Matriz_Produto[i][j]);
            }
            printf("\n");
        }
        /*Terminando de imprimir a matriz, libera a memória*/
        libera_matriz(Matriz_Produto, n);

     } else {
        printf("Nao e possivel calcular a multiplicacao, as Matrizes nao satisfazem a propriedade de multiplicacao");
     }

    system("pause");

}

void multiplicar_M1_M2transposta(int **M1, int **M2, int n, int m, int p, int q){

    int i, j,k;
    int **Matriz_Produto;

    /*Produto entre M1 e M2 transposta, se as colunas de M1 e as linhas de M2  transposta forem iguais*/
    if (m == q){
         /*Aloca a matriz produto*/
        Matriz_Produto = (int **)malloc(n*sizeof(int *));
        if(Matriz_Produto==NULL){
            printf("\nNao foi possível alocar");
            system("pause");
            exit(1);
        }

        for (i = 0; i < n; i++){
            Matriz_Produto[i] = (int *)malloc(p*sizeof(int));
        }
        for(i = 0; i < n; i++){
            for(j = 0; j < p; j++){
                Matriz_Produto[i][j] = 0;
                for (k = 0; k < q; k++){
                    Matriz_Produto[i][j] += (M1[i][k]*M2[j][k]);
                }
            }
        }
         /*Imprime a matriz produto*/
        printf("M1 x M2t = \n");  //M2t = Matriz 2 transposta
        for(i = 0; i < n; i++){
            for(j = 0; j < p; j++){
                printf("%d\t", Matriz_Produto[i][j]);
            }
            printf("\n");
        }
         //M2t = Matriz 2 transposta
        libera_matriz(Matriz_Produto, n);

     } else {
        printf("Nao e possivel calcular a multiplicacao, as Matrizes nao satisfazem a propriedade de multiplicacao");
     }

    system("pause");

}

void imprime_M1transposta(int **M1, int n, int m){
    int i, j;
    printf("\nMatriz1 transposta: \n");
    /*
        Manteve-se a mesma forma de imprimir uma matriz normal, mas foi invertida a ordem dos laços, assim
        pode-se obter a transposta de M1
    */
    for (j = 0; j < m; j++){
        for (i = 0; i < n; i++){
            printf("%d\t", M1[i][j]);
        }
        printf("\n");
    }
    system("pause");
}

void imprime_linha_de_M1(int **M1, int m, int n){
    int i, j;
    /*O usuario informa a linha desejada*/
    printf("Informe a linha a ser mostrada: ");
    scanf("%d", &i);
    if(i<n && i>=0){
        /*Mostra-se a linha*/
        for (j = 0; j < m; j++)
            printf("%d ", M1[i][j]);
        printf("\n");
        system("pause");
    } else{
        printf("Linha Invalida!\n");
        system("pause");
    }
}

void imprime_coluna_de_M1(int **M1, int n, int m){
    int i, j;
     /*O usuario informa a coluna desejada*/
    printf("Informe a coluna a ser mostrada: ");
    scanf("%d", &j);
    if(j<m && j>=0){
        /*Mostra-se a coluna*/
        for (i = 0; i < n; i++)
            printf("%d\n", M1[i][j]);
        printf("\n");
        system("pause");
    } else {
        printf("Coluna Invalida!\n");
        system("pause");
    }
}

void libera_matriz(int **M, int lin){

    int i;
    for (i = 0; i < lin; i++){
        free(M[i]);
    }
    free(M);

}
