#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

int main(){
	char nome[30];
	int cont=0,i;
	
	printf("Insira seu nome[max 30 caracteres]:\n");
	do{
		nome[cont]=getchar();
		cont++;
	}while(nome[cont]!=13);
	printf("\nSeu nome invertido e:\n");
	for(i=cont;i==0;i--){
		printf("%c",nome[i]);
	}
	
	return 0;
}
