/* Lista Encadeada Dinâmica
by: Daniel Santos
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define PESSOAS 10

//Estrtura Pessoa
typedef struct{
	char nome[30];
	float peso;
	float altura;
	long long cpf;
	struct Pessoa *pProximo;
}Pessoa;

//Protótipos das funções
int calculoIMC(Pessoa *pAux);//para calcular o IMC
void inserir();//Para inserir um novo NOH na Lista
void inicializa();//para inicializar a lista
void pesquisar();//para pesquisar na lista
void pesquisarNome();
int menu();//menu do Programa
	
Pessoa *L;//ponteiro do tipo Pessoa para manipular a Lista

int usuarios;

//----------Programa Principal----------
int main(){
	int opcao;//variavel local para receber a opção escolhida
	
	inicializa();//chama a função inicializa
	
	do{
		opcao=menu();//opcao recebe conteudo retornado pela função menu (no caso, retorna a opção escolhida)
		switch(opcao){
			case 0: 
					break;//interrompe o case
			case 1: 
					inserir();//chama a função leitura
					break;
			case 2: 
					pesquisar();//chama a fução pesquisar
					break;
			case 3:
					pesquisarNome();
					break;
			default: 
					system("cls");
					printf("Opcao invalida!\n");
		}	
	}while(opcao !=0);//quando opcao = 0 a estrutura de repetição é interrompida e sai do programa

	return 0;
}

//----------Implementação das funções----------
//Função para calcular o IMC do usuario
int calculoIMC(Pessoa *pAux){
	float imc,auxPeso,auxAltura;
	
	auxPeso = pAux->peso;//AuxPeso recebe o peso da pessoa
	auxAltura = pAux->altura;//auxAltura recebe a altura da pessoa
	
	imc = auxPeso/(auxAltura*auxAltura);//imc recebe peso dividido pela altura ao quadrado

	return imc;//retorna o IMC calculado
}

//Função para inserir um novo NOH na Lista com os dados lidos
void inserir(){
	int i=0,pessoas=1;// i - controlar a estrutura de repetição DO WHILE;   pessoas - controlar o numero da pessoa que está sendo inserida
	
	Pessoa *p;//ponteiro do tipo Pessoa
	
	p=malloc(sizeof(Pessoa));//ponteiro p aponta para a região do heap do tamanho Pessoa
	
//	do{
		system("cls");
		printf("-----------------------------------------------------\n");
		printf("Usuario %i\n\nInsira o nome: ",pessoas++);
		fflush(stdin);
		//scanf("%s",&p->nome);//leitura do nome do usuario
		gets(p->nome);
		printf("Insira seu peso: ");
		scanf("%f",&p->peso);//leitura do peso do usuario
		printf("Insira sua altura: ");
		scanf("%f",&p->altura);//leitura da altura do usuario
		printf("Insira seu CPF: ");
		scanf("%lli",&p->cpf);//leitura do CPF do usuario
		printf("-----------------------------------------------------\n");
		printf("	   Usuario registrado com sucesso!");
		getch();
			
		p->pProximo=L;//ponteiro pProximo aponta para onde L esta apontando
	
		L=p;//ponteiro L aponta para o elemento p
		
		i++;//incrementa no controlador 
//	}while(i<PESSOAS);
}

//Função para incializar a Lista
void inicializa(){
	L=NULL;//L aponta para Nulo
}

void pesquisar(){
	long long auxCPF;//variavel auxiliar do CPF
	Pessoa *pAux;//ponteiro auxiliar para a lista
	pAux = L;//pAux aponta para onde L esta apontando
	
	FILE *pFile;//cria um ponteiro pFile do tipo Arquivo(FILE)
	
	if ((pFile=fopen("IMC.txt","a+"))==NULL){//verifica se o arquivo não existe
		printf("Erro! Arquivo inexistente.");//mensagem de erro
	}
		
	system("cls");//limpa a tela
	printf("-----------------------------------------------------\n");
	printf("Insira o CPF que deseja pesquisar: ");
	fflush(stdin);
	scanf("%lli",&auxCPF);//leitura do CPF
	
	while(pAux != NULL){//repete até que pAux aponte para Nulo
		if(pAux->cpf == auxCPF){//Se o CPF apontado por pAux for igual ao CPF inserido para pesquisa...
			printf("\nCPF: %lli \nIMC: %i\n\n",pAux->cpf,calculoIMC(pAux));//Mostra na tela o CPF e o IMC da pessoa dona do CPF
			fprintf(pFile,"%lli\n",pAux->cpf);//salva o CPF no arquivo
			printf("-----------------------------------------------------\n");
			getch();
		}
		pAux = pAux->pProximo;//pAux aponta para onde pProximo esta apontando
	}
	fclose(pFile);//fecha o arquivo
}

void pesquisarNome(){
	char auxNome[30];//variavel auxiliar do CPF
	Pessoa *pAux;//ponteiro auxiliar para a lista
	pAux = L;//pAux aponta para onde L esta apontando
	
	system("cls");//limpa a tela
	printf("-----------------------------------------------------\n");
	printf("Insira o NOME que deseja pesquisar: ");
	fflush(stdin);
	gets(auxNome);//leitura do CPF
	
	while(pAux != NULL){//repete até que pAux aponte para Nulo
		if((strcmp(pAux->nome,auxNome))==0){//Se o CPF apontado por pAux for igual ao CPF inserido para pesquisa...
			printf("\nNOME: %s \nIMC: %i\n\n",pAux->nome,calculoIMC(pAux));//Mostra na tela o CPF e o IMC da pessoa dona do CPF
			printf("-----------------------------------------------------\n");
			getch();
		}else{
			system("cls");
			printf("Nome nao encontrado!\n");
			getch();
		}
		pAux = pAux->pProximo;//pAux aponta para onde pProximo esta apontando
	}
}

ordenar(){
	printf("Função em desenvolvimento!\n");
	getch();
	/*Pessoa *pAux;
	char auxNome[30], alfa[] = "abcdefghijklmnopqrstuvwxyz";
	int letra;
	
	pAux=L;
	
	auxNome = pAux->nome;
	
	while(pAux != NULL){
		
	}*/
}

void excluir(){
	printf("-----------------------------------------------------\n");
	printf("Sua lista possui %i usuarios!\nQual voce deseja excluir?\n",usuarios);
	scanf("%i",&num)
}

//Função Menu
int menu(){
	int opcao;
	
	system("cls");
	
	printf("-----------------------------------------------------\n");
	printf("1 - Inserir novo usuario\n");
	printf("2 - Pesquisar pessoa por CPF\n");
	printf("3 - Pesquisar pessoa por NOME\n");
	printf("4 - Exibir usuarios registrados em ordem alfabetica\n");
	printf("5 - Excluir usuario\n\n");
	printf("0 - Sair\n");
	printf("-----------------------------------------------------\n");
	printf("Selecione o que deseja fazer: ");
	fflush(stdin);
	scanf("%i",&opcao);//leitura da opção escolhida
	
	return opcao;//retorna a opção escohida
}
