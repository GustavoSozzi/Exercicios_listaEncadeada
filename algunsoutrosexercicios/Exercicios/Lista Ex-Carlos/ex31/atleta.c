
/*Escrever um procedimento de
inclusão randômica de 1 a n registros em um arquivo com dados de atletas. O seguinte tipo, utilizado
no procedimento, é definido externamente ao mesmo
no procedimento, é definido externamente ao mesmo*/

#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct atlet{
    int cod;
    char nome[50];
    int idade;
    float altura;
} Atleta;

void incluirAtleta(char *nomeArquivo, int maxCod) {
    Atleta atleta;
    FILE *arquivo = fopen(nomeArquivo, "r+b"); //lendo e escrevendo arquivo binario

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo\n");
        return;
    }

    int codigo;
    char continuar;

    do {
        printf("Informe o código do atleta (1 a %d): ", maxCod);
        scanf("%d", &codigo);

        if (codigo < 1 || codigo > maxCod) {
            printf("Código inválido. Tente novamente.\n");
            continue;
        }

        fseek(arquivo, (codigo - 1) * sizeof(Atleta), SEEK_SET);
        fread(&atleta, sizeof(Atleta), 1, arquivo); //lendo arquivo binario

        /*ou while (fread(&atleta, sizeof(Atleta), 1, arquivo) == 1) {
    // processa o elemento lido para ler ate o fim de arquivo*/
}

        if (atleta.cod != 0) {
            printf("Esta posição já está ocupada. Tente novamente.\n");
            continue;
        }

        atleta.cod = codigo;

        printf("Informe o nome do atleta: ");
        scanf("%s", atleta.nome);

        printf("Informe a idade do atleta: ");
        scanf("%d", &atleta.idade);

        printf("Informe a altura do atleta: ");
        scanf("%f", &atleta.altura);

        fseek(arquivo, (codigo - 1) * sizeof(Atleta), SEEK_SET);
        fwrite(&atleta, sizeof(Atleta), 1, arquivo); //escrevendo arquivo binario; endereco variavel, tamanho, qtd escritas, onde sers escrita

        printf("Deseja incluir mais um atleta? (S/N) ");
        scanf(" %c", &continuar);
    } while (continuar == 'S' || continuar == 's');

    fclose(arquivo);
}



