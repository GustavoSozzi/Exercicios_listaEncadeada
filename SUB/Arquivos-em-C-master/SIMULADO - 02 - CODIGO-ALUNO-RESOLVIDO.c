 //SIMULADO 02 - CODIGO DO ALUNO
 //NOME:
 //DATA:
 
 /* EXAMINANDO OS CODIGOS 1 E 2 DESENVOLVA ABAIXO 
 UM PROGRAMA APENAS que utilize fila, pilha e lista e que tenha o seguinte menu
 
 0 - Sair
 1 - Inserir Fila
 2-  Inserir na Pilha
 3 - Remover da FILA e PILHA (em uma mesma funcao)
 4 - Mostrar PENULTIMO elemento da LISTA
 
 Desenvolva/remodele abaixo todo programa e suas FUNÇÕES necessarias para o 
 funcionamento conforme menu cima */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	char info[30];
	struct t_no *prox;
} t_no;

typedef struct{
	t_no *no;
	t_no *comeco, *fim;
} t_fila;

typedef struct{
	int num;
	struct t_lista *prox;
} t_lista;

typedef struct{
	int num;
	struct t_pilha *prox;
} t_pilha;

t_pilha *topo;
t_fila *F;
t_lista *L;

int menu();
int FVazia();
int PVazia();
void inicializar();
void inserirFila(char info[]);
void inserirPilha(int num);
void insereLista(int num);
void remover();
void penultimoLista();

int main(){
	int opcao, num;
	char info[30];
	
	inicializar();
	do{
		opcao = menu();
		system("cls");
		
		switch(opcao){
			case 0:
				break;
			case 1:
				fflush(stdin);
				printf("Digite alguma coisa: ");
				gets(info);
				inserirFila(info);
				break;
			case 2:
				printf("Digite um numero: ");
				scanf("%d", &num);
				inserirPilha(num);
				break;
			case 3:
				if (!FVazia() || !PVazia())
					remover();
				else
					printf("A Fila e a Pilha estao vazias!\n");
				break;
			case 4:
				insereLista(8);
				insereLista(12);
				insereLista(18);
				penultimoLista();
				break;
			default:
				printf("Opcao invalida!\n");
		}
	}while (opcao != 0);
	
	printf("Obrigado, volte sempre!");
	return 0;
}

void inicializar(){
	L = malloc(sizeof(t_lista));
	F = malloc(sizeof(t_fila));
	
	L = NULL;
	F->comeco = NULL;
	F->fim = NULL;
}

int menu(){
	int opcao;
	
	printf("---------MENU DE OPCOES----------\n");
	printf("| 0 - SAIR                      |\n");
	printf("| 1 - Inserir na FILA           |\n");
	printf("| 2 - Inserir na PILHA          |\n");
	printf("| 3 - Remover da FILA e PILHA   |\n");
	printf("| 4 - Mostrar Penultimo LISTA   |\n");
	printf("---------------------------------\n\n");
	
	printf("O que voce deseja fazer? ");
	
	scanf("%d", &opcao);
	
	return opcao;
}

int FVazia(){
	return (F->comeco == NULL ? 1 : 0);
}

int PVazia(){
	return (topo == NULL ? 1 : 0);
}

void inserirFila(char info[]){
	t_no *aux = malloc(sizeof(t_no));
	
	strcpy(aux->info, info);
	aux->prox = NULL;
	
	if (FVazia())
		F->comeco = aux;
	else
		F->fim->prox = aux;
		
	F->fim = aux;
}

void inserirPilha(int num){
	t_pilha *aux = malloc(sizeof(t_pilha));

	aux->num = num;
	aux->prox = topo;
	
	topo = aux;
}

void remover(){
	t_no *aux = F->comeco;
	t_pilha *aux2 = topo;
	
	//Removendo FILA
	if (!FVazia()){
		F->comeco = aux->prox;
		printf("Elemento %s removido com sucesso da FILA!\n", aux->info);
		free(aux);
	}
	else printf("A Fila esta vazia!\n");
	
	//Removendo PILHA
	if (!PVazia()){
		topo = topo->prox;
		printf("Elemento %d removido com sucesso da PILHA!\n", aux2->num);
		free(aux2);
	}
	else printf("A Pilha esta vazia!\n");
}

void insereLista(int num){
	t_lista *aux = malloc(sizeof (t_lista));
	
	aux->num = num;
	aux->prox = L;
	L = aux;
}

void penultimoLista(){
	t_lista *aux = L, *ant;
	
	while (aux->prox != NULL){
		ant = aux;
		aux = aux->prox;
	}
	
	printf("Penultimo = %d\n", ant->num);
}
