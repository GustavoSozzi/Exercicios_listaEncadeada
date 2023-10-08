#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no
{
    int num;
    char nome[50];
    struct no *prox;
}CELULA;

void inicia_cabeca(CELULA *celula)
{
    celula->prox = NULL;

}

void insere_fim(CELULA *celula)
{
    CELULA *novo = (CELULA*)malloc(sizeof(CELULA));

    printf("\nEntre com o valor: ");
    scanf("%d", &novo->num);
    fflush(stdin);

    printf("\nEntre com tu nombre: ");
    scanf("%[^\n]s", novo->nome);
    fflush(stdin);

    novo->prox = NULL;

    if(celula->prox == NULL){ //se esta vazia
        celula->prox = novo;
    }
    else
    {
        CELULA *tmp = celula->prox; //apontando para o inicio valido da cabeca;

        while(tmp->prox!=NULL){  //andando ate o final da lista
            tmp = tmp->prox;
        }

        tmp->prox = novo;
    }
}

void imprimir(CELULA *celula)
{
    CELULA *aux = celula->prox;

    if(celula->prox == NULL){
        printf("\nlista vazia");
    }
    else
    {
        while(aux!=NULL){
            printf("\n%d", aux->num);
            printf("\n%s", aux->nome);
            aux = aux->prox;
        }
    }
}

void inserir_inicio(CELULA *celula)
{
    CELULA *novo = (CELULA*)malloc(sizeof(CELULA));

    printf("\nEntre com o valor: ");
    scanf("%d", &novo->num);
    fflush(stdin);

    printf("\nEntre com tu nombre: ");
    scanf("%[^\n]s", novo->nome);
    fflush(stdin);

    novo->prox = NULL;

    if(celula->prox == NULL){ //se esta vazia
        celula->prox = novo;
    }
    else{
        CELULA *tmp = celula->prox;
        celula->prox = novo;
        novo->prox = tmp;
    }
}

CELULA *buscar_valor(CELULA *celula, int valor)
{
    CELULA *aux = celula->prox;

    while(aux!=NULL && aux->num!=valor)
    {
        aux = aux->prox;
    }

    return aux;


}

CELULA *busca_Nome(CELULA *celula, char nome[])
{
    CELULA *tmp = celula->prox;

    while(tmp!=NULL){
        if(strcmp(tmp->nome, nome)==0){ //comparando as strings;
            return tmp;
        }

        tmp = tmp->prox;
    }


}

CELULA *remover_inicio(CELULA *celula)
{
    CELULA *morreu = celula->prox;

    if(celula->prox == NULL)
    {
        printf("\nlista vazia");
    }
    else{
        celula->prox = morreu->prox;
        free(morreu);
    }
}

int main()
{
    CELULA *celula = (CELULA*)malloc(sizeof(CELULA));
    int op=0, valor;

    CELULA *resultado;

    inicia_cabeca(celula);


    while(op!=8){
        printf("\n1-inserir fim\n2-imprimir\n3-inserir inicio\n4-buscar\n5-buscar nome\n6-Remover No\n");
        scanf("%d", &op);

        if(op==1){
            insere_fim(celula);
        }
        else if(op==2){
            imprimir(celula);
        }
        else if(op==3){
            inserir_inicio(celula);
        }
        else if(op==4){
            printf("\nvalor para busca");
            scanf("%d", &valor);
            resultado = buscar_valor(celula, valor);
            if(resultado==NULL)
            {
                printf("\nvalor nao encontrado");
            }
            else{
                 printf("\n%d valor achado: ", resultado->num);
            }

        }
        else if(op==5){
            resultado = busca_Nome(celula, "Gustavo");
            printf("\nNome encontrado: %s", resultado->nome);
        }
        else if(op==6){
            resultado = remover(celula);
        }
    }


    return 0;
}

