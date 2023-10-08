#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Escreva uma função
recursiva para calcular o valor de x
n*/

int x_potencia(int x, int n){

    if(n==0){
        return 1;
    }
    else{
        return x * x_potencia(x, n-1);
    }
}

int main(){

    int x, potencia;

    printf("\nentre com o valor de x e sua pontencia: ");
    scanf("%d %d", &x, &potencia);

    printf("\nresultado: %d", x_potencia(x, potencia));
}
