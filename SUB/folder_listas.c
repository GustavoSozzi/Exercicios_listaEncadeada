#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>

//criar varias listas e juntar em duas A e B, e salvar em um arquivo, desempilhar e depois empilhar as musicas;

typedef struct musicas
{
    int id_musica;
    char nome_musica[50];
    float temp_musica;
    int id_album;
    struct musicas *prox_musicas;
}MUSICAS;

typedef struct album
{
    char nome_album[50];
    int id_album;
    struct album *prox_album;
    int id_banda;
    MUSICAS *listamusica; //ponteiro para a lista encadeada de musicas
}ALBUM;

typedef struct banda
{
    int id_banda;
    char nome_banda[50];
    struct banda *prox_banda;
    ALBUM *lista_album; //ponteiro para a lista de albuns;
}BANDA;

typedef struct celula
{
    struct celula *prox;;
    struct celula *ant;
    int limite;
}Celula;


MUSICAS *criar_cabeca_musicas()
{
    MUSICAS *head = (MUSICAS*)malloc(sizeof(MUSICAS));
    head->prox_musicas = NULL;

    return head;
}

ALBUM *criar_cabeca_album()
{
    ALBUM *head = (ALBUM*)malloc(sizeof(ALBUM));
    head->prox_album = NULL;

    return  head;
}

BANDA *criar_cabeca_banda()
{
    BANDA *head = (BANDA*)malloc(sizeof(BANDA));
    head->prox_banda = NULL;

    return head;
}

Celula *inicializar_celula()
{
    Celula *celula = (Celula*)malloc(sizeof(Celula));

    celula->prox = NULL;
    celula->ant = NULL;
    celula->limite = 0;

    return celula;
}

void adicionar_musica(BANDA *lista_banda, int id_banda, int id_album, MUSICAS nova_musica) {
    // Percorre a lista de bandas até encontrar a banda com o id correto
    BANDA *banda_atual = lista_banda;
    while (banda_atual != NULL && banda_atual->id_banda != id_banda) {
        banda_atual = banda_atual->prox_banda;
    }

    if (banda_atual == NULL) {
        printf("Banda nao encontrada\n");
        return;
    }

    // Percorre a lista de albuns da banda até encontrar o album com o id correto
    ALBUM *album_atual = banda_atual->lista_album;
    while (album_atual != NULL && album_atual->id_album != id_album) {
        album_atual = album_atual->prox_album;
    }

    if (album_atual == NULL) {
        printf("Album nao encontrado\n");
        return;
    }

    // Percorre a lista de musicas do album até o final
    MUSICAS *musica_atual = album_atual->listamusica;
    while (musica_atual != NULL && musica_atual->prox_musicas != NULL) {
        musica_atual = musica_atual->prox_musicas;
    }

    // Cria a nova celula da lista encadeada de musicas e adiciona a nova musica
    MUSICAS *nova_celula = (MUSICAS *) malloc(sizeof(MUSICAS));
    nova_celula->id_musica = nova_musica.id_musica;
    strcpy(nova_celula->nome_musica, nova_musica.nome_musica);
    nova_celula->temp_musica = nova_musica.temp_musica;
    nova_celula->id_album = nova_musica.id_album;
    nova_celula->prox_musicas = NULL;

    if (musica_atual == NULL) {
        // A lista de musicas do album está vazia, adiciona a nova celula como primeiro elemento
        album_atual->listamusica = nova_celula;
    } else {
        // Adiciona a nova celula ao final da lista de musicas
        musica_atual->prox_musicas = nova_celula;
    }
}


int busca_banda(int id_banda, BANDA *head)
{
    int cont = 0;

    BANDA *aux;

    aux = head->prox_banda;

    while(aux!=NULL && aux->id_banda != id_banda){
        aux = aux->prox_banda;
        cont++;
    }

    return cont;
}

