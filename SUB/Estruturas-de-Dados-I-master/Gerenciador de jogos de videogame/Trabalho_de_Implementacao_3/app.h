
/*Struct Dados*/
    typedef struct _VIDEOGAMES_{
        int avaliacao;
        char nome_do_jogo[50];
        float preco ;
    }VidGames;

/*Menu com as opçoes para manipular a Coleção*/
    void menu();

/*Adiciona dados na struct VidGames e retorna na main para ser inserido na coleção*/
    void *adicionaDados();

/*Formas de consultar a coleção*/
    int comparaNomeDoJogo(void *a, void *b);
    int comparaAvaliacaoDoUsuario(void *a, void *b);
    int comparaPreco(void *a, void *b);

/*Imprimir informações*/
    void imprimirInfo(VidGames *a);

/*Teste para verificar os dados que o usuário digita*/
    float testeFloat();
    int testeInteiro();
