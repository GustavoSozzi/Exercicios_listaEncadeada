#include <stdio.h>

int main() {
  // Abre o arquivo com a lista de arquivos e datas
  FILE *arquivo = fopen("lista_arquivos.txt", "r");
  if (arquivo == NULL) {
    printf("Erro ao abrir o arquivo.\n");
    return 1;
  }

  // Lê a data informada pelo usuário
  int data_informada;
  printf("Informe a data (formato aammdd): ");
  scanf("%d", &data_informada);

  // Abre o novo arquivo
  FILE *novo_arquivo = fopen("arquivos_filtrados.txt", "w");
  if (novo_arquivo == NULL) {
    printf("Erro ao criar o novo arquivo.\n");
    fclose(arquivo);
    return 1;
  }

  // Lê os nomes de arquivos e datas do arquivo original
  char nome_arquivo[100];
  int data_arquivo;
  while (fscanf(arquivo, "%s %d", nome_arquivo, &data_arquivo) == 2) {
    // Se a data do arquivo é maior ou igual à data informada, escreve o nome do arquivo no novo arquivo
    if (data_arquivo >= data_informada) {
      fprintf(novo_arquivo, "%s\n", nome_arquivo);
    }
  }

  // Fecha os arquivos
  fclose(arquivo);
  fclose(novo_arquivo);

  return 0;
}
