
typedef struct no{
    int valor;
    struct no *proximo;
}No;

void inserir_na_fila(No **fila, int num){
    No *aux, *novo = malloc(sizeof(No));
    if(novo){
        novo->valor = num;
        novo->proximo = NULL;
        if(*fila == NULL)
            *fila = novo;
        else{
            aux = *fila;
            while(aux->proximo)
                aux = aux->proximo;
            aux->proximo = novo;
        }
    }
    else
        printf("\nErro ao alocar memoria.\n");
}

void inserir_com_prioridade(No **fila, int num){
    No *aux, *novo = malloc(sizeof(No));
    if(novo){
        novo->valor = num;
        novo->proximo = NULL;
        if(*fila == NULL)
            *fila = novo;
        else{
            // é prioridade?
            if(num > 59){
                if((*fila)->valor < 60){ // é a primeira prioridade?
                    novo->proximo = *fila; // insere no início da fila
                    *fila = novo;
                }
                else{
                    aux = *fila;
                    while(aux->proximo && aux->proximo->valor > 59)
                        aux = aux->proximo;
                    novo->proximo = aux->proximo; // insere depois da última prioridade
                    aux->proximo = novo;
                }
            }
            else{
                aux = *fila;
                while(aux->proximo)
                    aux = aux->proximo;
                aux->proximo = novo;
            }
        }
    }
    else
        printf("\nErro ao alocar memoria.\n");
}

No* remover_da_fila(No **fila){
    No *remover = NULL;

    if(*fila){
        remover = *fila;
        *fila = remover->proximo;
    }
    else
        printf("\tFila vazia\n");
    return remover;
}

void imprimir(No *fila){
    printf("\t------- FILA --------\n\t");
    while(fila){
        printf("%d ", fila->valor);
        fila = fila->proximo;
    }
    printf("\n\t------- FIM FILA --------\n");
}

int main(){
    No *r, *fila = NULL;
    int opcao, valor;

    do{
        printf("\t0 - Sair\n\t1 - Inserir\n\t2 - Remover\n\t3 - Imprimir\n\t4 - inserir com prioridade\n");
        scanf("%d", &opcao);

        switch(opcao){
        case 1:
            printf("Digite um valor: ");
            scanf("%d", &valor);
            inserir_na_fila(&fila, valor);
            break;
        case 2:
            r = remover_da_fila(&fila);
            if(r){
                printf("Removido: %d\n", r->valor);
                free(r);
            }
            break;
        case 3:
            imprimir(fila);
            break;
        case 4:
            printf("Digite um valor: ");
            scanf("%d", &valor);
            inserir_com_prioridade(&fila, valor);
            break;
        default:
            if(opcao != 0)
                printf("\nOpcao invaluda!\n");
        }

    }while(opcao != 0);

    return 0;
}

/*


#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int prioridade;
    struct No* prox;
} No;

typedef struct FilaPrioridade {
    No* inicio;
} FilaPrioridade;

void insere(FilaPrioridade* fila, int prioridade) {
    No* novo = (No*) malloc(sizeof(No));
    novo->prioridade = prioridade;
    novo->prox = NULL;

    if (fila->inicio == NULL) {
        fila->inicio = novo;
        return;
    }

    No* atual = fila->inicio;
    No* anterior = NULL;

    while (atual != NULL && atual->prioridade < prioridade) {
        anterior = atual;
        atual = atual->prox;
    }

    if (anterior == NULL) {
        novo->prox = fila->inicio;
        fila->inicio = novo;
    } else {
        anterior->prox = novo;
        novo->prox = atual;
    }
}

void remove(FilaPrioridade* fila) {
    if (fila->inicio == NULL) {
        printf("Fila vazia.\n");
        return;
    }

    No* temp = fila->inicio;
    fila->inicio = fila->inicio->prox;
    free(temp);
}

void altera_prioridade(FilaPrioridade* fila, int prioridade_antiga, int nova_prioridade) {
    // Percorre a lista encadeada até encontrar o elemento com a prioridade antiga
    No* atual = fila->inicio;
    No* anterior = NULL;

    while (atual != NULL && atual->prioridade != prioridade_antiga) {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual == NULL) {
        printf("Elemento não encontrado.\n");
        return;
    }

    // Remove o elemento da lista encadeada
    if (anterior == NULL) {
        fila->inicio = atual->prox;
    } else {
        anterior->prox = atual->prox;
    }

    // Altera a prioridade do elemento
    atual->prioridade = nova_prioridade;

    // Insere o elemento de volta na lista encadeada
    insere(fila, nova_prioridade);
}

void imprime(FilaPrioridade fila) {
    No* atual = fila.inicio;

    while (atual != NULL) {
        printf("%d ", atual->prioridade);
        atual = atual->prox;
    }

    printf("\n");
}

int main() {
    FilaPrioridade fila = { NULL };

    insere(&fila, 3);
    insere(&fila, 5);
    insere(&fila, 2);
    insere(&fila, 7);

    printf("Fila original: ");
    imprime(fila);

    altera_prioridade(&fila, 2, 4);

    printf("Fila alterada: ");
    imprime(fila);

    return 0;
}
*/

