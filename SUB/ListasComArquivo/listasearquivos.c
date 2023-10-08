#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int mat;
    char nome[50];
} estudante;

struct No
{
    estudante dado;
    struct no *prox;
};

typedef struct
{
    struct No *inicio;
} Lista;


void ler(estudante *pe)
{
    scanf("%d %[^\n]s", &pe->mat, &pe->nome);
}

void menu()
{
    printf("==========escolha uma opcao===========\n");
    printf("1-inserir novo estudante\n");
    printf("2-inserir no fim\n");
    printf("3-mostrar lista\n");
    printf("4-pesquisar matricula\n");
    printf("5-inserir apos\n");
    printf("6-inserir antes\n");
    printf("7-deletar inicio\n");
    printf("8-deletar o ultimo no\n");
    printf("9-deletar por matricula\n");
    printf("10-deletar apos\n");
    printf("11-deletar antes\n");
    printf("12-deletar lista\n");
    printf("13-alterar nome\n");
    printf("14-tamanho da lista\n");
    printf("15-salvar em arquivo\n");
    printf("16-ler de um arquivo\n");
    printf("20-sair\n");
    printf("========================================\n");
}

void inserir_inicio(Lista *lista, estudante dado)
{
    struct No *novo = (struct No*)malloc(sizeof(struct No));
    novo->dado = dado;
    novo->prox = lista->inicio;
    lista->inicio = novo;
}

void inserir_fim(Lista *lista, estudante dado)
{
    struct No *novo = (struct No*)malloc(sizeof(struct No));
    novo->dado = dado;
    novo->prox = NULL;

    if(lista->inicio == NULL)
    {
        lista->inicio = novo;
    }
    else
    {
        struct No *pi;
        for(pi = lista->inicio; pi->prox!=NULL; pi = pi->prox);
        pi->prox = novo;
    }

}

void mostrarlista(Lista lista)
{
    struct No *pi = lista.inicio;

    while(pi!=NULL)
    {
        printf("%d %s \n", pi->dado.mat, pi->dado.nome);
        pi = pi->prox;
    }
}

struct No* pesquisar(Lista lista, int mat)
{
    struct No *pi;

    for(pi = lista.inicio; pi!=NULL && pi->dado.mat != mat; pi = pi->prox);
    return pi;

    /*pesquisar o nome
     tipo strcmp(pi->dado.nome, nome) != 0 ao invés de utilizar pi->dado.mat != mat*/
}

struct No* inserir_apos(Lista *lista, estudante dado, int mat)
{
    struct No *pi;
    for(pi = lista->inicio; pi!=NULL && pi->dado.mat!=mat; pi=pi->prox);

    if(pi == NULL)  //se esta vazia a lista;
    {
        return pi;
    }
    else
    {
        struct No *novo = (struct No*)malloc(sizeof(struct No));
        novo->dado = dado;
        novo->prox = pi->prox;
        pi->prox = novo;
        return pi;
    }

}

struct No *inserir_antes(Lista *lista, estudante dado, int mat)
{
    if(lista->inicio == NULL)
    {
        return NULL;
    }
    else if(lista->inicio->dado.mat == mat)
    {
        struct No *novo = (struct No*)malloc(sizeof(struct No));
        novo->dado = dado;
        novo->prox = lista->inicio;
        lista->inicio = novo;
    }
    else
    {
        struct No *pi;

        for(pi = lista->inicio; pi->prox!=NULL && pi->prox->dado.mat == mat; pi=pi->prox);
        if(pi==NULL)
        {
            return pi;
        }
        else
        {
            struct No *novo = (struct No*)malloc(sizeof(struct No));
            novo->dado = dado;
            novo->prox = pi->prox;
            pi->prox = novo;
            return pi;
        }
    }
}

void deletar_inicio(lista *lista)
{
    if(lista->inicio == NULL)
    {
        printf("\nlista vazia");
    }
    else
    {
        struct No *pi = lista->inicio;
        lista->inicio = pi->prox;
        free(pi);
    }

}

void deletar_fim(Lista *lista)
{
    if(lista->inicio == NULL)
    {
        printf("\nlista vazia\n");
    }
    else if(lista->inicio->prox == NULL)
    {
        struct No *pi = lista->inicio;
        lista->inicio = NULL;
        free(pi)
    }
    else
    {
        struct No *pi;
        struct No *pa;

        for(pi = lista->inicio; pi->prox!=NULL; pi = pi->prox)
        {
            pa = pi;
        }
        pa->prox = NULL;
        free(pi);


    }
}

void deletar_por_valor(Lista *lista, int mat)
{
    //inicio = NULO
    if(lista->inicio == NULL){
        printf("A lista esta vazia");
    }
    //no se encontra no inicio
    else if(lista->inicio->mat == mat){
        struct No *pi = lista->inicio;
        lista->inicio = pi->prox;
        free(pi);
    }

    //lista tem um unico no matricula nao existe

    else if(lista->inicio->prox == null){
        if(lista->inicio->dado.mat != mat){
            printf("\nO estudante nao pode ser removido");
        }
    }

    //lista com multiplos nos, valor nao existe;
    //lista com multiplos nos, valor nao existe;

    else
    {
        struct No *pa;
        struct No *pi;

        for(pi=lista->inicio; pi!=NULL && pi->dado.mat != mat; pi=pi->prox){
            pa = pi;
        }

        if(pi == NULL)
        {
            printf("\n o estudante nao pode ser removido");
        }

        else{
            pa->prox = pi->prox;
            free(pi);
        }

    }



}

