#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 20

typedef struct _lista{
    int valor;
    struct _lista *prox;
}LISTA;

//lista ordenada

void imprimirLista(LISTA *head);

LISTA *novoNO(int valor)
{
    LISTA *novo = (LISTA *)malloc(sizeof(LISTA));
    novo->prox = NULL;
    novo->valor = valor;
    return novo;
}

void inserir(LISTA *head,int valor)
{
    LISTA *novo = novoNO(valor);
    if (head->prox==NULL)
    {
        head->prox=novo;
    }
    else
    {
        LISTA *aux = head->prox;
        LISTA *ant = head;
        while (aux!=NULL && valor > aux->valor)
        {
            ant = aux;
            aux=aux->prox;
        }
        if (ant==head)
        {
            head->prox = novo;
            novo->prox = aux;
        }
        else
        {
            ant->prox = novo;
            novo->prox = aux;
        }
        imprimirLista(head);
        /*LISTA *aux = head->prox;
        while (aux->prox!=NULL && valor < aux->prox->valor)
        {
            aux=aux->prox;
        }
        if (aux==head->prox)
        {
            head->prox = novo;
            novo->prox = aux;
        }
        else
        {
            novo->prox = aux->prox;
            aux->prox = novo;
        }*/
    }
}

void imprimirLista(LISTA *head)
{
    LISTA *aux;
    printf("Lista: ");
    for (aux=head->prox;aux!=NULL;aux=aux->prox)
    {
        printf("%i->",aux->valor);
    }
    printf("\n");
}

void liberaLista(LISTA *head)
{
    if (head!=NULL)
    {
        liberaLista(head->prox);
        free(head);
    }
}

int main()
{
    LISTA *head = (LISTA *)malloc(sizeof(LISTA));
    head->prox = NULL;
    srand(time(NULL));

    int i,valor;
    for (i=0;i<TAM;i++)
    {
        valor = (rand()%100)-50;
        inserir(head,valor);
    }
    imprimirLista(head);
    liberaLista(head);

    return 0;
}

// ---------------LISTA 2 ENCADEADA-------------------

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _pessoa{
    int rga;
    char nome[50];
    struct _pessoa *next;
} Pessoa;

Pessoa *novaPessoa(char *nome,int rga)
{
    Pessoa *nova = malloc(sizeof(Pessoa));
    strcpy(nova->nome,nome);
    nova->rga=rga;
    nova->next = NULL;
    return nova;
}

void inserirLista(Pessoa **lista,Pessoa *nova)
{
    Pessoa *aux=NULL;

    if (*lista==NULL)
    {
        *lista=nova;
    }
    else
    {
        for (aux = *lista;aux->next!=NULL;aux=aux->next){}
        aux->next=nova;
    }
}

Pessoa *removerLista(Pessoa **lista,int rga)
{
    Pessoa *aux=NULL,*ant=NULL;
    if (*lista!=NULL)
    {
        for (aux = *lista;aux!=NULL && aux->rga!=rga;ant=aux,aux=aux->next){}
        if (aux!=NULL && aux->rga==rga)
        {
            if (aux==*lista)
            {
                *lista = aux->next;
            }
            else
            {
                ant->next = aux->next;
            }
        }
        else
        {
            aux = NULL;
        }
    }
    return aux;
}

void print(Pessoa *lista)
{
    Pessoa *aux=lista;
    printf("\n*****Lista*****\n\n");
    while (aux!=NULL)
    {
        printf("Nome: %s - RGA: %i\n",aux->nome,aux->rga);
        aux = aux->next;
    }
}

void liberarLista(Pessoa *lista)
{
    if (lista!=NULL)
    {
        liberarLista(lista->next);
        free(lista);
    }
}

int main()
{
    Pessoa *lista = NULL;
    Pessoa *nova = NULL;
    int rga;
    char nome[50];

    printf("Digite o RGA (-1 para sair): ");
    scanf("%i",&rga);
    while (rga!=-1)
    {
        printf("Digite o nome do aluno: ");
        scanf("\n%[^\n]s",nome);
        nova = novaPessoa(nome,rga);
        inserirLista(&lista,nova);
        printf("Digite o RGA (-1 para sair): ");
        scanf("\n%i",&rga);
    }
    print(lista);
    printf("Digite o RGA (-1 para sair): ");
    scanf("%i",&rga);
    while (rga!=-1)
    {
        Pessoa *rem = removerLista(&lista,rga);
        if (rem!=NULL)
        {
            free(rem);
        }
        print(lista);
        printf("Digite o RGA (-1 para sair): ");
        scanf("\n%i",&rga);
    }
    liberarLista(lista);
    return 0;
}

