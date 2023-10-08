#include<stdio.h>
#include<stdlib.h>

int main(){
	//1- Declaração de variável do tipo ponteiro
	int *pInteiro;
	
	//2- Alocação de 10 bytes inteiro e atribui ao ponteiro pInteiro o primeiro endereço do primeiro byte alocado
	pInteiro=malloc(5*sizeof(int));
	
	//
	free(pInteiro);
	
	return 0;
}
