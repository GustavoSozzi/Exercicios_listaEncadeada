#include <stdio.h>
#include <stdlib.h>

//funcao recursiva que calcula x elevado a n.

int potencia(int x, int n){

    if(n == 0){
        return 1;
    }
    else{
        return x * potencia(x, n - 1);
    }
}

int main(){
    int n, x;

    printf("digite o valor de x e n: ");
    scanf("%d %d", &x, &n);

    printf("resultado: %d", potencia(x, n));

    return 0;
}