//------------------LISTA 3 FILA ENCADEADA----------------------

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 20

typedef struct _fila{
    float prova;
    float redacao;
    struct _fila *prox;
}FILA;

typedef struct{
    FILA *ini;
    FILA *fim;
}PIVO;

void imprimirLista(FILA *fila)
{
    FILA *aux;
    printf("Fila: ");
    for (aux=fila;aux!=NULL;aux=aux->prox)
    {
        printf("[%.2f,%.2f]->",aux->prova,aux->redacao);
    }
    printf("\n");
}

FILA *novoNO(float prova,float redacao)
{
    FILA *novo = (FILA *)malloc(sizeof(FILA));
    novo->prox = NULL;
    novo->prova = prova;
    novo->redacao = redacao;
    return novo;
}

void inserir(PIVO *pivo,float prova,float redacao)
{
    FILA *novo = novoNO(prova,redacao);
    if (pivo->ini==NULL)
    {
        pivo->ini = novo;
        pivo->fim = novo;
    }
    else
    {
        pivo->fim->prox = novo;
        pivo->fim = novo;
    }
}

FILA *remover(PIVO *pivo)
{
    FILA *aux = NULL;
    if (pivo->ini==NULL)
    {
        return NULL;
    }
    else
    {
        aux = pivo->ini;
        pivo->ini=pivo->ini->prox;
        return aux;
    }
}

void liberaLista(FILA *fila)
{
    if (fila!=NULL)
    {
        liberaLista(fila->prox);
        free(fila);
    }
}

int main()
{
    PIVO pivo;
    pivo.ini = NULL;
    pivo.fim = NULL;
    srand(time(NULL));

    int i,valor;
    for (i=0;i<TAM;i++)
    {
        inserir(&pivo,rand()%100,rand()%1000);
    }
    imprimirLista(pivo.ini);

    FILA *rem = remover(&pivo);
    free(rem);
    imprimirLista(pivo.ini);

    liberaLista(pivo.ini);

    return 0;
}

// --------------------- LISTA COM ARQUIVOS BINARIOS--------------------------

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define TMAX 10

typedef struct no
{
    int valor;
    short int status; //0: inalterado; 1: novo; 2: removido; 3: alterado
    struct no *prox;
} NO;

/** Arquivos Binarios **/

FILE *abrirArquivo(char *filename,char *tipo)
{
    FILE *arq = NULL;
    arq = fopen(filename,tipo);
    printf("Abrindo o arquivo '%s' como '%s'\n",filename,tipo);
    if (arq==NULL) //se retornou ponteiro nulo ao abrir o arquivo, erro
    {
        fprintf(stderr,"Erro ao abrir o arquivo: %s para '%s'\n",filename,tipo);
        exit(1);
    }
    else
    {
        return arq;
    }
}

NO *lerLista(char *filename) //le o arquivo binario e recria a lista
{
    FILE *file = abrirArquivo(filename,"rb");
    NO *lista = NULL;
    NO *novo = malloc(sizeof(NO));
    while (fread(novo,sizeof(NO),1,file)>0)
    {
        printf("Leu o ");printNO(novo);printf("\n");
        inserir(&lista,novo->valor,0);
    }
    free(novo);
    return lista;
}

void gravarLista(char *filename,NO *lista) //grava a lista em um arquivo binario
{
    NO *aux = NULL;
    FILE *file = fopen(filename,"rb");
    if (file==NULL)
    {
        fclose(file);
        file = abrirArquivo(filename,"wb");
        for (aux=lista;aux!=NULL;aux=aux->prox)
        {
            printf("Gravando ");printNO(aux);printf("\n");
            fwrite(aux,sizeof(NO),1,file);
        }
        fclose(file);
    }
    else
    {
        fclose(file);
        file = abrirArquivo(filename,"ab");
        int removeu = 0;
        printf("Gravando lista no arquivo '%s'\n",filename);
        rewind(file);
        for (aux=lista;aux!=NULL;aux=aux->prox)
        {
            if (aux->status==2)
            {
                removeu = 1;
            }

            if (removeu==0)
            {
                fseek(file,sizeof(NO),SEEK_CUR);
                if (aux->status==3)
                {
                    printf("Alterando ");printNO(aux);printf("\n");
                    fwrite(aux,sizeof(NO),1,file);
                }
            }
            else
            {
                printf("Gravando ");printNO(aux);printf("\n");
                fwrite(aux,sizeof(NO),1,file);
            }
        }
        fclose(file);
    }
}

