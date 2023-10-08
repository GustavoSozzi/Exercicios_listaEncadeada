#include<stdio.h>
#include<stdlib.h>
char cliente(char n[],char s[]){
	FILE *cli;
	
	char *dados="dados.txt";
	
	if((cli=fopen(dados,"w+b"))==NULL){
		printf("\n\nNao foi possivel abrir o arquivo para escrita.\n");
		exit(1);
	}
	
	fwrite(&n,sizeof(char),1,cli);
	fwrite(&s,sizeof(char),1,cli);
	
	rewind(cli);
	
	fread(&n,sizeof(char),1,cli);
	fread(&s,sizeof(char),1,cli);	
}
int main(){
	char nome[30];
	char senha[8];

	printf("Insira um nome de usuario:\n");
	scanf("%s",&nome);
	printf("\nInsira uma senha:\n");
	scanf("%s",&senha);
	
	cliente(nome,senha);
}
