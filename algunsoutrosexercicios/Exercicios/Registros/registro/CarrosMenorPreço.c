#include <stdio.h>
#include <stdlib.h>

/*crie algoritmo que leia um vetor com os dados de 5 carros*/

typedef struct carro{

    char marca[32];
    int ano;
    float preco;
}Carro;

int main(){

   int  i;
   Carro car[3];
   //float p;
   for(i=0; i<3; i++){

   printf("marca: ");
   scanf("%s", &car[i].marca);

   printf("ano: ");
   scanf("%d", &car[i].ano);

   printf("preco: ");
   scanf("%f", &car[i].preco);
   }

    for(i=0; i<3; i++){
          printf("\bmarca: %s", car[i].marca);
          printf("\nano: ", car[i].ano);
           printf("\npreco: ", car[i].preco);


    }



return 0;
}
