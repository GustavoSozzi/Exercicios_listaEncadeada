#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"

int menu(int state){
    int opcao;
    system("cls");
    printf("\nEscolha a opção desejada: ");
    printf("\n[1] - Criar Lista");
    printf("\n[2] - Inserir no inicio");
    printf("\n[3] - Inserir no final");
    printf("\n[4] - Remover uma matricula");
    printf("\n[5] - Consulta por posicao");
    printf("\n[6] - Consulta por matricula");
    printf("\n[7] - Apagar Lista");
    printf("\n[8] - Sair");
    printf("\nOpcao: ");
    scanf("%d", &opcao);
    system("cls");
    switch(opcao){
        case 1:
            cria_lista();
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;
        case 8:
            system("pause");
            exit(0);
            break;
        default:
            printf("Invalido");
            system("pause");
            break;

    }
}

int main(){
    int state = 0;
    do {
        state = menu(state);
    }while(state!=0);
    return 0;
}
