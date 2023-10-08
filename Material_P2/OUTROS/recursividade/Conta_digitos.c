#include <stdio.h>
#include <stdlib.h>

/*Reescreva a fun��o seguinte tornando-a recursiva. Essa fun��o conta e retorna o n�mero
de algarismos (d�gitos) que um n�mero inteiro n fornecido possui.

fun��o inteiro digitos (n : inteiro): inteiro
2 var
3 cont : inteiro
4 in�cio
5 cont <- 1
6 enquanto (n > 9) fa�a
7 n <- n / 10
8 cont <- cont + 1
9 fimenquanto
10
11 retorne cont
12 fimfun��o
*/

int main(){

    int num, cont=0;
    int algarismos;

    printf("Entre com um numero: \n");
    scanf("%d", &num);

    algarismos = digitos(num, cont);

    printf("NUMERO DE ALGARISMOS: %d\n", algarismos);

}

int digitos(int n, int cont){


//caso base

    if(n == 0){
        return cont;
    }
    else{
      return digitos(n / 10, cont+1);
    }




}