void salvar_arquivo(Lista lista)
{
    FILE *arq = fopen("arquivo.bin", "wb"); //escrita binaria

    struct No *pi;

    for(pi=lista.inicio;pi!=NULL;pi = pi->prox){
        fwrite(&pi->dado, sizeof(estudante), 1, arq);
    }

    fclose(arq);
}

void deletar_apos(Lista *lista, int mat)
{
    struct No *pa;
    struct No *pi;

    for(pa-lista->inicio;pa!=NULL && pa->dado.mat != mat; pa=pa->prox);
    if(pa==NULL){
        printf("o estudante nao pode ser removido");
    }
    else if(pa->prox == NULL){
        printf("o estudante nao pode ser removido");
    }
    else{
        pi = pa->prox;
        pa->prox = pi->prox;
        free(pi);
    }
}

void deletar_antes(Lista *lista, int mat)
{
    //lista vazia
    if(lista->inicio == NULL){
        printf("a lista esta vazia");
    }
    else{
        struct No *paa; //anterior ao anterior
        struct No *pa; //anterior
        struct No *pi;atual

        for(pi = lista->inicio; pi!=NULL && pi->dado.mat!= mat;pi=pi->prox){
            paa = pa;
            pa = pi;
        }
    }
    //no inicial igual ao pesquisado;
    if(pa==NULL){
        printf("o estudante nao pode ser removido");
    }

    //o segundo no é igual ao valor pesquisado

    else if(paa == NULL){
        lista->inicio = pi;
        free(pa);
    }

    //multiplos itens no No

    else if(pi == NULL){
        printf("o estudante nao pode ser removido");
    }
    else{
        paa->prox = pi;
        free(pa);
    }
}

void deletar_lista(Lista lista)
{
    struct No *aux;

    while(lista->inicio!=NULL)
    {
        aux=lista->inicio;
        lista->inicio = lista->prox;
        free(pi);
    }


}

void alterar_nome(Lista *lista, int mat, char nome[])
{
    struct No *pi = pesquisar(*lista, mat);

    if(pi==NULL)
    {
        printf("nao pode ser encontrado");
    }
    else{
        strcpy(pi->dado.nome, nome);
    }

}

int tamanho(Lista lista)
{
    struct No *pi;

    int cont=0;
    for(pi=lista->inicio;pi!=NULL; pi=pi->prox){
        cont++;
    }

    return cont;
}

Lista ler_arquivo()
{
    Lista lista;

    lista.inicio = NULL;
    FILE *arq = fopen("arquivo.bin", "rb"); //leitura binaria;

    estudante e;

    while(fread(&e, sizeof(estudante), 1, arq)){
        inserir_fim(&lista, e);
    }

    fclose(arq);

    return lista;
}

int main()
{
    Lista lista;
    lista.inicio = NULL;
    int op;
    menu();
    scanf("%d", &op);

    while(op!=20)
    {
        if(op == 1)
        {
            estudante e;
            ler(&e);
            inserir_inicio(&lista, e);
        }
        if(op == 2)
        {
            estudante e;
            ler(&e);
            inserir_fim(&lista, e);
        }

        if(op==3)
        {
            mostrarlista(lista);
        }

        if(op==4)
        {
            int mat;
            printf("\nentre com o numero da matricula: \n");
            scanf("%d", &mat);

            struct No *pi = pesquisar(lista, mat);

            if(pi != NULL)
            {
                printf("%d %s\n", pi->dado.mat, pi->dado.nome);
            }
            else
            {
                printf("estudante nao encontrado");
            }
        }

        if(op==5)
        {
            estudante e;
            ler(&e);
            int mat;
            printf("\ninforme a matricula do estudante para inserir apos: \n");
            scanf("%d", &mat);

            struct No *pi = inserir_apos(&lista, e, mat);
            if(pi==NULL)
            {
                printf("\nNao foi possivel inserir o estudante\n");
            }
        }

        if(op==6)
        {
            estudante e;
            ler(&e);
            int mat;
            printf("\ninforme a matricula do estudante para inserir antes: \n");
            scanf("%d", &mat);

            struct No *pi = inserir_antes(&lista, e, mat);
            if(pi==NULL)
            {
                printf("\nNao foi possivel inserir o estudante\n");
            }
        }

        if(op==7)
        {
            deletar_inicio(&lista);
        }

        if(op==8){
            deletar_fim(&lista);
        }

        if(op == 9){
            int mat;
            printf("\ninforme a matricula: \n");
            scanf("%d", &mat);

            deletar_por_valor(&lista, int mat);

        }
        if(op==10){
            int mat;
            printf("\ninforme a matricula: \n");
            scanf("%d", &mat);

            deletar_apos(&lista, mat);
        }

        if(op==11){
            int mat;
            printf("\ninforme a matricula: \n");
            scanf("%d", &mat);

            deletar_antes(&lista, mat);
        }

        if(op==12)
        {
            deletar_lista(lista);
        }

        if(op==13)
        {
            int mat;
            printf("\ninforme a matricula: \n");
            scanf("%d", &mat);

            printf("informe o nome do estudante: \n");
            char nome[100];
            scanf("%[^\n]s", nome);

            alterar_nome(&lista, mat, nome);
        }

        if(op==14)
        {
            int tam = tamanho(lista);
        }

        if(op==15)
        {
            salvar_arquivo(lista);
        }

    }
    menu();
    scanf("%d", &op);
}

}
