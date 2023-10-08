#include <stdio.h>

typedef struct {
	int info;
	struct t_pilha *prox;
} t_pilha;

t_pilha *topo;

int novoValor;

//verifica se a lista esta vazia
int vazia(){
	return (topo == NULL? 1 : 0);
}
//cria a pilha
void cria_pilha(){
	topo = malloc(sizeof (t_pilha));
	topo = NULL;
}
//insere um elemento na pilha
void inserir(){
	t_pilha *elemento = malloc(sizeof(t_pilha));

	elemento->info = novoValor;
	elemento->prox = topo;
	topo = elemento;

	printf("\nElemento inserido com sucesso!");
}
//mostra os elementos da pilha
void mostrar(){
	t_pilha *auxiliar;
	
	auxiliar = topo;
	
	while(auxiliar != NULL){
		printf("\nValor: %d",auxiliar->info);
	
		auxiliar = auxiliar->prox;
	}
}
//Função principal do programa
int main(){
	cria_pilha();
	
	do{
		printf("\nInsira um valor: ");
		scanf("%d", &novoValor);
		if(novoValor==0)
			break;		
		inserir();
	}while(novoValor!=0);
	
	mostrar();
}
