#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<ctype.h>


int main(){
    setlocale(LC_ALL,"Portuguese");

    FILE *e, *s;
    char entrada[41], saida[41];

    int c;
    int erro=0;//status

    printf("Insira o nome do arquivo de entrada: ");
    setbuf(stdin, NULL);
    scanf("%40s",entrada);
    printf("%s\n",entrada);

    printf("Digite o nome do arquivo de saída: ");
    setbuf(stdin, NULL);
    scanf("%40[^\n]",saida);
    printf("%s\n",saida);

    e = fopen(entrada,"r");
    if(e == NULL){
        printf("\nNão foi possível abrir o arquivo de entrada!");
        erro=1;
    }

    s = fopen(saida,"w");
    if(s == NULL){
        printf("Não foi possível abrir o arquivo de saída!");
        erro=2;
    }

    //Lê a entrada e escreve na saída
    if (!erro) while((c=fgetc(e))!=EOF){
        fputc(toupper(c),s);
    }

    fclose(e);
    fclose(s);
    return 0;
}
