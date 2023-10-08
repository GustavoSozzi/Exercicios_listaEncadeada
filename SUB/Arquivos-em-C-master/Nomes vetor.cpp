#include<stdio.h>
#include<conio.h>

int main(){
	char nomes[3];
	char *n;
	int i;
	
	for(i=0;i<3;i++){
		*n=nomes[i];
		printf("Insira um nome:\n");
		scanf("%s",&n);
		printf("\n");
	}
}
