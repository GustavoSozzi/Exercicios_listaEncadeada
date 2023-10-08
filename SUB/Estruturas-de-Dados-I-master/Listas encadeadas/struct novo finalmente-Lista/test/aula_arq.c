#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct CONTATO {
    char nome[40];
    char telefone[10];
}contato;

typedef struct _NODE{
    contato *valor;
    struct _NODE *prox;
}node;


void inserir(node **lista);
node *alocar(contato *q);
void exibir(node *lista);
void freelista(node **lista);
void gravar_arquivo(node *lista, FILE *ptr);
void ler_arquivo(node **lista, FILE *ptr);
void remover(node **lista, char *rv_elem);

int main (){
    FILE *ptr;
    int i, sistema = 1, escolha;
    char rv_elm[40];
    node *lista = NULL;
    for (i = 0; i <3; i++)
        inserir(&lista);
    system("cls");

    system("pause");
    do {

        printf("Esolha o que fazer\n");
        printf("Remover [1]\nExibir [2]\nLimpar[3]\nGravar [4]\nSair [5]\n");
        scanf("%d", &escolha);
        switch(escolha){
            case 1:
                printf("Informe o contato a remover: ");
                fflush(stdin);
                gets(rv_elm);
                remover(&lista, rv_elm);
                break;
            case 2:
                exibir(lista);
                break;
            case 3:
                break;
            case 4:
                freelista(&lista);
                break;
            case 5:
                freelista(&lista);
                sistema = 0;
                break;
            default:
                break;
        }
    }while(sistema == 1);




    return 0;
}
void inserir(node **lista){
    node *aux = *lista;
    contato p;
    node *novo;
    printf("Informe o nome: ");
    gets(p.nome);
    printf("Informe o telefone: ");
    gets(p.telefone);
    novo = alocar(&p);
    if (aux == NULL)
        *lista = novo;
    else{
        while(aux->prox != NULL)
            aux = aux->prox;
        aux->prox = novo;

    }




}

node *alocar (contato *q){
    node *novo;
    contato *t;
    t = (contato *)malloc(sizeof(contato));
    novo = (node *)malloc(sizeof(node));
    if (novo==NULL)
        exit(1);
    *t  = *q;
    novo->valor = t;
    novo->prox = NULL;
    return novo;

}

void exibir(node *lista){
    node *elm;
    elm = lista;
    while(elm!= NULL){
        printf("Nome: %s\n", elm->valor->nome);
        printf("Tel.: %s\n", elm->valor->telefone);
        printf("---------------\n");
        elm = elm->prox;
    }
}
void remover(node **lista, char *rv_elem){
    node *elm;
    node *aux;
    elm = *lista;
    if(strcmp(elm->valor->nome,rv_elem)==0){
        (*lista) = elm->prox;
        free(elm);
    }
    while(elm != NULL){
        if (strcmp(elm->prox->valor->nome, rv_elem)==0){
            aux = elm->prox;
            elm->prox = aux->prox;
            free(aux);
            break;
        }
        elm = elm->prox;
    }

}

void freelista(node **lista){
    if (lista !=NULL){
        node *elm;
        while(elm!=NULL){
            elm = *lista;
            (*lista) = (*lista)->prox;
            free(elm);
        }
        free(lista);
    }
}
/*
void gravar_arquivo(FILE *ptr){
    contato p;
    ptr = fopen("edu_contatos.txt","w");
    fclose(ptr);
}
void ler_arquivo(FILE *ptr){
    ptr= fopen("edu_contatos.txt", "r");
    fclose(ptr);
}
*/
