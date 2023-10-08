#include <stdio.h>
#include <stdlib.h>

#define TAM 50


int Conta_Palavra(char txt[]) //Contando palavras de uma string char
{
    int i,cont=0;
    for (i=0;i<TAM && txt[i]!='\0';i++)
    {
        if (txt[i]!=' ')
        {
            cont++;
        }
    }
    return cont;
}


int main(){

    int j, i;
    int num1=10;
    float num2=10.2;
    char string[TAM] = "Gustavo";


    printf("\nNum1: %d e endereco de memoria: %p\n", num1, &num1);
    printf("\nNum2: %2.f e endereco de memoria: %p\n", num2, &num2);

    i = Conta_Palavra(string);

    for(j=0; j<i; j++){
        printf("\nEndereco: %p e Conteudo: %c\n", string + j, *(string + j));
    }
}
