/*Struct Coleção*/
    typedef struct _COL_{
        int qtd;
        int maxElms;
        void**Elms;
        int current;
    }Col;

/*Criar Lista*/
    Col *colCriar(int valor_max);

/*Inserir elemento na lista*/
    int colInserir(Col **c, void *elem);


/*Consulta por nome, avaliação do usuario */
    void *colConsulta(Col *c, void *key, int (*cmp)(void *, void *));

/*Remover elemento da lista*/
    void *colRemove(Col *c, void *key, int (*cmp)(void *, void *));

/*Destruir Lista*/
    Col *colDestroi(Col *c);

/*Listar Todos*/
    void *colGetFirst(Col *c);
    void *colGetNext(Col *c);
