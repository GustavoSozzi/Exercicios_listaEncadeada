//Procedimento que converte toos os caracteres de uma cadeia para Maiusculo
#include <stdio.h>
#include <ctype.h> //toupper e tolower
#define TAM_MAX 100


//procedimento maiusculo
/*void maiusculo(char txt[], char txt2[]){

int i=0;

while(txt[i]!= '\0'){  //enquanto nao terminar a string
    txt2[i] = toupper(txt[i]); //toupper convertendo para maiusculo
    i++;
}

txt2[i] = '\0';
}*/


//procedimento minusculo
void maiusculo(char txt[], char txt2[]){

int i=0;

while(txt[i]!= '\0'){  //enquanto nao terminar a string
    txt2[i] = tolower(txt[i]); //toupper convertendo para maiusculo
    i++;
}

txt2[i] = '\0';
}

int main(){

char txt[TAM_MAX];
char txt2[TAM_MAX];

printf("Entre com o texto: ");
scanf("%s", &txt);

maiusculo(txt, txt2);

printf("\n%s", txt2);

return 0;
}
