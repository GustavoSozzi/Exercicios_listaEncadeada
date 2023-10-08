#include <stdio.h>
#include <stdlib.h>

/*Escreva um método recursivo tal que para um
inteiro positivo n imprima números ímpares:
a) entre 1 e n
b) entre n e 1*/

int main(){

    int n = 1000;

    num_impares(n);
    imprime_crescente_impar(n);

    printf("\nIMPRESSO TODOS OS NUMEROS IMPARES");

}

int num_impares(int n){

    if(n<=0){
    return ;
    }

    if(n%2!=0){
        printf("%d\n", n);
    }

    num_impares(n-1);

}

int imprime_crescente_impar(int n){

     if (n <= 0) {
        // Caso base: chegou ao fim da sequência
        return;
     }
      // Chama a função recursivamente para o próximo número
     imprime_crescente_impar(n-1); //ordem crescente
     if (n % 2 != 0) {
        // Se o número é ímpar, imprime
        printf("\n%d ", n);
    }
}


