#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int num;
    struct no *prox;
    struct no *ant;
} Celula;

void inserir_ordenado(Celula *cabeca) { //lista duplamente circular com no cabeça;

    Celula *novo = (Celula*) malloc(sizeof(Celula));
    Celula *anterior = cabeca;
    Celula *atual = cabeca->prox;

    if (novo == NULL) {
        printf("\nErro ao alocar memoria.");
        exit(1);
    }

    printf("\nNovo elemento: ");
    scanf("%d", &novo->num);

    novo->prox = NULL;
    novo->ant = NULL;

    while (atual != cabeca && atual->num < novo->num) {
        anterior = atual;
        atual = atual->prox;
    }

    novo->prox = atual;
    novo->ant = anterior;
    anterior->prox = novo;
    atual->ant = novo;
}

void imprimir(Celula *cabeca) {
    if (cabeca->prox == cabeca) {
        printf("\nLista vazia.");
        return;
    }

    Celula *tmp = cabeca->prox;

    while (tmp != cabeca) {
        printf("\n%d", tmp->num);
        tmp = tmp->prox;
    }

    printf("\n");
}

int main() {
    int op;
    Celula *cabeca = (Celula*) malloc(sizeof(Celula));

    cabeca->prox = cabeca;
    cabeca->ant = cabeca;

    if (cabeca == NULL) {
        printf("\nErro ao alocar memoria.");
        exit(1);
    }

    while (op != 3) {
        printf("\n1-Inserir\n2-Imprimir\n3-Sair\n");
        scanf("%d", &op);

        if (op == 1) {
            inserir_ordenado(cabeca);
        } else if (op == 2) {
            imprimir(cabeca);
        }
    }

    // Libera a memória alocada para todos os nós da lista
    Celula *atual = cabeca->prox;

    while (atual != cabeca) {
        Celula *prox = atual->prox;
        free(atual);
        atual = prox;
    }

    free(cabeca);

    return 0;
}
