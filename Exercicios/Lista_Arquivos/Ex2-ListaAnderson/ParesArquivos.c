#include <stdio.h>
#include <stdlib.h>

int main(){

int num[50];
int i;
int cont=0;

FILE *arq;
arq = fopen("entrada.txt", "r"); //determinando qual arquivo a ser aberto;


if(arq == NULL){
        printf("\nnao foi possivel abrir");
        exit(1); //saindo do programa
}

else{
    while(!feof(arq)){ //enquanto nao chegar no final do arquivo
        for(i=0; i<50; i++){
        fscanf(arq, "%d", &num[i]); //lendo os dados diretamente do arquivo
    }
    }
}

for(i=0; i<5; i++){
    printf("%d ", num[i]);
}

fclose(arq);

return 0;

}
