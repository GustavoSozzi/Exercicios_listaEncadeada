#include <stdio.h>


void imprimir(int *num){

*num = 80;
}

int main(){

int idade = 35;

imprimir(&idade);

printf("%d", idade);
}
