#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "slList.h"
#include "app.h"


void menu(){

        printf("\t\t MENU");
        printf("\n[1] - Criar");
        printf("\n[2] - Inserir no inicio");
        printf("\n[3] - Inserir no final");
        printf("\n[4] - Remover");
        printf("\n[5] - Listar Todos");
        printf("\n[6] - Consultar por nome");
        printf("\n[7] - Consultar por avaliacao do usuario");
        printf("\n[8] - Consultar por Preco");
        printf("\n[9] - Destruir Lista");
        printf("\n[10] - Numero de elementos na Lista");
        printf("\n[0] - Sair");
}

void *adicionaDados(){
    VidGames *elem;
    elem = (VidGames *)malloc(sizeof(VidGames));
    if(elem != NULL){
        printf("Informe o nome do jogo: ");
        fflush(stdin);
        scanf("%[^\n]", elem->nome_do_jogo);
        /*O scanf utilizado lê os caracteres e atá os espaços em branco, menos o \n*/

        printf("Informe o preco: ");
        elem->preco = testeFloat();/*o usuario digita e a função verifica se é um dado válido*/

        inicio:/*Se a avaliação for um inteiro, mas passa de 5 ou é menor que 1, ela volta a executar a partir daqui*/
        printf("Informe a sua avaliacao do jogo de (De 1(Pior) a 5(Melhor)): ");
        elem->avaliacao = testeInteiro();/*o usuario digita e a função verifica se é um dado válido*/

        if (elem->avaliacao < 1 || elem->avaliacao > 5){
            printf("\nNota fora do padrao!Informe de 1 a 5!\n");
            goto inicio;
        }
        return ((void *)elem);
    }
    return NULL;

}
int comparaNomeDoJogo(void *a, void *b){

    VidGames *pa;
    char *pb;
    pa = (VidGames *)a;
    pb = (char *)b;
    if(strstr(pa->nome_do_jogo, pb)){ /*Verifica se os dados são semelhantes*/
        return 1;
    } else{
        return 0;
    }
}

int comparaPreco(void *a, void *b){

    VidGames *pa;
    float *pb;
    pa = (VidGames *)a;
    pb = (float *)b;
    if(pa->preco == *pb){/*Verifica se os dados são semelhantes*/
        return 1;
    } else{
        return 0;
    }
}

int comparaAvaliacaoDoUsuario(void *a, void *b){

    VidGames *pa;
    int *pb;
    pa = (VidGames *)a;
    pb = (int *)b;
    if(pa->avaliacao==(*pb)){/*Verifica se os dados são semelhantes*/
        return 1;
    } else{
        return 0;
    }
}
/*Imprime os dados*/
void imprimirInfo(VidGames *a){
    if(a != NULL)
        printf("Nome do jogo: %s\nAvaliacao do Usuario: %d\nPreco: R$ %.2f\n\n", a->nome_do_jogo, a->avaliacao, a->preco);
}

/*As duas funções abaixo fazem testes do que o usuário digita*/

int testeInteiro(){
    int valor;
     while((!scanf("%d", &valor)|| valor < 1)){
        while(getchar()!='\n'){
            printf("Por favor, informe um dado valido\n");
        }
    }
    return valor;
}
float testeFloat(){
    float valor;
    while((!scanf("%f", &valor)|| valor < 0)){
        while(getchar()!='\n'){
            printf("Por favor, informe um dado valido\n");
        }
    }
    return valor;
}

