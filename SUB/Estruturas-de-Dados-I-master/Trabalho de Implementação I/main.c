#include <stdio.h>
#include <stdlib.h>
#include "assinaturas.h"

int main (){
    int **M1 = NULL, **M2 = NULL, n, m, p, q, state;
    /*
        M1 = matriz 1, n -  numero de linhas da matriz 1, m - colunas da matriz 1
        M2 = matriz 2, p -  numero de linhas da matriz 2, q - colunas da matriz 2
    */
    do {
        menu();
        printf("\nEscolha uma das opcoes: ");
        scanf("%d", &state);
        switch(state){
            case 0:
                break;
            case 1:
                if(M1!=NULL)
                    libera_matriz(M1, n);
                M1 = ler_Matriz(&n, &m);
                break;
            case 2:
                if(M2!=NULL)
                    libera_matriz(M2, p);
                M2 = ler_Matriz(&p, &q);
                break;
            case 3:
              /*Teste para verificar se as matrizes tem valores*/
                if ((M1 && M2)!=NULL) {
                    multiplicar_M1_M2(M1, M2, n, m, p, q);
                } else {
                    printf("Nao e possivel calcular, informe os valores das Matrizes\n");
                    system("pause");
                    system("cls");
                }
                break;
            case 4:
             /*Teste para verificar se as matrizes tem valores*/
                if ((M1 || M2)!=NULL){
                    multiplicar_M1_M2transposta(M1, M2, n, m, p, q);
                } else{
                    printf("Nao e possivel calcular, informe os valores das Matrizes\n");
                    system("pause");
                    system("cls");
                }
                break;
            case 5:
             /*Teste para verificar se as matrizes tem valores*/
                if (M1 != NULL){
                    imprime_M1transposta(M1, n, m);
                } else {
                    printf("Nao e possivel mostrar, informe os valores das Matriz\n");
                    system("pause");
                    system("cls");
                }

                break;
            case 6:
             /*Teste para verificar se a matriz 1 tem valores*/
                if (M1 != NULL){
                    imprime_linha_de_M1(M1, n, m);
                } else{
                    printf("Nao e possivel mostrar, informe os valores das Matriz\n");
                    system("pause");
                    system("cls");
                }

                break;
            case 7:
             /*Teste para verificar se a matriz 1 tem valores*/
                if (M1 != NULL){
                    imprime_coluna_de_M1(M1, m, n);
                } else {
                    printf("Nao e possivel mostrar, informe os valores das Matriz\n");
                    system("pause");
                    system("cls");
                }
                break;
            default:
                printf("\nOpcao Invalida!");
                system("pause");
                system("cls");
                break;
        }
        system("cls");
    }while(state!=0);

    system("pause");

    if (M1!=NULL){
        /*Liberar Matriz 1*/
        libera_matriz(M1, n);
    }
    if(M2!=NULL){
         /*Liberar Matriz 2*/
        libera_matriz(M2, p);
    }


    return 0;
}
