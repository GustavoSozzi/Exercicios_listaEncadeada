#include <stdio.h>
#include <stdlib.h>

/*Fa�a um programa que leia n�meros positivos
e os converta em bin�rio. Cada n�mero bin�rio dever� ser salvo em uma linha de um arquivo texto. O
programa termina quando o usu�rio digitar um n�mero negativo.*/

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
    fprintf(arquivo, "%s\n", binario); //Salva cada n�mero bin�rio em uma linha do arquivo
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
