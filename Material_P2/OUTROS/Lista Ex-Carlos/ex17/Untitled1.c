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

  // Lê dados dos empregados do arquivo
  FILE *fp = fopen("empregados.cad", "r");
  while (fscanf(fp, "%d %s %lf", &employees[count].matricula, employees[count].nome, &employees[count].salario) == 3) {
    // Procura o empregado com o maior salário
    if (employees[count].salario > max_salario) {
      max_salario = employees[count].salario;
      max_index = count;
    }

    // Procura o empregado com o menor salário
    if (employees[count].salario < min_salario) {
      min_salario = employees[count].salario;
      min_index = count;
    }

    count++;
  }
  fclose(fp);

  // Imprime informações dos empregados com o maior e menor salário
  printf("Empregado com o maior salário:\n");
  printf("Matrícula: %d\n", employees[max_index].matricula);
  printf("Nome: %s\n", employees[max_index].nome);
  printf("Salário: %.2f\n\n", employees[max_index].salario);

  printf("Empregado com o menor salário:\n");
  printf("Matrícula: %d\n", employees[min_index].matricula);
  printf("Nome: %s\n", employees[min_index].nome);
  printf("Salário: %.2f\n\n", employees[min_index].salario);

  return 0;
}
