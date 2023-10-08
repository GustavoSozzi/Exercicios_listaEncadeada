//Declaração das bibliotecas

#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include <math.h>

#include <conio.h>



typedef struct{

	char nome[30];

	float peso;

	float altura;

	int cpf;

	struct Pessoa *pProximo;

}Pessoa;



Pessoa *l;



#define PESSOAS 2





void Menu();

void Cadastro();

void cpf();

void sair();

int main()

{

	Menu();
	return 0;

}
  //--------------------------------------Menu-----------------------------------------------------------

void Menu()

{

	

	int codigo; 

		

	printf("---------------Menu--------------\n\n");

	printf ("01 -    Cadastrar\n"); 

	printf ("02 -  Pesquisar por cpf\n\n");

	

	

	printf("Digite a opcao desejada: \n\n");

	scanf("%d",&codigo);

	system ("cls");

	

	switch (codigo)

	{

		case 0:

		printf ("00 - Sair do sistema\n");

		sair();

		break;

		

		case 1: 

		printf ("01 - Cadastrar\n"); 

		Cadastro();

		break;

		

		case 2:

		printf ("02- Pesquisar por cpf\n" );

		cpf(); 

		break;

		

		default:

		printf("CODIGO INVALIDO\n");



	}

	

	system ("pause");

	

}



// ---------------------------------------Cadastro ------------------------------------------------------------





void Cadastro()

{

	int cont;

	float imc;

	int guardar;

	

	FILE *arquivo;

	l = NULL;

	

	if ((arquivo = fopen ("IMC.txt", "w+t")) == NULL)

    		{

    			printf ("Erro, este arquivo nao existe");

    			exit(1);

    		}

    		

    		fflush(stdin);

    		//Salvar o CPF dentro do arquivo "IMC.txt"

    		fprintf (arquivo, "%i", guardar);

    		//Fecha o arquivo

    		fclose (arquivo);

	

	

	

	

		

		//Criar um ponteiro para a estrutura Pessoa

		Pessoa *p;

		//Ponteiro p que aponta para regiao do heap do tamanho de Pessoa

		p = malloc (sizeof (Pessoa));

		//Lendo os dados das PESSOAS

		printf ("------CADASTRO DE PESSOA %i------\n", cont);

		printf ("\nNome..: ");

		scanf ("%s", &p->nome);

		printf ("Peso..:");

		scanf ("%f", &p->peso);

		printf ("Altura:");

		scanf ("%f", &p->altura);

		printf ("CPF...: ");

		scanf ("%i", &p->cpf);

		//O ponteiro pProximo apontara para onde l esta apontando

		p->pProximo = l;

		//l apontara para onde p estiver apontando

		l = p;

		//imc recebe o calculo do imc 

		imc = p->peso / (p->altura * p->altura);

	

 	 Menu();

 return 0;

}





 

    

    //----------------------------------------Pesquisar Cpf-------------------------------------------------

   

   

void cpf()

{

    int pesq_cpf;

    int CPF;

    Pessoa *aux = l;

   	float imc;

   	

   	FILE *arquivo;

	l = NULL;

   

   

   

    printf("\nDigite um CPF: ");

    scanf("%i",&pesq_cpf);

    aux = l;

    //Estrutura while para verificar o cpf 

    while (aux != NULL)

    {

    	

    	if (aux->cpf == pesq_cpf)

    	{

    		printf ("\nIMC e: %.2f\n", imc);

				//cria um arquivo com o nome "IMC.txt"

			if ((arquivo = fopen ("IMC.txt", "r")) == NULL)

    		{

    			printf ("Erro, este arquivo nao existe");

    			exit(1);

    		}

    		fflush(stdin);

    		//Salvar o CPF dentro do arquivo "IMC.txt"

    		fprintf (arquivo, "%i", pesq_cpf);

    		//Fecha o arquivo

    		fclose (arquivo);

    		return 0;

    	}

    	else

    	{

    		aux = aux->pProximo;

    	}

    }



getch();

return 0;

}



void sair()

{

	char letra;

	

	printf("Digite (s) - sair ou (n) - para voltar ao Menu\n\n");

	scanf("%s",&letra);

	

	if ((letra=='s')||(letra=='S'))

	{

	system ("pause\n\n");	

	}

	else if

	

		((letra=='n')||(letra=='N'))

		

	Menu();

	

return 0;

	

}