// ----------------------FILA CIRCULAR---------------------

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 20

typedef struct _fila{
    float prova;
    float redacao;
    struct _fila *prox;
}FILA;

typedef struct{
    FILA *ini;
    FILA *fim;
}PIVO;

void printNO(FILA *no)
{
    printf("[%.2f,%.2f]->",no->prova,no->redacao);
}

void imprimirLista(PIVO pivo)
{
    FILA *aux;
    printf("Fila: ->");
    if (pivo.ini!=NULL)
    {
        aux=pivo.ini;
        printNO(aux);
        for (aux=aux->prox;aux!=NULL && aux!=pivo.fim->prox;aux=aux->prox)
        {
            printNO(aux);
        }
    }
    printf("\n");
}

FILA *novoNO(float prova,float redacao)
{
    FILA *novo = (FILA *)malloc(sizeof(FILA));
    novo->prox = NULL;
    novo->prova = prova;
    novo->redacao = redacao;
    return novo;
}

void inserir(PIVO *pivo,float prova,float redacao)
{
    FILA *novo = novoNO(prova,redacao);
    if (pivo->ini==NULL)
    {
        pivo->ini = novo;
        pivo->fim = novo;
        //novo->prox = pivo->ini;
        pivo->fim->prox = pivo->ini;
    }
    else
    {
        pivo->fim->prox = novo;
        pivo->fim = novo;
        novo->prox = pivo->ini;
    }
}

FILA *remover(PIVO *pivo)
{
    FILA *aux = NULL;
    if (pivo->ini==NULL)
    {
        return NULL;
    }
    else
    {
        aux = pivo->ini;
        if (pivo->ini==pivo->fim)
        {
            pivo->ini = NULL;
            pivo->fim = NULL;
        }
        else
        {
            pivo->fim->prox = pivo->ini->prox;
            pivo->ini = pivo->fim->prox;
            //pivo->ini=pivo->ini->prox;
            //pivo->fim->prox = pivo->ini;
        }
        return aux;
    }
}

void liberaFila(PIVO *pivo)
{
    FILA *aux = NULL;
    aux = remover(pivo);
    while (aux!=NULL)
    {
        printf("Removendo: ");
        printNO(aux);
        printf("\n");
        free(aux);
        aux = remover(pivo);
    }
}

int main()
{
    PIVO pivo;
    pivo.ini = NULL;
    pivo.fim = NULL;
    srand(time(NULL));

    int i,valor,valor2;
    for (i=0;i<TAM;i++)
    {
        valor = rand()%100;
        valor2 = rand()%1000;
        inserir(&pivo,valor,valor2);
    }
    imprimirLista(pivo);

    FILA *rem = remover(&pivo);
    free(rem);
    imprimirLista(pivo);

    liberaFila(&pivo);

    return 0;
}

//-------------------FILA DE PRIORIDADE--------------------

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 20
#define CORTE 0

typedef struct _fila{
    float prova;
    float redacao;
    struct _fila *prox;
}FILA;

typedef struct{
    FILA *ini;
    FILA *fim;
}PIVO;

void printNO(FILA *no)
{
    printf("[%.2f,%.2f]->",no->prova,no->redacao);
}

void imprimirLista(FILA *fila)
{
    FILA *aux;
    printf("Fila: ");
    for (aux=fila;aux!=NULL;aux=aux->prox)
    {
        printNO(aux);
    }
    printf("\n");
}

FILA *novoNO(float prova,float redacao)
{
    FILA *novo = (FILA *)malloc(sizeof(FILA));
    novo->prox = NULL;
    novo->prova = prova;
    novo->redacao = redacao;
    return novo;
}

FILA *removeSelecao(PIVO *pivo,FILA *no)
{
    FILA *aux = pivo->ini;
    FILA *ant = NULL;
    while (aux != NULL && no->prova != aux->prova && no->redacao != aux->redacao)
    {
        ant = aux;
        aux=aux->prox;
    }

    if (aux==NULL)
    {
        return NULL;
    }
    else
    {
        if (aux==pivo->ini)
        {
            pivo->ini = aux->prox;
        }
        else
        {
            ant->prox = aux->prox;
        }
        return aux;
    }
}

