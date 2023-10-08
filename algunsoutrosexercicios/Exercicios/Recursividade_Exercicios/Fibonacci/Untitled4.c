#include <stdio.h>
#include <stdlib.h>

int main(){

    int n=8;

    printf("soma do fibonacci: %d", fibonacci(n));

}

int fibonacci(int n) {
    if (n == 0) {
        return 0; // caso base 1: retorna 0 para n = 0
    } else if (n == 1) {
        return 1; // caso base 2: retorna 1 para n = 1
    } else {
        return fibonacci(n-1) + fibonacci(n-2); // cálculo recursivo para n >= 2
    }
}


