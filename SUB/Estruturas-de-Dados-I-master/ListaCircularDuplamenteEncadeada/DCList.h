typedef struct _CLNODE_{
    void *data;
    struct _CLNODE_  *next, *prev;
}ClNode;

typedef struct _CLLIST_{
    CLNode *first, *cur;
}CLList;


CLList *cllCreate();

int cllDestroyAll(CLList *l);

void killNode(void *data);

int cllInsertBeforeSpec(CLList *l, void key, void *data, (int *)cmp(void *, void *));

int cllInsertAfterSpec(CLList *l, void key, void *data, (int *)cmp(void *, void *));
