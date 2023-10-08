
/*Faça um programa que leia do teclado e
grave em um arquivo-texto empregados.cad os registros dos empregados de uma empresa, consistindo
cada um em matrícula, nome e salário do empregado. O usuário do programa deve digitar a matrícula,
seguida do nome e do salário. O nome deve ser digitado em uma linha separada da linha em que é
digitado o salário, isto é, o usuário deve teclar Enter para finalizar a digitação do nome. Para cada
empregado, o programa deve gravar no arquivo empregados.cad uma linha contendo a matrícula, o
nome e o salário, no seguinte formato:
<matrícula> <nome> <salário>
obedecendo às seguintes restrições:
a) A matrícula deve ser um valor do tipo int.

b) Todo nome deve ser gravado com exatamente 25 caracteres, desprezando os caracteres excedentes
se o nome digitado for maior, ou complementando com espaços, se for menor.
c) O salário deve ser um valor do tipo double, gravado com 2 casas decimais.
d) Deve haver exatamente um espaço entre os campos matrícula, nome e salário.
O programa deve terminar assim que o usuário digitar uma matrícula menor ou igual a zero.*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 25

int main() {
    FILE *file = fopen("empregadosCad.txt", "w");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    int matricula;
    char nome[MAX_NAME_LENGTH + 1];
    double salario;

    do {
        printf("Digite a matricula (menor ou igual a zero para encerrar): ");
        scanf("%d", &matricula);
        fflush(stdin);

        if (matricula <= 0) {
            break;
        }

        printf("Digite o nome: ");
        fgets(nome, MAX_NAME_LENGTH + 1, stdin);
        nome[strcspn(nome, "\r\n")] = 0;
        fflush(stdin);

        printf("Digite o salario: ");
        scanf("%lf", &salario);
        fflush(stdin);

        fprintf(file, "%d %-*s %.2lf\n", matricula, MAX_NAME_LENGTH, nome, salario);
    } while (matricula > 0);

    fclose(file);
    return 0;
}

