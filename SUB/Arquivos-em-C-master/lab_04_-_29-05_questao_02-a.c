#include<stdio.h>

struct nodo{
	int valor;
	struct nodo *prox;
	struct nodo *ant;
};

void insere_depois_prim(struct nodo *inicio, struct nodo **fim, int v, int *status){
	struct nodo *novo;
	*status = 0;
	
	if(inicio != NULL){
		novo = (struct nodo *) malloc(sizeof(struct nodo));
		
		if(novo!=NULL){
			novo->valor = v;
			novo->prox = inicio->prox;
			
			if(inicio->prox != NULL)
				(inicio->prox)->ant = novo;
			else *fim = novo;
			inicio->prox = novo;
			novo->ant = inicio;
			*status = 1;
		}
	}
	printf("\nValor inserido no nodo: %d",novo->valor);
}

//Lista sem ptr fim
/*
void insere_depois_prim(struct nodo *inicio, int v, int *status){
	struct nodo *novo;
	*status = 0;
	
	if(inicio!=NULL){
		novo = (struct nodo *) malloc(sizeof(struct nodo));
		if(novo!=NULL){
			novo->valor = v;
			novo->prox = inicio->prox;
			
			if(inicio->prox != NULL)
				(inicio->prox)->ant = novo;
			
			inicio->prox = novo;
			novo->ant = inicio;
			*status = 1;
		}
	}
}
*/

int main(){
	struct nodo *inicio,*fim;
	int *status;
	int valor;
	
	inicio = NULL;
	fim = NULL;
	
	printf("\nInsira um valor:");
	scanf("%d",&valor);
	
	insere_depois_prim(&inicio,&fim, valor, &status);
	
	return 0;
}
