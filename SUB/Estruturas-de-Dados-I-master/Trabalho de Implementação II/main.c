#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "colecao.h"
#include "funcoes.h"


int main(){
    int valor_max, estado, pesquisa_nota, state;
    char pesquisa_nome[50]; float pesquisa_preco;
    void *data, *elem;
    VidGames *a;
    Col *c = NULL;




    do {
        menu();
        printf("\nEscolha uma das opcoes: ");
        /*Verifica se a opção digitada é um numero mesmo, se não entra no loop até o dado correto for digitado*/
        while(!scanf("%d", &state)){
            while(getchar()!='\n'){
                system("cls");
                menu();
                printf("\nPor favor, informe uma opcao valida!\n");
            }
        }
        switch(state){
            //Encerra o programa
            case 0:
                break;
            case 1:
                if(c==NULL){
                    printf("Informe a quantidade de elementos na colecao: ");
                    valor_max = testeInteiro();
                    /*Crio a coleção*/
                    c = colCriar(valor_max);
                    printf("Colecao criada!\n");
                } else{
                    printf("Colecao ja criada!\n");
                }
                system("pause");
                system("cls");
                break;
            case 2:
                if(c==NULL){
                    printf("Lista Vazia!\n");
                }else{
                    //Insere elementos na coleção
                    elem = adicionaDados();
                    /*A coleção é passada por referencia, se ocorrer tudo bem, o estado fica igual a 1*/
                    estado = colInserir(&c, elem);
                    if (estado == 1){
                        printf("Elemento Inserido!\n");
                    }else {
                        printf("Elemento nao inserido\n");
                    }
                }
                system("pause");
                system("cls");
                break;

            case 3:
                if(c!=NULL){
                    printf("Informe o nome do elemento a ser removido: ");
                    fflush(stdin);
                    scanf("%[^\n]", pesquisa_nome);
                    data = colRemove(c, pesquisa_nome, comparaNomeDoJogo);
                    if (data != NULL){
                        printf("Elemento Removido!\n");
                    }else{
                        printf("Lista Vazia!\n");
                    }
                }else{
                    printf("Lista Vazia!\n");
                }
                system("pause");
                system("cls");
                break;

            case 4:
                if(c!=NULL){
                    data = colGetFirst(c);
                    a = (VidGames *)data;
                    if(data !=NULL){
                    printf("\n\tCOLECAO\n");
                        while(data!=NULL){
                            imprimirInfo(a);
                            data = colGetNext(c);
                            a = (VidGames *)data;
                        }
                    } else{
                        printf("\nLista Vazia!");
                    }
                }else{
                    printf("Lista Vazia!\n");
                }
                system("pause");
                system("cls");
                break;

            case 5:
                if(c!=NULL){
                    printf("Informe o nome a ser consultado: ");
                    fflush(stdin);
                    scanf("%[^\n]", pesquisa_nome);
                    data = colConsulta(c, (void *)pesquisa_nome, comparaNomeDoJogo);
                    a = (VidGames *)data;
                    if(data!=NULL)
                        imprimirInfo(a);
                    else
                        printf("\nNao encontrado!");
                }else{
                    printf("Lista Vazia!\n");
                }
                system("pause");
                system("cls");
                break;

            case 6:
                if(c!=NULL){
                    inicio:
                    printf("Informe a nota(1 a 5) para a consulta: ");
                    pesquisa_nota = testeInteiro();
                    if (pesquisa_nota < 1 || pesquisa_nota > 5){
                        printf("Nota fora do padrao!Informe de 1 a 5!");
                        goto inicio;
                    }

                    data = colConsulta(c, &pesquisa_nota, comparaAvaliacaoDoUsuario);
                    a = (VidGames *)data;
                    if(data!=NULL){
                        imprimirInfo(a);
                    }

                    else
                        printf("\nNao encontrado!\n");
                }else{
                    printf("Lista Vazia!\n");
                }
                system("pause");
                system("cls");
                break;

            case 7:
                if(c!=NULL){
                    printf("Informe o preco a ser consultado: ");
                    pesquisa_preco = testeFloat();
                    data = colConsulta(c, &pesquisa_preco, comparaPreco);
                    a = (VidGames *)data;
                    if(data!=NULL)
                        imprimirInfo(a);
                    else
                        printf("\nNao encontrado!");
                } else{
                    printf("Lista Vazia!\n");
                }
                system("pause");
                system("cls");
                break;

            case 8:
                if(c!= NULL){
                    c = colDestroi(c);
                    printf("Colecao destruida!\n");
                    c = NULL;
                } else{
                    printf("Lista Vazia!\n");
                }
                system("pause");
                system("cls");

                break;

            default:
                printf("\nOpcao Invalida!");
                system("pause");
                system("cls");
                break;
        }
        system("cls");
    }while(state!=0);

    c = colDestroi(c);

    system("pause");
    return 0;
}
