#include <stdio.h>
#include <stdlib.h>

//Cadastro de conta bancaria

typedef struct{
    int numero_conta;
    char nome_cliente[50];
    int saldo;
}Conta;

int main(){

int op=0;
int i=0;
int cont=0;
int num_conta;
int menor;
int num=0;
Conta conta[15];


while(op!=5){

        printf("ESCOLHA UMA OPCAO\n1-CADASTRAS_CONTAS\n2-VISUALIZAR CONTA DE DETERMINADO CLIENTE\n3-EXCLUIR CONTA COM MENOR SALDO\n4-VISUALIZAR TODAS AS CONTAS\n5-SAIR\n");
        scanf("%d", &op);

    switch(op)
    {
    case 1:
        system("cls");
        if(cont > 15){
            printf("NUMERO DE CONTAS EXCEDIDO\n");
        }
        else{
            printf("NUMERO DA CONTA: \n");
            scanf("%d", &conta[i].numero_conta);
            fflush(stdin);

            printf("NOME DO CLIENTE: \n");
            scanf("%[^\n]s", &conta[i].nome_cliente);
            fflush(stdin);


            printf("SALDO: \n");
            scanf("%d", &conta[i].saldo);
            fflush(stdin);

            i++;
            cont++;
        }

        break;

        case 2:

            system("cls");

            printf("NUMERO DA CONTA:  \n");
            scanf("%d", &num_conta);

            for(i=0; i<cont; i++){
                if(num_conta == conta[i].numero_conta){
                    printf("NOME %s\n", conta[i].nome_cliente);
                    printf("NUMERO DA CONTA %d\n", conta[i].numero_conta);
                    printf("SALDO %d\n", conta[i].saldo);

                }
            }

        break;

        case 3:
            menor = conta[0].saldo;

            for(i=1; i<cont; i++){
                if(conta[i].saldo < menor){
                    menor = conta[i].saldo;
                    num = i;
                }
            }

            for(i=num; i<cont-1; i++){
                conta[i] = conta[i+1];
            }

            cont--;

        case 4:
            for(i=0; i<cont;i++){
                printf("NOME %s\n", conta[i].nome_cliente);
                printf("NUMERO DA CONTA %d\n", conta[i].numero_conta);
                printf("SALDO %d\n", conta[i].saldo);

            }

        default:
            printf("erro\n");

    }


}

}











