//Smart Recipes 1.0
//Registra os produtos que tem na casa
//Compara com os da receita que deseja fazer
//Informa o que falta (se falta, para a receita ser feita)

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
//Estruturas
typedef struct{
		char nome[30];
		struct Receita *prox;
}Receita;

//Funções
int menu(); //Menu
void CadastrarProdutos();//CADASTRA os PRODUTOS da Casa
void MostrarProdutos();//MOSTRA os PRODUTOS da Casa
void CadastrarReceitas();//CADASTRA as RECEITAS
void MostrarReceitas();//MOSTRA  as RECEITAS
void PossoCozinhar();//Can I Cook?

void CadastrarProdutos(){
	
}

void MostrarProdutos(){
	
}

void CadastrarReceitas(){
	
}
void MostrarReceitas(){
	
}

void PossoCozinhar(){
	
}

int menu(){
	int opcao;
	
	system("cls");
	
	printf("--------------- Posso cozinhar? ----------------\n");
	printf("1 - Cadastrar produtos da Casa\n");
	printf("2 - Ver Produtos cadastrados\n");
	printf("3 - Cadastrar Receitas\n");
	printf("4 - Ver Receitas cadastradas\n");
	printf("5 - Posso cozinhar?\n\n");
	printf("0 - Sair\n");
	printf("------------------------------------------------\n");
	printf("O que deseja fazer? ");
	fflush(stdin);
	scanf("%i",&opcao);
	
	return opcao;
}

int main(){
	
	int opcao;
	
	Inicializa();
	
	do{
		opcao = menu();
		
		switch(opcao){
			case 0: break;
			case 1: 
					CadastrarProdutos();
					break;
			case 2:
					MostrarProdutos();
					break;
			case 3:
					CadastrarReceitas();
					break;
			case 4:
					MostrarReceitas();
					break;
			case 5:
					PossoCozinhar();
					break;
			default: printf("\n OPCAO INVALIDA!");
		}
	}while(opcao!=0);
}
