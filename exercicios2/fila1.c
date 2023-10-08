/*
        C�digo escrito por Wagner Gaspar
        Julho de 2021

        Aula 238: Estrutura FILA - Segunda vers�o
*/

typedef struct no{
    int valor;
    struct no *proximo;
}No;

typedef struct{
    No *prim;
    No *fim;
    int tam;
}Fila;

void criar_fila(Fila *fila){
    fila->prim = NULL;
    fila->fim = NULL;
    fila->tam = 0;
}
/*
    Procedimento para inserir um novo n� na fila
*/
void inserir_na_fila(Fila *fila, int num){
    No *aux, *novo = malloc(sizeof(No));
    if(novo){
        novo->valor = num;
        novo->proximo = NULL;
        if(fila->prim == NULL){ // se a fila estiver vazia
            fila->prim = novo;
            fila->fim = novo;
        }
        else{ // se a fila N�O estiver vazia
            fila->fim->proximo = novo; // o pr�ximo do ponteiro fim aponta para o novo n�
            fila->fim = novo; // o ponteiro fim aponta para o novo n�
        }
        fila->tam++;
    }
    else
        printf("\nErro ao alocar memoria.\n");
}

No* remover_da_fila(Fila *fila){
    No *remover = NULL;

    if(fila->prim){ //se for diferente de NULL
        remover = fila->prim;
        fila->prim = remover->proximo;
        fila->tam--;
    }
    else
        printf("\tFila vazia\n");
    return remover;
}

void imprimir(Fila *fila){
    No *aux = fila->prim;
    printf("\t------- FILA --------\n\t");
    while(aux){
        printf("%d ", aux->valor);
        aux = aux->proximo;
    }
    printf("\n\t------- FIM FILA --------\n");
}

int main(){
    No *r;
    Fila fila;
    int opcao, valor;

    criar_fila(&fila);

    do{
        printf("\t0 - Sair\n\t1 - Inserir\n\t2 - Remover\n\t3 - Imprimir\n");
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
            imprimir(&fila);
            break;
        default:
            if(opcao != 0)
                printf("\nOpcao invaluda!\n");
        }

    }while(opcao != 0);

    return 0;
}
