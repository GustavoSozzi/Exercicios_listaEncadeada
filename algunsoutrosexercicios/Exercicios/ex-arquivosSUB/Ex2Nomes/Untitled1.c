#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char nome[41];
    int dia, mes, ano;
} Pessoa;

/*Faça um programa que receba como entrada o ano corrente e o nome de dois arquivos: um de entrada
e outro de saída. Cada linha do arquivo de entrada contém o nome de uma pessoa (ocupando 40
caracteres) e o seu ano de nascimento. O programa deverá ler o arquivo de entrada e gerar um arquivo
de saída onde aparece o nome da pessoa seguida por uma string que representa a sua idade.
• Se a idade for menor do que 18 anos, escreva “menor de idade”
• Se a idade for maior do que 18 anos, escreva “maior de idade”
• Se a idade for igual a 18 anos, escreva “entrando na maior idade”*/

void imprimir(Pessoa pessoa[], int cont, FILE *arq_saida)
{

    int i;
    int ano_atual = 2023;
    int idade;

    for(i=0; i<cont; i++)
    {
        printf("\n%s", pessoa[i].nome);
        printf(" %d /0%d /%d", pessoa[i].dia, pessoa[i].mes, pessoa[i].ano);

        idade = ano_atual - pessoa[i].ano;

        if(idade > 18)
        {
            fprintf(arq_saida, "%s\n", pessoa[i].nome, "idade %d",idade, "maior de idade");
        }
        else if(idade < 18)
        {
            fprintf(arq_saida, "%s\n", pessoa[i].nome, " idade %d", " menor de idade");
        }
        else
        {
            fprintf(arq_saida, "%s\n", pessoa[i].nome, "idade %d", idade, "entrando na maior idade");

        }
    }

}

int main()
{
    char nome_entrada[50];
    char nome_saida[50];
    int cont=0;

    Pessoa pessoa[50];

    printf("\nEntre com o nome de arquivo de entrada e ano corrente: ");
    scanf("%s", nome_entrada);

    printf("\nNome arquivo saida: ");
    scanf("%s", nome_saida);

    FILE *arq = fopen(nome_entrada, "r");
    FILE *arq_saida = fopen(nome_saida, "w");

    if(arq == NULL || arq_saida == NULL)
    {
        printf("\nerro ao abrir um dos arquivos");
        exit(1);
    }

    while(!feof(arq))
    {
        fscanf(arq, "%[^;];", pessoa[cont].nome);
        fflush(stdin);
        fscanf(arq, "%d;%d;%d", &pessoa[cont].dia, &pessoa[cont].mes, &pessoa[cont].ano);
        fflush(stdin);
        cont++;
    }

    imprimir(pessoa, cont, arq_saida);

    fclose(arq);
    fclose(arq_saida);
}

//-------implementação dois----------//

/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[41];
    int ano_nasc;
} Pessoa;

void imprimir_idades(Pessoa pessoas[], int n, int ano_corrente, FILE *arq_saida) {
    int i;
    for (i = 0; i < n; i++) {
        int idade = ano_corrente - pessoas[i].ano_nasc;
        char* mensagem_idade;
        if (idade < 18) {
            mensagem_idade = "menor de idade";
        } else if (idade > 18) {
            mensagem_idade = "maior de idade";
        } else {
            mensagem_idade = "entrando na maior idade";
        }
        fprintf(arq_saida, "%s: %s\n", pessoas[i].nome, mensagem_idade);
    }
}

int main() {
    int ano_corrente;
    char nome_arquivo_entrada[100];
    char nome_arquivo_saida[100];

    printf("Digite o ano corrente: ");
    scanf("%d", &ano_corrente);

    printf("Digite o nome do arquivo de entrada: ");
    scanf("%s", nome_arquivo_entrada);

    printf("Digite o nome do arquivo de saída: ");
    scanf("%s", nome_arquivo_saida);

    FILE* arq_entrada = fopen(nome_arquivo_entrada, "r");
    FILE* arq_saida = fopen(nome_arquivo_saida, "w");

    if (arq_entrada == NULL || arq_saida == NULL) {
        printf("Erro ao abrir arquivos\n");
        return 1;
    }

    Pessoa pessoas[50];
    int i = 0;
    while (!feof(arq_entrada) && i < 50) {
        fscanf(arq_entrada, "%40[^\n] %d\n", pessoas[i].nome, &pessoas[i].ano_nasc);
        i++;
    }

    imprimir_idades(pessoas, i, ano_corrente, arq_saida);

    fclose(arq_entrada);
    fclose(arq_saida);

    return 0;
}*/

