#include <stdio.h>
typedef struct{
 char nome[30];
 float peso;
 float altura;
 int cpf;
 } Pessoa;
 
#define PESSOAS 10

typedef struct {
	 Pessoa cadastro;
	 struct no *prox; 
 } no;

 no *L;
 Pessoa academia;

 int main() { 	
	float imc;
	
	L == NULL;

	printf("Insira seu nome: ");
 	gets(academia.nome);
 	printf("Insira sua altura: ");
 	scanf("%1.2f",academia.altura);
 	printf("Insira sua cpf : ");
 	scanf("%i",academia.cpf);
 	fb();
 	
 	imc=academia.peso/(academia.altura*academia.altura);
 
 	return 0;
 }
fb ()
{
  float imc;
   	 	no *p; 
	 p = malloc(sizeof (no));
	 
	 p->cadastro=academia;
	 p->prox = L;
	 L = p;
}


 
 
 	
 
  