/*

/*
            Código escrito por Wagner Gaspar
            Agosto de 2021

            Aula 253: Lista Simplesmente Encadeada
            Busca COM a estrutura lista
*/
/*
typedef struct no{
    int valor;
    struct no *proximo;
}No;

typedef struct{
    No *inicio;
    int tam;
}Lista;

void criar_lista(Lista *lista){
    lista->inicio = NULL;
    lista->tam = 0;
}

// procedimento para inserir no início
void inserir_no_inicio(Lista *lista, int num){
    No *novo = malloc(sizeof(No));

    if(novo){
        novo->valor = num;
        novo->proximo = lista->inicio;
        lista->inicio = novo;
        lista->tam++;
    }
    else
        printf("Erro ao alocar memoria!\n");
}

// procedimento para inserir no fim
void inserir_no_fim(Lista *lista, int num){
    No *aux, *novo = malloc(sizeof(No));

    if(novo){
        novo->valor = num;
        novo->proximo = NULL;

        // é o primeiro?
        if(lista->inicio == NULL)
            lista->inicio = novo;
        else{
            aux = lista->inicio;
            while(aux->proximo)
                aux = aux->proximo;
            aux->proximo = novo;
        }
        lista->tam++;
    }
    else
        printf("Erro ao alocar memoria!\n");
}

// procedimento para inserir no meio
void inserir_no_meio(Lista *lista, int num, int ant){
    No *aux, *novo = malloc(sizeof(No));

    if(novo){
        novo->valor = num;
        // é o primeiro?
        if(lista->inicio == NULL){
            novo->proximo = NULL;
            lista->inicio = novo;
        }
        else{
            aux = lista->inicio;
            while(aux->valor != ant && aux->proximo)
                aux = aux->proximo;
            novo->proximo = aux->proximo;
            aux->proximo = novo;
        }
        lista->tam++;
    }
    else
        printf("Erro ao alocar memoria!\n");
}

void inserir_ordenado(Lista *lista, int num){
    No *aux, *novo = malloc(sizeof(No));

    if(novo){
        novo->valor = num;
        if(lista->inicio == NULL){
            novo->proximo = NULL;
            lista->inicio = novo;
        }
        else if(novo->valor < lista->inicio->valor){
            novo->proximo = lista->inicio;
            lista->inicio = novo;
        }
        else{
            aux = lista->inicio;
            while(aux->proximo && novo->valor > aux->proximo->valor)
                aux = aux->proximo;
            novo->proximo = aux->proximo;
            aux->proximo = novo;
        }
        lista->tam++;
    }
    else
        printf("Erro ao alocar memoria!\n");
}

No* remover(Lista *lista, int num){
    No *aux, *remover = NULL;

    if(lista->inicio){
        if(lista->inicio->valor == num){
            remover = lista->inicio;
            lista->inicio = remover->proximo;
            lista->tam--;
        }
        else{
            aux = lista->inicio;
            while(aux->proximo && aux->proximo->valor != num)
                aux = aux->proximo;
            if(aux->proximo){
                remover = aux->proximo;
                aux->proximo = remover->proximo;
                lista->tam--;
            }
        }
    }

    return remover;
}

No* buscar(Lista *lista, int num){
    No *aux, *no = NULL;

    aux = lista->inicio;
    while(aux && aux->valor != num)
        aux = aux->proximo;
    if(aux)
        no = aux;
    return no;
}

void imprimir(Lista lista){
    No *no = lista.inicio;
    printf("\n\tLista tam %d: ", lista.tam);
    while(no){
        printf("%d ", no->valor);
        no = no->proximo;
    }
    printf("\n\n");
}

int main(){

    int opcao, valor, anterior;
    //No *lista = NULL;
    Lista lista;
    No *removido;

    criar_lista(&lista);

    do{
        printf("\n\t0 - Sair\n\t1 - InserirI\n\t2 - inserirF\n\t3 - InserirM\n\t4 - InserirO\n\t5 - Remover\n\t6 - Imprimir\n\t7 - Buscar\n");
        scanf("%d", &opcao);

        switch(opcao){
        case 1:
            printf("Digite um valor: ");
            scanf("%d", &valor);
            inserir_no_inicio(&lista, valor);
            break;
        case 2:
            printf("Digite um valor: ");
            scanf("%d", &valor);
            inserir_no_fim(&lista, valor);
            break;
        case 3:
            printf("Digite um valor e o valor de referencia: ");
            scanf("%d%d", &valor, &anterior);
            inserir_no_meio(&lista, valor, anterior);
            break;
        case 4:
            printf("Digite um valor: ");
            scanf("%d", &valor);
            inserir_ordenado(&lista, valor);
            break;
        case 5:
            printf("Digite um valor a ser removido: ");
            scanf("%d", &valor);
            removido = remover(&lista, valor);
            if(removido){
                printf("Elemento removido: %d\n", removido->valor);
                free(removido);
            }
            else
                printf("elemento inexistente!\n");
            break;
        case 6:
            imprimir(lista);
            break;
        case 7:
            printf("Digite um valor a ser buscado: ");
            scanf("%d", &valor);
            removido = buscar(&lista, valor);
            if(removido)
                printf("Valor encontrado: %d\n", removido->valor);
            else
                printf("Valor nao encontrado!\n");
            break;
        default:
            if(opcao != 0)
                printf("Opcao invalida!\n");
        }

    }while(opcao != 0);

    return 0;
}**/
