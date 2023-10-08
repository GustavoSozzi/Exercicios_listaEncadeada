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
void leitura();//para ler os Dados do usuário
void inicializa();//para inicializar a lista
void pesquisar();//para pesquisar na lista
int menu();//menu do Programa
	
Pessoa Usuario;//para manipular a estrutura Pessoa
Pessoa *L;//ponteiro do tipo Pessoa para manipular a Lista

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
					leitura();//chama a função leitura
					break;
			case 2: 
					pesquisar();//chama a fução pesquisar
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
	Pessoa *p;//ponteiro do tipo Pessoa
	
	p=malloc(sizeof(Pessoa));//ponteiro p aponta para a região do heap do tamanho Pessoa
	
	strcpy(p->nome,Usuario.nome);//variavel "nome" do NOH apontada por "p" recebe o conteudo de "nome" da struct apontada por "Usuario"
	p->peso=Usuario.peso;//variavel "peso" do NOH apontada por "p" recebe o conteudo de "peso" da struct apontada por "Usuario"
	p->altura=Usuario.altura;//variavel "altura" do NOH apontada por "p" recebe conteudo de "altura" da struct apontada por "Usuario"
	p->cpf=Usuario.cpf;//variavel "cpf" do NOH apontada por "p" recebe o conteudo de "cpf" da struct apontada por "Usuario"
	
	p->pProximo=L;//ponteiro pProximo aponta para onde L esta apontando
	
	L=p;//ponteiro L aponta para o elemento p
}

//Função para ler os dados do usuário
void leitura(){
	int i=0,pessoas=1;// i - controlar a estrutura de repetição DO WHILE;   pessoas - controlar o numero da pessoa que está sendo inserida
	
	do{
		system("cls");
		printf("-----------------------------------------------------\n");
		printf("Usuario %i\n\nInsira o nome: ",pessoas++);
		fflush(stdin);
		gets(Usuario.nome);//leitura do nome do usuario
		printf("Insira seu peso: ");
		scanf("%f",&Usuario.peso);//leitura do peso do usuario
		printf("Insira sua altura: ");
		scanf("%f",&Usuario.altura);//leitura da altura do usuario
		printf("Insira seu CPF: ");
		scanf("%lli",&Usuario.cpf);//leitura do CPF do usuario
		printf("-----------------------------------------------------\n");
		inserir();//chama a função inserir passando como parametro a estrutura Usuario
		i++;//incrementa no controlador 
	}while(i<PESSOAS);
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
		}
		pAux = pAux->pProximo;//pAux aponta para onde pProximo esta apontando
	}
	fclose(pFile);//fecha o arquivo
}

//Função Menu
int menu(){
	int opcao;
	
	printf("-----------------------------------------------------\n");
	printf("1 - Inserir novo usuario\n");
	printf("2 - Pesquisar pessoa por CPF\n\n");
	printf("0 - Sair\n");
	printf("-----------------------------------------------------\n");
	printf("Selecione o que deseja fazer: ");
	fflush(stdin);
	scanf("%i",&opcao);//leitura da opção escolhida
	
	return opcao;//retorna a opção escohida
}
