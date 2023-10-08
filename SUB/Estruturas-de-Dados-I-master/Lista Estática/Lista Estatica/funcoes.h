#define MAX 100
struct aluno {
    int matricula;
    char nome[20];
    float n[3];
};
typedef struct lista Lista;
struct lista {
    int qtd;
    struct aluno dados[MAX];
}
//Lista-Criando e Removendo
Lista *cria_lista(void);
void libera_lista(Lista *li);
int tamanho_lista(Lista *li);
int lista_cheia(Lista *li);
int lista_vazia(Lista *li);
//Inserção
int insercao_no_final(Lista *li, struct aluno al);
int insercao_no_inicio(Lista *li, struct aluno al);
int insercao_ordenada(Lista *li, struct aluno al);
//Remoção
int remove_inicio(Lista *li);
int remove_lista_elemento(Lista *li, int mat);
//Consulta
int consulta_lista_posicao(Lista *li, int pos, struct aluno *al);
int consulta_lista_conteudo(Lista *li, int mat, struct aluno *al);
