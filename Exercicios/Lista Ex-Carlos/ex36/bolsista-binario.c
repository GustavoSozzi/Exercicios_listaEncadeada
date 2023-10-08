#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int codigo;
    char nome[30];
    int tipo_bolsa;
    char email[30];
} Bolsista;

int verificarCodigo(int codigo) {
    FILE *arq = fopen("bolsista.cad", "rb");
    if (arq == NULL) {
        printf("\nErro ao abrir o arquivo");
        exit(1);
    }

    Bolsista bolsista;
    int encontrado = 0;
    while (fread(&bolsista, sizeof(Bolsista), 1, arq) == 1) {
        if (codigo == bolsista.codigo) {
            encontrado = 1;
            break;
        }
    }

    fclose(arq);
    return encontrado;
}

void leitura() {
    FILE *arq = fopen("bolsista.cad", "rb");
    if (arq == NULL) {
        printf("\nErro ao abrir o arquivo");
        exit(1);
    }

    Bolsista bolsista;
    while (fread(&bolsista, sizeof(Bolsista), 1, arq) == 1) {
        printf("Codigo: %d\n", bolsista.codigo);
        printf("Nome: %s\n", bolsista.nome);
        printf("Tipo de bolsa: %d\n", bolsista.tipo_bolsa);
        printf("Email: %s\n\n", bolsista.email);
    }

    fclose(arq);
}

int main() {
    FILE *arq = fopen("bolsista.cad", "ab");
    if (arq == NULL) {
        printf("\nErro ao abrir o arquivo");
        exit(1);
    }

    int sair;
    Bolsista bolsista;

    do {
        printf("Codigo: ");
        scanf("%d", &bolsista.codigo);
        fflush(stdin);

        if (bolsista.codigo < 1 || bolsista.codigo > 25) {
            printf("\nCodigo invalido\n");
            continue;
        }

        if (verificarCodigo(bolsista.codigo) == 1) {
            printf("\nCodigo ja cadastrado\n");
            continue;
        }

        printf("\nNome: ");
        scanf(" %[^\n]s", bolsista.nome);
        fflush(stdin);

        printf("\nTipo da bolsa:\n1 - trabalho\n2 - iniciacao\n3 - pesquisa\n");
        scanf("%d", &bolsista.tipo_bolsa);
        fflush(stdin);

        if (bolsista.tipo_bolsa < 1 || bolsista.tipo_bolsa > 3) {
            printf("Tipo de bolsa invalida\n");
            continue;
        }

        printf("\nEmail: ");
        scanf(" %s", bolsista.email);
        fflush(stdin);

        fwrite(&bolsista, sizeof(Bolsista), 1, arq);

        printf("\nDeseja continuar? 1 - para sair: ");
        scanf("%d", &sair);
        fflush(stdin);
    } while (sair != 1);

    fclose(arq);

    leitura();

    return 0;
}
