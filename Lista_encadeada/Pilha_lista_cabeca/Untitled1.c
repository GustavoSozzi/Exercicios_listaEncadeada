#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//pilha na lista encadeada com celula cabeca

//pila cheia == tam-1;

typedef struct pessoa
{
    int codigo;
    char nome[100];
    struct pessoa *prox;
} Celula;

void empilhar(Celula *celula)
{
    Celula *novo = (Celula*)malloc(sizeof(Celula));

    if(novo==NULL)
    {
        printf("\nerro ao alocar");
        exit(1);
    }

    printf("\nDigite o novo codigo codigo: ");
    scanf("%d", &novo->codigo);
    fflush(stdin);

    novo->prox = NULL;

    printf("\ndigite o nome: \n");
    scanf("%[^\n]s", novo->nome);

    Celula *tmp = celula; //neste codigo nao foi feito celula->prox para que entre no while, pois iniciamente tmp ira apontar para null, no caso lista vazia;

    while(tmp->prox != NULL)
    {
        tmp = tmp->prox;
    }

    tmp->prox = novo; //adiciona ao final da lista;

    printf("\nelemento empilhado com sucesso\n");

}

void desempilhar(Celula *celula)
{
    if(celula->prox == NULL) //verificando se esta vazia a pilha
    {
        printf("\npilha vazia");
    }

    Celula *atual = celula->prox; //recebe o primeiro elemento da cabe�a
    Celula *ant = celula;

    while(atual->prox != NULL)
    {
        ant = atual;
        atual = atual->prox;
    }

    ant->prox = atual->prox; //anterior ira apontar para o penultimo
    //atual apontando para o ultimo elemento da lista antes da desempilhacao

    printf("Removido-> %d - %s\n", atual->codigo, atual->nome);

    if(ant == celula && ant->prox == NULL) // se removeu o �ltimo elemento, atualiza a cabe�a da lista
    {
        celula->prox = NULL;
    }

    free(atual);
}

void imprimir(Celula *celula)
{
    if(celula->prox == NULL)
    {
        printf("\npilha vazia\n");
    }

    Celula *aux = celula->prox;

    while(aux!=NULL)
    {
        printf("\n%d-%s ", aux->codigo, aux->nome);
        aux = aux->prox;
    }


}

void liberar(Celula *celula)
{
    Celula *aux = celula->prox;

    while(aux!=NULL)
    {
        free(aux);
        aux = aux->prox;
    }
}


int main()
{
    Celula *celula = (Celula*)malloc(sizeof(Celula));
    celula->prox = NULL;

    int op=0;

    if(celula == NULL)
    {
        printf("\nerro ao alocar memoria");
        exit(1);
    }

    while(op!=4)
    {
        printf("\n1-empilhar\n2-desempilhar\n3-imprimir\n4-sair\n");
        scanf("%d", &op);

        if(op == 1)
        {
            empilhar(celula);
        }
        else if(op == 2)
        {
            desempilhar(celula);
        }
        else if(op == 3)
        {
            imprimir(celula);
        }
    }

    liberar(celula);
}

/*

#include<stdio.h>
#include<stdlib.h>


struct Pilha {

    int topo;
    int capa;
    float *pElem;

};

void criarpilha( struct Pilha *p, int c ){

   p->topo = -1;
   p->capa = c;
   p->pElem = (float*) malloc (c * sizeof(float));

}


void push ( struct Pilha *p, float v){

    p->topo++;
    p->pElem [p->topo] = v;

}

float sub(struct Pilha *p)
{
  int x,y;
  float calc;
  p->topo--;
  x=p->pElem [p->topo];
  p->topo++;
  y=p->pElem [p->topo];
  calc=x-y;
  p->topo--;
  p->pElem [p->topo]=calc;

  return calc;

}

float mpy(struct Pilha *p)
{
  int x,y;
  float calc;
  p->topo--;
  x=p->pElem [p->topo];
  p->topo++;
  y=p->pElem [p->topo];

  calc=x*y;

  p->topo--;
  p->pElem [p->topo]=calc;

  return calc;
}

float add(struct Pilha *p)
{
  int x,y;
  float calc;
  p->topo--;
  x=p->pElem [p->topo];
  p->topo++;
  y=p->pElem [p->topo];
  calc=x+y;
  p->topo--;
  p->pElem [p->topo]=calc;


  return calc;
}


float Div(struct Pilha *p)
{
  int x,y;
  float calc;
  p->topo--;
  x=p->pElem [p->topo];
  p->topo++;
  y=p->pElem [p->topo];
  calc=x/y;
  p->topo--;
  p->pElem [p->topo]=calc;

  return calc;
}

float dec(struct Pilha *p)
{
  int x;
  x=p->pElem [p->topo];
  x--;
  return x;
}


float  pop ( struct Pilha *p ){

   float aux = p->pElem [p->topo];
   p->topo--;
   return aux;

}

float monstrarpilha ( struct Pilha *p ){

   return p->pElem [p->topo];

}

int main(){

    struct Pilha p;
    int capacidade=4;
    float valor;
    int A=9,B=3,C=2,D=1,E=1;

    criarpilha (&p, capacidade);

    push(&p,A);
    printf("\nPUSH A: %.1f\n",monstrarpilha(&p));

    push(&p,B);
    printf("\nPUSH B: %.1f\n",monstrarpilha(&p));

    sub(&p);
    printf("\nSubtracao: %.1f\n",sub(&p));

    push(&p,C);
    printf("\nPUSH C: %.1f\n",monstrarpilha(&p));

    push(&p,D);
    printf("\nPUSH D: %.1f\n",monstrarpilha(&p));

    push(&p,E);
    printf("\nPUSH E: %.1f\n",monstrarpilha(&p));

    mpy(&p);
    printf("\nmultiplicacao: %.1f\n",mpy(&p));

    add(&p);
    printf("\nadicao: %.1f\n",add(&p));

    dec(&p);
    printf("\ndecrementar: %.1f\n",dec(&p));

    Div(&p);
    printf("\ndivisao: %.1f\n",Div(&p));

    printf("\nPOP F%.1f\n",pop(&p));



}


busca_e_remove (int y, celula *le)
{
   celula *p, *q;
   p = le;
   q = le->prox;
   while (q != NULL && q->conteudo != y) {
      p = q;
      q = q->prox;
   }
   if (q != NULL) {
      p->prox = q->prox;
      free (q);
   }
}
