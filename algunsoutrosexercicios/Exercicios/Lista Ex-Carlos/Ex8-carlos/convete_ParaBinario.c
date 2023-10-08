#include <stdio.h>
#include <stdlib.h>

/*Faça um programa que leia números positivos
e os converta em binário. Cada número binário deverá ser salvo em uma linha de um arquivo texto. O
programa termina quando o usuário digitar um número negativo.*/

void decimal_para_binario(int num, char* binario);

int main(){
  int num;
  char binario[32];
  FILE* arquivo = fopen("numeros_binarios.txt", "w"); //Abre o arquivo para escrita
  if (arquivo == NULL){
      printf("Erro ao abrir arquivo!\n");
      return 1;
  }
  printf("Insira numeros positivos para conversao para binario, insira numero negativo para encerrar:\n");
  scanf("%d", &num);
  while(num >= 0){
    decimal_para_binario(num, binario);
    fprintf(arquivo, "%s\n", binario); //Salva cada número binário em uma linha do arquivo
    printf("Insira outro numero: ");
    scanf("%d", &num);
  }
  fclose(arquivo); //Fecha o arquivo
  return 0;
}

void decimal_para_binario(int num, char* binario){
  int i;
  for (i = 31; i >= 0; i--){
    binario[i] = (num % 2) + '0';
    num /= 2;
  }
  binario[32] = '\0';
}
