typedef struct _DLNODE_{
    void *data;
    struct _DLNODE_ *next, *prev;
}DLNode;

typedef struct _DLLIST_{
    SlNode *first, *cur;
}DLList;

//Pilha simplesmente encadeada, ultimo que entra, primeiro que sai;

DLList *sllCreate();
//Cria a lista

int dllDestroy(DLList *l);
//Destroi a lista;

int dllInsertAfterSpec(SlList *l, int (*cmp)(void *, void *), void *key, void *data);
//Insere um elemento no final