/*


#include <stdio.h>
#include <stdlib.h>

// Definindo a estrutura do nó
typedef struct node {
    int data;
    int priority;
    struct node *next;
} Node;

// Definindo a estrutura da fila de prioridade
typedef struct priority_queue {
    Node *head;
} PriorityQueue;

// Função para criar um novo nó
Node *new_node(int data, int priority) {
    Node *temp = (Node *) malloc(sizeof(Node));
    temp->data = data;
    temp->priority = priority;
    temp->next = NULL;
    return temp;
}

// Função para criar uma nova fila de prioridade vazia
PriorityQueue *new_priority_queue() {
    PriorityQueue *q = (PriorityQueue *) malloc(sizeof(PriorityQueue));
    q->head = NULL;
    return q;
}

// Função para verificar se a fila de prioridade está vazia
int is_empty(PriorityQueue *q) {
    return (q->head == NULL);
}

// Função para inserir um novo elemento na fila de prioridade
void insert(PriorityQueue *q, int data, int priority) {
    Node *temp = new_node(data, priority);

    // Se a fila de prioridade está vazia ou a prioridade do novo nó é maior que a prioridade do primeiro nó
    if (is_empty(q) || priority > q->head->priority) {
        temp->next = q->head;
        q->head = temp;
    } else {
        Node *current = q->head;

        // Encontrando o ponto de inserção correto
        while (current->next != NULL && current->next->priority >= priority) {
            current = current->next;
        }

        temp->next = current->next;
        current->next = temp;
    }
}

// Função para remover o elemento de maior prioridade da fila de prioridade
int remove_max(PriorityQueue *q) {
    if (is_empty(q)) {
        printf("Erro: fila de prioridade vazia!");
        return -1;
    }

    int data = q->head->data;
    Node *temp = q->head;
    q->head = q->head->next;
    free(temp);

    return data;
}

// Função para imprimir a fila de prioridade
void print_priority_queue(PriorityQueue *q) {
    if (is_empty(q)) {
        printf("Fila de prioridade vazia!\n");
        return;
    }

    printf("Elementos da fila de prioridade: ");

    Node *current = q->head;
    while (current != NULL) {
        printf("(%d, %d) ", current->data, current->priority);
        current = current->next;
    }

    printf("\n");
}

// Função principal
int main() {
    PriorityQueue *q = new_priority_queue();

    insert(q, 10, 1);
    insert(q, 20, 2);
    insert(q, 30, 3);
    insert(q, 40, 2);

    printf("Antes da alteração de prioridade: ");
    print_priority_queue(q);

    // Alterando a prioridade do elemento 20 para 4
    Node *current = q->head;
    while (current != NULL) {
        if (current->data == 20
*/



/*----------------FILAAAAAA CIRCULARR----------------


#include <stdio.h>
#include <stdlib.h>

typedef struct NO {
    int valor;
    struct NO* prox;
} NO;

typedef struct FILA {
    NO* inicio;
    NO* fim;
} FILA;

void inicializar(FILA* f) {
    f->inicio = NULL;
    f->fim = NULL;
}

int vazia(FILA* f) {
    return f->inicio == NULL;
}

void enfileirar(FILA* f, int valor) {
    NO* novo = (NO*) malloc(sizeof(NO));
    novo->valor = valor;
    novo->prox = NULL;
    if(vazia(f)) {
        f->inicio = novo;
        f->fim = novo;
    } else {
        f->fim->prox = novo;
        f->fim = novo;
    }
    f->fim->prox = f->inicio;
}

int desenfileirar(FILA* f) {
    if(vazia(f)) {
        printf("Fila vazia\n");
        return -1;
    }
    int valor;
    NO* aux = f->inicio;
    if(f->inicio == f->fim) { // fila com um único elemento
        f->inicio = NULL;
        f->fim = NULL;
    } else {
        f->inicio = f->inicio->prox;
        f->fim->prox = f->inicio;
    }
    valor = aux->valor;
    free(aux);
    return valor;
}

void imprimir(FILA* f) {
    if(vazia(f)) {
        printf("Fila vazia\n");
        return;
    }
    NO* aux = f->inicio;
    do {
        printf("%d ", aux->valor);
        aux = aux->prox;
    } while(aux != f->inicio);
    printf("\n");
}

int main() {
    FILA f;
    inicializar(&f);
    enfileirar(&f, 1);
    enfileirar(&f, 2);
    enfileirar(&f, 3);
    imprimir(&f);
    desenfileirar(&f);
    imprimir(&f);
    enfileirar(&f, 4);
    imprimir(&f);
    return 0;
}
*/


