/*Liste o arquivo de
texto gerado no exercício anterior, linha por linha, com a primeira letra de cada linha em maiúsculas.
Apresente, ao final do processamento, o número de linhas lidas do arquivo.*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_LEN 1000

void Primeira_letra(FILE *arq){
    int linha_num = 1;
    char linha[MAX_LEN];

    while(fgets(linha, MAX_LEN, arq) != NULL){
        if(linha[0] >= 'a' && linha[0] <= 'z'){
            linha[0]=linha[0]-32;
        }
        printf("Linha %d: %s", linha_num, linha);
        linha_num++;
    }
}

int main() {
  char entrada[MAX_LEN];
  int cont_linhas = 0;
  FILE *arquivo;

  // Abre o arquivo para escrita
  arquivo = fopen("arquivo.txt", "w");
  if (arquivo == NULL) {
    printf("Erro ao abrir o arquivo.\n");
    return 1;
  }

  // Lê o texto digitado
  printf("Digite o texto: ");
  fgets(entrada, MAX_LEN, stdin);

  // Processa o texto digitado
  int i;
  for (i = 0; i < strlen(entrada); i++) {
    char c = tolower(entrada[i]);
    if (c != '#') {
      fprintf(arquivo, "%c", c);
    } else {
      fprintf(arquivo, "\n");
      cont_linhas++;
    }
  }

  // Exibe o número de linhas gravadas
  printf("Foram gravadas %d linhas.\n", cont_linhas + 1);

  Primeira_letra(arquivo);

  fclose(arquivo);
  return 0;
}
