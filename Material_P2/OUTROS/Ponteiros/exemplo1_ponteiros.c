#include <stdio.h>

void imprimirPonteiro(int *v, int tam){

int i;

for(i=0; i<tam; i++){

printf(" %d ", *(v + i)); //percorrendo o vetor e imprimindo

}

}


void imprimirNome(char *letra, int tam){
int i;
    for(i=0; i<tam; i++){
    printf(" %c ", *(letra + i)); //percorrendo o vetor e imprimindo
    }


}

int main(){


int i, vet[10] = {10,11,12,13,14,15,16,18,19,20};
char letra[3] = {'a', 'b', 'c'};

imprimirPonteiro(vet, 10);
imprimirNome(letra, 3);


/*for(i=0; i<10; i++){

printf("%d", *(vet + i)) //percorrendo o vetor e imprimindo

}



/*int *valor1, valor2 = 50;
char *letra1, letra2 = 'g';

valor1 = &valor2;
letra1 = &letra2;

printf("valor da variavel valor: %d\n", valor2);
printf("endereço da variavel valor2: %p\n", &valor2);
printf("conteudo variavel valor 1: %p\n", valor1);
printf("conteudo apontado para variavel valor1: %d\n", *valor1);*/

return 0;

}
