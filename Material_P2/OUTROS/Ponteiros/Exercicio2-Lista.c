#include <stdio.h>
#include <stdlib.h>

int main(){

int x, y;
int *p, *q;

x=2;
y=8;


p = &x; //recebendo o endereço de x;
q = &y;

printf("Endereço de x %p e valor de x: %d\n", &x, x); //mostrando endereco de x e valor de x
printf("valor de p %d e valor de *p %d\n", p, *p);    //lixo de memoria de p e para oque p aponta, no caso x(que recebeu 2)
printf("Endereco de y: %p e valor de y: %d\n", &y, y);
printf("Valor de Q: %d e Valor de *Q: %d\n", q, *q);
printf("Endereco de P: %p\n", &p);
printf("Endereco de Q: %p\n", &q);

return 0;
}
