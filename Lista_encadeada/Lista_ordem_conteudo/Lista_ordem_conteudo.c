#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int num;
    struct no *prox;
} Celula;

void inserir_ordenado(Celula *celula) //inserindo em ordem
{
    Celula *novo = (Celula*)malloc(sizeof(Celula));
    Celula *anterior = celula; //guarda a cabeça
    Celula *atual = celula->prox; //recebe a primeira celula depois da cabeca;

    if(novo == NULL)
    {
        printf("\nerro ao alocar memoria");
        exit(1);
    }

    printf("\nNovo elemento: ");
    scanf("%d", &novo->num);

    novo->prox = NULL; //indica que o proximo no nao tem nada; sempre inicializar os campos dos proximos nos;

    //tambem ajuda prox->null a chegar no final da lista;

    while(atual != NULL && atual->num < novo->num) //se atual e menor que novo
    {
        anterior = atual; //rebece a celula dps da cabeca, com o atual andando as casas;
        atual = atual->prox; //percorre a lista
    }

    novo->prox = atual; //guarda o numero
    anterior->prox = novo; //guarda o anterior para nao perdelo
}

void imprimir(Celula *celula) //imprimindo em ordem crescente
{
    if(celula->prox == NULL)
    {
        printf("\nlista vazia");
        exit(1);
    }

    Celula *tmp = celula->prox;

    while(tmp != NULL)
    {
        printf("\n%d", tmp->num);
        tmp = tmp->prox; //recebe a celula seguinte a cada loop
    }

    printf("\n");
}

int main()
{
    int op;
    Celula *celula = (Celula*)malloc(sizeof(Celula));

    celula->prox = NULL;

    if(celula == NULL)
    {
        printf("\nerro ao alocar memoria");
        exit(1);
    }

    while(op != 3)
    {
        printf("\n1-inserir\n2-imprimir\n3-sair\n");
        scanf("%d", &op);

        if(op == 1)
        {
            inserir_ordenado(celula);
        }
        else if(op == 2)
        {
            imprimir(celula);
        }
    }

    return 0;
}
