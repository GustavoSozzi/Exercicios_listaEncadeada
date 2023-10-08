#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*Faça um programa que leia 100 números.
Esse programa deverá, em seguida, armazenar esses números em um arquivo binário*/

int main(){

int vet[100], i;
srand(time(NULL));

FILE *arq = fopen("binario.txt", "wb"); //escrevendo arquivo binario

if(arq == NULL){
    exit(1);
}

for(i=0; i<100; i++){
    vet[i] = rand() % 10;
}

// escrevendo os números no arquivo
    fwrite(vet, sizeof(int), 100, arq);

    // fechando o arquivo
    fclose(arq);

}