/*



/*---------------------LISTA ENCADEADA SIMPLES-------------------------



#include <stdio.h>
#include <stdlib.h>

typedef struct NO {
    int dado;
    struct NO *prox;
} NO;

typedef struct LISTA {
    NO *inicio;
    int tamanho;
} LISTA;

void inicializar(LISTA *lst) {
    lst->inicio = NULL;
    lst->tamanho = 0;
}

void imprimir(LISTA *lst) {
    NO *ptr = lst->inicio;
    printf("Lista: ");
    while(ptr != NULL) {
        printf("%d ", ptr->dado);
        ptr = ptr->prox;
    }
    printf("\n");
}

void inserir_final(LISTA *lst, int dado) {
    NO *ptr = (NO*) malloc(sizeof(NO));
    ptr->dado = dado;
    ptr->prox = NULL;

    if(lst->inicio == NULL) {
        lst->inicio = ptr;
    } else {
        NO *aux = lst->inicio;
        while(aux->prox != NULL) {
            aux = aux->prox;
        }
        aux->prox = ptr;
    }

    lst->tamanho++;
}

void inserir_inicio(LISTA *lst, int dado) {
    NO *ptr = (NO*) malloc(sizeof(NO));
    ptr->dado = dado;
    ptr->prox = lst->inicio;
    lst->inicio = ptr;
    lst->tamanho++;
}

int buscar(LISTA *lst, int dado) {
    NO *ptr = lst->inicio;
    int pos = 0;
    while(ptr != NULL) {
        if(ptr->dado == dado) {
            return pos;
        }
        pos++;
        ptr = ptr->prox;
    }
    return -1;
}

void liberar(LISTA *lst) {
    NO *ptr = lst->inicio;
    while(ptr != NULL) {
        NO *aux = ptr;
        ptr = ptr->prox;
        free(aux);
    }
    lst->inicio = NULL;
    lst->tamanho = 0;
}

int remover_inicio(LISTA *lst) {
    if(lst->inicio == NULL) {
        printf("Lista vazia!\n");
        return -1;
    }

    NO *ptr = lst->inicio;
    lst->inicio = ptr->prox;
    int dado = ptr->dado;
    free(ptr);
    lst->tamanho--;

    return dado;
}

int remover_final(LISTA *lst) {
    if(lst->inicio == NULL) {
        printf("Lista vazia!\n");
        return -1;
    }

    NO *ptr = lst->inicio;
    NO *ant = NULL;
    while(ptr->prox != NULL) {
        ant = ptr;
        ptr = ptr->prox;
    }
    int dado = ptr->dado;
    free(ptr);
    lst->tamanho--;

    if(ant == NULL) {
        lst->inicio = NULL;
    } else {
        ant->prox = NULL;
    }

    return dado;
}

int remover_meio(LISTA *lst, int pos) {
    if(lst->inicio == NULL) {
        printf("Lista vazia!\n");
        return -1;
    }

    if(pos >= lst->tamanho) {
        printf("Posicao invalida!\n");
        return -1;
    }

    NO *ptr = lst->inicio;
    NO *ant = NULL;
    int i = 0;
    while(i < pos) {
        ant = ptr;
        ptr = ptr->prox;
        i++;
void insere_final(Lista *lista, int valor) {
    Celula *nova_celula = (Celula*) malloc(sizeof(Celula));
    nova_celula->dado = valor;
    nova_celula->prox = NULL;

    if (lista->primeiro == NULL) { // lista vazia
        lista->primeiro = nova_celula;
        lista->ultimo = nova_celula;
    } else {
        lista->ultimo->prox = nova_celula;
        lista->ultimo = nova_celula;
    }

    lista->tamanho++;
}
int remove_inicio(Lista *lista) {
    if (lista->primeiro == NULL) { // lista vazia
        printf("Lista vazia.\n");
        return -1;
    }

    Celula *removida = lista->primeiro;
    int valor = removida->dado;
    lista->primeiro = removida->prox;

    free(removida);
    lista->tamanho--;

    return valor;
}
int remove_inicio(Lista *lista) {
    if (lista->primeiro == NULL) { // lista vazia
        printf("Lista vazia.\n");
        return -1;
    }

    Celula *removida = lista->primeiro;
    int valor = removida->dado;
    lista->primeiro = removida->prox;

    free(removida);
    lista->tamanho--;

    return valor;
}





---------------------------lISTA DUPLAMETE ENCADEADA--------------------------------


Inserir no início:
c
Copy code
void insere_inicio(Lista *lista, int valor) {
    Celula *nova_celula = (Celula*) malloc(sizeof(Celula));
    nova_celula->dado = valor;
    nova_celula->prox = lista->primeiro;
    nova_celula->ant = NULL;

    if (lista->primeiro == NULL) { // lista vazia
        lista->ultimo = nova_celula;
    } else {
        lista->primeiro->ant = nova_celula;
    }

    lista->primeiro = nova_celula;
    lista->tamanho++;
}
Remover no final:
c
Copy code
int remove_final(Lista *lista) {
    if (lista->ultimo == NULL) { // lista vazia
        printf("Lista vazia.\n");
        return -1;
    }

    Celula *removida = lista->ultimo;
    int valor = removida->dado;
    lista->ultimo = removida->ant;

    if (lista->ultimo == NULL) { // lista com apenas um elemento
        lista->primeiro = NULL;
    } else {
        lista->ultimo->prox = NULL;
    }

    free(removida);
    lista->tamanho--;

    return valor;
}
FILA COM LISTA ENCADEADA

Inserir no final:
c
Copy code
void insere_fila(Fila *fila, int valor) {
    Celula *nova_celula = (Celula*) malloc(sizeof(Celula));
    nova_celula->dado = valor;
    nova_celula->prox = NULL;

    if (fila->primeiro == NULL) { // fila vazia
        fila->primeiro = nova_celula;
        fila->ultimo = nova_celula;
    } else {
        fila->ultimo->prox = nova_celula;
        fila->ultimo = nova_celula;
    }

    fila->tamanho++;
}


#include <stdio.h>
#include <stdlib.h>

typedef struct NO{
    int dado;
    struct NO* proximo;
    struct NO* anterior;
}NO;

typedef struct LISTA_ENCADEADA{
    NO* inicio;
}LISTA_ENCADEADA;

void inicializar(LISTA_ENCADEADA* lista){
    lista->inicio = NULL;
}

void inserir_inicio(LISTA_ENCADEADA* lista, int valor){
    NO* novo = (NO*)malloc(sizeof(NO));
    novo->dado = valor;
    novo->anterior = NULL;
    novo->proximo = lista->inicio;
    if(lista->inicio != NULL)
        lista->inicio->anterior = novo;
    lista->inicio = novo;
}

void inserir_fim(LISTA_ENCADEADA* lista, int valor){
    NO* novo = (NO*)malloc(sizeof(NO));
    novo->dado = valor;
    novo->proximo = NULL;
    if(lista->inicio == NULL){
        novo->anterior = NULL;
        lista->inicio = novo;
    }
    else{
        NO* aux = lista->inicio;
        while(aux->proximo != NULL)
            aux = aux->proximo;
        aux->proximo = novo;
        novo->anterior = aux;
    }
}

void inserir_posicao(LISTA_ENCADEADA* lista, int valor, int posicao){
    NO* novo = (NO*)malloc(sizeof(NO));
    novo->dado = valor;
    if(lista->inicio == NULL){
        novo->proximo = NULL;
        novo->anterior = NULL;
        lista->inicio = novo;
        return;
    }
    if(posicao == 0){
        novo->proximo = lista->inicio;
        lista->inicio->anterior = novo;
        lista->inicio = novo;
        return;
    }
    NO* aux = lista->inicio;
    for(int i = 0; i < posicao-1; i++){
        aux = aux->proximo;
        if(aux == NULL){
            printf("Posicao invalida!\n");
            return;
        }
    }
    novo->anterior = aux;
    novo->proximo = aux->proximo;
    if(aux->proximo != NULL)
        aux->proximo->anterior = novo;
    aux->proximo = novo;
}

void remover_inicio(LISTA_ENCADEADA* lista){
    if(lista->inicio == NULL){
        printf("Lista vazia!\n");
        return;
    }
    NO* aux = lista->inicio;
    lista->inicio = lista->inicio->proximo;
    if(lista->inicio != NULL)
        lista->inicio->anterior = NULL;
    free(aux);
}

void remover_fim(LISTA_ENCADEADA* lista){
    if(lista->inicio == NULL){
        printf("Lista vazia!\n");
        return;
    }
    if(lista->inicio->proximo == NULL){
        free(lista->inicio);
        lista->inicio = NULL;
        return;
    }
    NO* aux = lista->inicio;
    while(aux->proximo != NULL)
        aux = aux->proximo;
    aux->anterior->proximo = NULL;
    free(aux);
}

void remover_posicao(LISTA_ENCADEADA* lista, int posicao){
    if(lista->inicio == NULL){
        printf("Lista vazia!\n");
        return;
    }
    if(posicao == 0){
        NO* aux = lista
*/

