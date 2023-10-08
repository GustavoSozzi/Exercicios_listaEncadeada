#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct _NODE{
    char nome[40];
    char telefone[10];
    struct _NODE *prox;
}node;


void inserir(node **lista);
node *alocar(char *name, char *tel);
void exibir(node *lista);
void freelista(node **lista);
void remover(node **lista, char *rv_elem);

int main (){
    int i; char rv_elm[40];
    node *lista = NULL;
    for (i = 0; i <3; i++)
        inserir(&lista);
    system("cls");
    exibir(lista);
    system("pause");
    printf("Informe o contato a remover: ");
    gets(rv_elm);
    remover(&lista, rv_elm);
    system("cls");
    exibir(lista);
    system("pause");

    freelista(&lista);

    return 0;
}
void inserir(node **lista){
    node *aux = *lista;
    char name[40], tel[10];
    node *novo;
    printf("Informe o nome: ");
    gets(name);
    printf("Informe o telefone: ");
    gets(tel);
    novo = alocar(name, tel);
    if (aux == NULL)
        *lista = novo;
    else{
        while(aux->prox != NULL)
            aux = aux->prox;
        aux->prox = novo;

    }




}

node *alocar (char *name, char *tel){
    node *novo;
    novo = (node *)malloc(sizeof(node));
    if (novo==NULL)
        exit(1);
    strcpy(novo->nome, name);
    strcpy(novo->telefone, tel);
    novo->prox = NULL;
    return novo;

}

void exibir(node *lista){
    node *elm;
    elm = lista;
    while(elm!= NULL){
        printf("Nome: %s\n", elm->nome);
        printf("Tel.: %s\n", elm->telefone);
        printf("---------------\n");
        elm = elm->prox;
    }
}
void remover(node **lista, char *rv_elem){
    node *elm;
    node *aux;
    elm = *lista;
    if(strcmp(elm->nome,rv_elem)==0){
        *lista = elm->prox;
        free(elm);
    }
    while(elm != NULL){
        if (strcmp(elm->prox->nome, rv_elem)==0){
            aux = elm->prox;
            elm->prox = aux->prox;
            free(aux);
            break;
        }
        elm = elm->prox;
    }

}

void freelista(node **lista){
    node *elm;
    elm = *lista;
    while(elm!=NULL){
        elm = (*lista)->prox;
        free(*lista);
        *lista = elm;
    }
}
