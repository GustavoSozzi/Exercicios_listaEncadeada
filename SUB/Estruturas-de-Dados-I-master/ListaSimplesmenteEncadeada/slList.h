typedef struct _SLNODE_{
    void *data;
    struct _SLNODE_ *next;
}SlNode;

typedef struct _SLIST_{
    SlNode *first;
}SlList;

//Pilha simplesmente encadeada, ultimo que entra, primeiro que sai;

SlList *sllCreate();
//Cria a lista

int sllDestroy(SlList *s);
//Destroi a lista;

int sllInsertAsLast(SlList *s, void *elm);
//Insere um elemento no final

void *sllDestroyLast(SlList *s);
//Destroi o ultimo elemento da lista

int sllInsertFirst(SlList *s, void *elm);
//Insere elemento na cabeça da lista

void *sllDestroyFirst(SlList *s);
//Destroi o primeiro elemento da lista

void *sllRemoveSpecified(SlList *s, int (*cmp)(void *, void *), void *key);
//Remove específico

