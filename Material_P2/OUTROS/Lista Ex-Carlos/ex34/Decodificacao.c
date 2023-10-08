#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Faça um programa
que decodifique um determinado texto gravado em um arquivo a partir da seguinte tabela de substituição
de caracteres:

Caractere existente A E I O U V W X Y Z
Caractere a ser substituído Z Y X W V U O I E A*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Faça um programa
que decodifique um determinado texto gravado em um arquivo a partir da seguinte tabela de substituição
de caracteres:

Caractere existente A E I O U V W X Y Z
Caractere a ser substituído Z Y X W V U O I E A*/

void substitui(char *c, FILE *saida);

int main(){

    char Nome_arquivo[100];
    char Arq_saida[100];
    char c;

    printf("Nome do arquivo para leitura: ");
    scanf("%s", Nome_arquivo);
    fflush(stdin);

    printf("\nNome arquivo saida: ");
    scanf("%s", Arq_saida);
    fflush(stdin);

    FILE *arq =   fopen(Nome_arquivo, "r");
    FILE *saida = fopen(Arq_saida, "w");

    if(arq == NULL || saida == NULL){
        printf("erro no arquivo\n");
        exit(1);
    }

    while((c = fgetc(arq)) != EOF){
        substitui(&c, saida);
    }

    fclose(arq);
    fclose(saida);

}


void substitui(char *c, FILE *saida){

    char char_existente[11] = {'A', 'E', 'I', 'O', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    char substitui[11] = {'Z', 'Y', 'X', 'W', 'V', 'U', 'O', 'I', 'E', 'A'};

        if(*c == 'A'){
            fputc('Z', saida);  //escrevendo caractere por caractere
        }
        else if(*c == 'E'){
            fputc('Y', saida);
        }
        else if(*c == 'I'){
            fputc('X', saida);
        }
        else if(*c == 'O'){
            fputc('W', saida);
        }
        else if(*c == 'U'){
            fputc('V', saida);
        }
        else if(*c == 'W'){
            fputc('U', saida);
        }
        else if(*c == 'X'){
            fputc('O', saida);
        }
        else if(*c == 'Y'){
            fputc('I', saida);
        }
        else if(*c == 'Z'){
            fputc('E', saida);
        }
        else if(*c == 'V'){
            fputc('A', saida);
        }
        else{
            fputc(*c, saida);
        }

}
