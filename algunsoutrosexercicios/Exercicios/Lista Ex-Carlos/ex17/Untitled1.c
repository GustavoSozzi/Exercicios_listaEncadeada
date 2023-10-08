#include <stdio.h>
#define MAX_EMPLOYEES 100

struct Employee {
  int matricula;
  char nome[26];
  double salario;
};

int main() {
  struct Employee employees[MAX_EMPLOYEES];
  int count = 0;
  double max_salario = 0;
  double min_salario = 999999999;
  int max_index, min_index;

  // L� dados dos empregados do arquivo
  FILE *fp = fopen("empregados.cad", "r");
  while (fscanf(fp, "%d %s %lf", &employees[count].matricula, employees[count].nome, &employees[count].salario) == 3) {
    // Procura o empregado com o maior sal�rio
    if (employees[count].salario > max_salario) {
      max_salario = employees[count].salario;
      max_index = count;
    }

    // Procura o empregado com o menor sal�rio
    if (employees[count].salario < min_salario) {
      min_salario = employees[count].salario;
      min_index = count;
    }

    count++;
  }
  fclose(fp);

  // Imprime informa��es dos empregados com o maior e menor sal�rio
  printf("Empregado com o maior sal�rio:\n");
  printf("Matr�cula: %d\n", employees[max_index].matricula);
  printf("Nome: %s\n", employees[max_index].nome);
  printf("Sal�rio: %.2f\n\n", employees[max_index].salario);

  printf("Empregado com o menor sal�rio:\n");
  printf("Matr�cula: %d\n", employees[min_index].matricula);
  printf("Nome: %s\n", employees[min_index].nome);
  printf("Sal�rio: %.2f\n\n", employees[min_index].salario);

  return 0;
}
