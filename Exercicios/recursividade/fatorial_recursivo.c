#include <stdio.h>
#include <stdlib.h>

int main(){

  int n;

  printf("Digite um valor maior que 0: ");
  scanf("%d", &n);

  printf("Fatorial de %d: %d\n", n, fatorial(n));

  return 0;
}

int fatorial(int x){

if(x == 0 || x == 1)
    return 1;
else{
    //5 * !4
    return x * fatorial(x - 1);
}

}


