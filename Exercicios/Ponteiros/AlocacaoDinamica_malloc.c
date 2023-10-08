#include <stdio.h>
#include <stdlib.h>

int main(){


int *x;

x = malloc(sizeof(int));

if(x){
    printf("Memoria alocada com sucesso");
    printf("\nx: %d: ", *x);
    *x = 50;
    printf("\nx: %d", *x);
}

else{
    printf("Erro ao alocar memoria");
}

}
