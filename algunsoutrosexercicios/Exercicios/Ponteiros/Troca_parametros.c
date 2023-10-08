#include <stdio.h>
#include <stdlib.h>

//Exercicio: trocando o conteudo de duas variaveis


int main(){

int a, *b;

a=11;
b=&a;
a = 33;
*b = 115;

printf("%d", a);

//printf("%p",b);


}


/*void troca(float *a, float *b){

float c;

c = *a;
*a = *b;
*b = c;

}

int main(){

float  num1 = 52.2; float num2 = 77.8;

printf("\nNum1: %f", num1);
printf("\nNum2: %f", num2);

troca(&num1, &num2);

printf("\nNum1: %f", num1);
printf("\nNum2: %f", num2);


}
*/