/** Insere como prioridade a partir da nota obtida na redacao.
    inserirPrioridadeOrdenada() -> prioridade maior no comeco.
**/
void inserirOrdenado(PIVO *pivo,FILA *novo)
{
    if (novo->redacao<=CORTE)
    {
        pivo->fim->prox = novo;
        pivo->fim = novo;
    }
    else
    {
        FILA *aux = pivo->ini;
        FILA *ant = NULL;
        while (aux != NULL && novo->redacao <= aux->redacao)
        {
            ant = aux;
            aux=aux->prox;
        }

        if (aux==NULL)
        {
            pivo->fim->prox = novo;
            pivo->fim = novo;
        }
        else if (aux==pivo->ini)
        {
            novo->prox=pivo->ini;
            pivo->ini = novo;
        }
        else
        {
            ant->prox = novo;
            novo->prox = aux;
        }
    }
}

void inserirPrioridadeOrdenada(PIVO *pivo,float prova,float redacao)
{
    FILA *novo = novoNO(prova,redacao);
    if (pivo->ini==NULL)
    {
        pivo->ini = novo;
        pivo->fim = novo;
    }
    else
    {
        inserirOrdenado(pivo,novo);
    }
}

void alterarPrioridadeOrdenada(PIVO *pivo,FILA *no,float redacao)
{
    no = removeSelecao(pivo,no);
    if (no==NULL)
    {
        printf("Elemento nao encontrado\n");
        return;
    }
    inserirPrioridadeOrdenada(pivo,no->prova,redacao);
    free(no);
}

void inserirPrioridade(PIVO *pivo,float prova,float redacao)
{
    FILA *novo = novoNO(prova,redacao);
    if (pivo->ini==NULL)
    {
        pivo->ini = novo;
        pivo->fim = novo;
    }
    else
    {
        pivo->fim->prox = novo;
        pivo->fim = novo;
    }
}

FILA *removerPrioridade(PIVO *pivo)
{
    FILA *aux = NULL;
    if (pivo->ini==NULL)
    {
        return NULL;
    }
    else
    {
        FILA *aux = pivo->ini;
        FILA *antMaior = aux;
        FILA *ant = aux;
        FILA *maior = aux;
        while (aux != NULL)
        {
            if (maior->redacao < aux->redacao)
            {
                antMaior = ant;
                maior = aux;
            }
            ant=aux;
            aux=aux->prox;
        }
        printf("MAIOR: ");printNO(maior);printf("\n");
        printNO(antMaior);printf("\n");

        if (maior==pivo->ini)
        {
            pivo->ini = maior->prox;
        }
        else
        {
            antMaior->prox = maior->prox;
        }
        return maior;
    }
}

void alterarPrioridade(PIVO *pivo,FILA *no,float redacao)
{
    if (pivo->ini==NULL)
    {
        printf("Fila vazia\n");
    }
    else
    {
        FILA *aux = pivo->ini;
        while (aux != NULL && no->prova != aux->prova && no->redacao != aux->redacao)
        {
            aux=aux->prox;
        }
        if (aux==NULL)
        {
            printf("Elemento nao encontrado\n");
        }
        else
        {
            aux->redacao = redacao;
        }
    }
}

/** fim insercao **/

FILA *removerPrioridadeOrdenada(PIVO *pivo)
{
    FILA *aux = NULL;
    if (pivo->ini==NULL)
    {
        return NULL;
    }
    else
    {
        aux = pivo->ini;
        pivo->ini=pivo->ini->prox;
        return aux;
    }
}

void liberaLista(FILA *fila)
{
    if (fila!=NULL)
    {
        liberaLista(fila->prox);
        free(fila);
    }
}

int main()
{
    PIVO pivo;
    pivo.ini = NULL;
    pivo.fim = NULL;
    srand(time(NULL));

    int i,valor;
    for (i=0;i<TAM;i++)
    {
        if (rand()%2==0)
        {
            //inserirPrioridadeOrdenada(&pivo,rand()%100,rand()%1000);
            inserirPrioridade(&pivo,rand()%100,rand()%1000);
        }
        else
        {
            //inserirPrioridadeOrdenada(&pivo,rand()%100,0);
            inserirPrioridade(&pivo,rand()%100,0);
        }
    }
    imprimirLista(pivo.ini);

    /*FILA *rem = remover(&pivo);*/
    FILA *rem = removerPrioridade(&pivo);
    //printNO(rem);
    free(rem);
    imprimirLista(pivo.ini);

    /*liberaLista(pivo.ini);*/

    return 0;
}





