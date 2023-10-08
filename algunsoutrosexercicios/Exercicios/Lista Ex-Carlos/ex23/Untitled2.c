
/*Crie um arquivo de
texto, todo em min�sculas, sem acentos ou cedilha, a partir de um texto digitado, em que mudan�as de
linha podem ser tamb�m sinalizadas pelo s�mbolo �#�. Na gera��o do arquivo, sempre que no texto de

entrada for encontrado o caractere �#�, deve ser gerada uma mudan�a de linha. Os caracteres �#�
n�o dever�o aparecer no arquivo de texto gerado.

Contabilize o n�mero de linhas gravadas no arquivo de texto e apresente esse total ao final do processa-
mento.*/


#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_LEN 1000

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

  // L� o texto digitado
  printf("Digite o texto: ");
  fgets(entrada, MAX_LEN, stdin);

  // Processa o texto digitado
  int i;
  for (i = 0; i < strlen(entrada); i++) { //conta quantos caracteres foram digitados strlen
    char c = tolower(entrada[i]);
    if (c != '#') {
      fprintf(arquivo, "%c", c);
    } else {
      fprintf(arquivo, "\n");
      cont_linhas++;
    }
  }

  // Fecha o arquivo
  fclose(arquivo);

  // Exibe o n�mero de linhas gravadas
  printf("Foram gravadas %d linhas.\n", cont_linhas + 1);

  return 0;
}
