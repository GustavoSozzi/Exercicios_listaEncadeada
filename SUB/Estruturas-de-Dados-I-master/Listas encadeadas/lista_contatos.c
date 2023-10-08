#include <stdio.h>
#include <stdlib.h>

typedef struct contato_ {
	char nome[100];
	char telefone[14];
} contato;

typedef struct node_ {
	contato *vlr;
	struct node_ *prox;
}node;

//Funções-assinaturas

node *adicionar(node *c, contato *vlr);
//void adicionar(node **c, contato *vlr outro tipo para adicionar
void imprime_arq(node *c);
void busca(node *c, char *pesq);
void lst_imprime (node *c);
node *remover(node *c);
void freelista(node **lista );
void ler_arq(node **lista);


int main()
{
    node *elemento = NULL;
    contato valor;
    int resp;
    char pesquisa[100], retira[100];
    printf("\nCadastrar dados? 1- Sim/ 2- Nao\n");
        scanf("%d", &resp);
        system("cls");
        if (resp==1){
            while (resp == 1){
                printf("\n----------------------------");
                printf("\n________CADASTRO____________");
                printf("\nNome.........: ");
                fflush(stdin);
                fgets(valor.nome, 100, stdin);
                printf("Telefone.....: ");
                fflush(stdin);
                fgets(valor.telefone, 14, stdin);

                elemento = adicionar(elemento, &valor);
                // ou  adicionar(&c, &valor);
                system("cls");
                printf("\nDeseja Continuar? 1- Sim/ 2- Nao\n");
                scanf("%d", &resp);
                system("cls");

    }

        }


        //imprimir
        printf("\n-------------------------------------");
        printf("\n________LISTA DE CONTATOS____________");
        lst_imprime (elemento);

        printf("\nPesquisar? 1- Sim/ 2- Nao\n");
        scanf("%d", &resp);
        system("cls");
        if (resp==1){
            /*Pesquisar*/
            printf("\nInforme o nome do contato: ");
            fflush(stdin);
            fgets(pesquisa, 40, stdin);
            busca(elemento, pesquisa);
        }
        printf("\nGravar em arquivo? 1- Sim/ 2- Nao\n");
        scanf("%d", &resp);
        system("cls");
        if (resp==1){
            //Retirar contato
            imprime_arq(elemento);
        }
        freelista(&elemento);
        printf("\nLer o arquivo? 1- Sim/ 2- Nao\n");
        scanf("%d", &resp);
        system("cls");
        if (resp==1){
            //Retirar contato
            ler_arq(&elemento);
        }


    return 0;
}
/*
void adicionar(node **c, contato *vlr){
    node *novo;
    contato *p;
    p = (contato* )malloc(sizeof(contato));
    novo = (node *)malloc(sizeof(node));
    *p = *vlr;
    novo->vlr = p;
    novo->prox = *c;
    *c = novo;
}
*/

node *adicionar(node *c, contato *vlr)
{
    node *novo;
    contato *p;
    p = (contato* )malloc(sizeof(contato));
    novo = (node *)malloc(sizeof(node));
    *p = *vlr;
    novo->vlr = p;
    novo->prox = c;

    return novo;
}
void lst_imprime (node *c)
{
    node *ele;
    for(ele = c; ele != NULL; ele = ele->prox){
        printf("\nNome..: %s\n", ele->vlr->nome);
        printf("telefone: %s\n", ele->vlr->telefone);
        printf("----------------------------");
    }
}
void busca(node *c, char *pesq)
{
    node *ele;
    int encontrado = 0;
    for(ele = c; ele != NULL; ele = ele->prox){
        if (strcmp(pesq, ele->vlr->nome)==0){
            printf("----------------------------\n");
            printf("Encontrado:\n");
            printf("\tNome..: %s\n", ele->vlr->nome);
            printf("\ttelefone: %s\n", ele->vlr->telefone);
            printf("----------------------------");
            encontrado = 1;
            break;
        }
    }
    if (encontrado!=1)
        printf("\nNao Encontrado!");
}

void imprime_arq(node *c){
    FILE *ptr;
    node *ele;
    ptr = fopen ("contatos.txt", "w");
    if (ptr == NULL)
        exit(1);
     for(ele = c; ele!=NULL; ele = ele->prox){
        fprintf(ptr, "---------------------------------\n");
        fprintf(ptr, "Nome.....: %s\n", ele->vlr->nome);
        fprintf(ptr, "Telefone.: %s\n", ele->vlr->telefone);
        fprintf(ptr, "---------------------------------\n");
    }
    printf("\nSalvo com sucesso!");
}
void ler_arq(node **lista){
    FILE *p2;
    int i,j;
    char c;
    char valores[1000][1000];
    p2 = fopen("contatos.txt", "r");
    if (p2==NULL)
        exit(1);
    c = fgetc(p2);
    i = 0;
    j = 0;
    while(c!=EOF){
        if (c!= '\n' || c !='-' || c != ':')
            valores[i][j] = c;
            if (c==' '){
                i++;
                printf("%s", valores[i]);
            }
        c = fgetc(p2);
    }



}


void freelista(node **lista ){
    node *atual = *lista;
    node *ant;
    while (atual!=NULL){
        ant = atual;
        atual = atual->prox;
        free (ant);
    }
    *lista = NULL;
}
