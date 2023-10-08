
/*Faça um programa que leia do teclado
o nome de um arquivo.
a) Se o arquivo existir, o programa deve solicitar um novo nome para o arquivo e renomeá-lo.
b) Se o arquivo não existir, a mensagem “arquivo inexistente” deve ser impressa e o processo deve
ser reiniciado com a leitura de um outro nome de arquivo.
c) O programa deve parar quando for digitado um nome vazio*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char arquivo_antigo[100], arquivo_novo[100];

  while (1) {
    printf("Digite o nome do arquivo: ");
    scanf("%s", arquivo_antigo);
    if (strlen(arquivo_antigo) == 0) break;   //strlen compara as strings, se nao tiver nada e igual a 0
    if (rename(arquivo_antigo, arquivo_novo) == 0) {
      printf("Digite o novo nome do arquivo: ");
      scanf("%s", arquivo_novo);
      if (rename(arquivo_antigo, arquivo_novo) != 0) {
        perror("Erro ao renomear o arquivo");
        return 1;
      }
    } else {
      perror("Arquivo inexistente");
    }
  }

  return 0;
}

