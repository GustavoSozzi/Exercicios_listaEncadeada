/* Lista Encadeada Din�mica
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

//Prot�tipos das fun��es
int calculoIMC(Pessoa *pAux);//para calcular o IMC
void inserir();//Para inserir um novo NOH na Lista
void leitura();//para ler os Dados do usu�rio
void inicializa();//para inicializar a lista
void pesquisar();//para pesquisar na lista
int menu();//menu do Programa
	
Pessoa Usuario;//para manipular a estrutura Pessoa
Pessoa *L;//ponteiro do tipo Pessoa para manipular a Lista

//----------Programa Principal----------
int main(){
	int opcao;//variavel local para receber a op��o escolhida
	
	inicializa();//chama a fun��o inicializa
	
	do{
		opcao=menu();//opcao recebe conteudo retornado pela fun��o menu (no caso, retorna a op��o escolhida)
		switch(opcao){
			case 0: 
					break;//interrompe o case
			case 1: 
					leitura();//chama a fun��o leitura
					break;
			case 2: 
					pesquisar();//chama a fu��o pesquisar
					break;
			
			default: 
					system("cls");
					printf("Opcao invalida!\n");
		}	
	}while(opcao !=0);//quando opcao = 0 a estrutura de repeti��o � interrompida e sai do programa

	return 0;
}

//----------Implementa��o das fun��es----------
//Fun��o para calcular o IMC do usuario
int calculoIMC(Pessoa *pAux){
	float imc,auxPeso,auxAltura;
	
	auxPeso = pAux->peso;//AuxPeso recebe o peso da pessoa
	auxAltura = pAux->altura;//auxAltura recebe a altura da pessoa
	
	imc = auxPeso/(auxAltura*auxAltura);//imc recebe peso dividido pela altura ao quadrado

	return imc;//retorna o IMC calculado
}

//Fun��o para inserir um novo NOH na Lista com os dados lidos
void inserir(){
	Pessoa *p;//ponteiro do tipo Pessoa
	
	p=malloc(sizeof(Pessoa));//ponteiro p aponta para a regi�o do heap do tamanho Pessoa
	
	strcpy(p->nome,Usuario.nome);//variavel "nome" do NOH apontada por "p" recebe o conteudo de "nome" da struct apontada por "Usuario"
	p->peso=Usuario.peso;//variavel "peso" do NOH apontada por "p" recebe o conteudo de "peso" da struct apontada por "Usuario"
	p->altura=Usuario.altura;//variavel "altura" do NOH apontada por "p" recebe conteudo de "altura" da struct apontada por "Usuario"
	p->cpf=Usuario.cpf;//variavel "cpf" do NOH apontada por "p" recebe o conteudo de "cpf" da struct apontada por "Usuario"
	
	p->pProximo=L;//ponteiro pProximo aponta para onde L esta apontando
	
	L=p;//ponteiro L aponta para o elemento p
}

//Fun��o para ler os dados do usu�rio
void leitura(){
	int i=0,pessoas=1;// i - controlar a estrutura de repeti��o DO WHILE;   pessoas - controlar o numero da pessoa que est� sendo inserida
	
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
		inserir();//chama a fun��o inserir passando como parametro a estrutura Usuario
		i++;//incrementa no controlador 
	}while(i<PESSOAS);
}

//Fun��o para incializar a Lista
void inicializa(){
	L=NULL;//L aponta para Nulo
}

void pesquisar(){
	long long auxCPF;//variavel auxiliar do CPF
	Pessoa *pAux;//ponteiro auxiliar para a lista
	pAux = L;//pAux aponta para onde L esta apontando
	
	FILE *pFile;//cria um ponteiro pFile do tipo Arquivo(FILE)
	
	if ((pFile=fopen("IMC.txt","a+"))==NULL){//verifica se o arquivo n�o existe
		printf("Erro! Arquivo inexistente.");//mensagem de erro
	}
		
	system("cls");//limpa a tela
	printf("-----------------------------------------------------\n");
	printf("Insira o CPF que deseja pesquisar: ");
	fflush(stdin);
	scanf("%lli",&auxCPF);//leitura do CPF
	
	while(pAux != NULL){//repete at� que pAux aponte para Nulo
		if(pAux->cpf == auxCPF){//Se o CPF apontado por pAux for igual ao CPF inserido para pesquisa...
			printf("\nCPF: %lli \nIMC: %i\n\n",pAux->cpf,calculoIMC(pAux));//Mostra na tela o CPF e o IMC da pessoa dona do CPF
			fprintf(pFile,"%lli\n",pAux->cpf);//salva o CPF no arquivo
			printf("-----------------------------------------------------\n");
		}
		pAux = pAux->pProximo;//pAux aponta para onde pProximo esta apontando
	}
	fclose(pFile);//fecha o arquivo
}

//Fun��o Menu
int menu(){
	int opcao;
	
	printf("-----------------------------------------------------\n");
	printf("1 - Inserir novo usuario\n");
	printf("2 - Pesquisar pessoa por CPF\n\n");
	printf("0 - Sair\n");
	printf("-----------------------------------------------------\n");
	printf("Selecione o que deseja fazer: ");
	fflush(stdin);
	scanf("%i",&opcao);//leitura da op��o escolhida
	
	return opcao;//retorna a op��o escohida
}
