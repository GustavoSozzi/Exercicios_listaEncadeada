#include <stdio.h>
#include <stdlib.h>

/*Copie o arquivo
sequencial fonte.dad para um arquivo sequencial chamado fontenova.dad. Os registros do primeiro
arquivo t�m tr�s campos: chave � num�rico (inteiro), informa��o - string (30 caracteres) e data - string,
no formato ddmmaaaa. Os registros do segundo arquivo t�m esses mesmos campos mais um quarto
campo chamado de valor � num�rico (real). Os valores para preencher esse novo campo devem ser lidos
do teclado durante o processo de cria��o do novo arquivo.*/

typedef struct{
    int chave;
    char informacao[30];
    char data[9];
}Registro;


int main(){

    Registro registro;      //struct
    float valor;

    FILE *fonteNova = fopen("fontenova.dad.txt", "w");
    FILE *FonteDad = fopen("fonte.dad.txt", "r");

    if(fonteNova == NULL || FonteDad == NULL){
            printf("erro\n");
            exit(1);
    }

    while(fscanf(FonteDad, "%d %30s %9s", &registro.chave, registro.informacao, registro.data) == 3){ //verifica se os 3 campos foram lidos com sucesso e retorna **3**
    printf("Digite o valor para o registro com chave %d: ", registro.chave);
    scanf("%f", &valor);

    fprintf(fonteNova, "%d %s %s %.2f\n", registro.chave, registro.informacao, registro.data, valor); //escrevendo no arquivo;
    }

    fclose(fonteNova);
    fclose(FonteDad);

    printf("\nC�pia do arquivo concluida!!");

    return 0;

}
