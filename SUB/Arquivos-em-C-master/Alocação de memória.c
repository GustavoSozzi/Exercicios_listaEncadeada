#include<stdio.h>
#include<stdlib.h>

int main(){
	//1- Declara��o de vari�vel do tipo ponteiro
	int *pInteiro;
	
	//2- Aloca��o de 10 bytes inteiro e atribui ao ponteiro pInteiro o primeiro endere�o do primeiro byte alocado
	pInteiro=malloc(5*sizeof(int));
	
	//
	free(pInteiro);
	
	return 0;
}