void adicionar_album(ALBUM *head)
{
    ALBUM *novo = (ALBUM*)malloc(sizeof(ALBUM));

    if(novo==NULL){
        printf("erro de alocacao\n");
        exit(1);
    }

    printf("\nNome do album: ");
    scanf("%[^\n]s", &novo->nome_album);

    printf("\nid do album: ");
    scanf("%d", &novo->id_album);

    novo->prox_album = NULL;

    ALBUM *tmp = head->prox_album;

    while(tmp!=NULL)
    {
        tmp = tmp->prox_album;
    }

    tmp->prox_album = novo;

    printf("Album adicionado com sucesso\n");
}

void adicionar_banda(BANDA *head)
{
    BANDA *novo = (BANDA*)malloc(sizeof(BANDA));

    printf("\nnome da banda: ");
    scanf("%[^\n]s", novo->nome_banda);

    printf("\nid banda: ");
    scanf("%d", novo->id_banda);

    novo->prox_banda = NULL;

    BANDA *tmp = head->prox_banda;

    while(tmp!=NULL)
    {
        tmp = tmp->prox_banda;
    }

    tmp->prox_banda = novo;

    printf("banda adicionada com sucessso\n");
}

void imprimir(MUSICAS *head, ALBUM *head2, BANDA *head3)
{
    if (head == NULL || head2 == NULL || head3 == NULL) {
        return;
    }

    printf("Musica: %s| Id musica %d| tempo musica %f| id album %d \n", head->nome_musica, head->id_musica, head->temp_musica, head->id_album);
    printf("Album: %s| id album %d| id banda %d\n", head2->nome_album, head2->id_album, head2->id_banda);
    printf("Banda: %s | id banda %d\n", head3->nome_banda, head3->id_banda);

    imprimir(head->prox_musicas, head2->prox_album, head3->prox_banda);
}

void salvar_arquivo(MUSICAS *musicas, ALBUM *album, BANDA *banda)
{
    FILE *arq = fopen("arquivo.txt", "w");

    MUSICAS *novo = musicas->prox_musicas;
    ALBUM *newalbum = album->prox_album;
    banda *newbanda = banda->prox_banda;

    while(novo!=NULL && newalbum != NULL && newbanda != NULL)
    {
        fprintf("Musica: %s| Id musica %d| tempo musica %f| id album %d \n ", head->nome_musica, head->id_musica, head->temp_musica, head->id_album);
        fprintf("Album: %s| id album %d| id banda %d\n", head2->nome_album, head2->id_album, head2->id_banda);)
        fprintf("Banda: %s | id banda %d\n", head3->nome_banda, head3->id_banda);

        novo=novo->prox_musicas;
        newalbum = newalbum->prox_album;
        newbanda = newbanda->prox_banda;
    }


}


int main()
{
    int op=0;
    int id_album, id_banda;
    MUSICAS *musicas_cabeca = criar_cabeca_musicas();
    ALBUM *album_cabeca = criar_cabeca_album();
    BANDA *banda_cabeca = criar_cabeca_banda();
    Celula *celula = inicializar_celula(); //inicializando os ponteiros;


    while(op!=20)
    {
        printf("1-adicionar musicas\n2-adicionar album\n3-adicionar banda\n4-salvar em arquivo\n5-imprimir a banda-album e musicas\n6-busca e remove\n7-liberar memoria e encerrar\n");
        scanf("%d", &op);

        fflush(stdin);

        if(op==1){
            printf("id da banda: ");
            scanf("%d", &id_banda);

            printf("id do album: ");
            scanf("%d", &id_album);
            adicionar_musicas(musicas_cabeca, album_cabeca, banda_cabeca, id_banda, id_album);
        }

        if(op==2){
            adicionar_album(album_cabeca);
        }

        if(op==3){
            adicionar_banda(banda_cabeca);
        }

        if(op==4){
            salvar_arquivo(musicas_cabeca, album_cabeca, banda_cabeca);
        }

        if(op==5){
            imprimir(musicas_cabeca, album_cabeca, banda_cabeca);
        }

    }




}




