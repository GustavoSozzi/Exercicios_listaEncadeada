#include<stdio.h>
#include<stdlib.h>

void main(){
	//Alocação dinâmica
	char *nomeAgenda;
	nomeAgenda = malloc(10*sizeof(char));
	
	//Arquivo
	FILE *pAgenda;
	pAgenda=fopen("agendas.txt","a+");
	
	printf("### AGENDA 1.0 ###\n\nSelecione a agenda que deseja abrir: \n");
	do{
		fscanf(pAgenda,"%s\n",nomeAgenda);
		printf("%s",nomeAgenda);
	}while(!EOF);
}
