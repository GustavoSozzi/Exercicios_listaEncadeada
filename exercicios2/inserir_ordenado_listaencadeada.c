#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

typedef struct nodo {
	int conteudo;
	struct nodo *prox;
} Celula;

//inserindo na lista com ordenacao. Na sua posi��o correta: no in�cio, no fim, ou no meio
Celula *inserir(int valor, Celula *lista) {
	Celula *novo; //para alocar nova celula
    Celula *p, *pR;

	//alocar memoria
	novo = (Celula *)malloc(sizeof(Celula));
	//depositar valor
	novo->conteudo = valor;
    novo->prox = NULL; //nao sabemos onde o novo ser� inserido

    if (!lista) {
        return novo;
    }

    //percorrer a lista a procura da posicao correta
    for (pR = NULL, p = lista; p ; pR = p, p = p->prox) {
        if (valor < p->conteudo) {
            //achamos a posicao
            break;
        }
    }
    //numero inserido como primeiro
    if (!pR) { // p == lista
        novo->prox = p; //ou novo->prox = lista;
        return novo;
    } else if (p == NULL) {//numero inserido na ultima posicao
        pR->prox = novo;
    } else {//numero inserido no meio
        pR->prox = novo;
        novo->prox = p;
    }
	return lista; //retornamos o primeiro elemento
}

void exibir(Celula *lista) {
    Celula *p;
    if (!lista) {
        printf("Lista vazia.\n");
        return;
    }
    for (p = lista; p; p = p->prox) {
        printf("%d\t", p->conteudo);
    }
    printf("\n");
}

int contar(Celula *lista) {
    Celula *p;
    int total = 0;
    for (p = lista; p; p = p->prox, total++);

    return total;
}

Celula *popular(Celula *lista, int quantidade) {
    srand(time(NULL));
    int i;
    for (i = 0; i < quantidade; i++ ) {
        lista = inserir(rand() % 100, lista);
    }

    return lista;
}

int main() {
    setlocale(LC_ALL,"Portuguese");
	Celula *lista = NULL;

    lista = popular(lista,10);
    printf("A lista cont�m: %d n�meros sorteados\n", contar(lista));
    exibir(lista);

	return 1;
}



/*fila circular com cabeca


Celula *inserir(Celula *fim, Pessoa *p){
    Celula *nova = (Celula*) malloc(sizeof(Celula));
    nova->ptrpessoa = p;
    nova->prox = fim->prox;
    fim->prox = nova;
    fim = nova;
    return fim;
}

void remover(Celula *ini){
    Celula *li = ini->prox;
    ini->prox = li->prox;
    printf("OPA");
    free(li);

    Celula *cabeca = (Celula*) malloc(sizeof(Celula));
cabeca->prox = cabeca;
}
