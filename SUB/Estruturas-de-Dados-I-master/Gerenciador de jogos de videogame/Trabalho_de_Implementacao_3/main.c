#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "slList.h"
#include "app.h"

int main(){
    int estado, pesquisa_nota, state, cont;
    char pesquisa_nome[50]; float pesquisa_preco;
    void *data, *elem;
    VidGames *a;
    SlList *s = NULL;

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

            case 0:
                //Encerra o programa
                break;

            case 1:
                //Cria a Lista Simplesmente Encadeada
                if(s==NULL){
                    s = sllCreate();
                    printf("Colecao criada!\n");

                } else{
                    printf("Colecao ja criada!\n");
                }
                system("pause");
                system("cls");
                break;

            case 2:
                //Insere um elemento no inicio Lista
                if(s==NULL){
                    printf("Lista Vazia!\n");
                }else{
                    //Insere elementos na coleção
                    elem = adicionaDados();
                    /*A coleção é passada por referencia, se ocorrer tudo bem, o estado fica igual a 1*/
                    estado = sllInsertFirst(&s, elem);
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
                //Insere um elemento no final da Lista
                if(s==NULL){
                    printf("Lista Vazia!\n");
                }else{
                    //Insere elementos na coleção
                    elem = adicionaDados();
                    /*A coleção é passada por referencia, se ocorrer tudo bem, o estado fica igual a 1*/
                    estado = sllInsertAsLast(&s, elem);
                    if (estado == 1){
                        printf("Elemento Inserido!\n");
                    }else {
                        printf("Elemento nao inserido\n");
                    }
                }
                system("pause");
                system("cls");
                break;

            case 4:
                //Remove um elemento da Lista
                if(s!=NULL){
                    printf("Informe o nome do elemento a ser removido: ");
                    fflush(stdin);
                    scanf("%[^\n]", pesquisa_nome);
                    data = sllRemoveSpecified(s, comparaNomeDoJogo, pesquisa_nome);
                    if (data != NULL){
                        printf("Elemento Removido!\n");
                    }else{
                        printf("Elemento Nao Removido!\n");
                    }
                }else{
                    printf("Lista Vazia!\n");
                }
                system("pause");
                system("cls");
                break;

            case 5:
                //Listar todos
                if(s!=NULL){
                    data = sllGetFirst(s);
                    a = (VidGames *)data;
                    if(data !=NULL){
                        printf("\n\tLISTA\n");
                        while(data!=NULL){
                            imprimirInfo(a);
                            data = sllGetNext(s);
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

            case 6:
                //Consulta por nome
                if(s!=NULL && s->first!=NULL){
                    printf("Informe o nome a ser consultado: ");
                    fflush(stdin);
                    scanf("%[^\n]", pesquisa_nome);
                    data = sllConsultaEspecificado(s, comparaNomeDoJogo, (void *)pesquisa_nome);
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

            case 7:
                //Consulta por nota
                if(s!=NULL && s->first!=NULL){
                    inicio:
                    printf("Informe a nota(1 a 5) para a consulta: ");
                    pesquisa_nota = testeInteiro();
                    if (pesquisa_nota < 1 || pesquisa_nota > 5){
                        printf("Nota fora do padrao!Informe de 1 a 5!");
                        goto inicio;
                    }
                    data = sllConsultaEspecificado(s, comparaAvaliacaoDoUsuario, (void *)&pesquisa_nota);
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

            case 8:
                //Consulta por preço
                if(s!=NULL && s->first!=NULL){
                    printf("Informe o preco a ser consultado: ");
                    pesquisa_preco = testeFloat();
                    data = sllConsultaEspecificado(s, comparaPreco, (void *)&pesquisa_preco);
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

            case 9:
                //Destroi Lista
                if(s!= NULL){
                    estado = sllDestroy(&s);
                    if(estado != 0){
                        printf("Colecao destruida!\n");
                    } else{
                        printf("Erro: Colecao nao destruida!\n");
                    }
                } else{
                    printf("Lista Vazia!\n");
                }
                system("pause");
                system("cls");
                break;

            case 10:
                //Numero de elementos
                if(s!=NULL){
                    cont = sllNumDeElem(s);
                    printf("\nNumero de elementos na lista: %d\n", cont);
                }else{
                    printf("\nLista Vazia!\n");
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

    if(s!= NULL)
        estado = sllDestroy(&s);

    system("pause");

    return 0;
}
