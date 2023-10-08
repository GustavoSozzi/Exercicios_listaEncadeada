#include <stdio.h>
#include <stdlib.h>

/*int main(void)
{
  // criando a variável ponteiro para o arquivo
  FILE *pont_arq;

  //abrindo o arquivo
  pont_arq = fopen("arquivo.txt", "a");

  // fechando arquivo
  fclose(pont_arq);

  //mensagem para o usuário
  printf("O arquivo foi criado com sucesso!");

  system("pause");
  return(0);
}*/


int main(){

int num1, num2;
int soma;

FILE *arq;
arq = fopen("entrada.txt", "r"); //determinando qual arquivo a ser aberto;


if(arq == NULL){
        printf("\nnao foi possivel abrir");
        exit(1); //saindo do programa
}

else{
    fscanf(arq, "%d %d", &num1, &num2); //lendo os dados diretamente do arquivo
    printf("%d %d", num1, num2);
}

soma = num1 + num2;

printf("\n %d", soma);

arq = fopen("saida.txt", "w");
fprintf(arq, "resultado soma: %d", soma);

fclose(arq);

return 0;

}




