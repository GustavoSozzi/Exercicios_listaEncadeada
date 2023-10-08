//procedimento ou funcao que separe as palavras em uma matriz

#include <stdio.h>


char string[50];   /* uma frase de ate 50 caracteres */
char vetor[50][30];/* cinquenta palavras de ate 30 caracteres cada */
int i,j,Npalavras,k;
int main(){
    Npalavras=1;
    /*strcpy(string,"eu fui ao baile");*/
    printf("Digite Uma Frase De No Maximo 50 Caracteres");
    gets(string);
    for(i=0;i<strlen(string);i++){
        if(string[i]!=' '){
            vetor[j][k]=string[i];
            k++;
        }
        else{
            j++;
            k=0;
            Npalavras++;
        }
    }
    printf("\nO Texto Teve %d Palavras\n\n",Npalavras);
    for(i=0;i<Npalavras;i++){
        printf("O Que Esta Armazenado Na Posicao %d Do Vetor => %s\n",i,vetor[i]);
    }
    return 0;
}

//int main(){

//char txt[50]; //uma frase de ate 50 caracteres */


/*printf("Digite Uma Frase De No Maximo 50 Caracteres: ");
scanf("%s", &txt);


separa(txt);

return 0;

}

void separa(char txt[]){


int M[50][30]; /* cinquenta palavras de ate 30 caracteres cada */
/*int i,j,Npalavras,k;

for(i=0;i<strlen(txt);i++){ // retorna um inteiro que é o comprimento do string
        if(txt[i]!=' '){
            M[j][k]=txt[i];
            k++;
        }
        else{
            j++;
            k=0;
            Npalavras++;
        }
    }
    printf("\nO Texto Teve %d Palavras\n\n",Npalavras);
    for(i=0;i<Npalavras;i++){
        printf("O Que Esta Armazenado Na Posicao %d Do Vetor => %s\n",i,M[i]);
    }
    return 0;
}*/
