typedef struct _SLNODE_{
    void *data;
    struct _SLNODE_ *next;
}SlNode;

typedef struct _SLIST_{
    SlNode *first, *cur;
}SlList;



SlList *sllCreate();
//Cria a lista

int sllDestroy(SlList **s);
//Destroi a lista;

int sllInsertAsLast(SlList **s, void *elm);
//Insere um elemento no final

int sllInsertFirst(SlList **s, void *elm);
//Insere elemento na cabeça da lista

void *sllRemoveSpecified(SlList *s, int (*cmp)(void *, void *), void *key);
//Remove específico

void *sllDestroyLast(SlList *s);
//Remove o último elemento da lista

void *sllConsultaEspecificado(SlList *s, int (*cmp)(void *, void *), void *key);
//Consulta um elemento especidficado

/*Retorna os dados que a lista guarda para que possa imprimir*/
void *sllGetFirst(SlList *s);
void *sllGetNext(SlList *s);
