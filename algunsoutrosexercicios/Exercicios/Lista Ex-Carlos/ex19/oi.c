
/*Gere, linha por
linha, um arquivo de texto com o seu conte�do digitado pelo usu�rio durante a execu��o. Como
textos de teste, sugere-se trechos dos hinos Nacional do Estado ou de times de futebol. O n�mero de
linhas fornecidas em uma execu��o particular poder� ser maior ou igual a 1. Ao dar entrada ao texto,
sugere-se digitar apenas um espa�o separador entre palavras e colocar os sinais de pontua��o sempre
junto �s palavras, com o espa�o inserido depois deles (exemplo: Isso eh um teste. S� para entender o
que foi explicado.). Apresente, ao final do processamento, o total de linhas gravadas no arquivo.*/

#include <stdio.h>
#include <string.h>

int main() {
  FILE *file;
  char line[100];
  int line_count = 0;

  // Abre o arquivo para escrita
  file = fopen("text_file.txt", "w");
  if (file == NULL) {
    printf("Erro ao abrir o arquivo.\n");
    return 1;
  }

  // Loop para ler as linhas de texto
  while (fgets(line, sizeof(line), stdin)) {  //continua enquanto fgets retornar diferente de NULL
    // Incrementa o contador de linhas
    line_count++;
    // Escreve a linha no arquivo
    fprintf(file, "%s", line);

    if(line_count > 10){
        printf("\nNUMERO DE LINHAS EXCEDIDO");
        break;
    }
  }

  // Fecha o arquivo
  fclose(file);

  // Imprime o n�mero de linhas escritas
  printf("Total de linhas escritas: %d\n", line_count);

  return 0;
}
