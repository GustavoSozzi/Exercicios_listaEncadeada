#include <stdio.h>

typedef struct {
    char nome[50];
    char esporte[30];
    int idade;
    float altura;
} Atleta;

int main() {
    Atleta atletas[5];
    FILE *arq = fopen("atleta.bin", "rb");

    if (arq == NULL) {
        printf("Erro ao abrir o arquivo.");
        return 1;
    }

    fread(atletas, sizeof(Atleta), 5, arq);

    Atleta atletaMaisAlto = atletas[0];
    Atleta atletaMaisVelho = atletas[0];

    for (int i = 1; i < 5; i++) {
        if (atletas[i].altura > atletaMaisAlto.altura) {
            atletaMaisAlto = atletas[i];
        }
        if (atletas[i].idade > atletaMaisVelho.idade) {
            atletaMaisVelho = atletas[i];
        }
    }

    printf("Atleta mais alto: %s\n", atletaMaisAlto.nome);
    printf("Atleta mais velho: %s\n", atletaMaisVelho.nome);

    fclose(arq);

    return 0;
}

