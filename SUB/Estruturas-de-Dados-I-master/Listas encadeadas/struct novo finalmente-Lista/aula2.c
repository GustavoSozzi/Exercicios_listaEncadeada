#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct _contato_{

    char nome [100];
    char telefone[100];

}contato;

typedef struct _node_{

    struct _node_ *prox;
    contato *apontador;

}node;

void *limpa (node **lista);
char cria_contato(FILE *alexandria);
char le_contato (FILE *alexandria, node **lista);
node *criar(char *nome, char *telefone);
void inserirFim(node **lista, char *nome, char *telefone);
void mostra (node *lista);
void buscar (node *lista, char *nomeP);

int main (){
int n;
char nomeP[100];
FILE *alexandria;
alexandria = fopen("arroz.txt", "a+");
node *lista = NULL;

do {
    system("cls");
    printf("Digite 1 para mostrar a lista, 2 para inserir um contato e 3 para procurar:\n>>");
    scanf("%d",&n );

    if (n == 1){

        limpa (&lista);
        le_contato(alexandria, &lista);
        mostra(lista);
        getche();
    }
  else if (n == 2){

        cria_contato(alexandria);
        getche();
    }
    else if(n == 3){

        limpa (&lista);
        le_contato(alexandria, &lista);
        printf("\n\nQual contato deseja buscar:\n >>");
        scanf ("%s", nomeP);
        buscar(lista, nomeP);
        getche();

    }
} while(n!=4);
    limpa (&lista);
    fclose(alexandria);

}
char cria_contato(FILE *alexandria){

    contato vetor;
    int n = 2,i;

    printf("Digite o nome  ");
    scanf("%s", vetor.nome);

    printf("Digite o telfone  ");
    scanf("%s", vetor.telefone);

    fprintf(alexandria, "%s %s ", vetor.nome, vetor.telefone);

}

char le_contato (FILE *alexandria, node **lista){

    rewind(alexandria);

    char nome[100];
    char telefone[20];

    while (fscanf(alexandria, "%s",nome)!= EOF){

        fscanf(alexandria, "%s", telefone);
        inserirFim(lista, nome, telefone);
    }
}

node *criar(char *nome, char *telefone){
  node *elm;
  elm = (node*)malloc(sizeof(node));
  elm -> apontador = (contato *) malloc (sizeof(contato));
  strcpy(elm->apontador->nome, nome);
  strcpy(elm->apontador->telefone, telefone);
  elm->prox= NULL;

  return elm;
}

void inserirFim(node **lista, char *nome, char *telefone){
  node *tmp = *lista;

  node *novo = criar(nome, telefone);
  if (tmp == NULL){
    *lista = novo;
  }else{
    while (tmp->prox!=NULL){
      tmp = tmp->prox;
    }
    tmp->prox = novo;
  }

}

void mostra (node *lista){
    node *aux = lista;
    while (aux != NULL){

        printf("\n contato: %s,%s", aux->apontador->nome, aux->apontador->telefone);
        aux = aux->prox;
    }
}

void buscar (node *lista, char *nomeP){

     node *aux = lista;

    while(aux != NULL){

        if (strcmp (aux -> apontador -> nome,nomeP) == 0){

            printf("\ncontato encontrado: %s, %s", aux -> apontador -> nome, aux -> apontador -> telefone);

        }
        aux = aux->prox;
    }
}

void *limpa (node **lista){

    node *aux = *lista;

    while(aux!=NULL){

        aux = (*lista)->prox;
        free((*lista)->apontador);
        free(*lista);
        *lista = aux;
    }
}
__________________________________________________________________________


typedef struct _lista_ {
    int dado;
    struct _lista_ *prox;
}listaencadeada;

void inserir_ordenado(listaencadeada **li, int valor){
    listaencadeada *novo, *aux, *temp = *li;
    int valor_logico = 1;
    novo = (listaencadeada *)malloc(sizeof(listaencadeada));
    novo->dado = valor;
    novo->prox = NULL;
    while(temp != NULL){
        if (valor_logico = 1){
            if (valor < temp->dado)
                valor_logico = 0;
            else{
                aux = temp;
                temp = temp->prox;
            }
        }
    }
    novo->prox = temp;
    if (aux == NULL)
        *li = novo;
    else
        aux->prox = novo;
}
