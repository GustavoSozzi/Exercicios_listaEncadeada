//By: Daniel Santos
#include<stdio.h>
#include<conio.h>
#include<malloc.h>

struct nodo{
	int valor;
	struct nodo *prox;
};

void insere_fim(struct nodo **inicio, struct nodo **fim, int v, int *status){
	struct nodo *elemento;
	
	*status = 0;

	elemento = (struct nodo *) malloc(sizeof(struct nodo));

	
 	if (elemento!=NULL){
    	elemento->valor=v;
    	elemento->prox=NULL;
    	
		if (*inicio==NULL)
        	*inicio = elemento;
    	else
        	(*fim)->prox=elemento;
     *fim=elemento;
     *status =1;
    }
}

void exclui5(struct nodo *inicio, struct nodo **fim, int *v, int *status){
	struct nodo *ant,*aux;
	aux = inicio;
	int cont = 1;
	*status = 0;
	
	if(inicio == NULL){
		printf("\nLista vazia!");
		return;
	}
	
	while(aux != NULL && cont != 5){
		ant = aux;
		aux = aux->prox;
		cont++;
	}
	
	if(cont == 5){
		*v = aux->valor;
		if(aux->prox == NULL){
			ant->prox = NULL;
			*fim = ant;
		}else
			ant->prox = aux->prox;
		free(aux);	
		*status = 1;
	}
	
}

int maior(struct nodo *inicio){
	struct nodo *aux;
	int maior;
	if(inicio!=NULL){
		maior = inicio->valor;// o maior é o primeiro elemento do campo valor
		aux = inicio;//aux aponta para o inicio da lista para testar um por um
		while(aux != NULL){
			if(aux->valor > maior)//se o valor apontado por aux for maior do que 1...
				maior = aux->valor;//...esse elemento é o maior no momento
			aux = aux->prox;//se não achar o maior, prossegue na lista ate achar...
		}
	}
	
	return maior;
}

int conta(struct nodo *inicio){
	struct nodo *aux;
	aux = inicio;
	
	int cont = 0;
	
	while(aux!=NULL){
		cont++;
		aux = aux->prox;
	}
	
	return cont;
}

int menu(){
	int opcao;
	
	system("cls");
	printf("----------------------------------------------------");
	printf("\n1 - Inserir elemento no final");
	printf("\n2 - Excluir o 5 elemento");
	printf("\n3 - Mostrar maior valor da lista");
	printf("\n4 - Mostrar numero de elementos da lista\n");
	printf("\n0 - Sair");
	printf("\n----------------------------------------------------");
	fflush(stdin);
	printf("\nO que deseja fazer? ");
	scanf("%d",&opcao);
	
	return opcao;
}

int main(){
	struct nodo *inicio, *fim, *aux;
	int opcao, valor, status;
	
	inicio = NULL;
	fim = NULL;
	
	do{
		opcao=menu();
		
		switch(opcao){
			case 0:
					break;
			case 1:
					system("cls");
					printf("--------------------INSERIR-------------------------");
					printf("\nInsira um valor: ");
					fflush(stdin);
					scanf("%d",&valor);
					printf("----------------------------------------------------");
					insere_fim(&inicio,&fim,valor,&status);
					if(status){
						printf("\n      Elemento inserido com sucesso!");
					}else
						printf("\nOcorreu um erro ao inserir o elemento.\nPor favor, tente novamente!");
					getch();
					break;
			case 2:
					system("cls");
					printf("--------------------EXCLUIR-------------------------");
					exclui5(inicio,&fim,&valor,&status);//inicio já é um endereçamento de memória, não precisa do &
					if(status)
						printf("\nElemento excluido com sucesso!");
					else
						printf("\nElemento nao encontrado para a remocao!");
					printf("\n----------------------------------------------------");
					getch();
					break;
			case 3:
					system("cls");
					printf("------------------MAIOR VALOR-----------------------");
					if(inicio == NULL)
						printf("\nLista vazia!");
					else	
						printf("\nO maior valor da lista e: %d",maior(inicio));
					printf("\n----------------------------------------------------");
					getch();
					break;
			case 4:
					system("cls");
					printf("---------------ELEMENTOS DA LISTA-------------------");
					if(inicio== NULL)
						printf("\nLista vazia!");
					else
						printf("\nElementos da lista: %d",conta(inicio));
					printf("\n----------------------------------------------------");
					aux=inicio;
					while(aux!=NULL){
						printf("\nValor: %i",aux->valor);
						aux = aux->prox;
					}	
					getch();
					break;
		}
	}while(opcao!=0);
}
