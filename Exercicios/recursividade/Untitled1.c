#include <stdio.h>
#include <stdlib.h>

//funçao recursiva, imprimir de N ate 0

int main(){

int n;

  printf("Digite um valor maior que 0: ");
  scanf("%d", &n);

  imprime(n);

  return 0;


}

void imprime(int x){

  if(x == 0){
      printf("%d", x);
   }
   else{
    imprime(x - 1);
    printf(" %d", x);
    }

}
