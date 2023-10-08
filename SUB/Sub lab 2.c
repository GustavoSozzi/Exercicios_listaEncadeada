#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct _file
{
    char *nome;
    char dados[256];
    struct _file *prox;
    struct _file *ant;
}File;

typedef struct _folder
{
    File *file;
    char *nome_folder;
    struct _folder *pai;
    struct _folder *subfolder;
    struct _folder *prox;
    struct _folder *ant;
}Folder;
typedef struct
{
    Folder *Root;
    Folder *atual;
}Pivo;
typedef struct _pilha
{
    File *file;
    struct _pilha *prox;
    struct _pilha *ant;
}Pilha;

Pilha *cria_pilha()
{
    Pilha *p = malloc(sizeof(Pilha));
    p->prox = NULL;
    p->ant = NULL;
    return p;
}
void empilhar(Pilha **pilha, File *file)
{
    Pilha *no = malloc(sizeof(Pilha));
    if(no)
    {
        no->file = file;
        no->prox = *pilha;
        no->ant = NULL;
        if(*pilha)
        {
            (*pilha)->ant = no;
        }
        *pilha = no;
    }
}
Pilha *desempilhar(Pilha **pilha)
{
    Pilha *post = (*pilha)->prox;
    Pilha *ant = (*pilha)->prox->ant;
    if(*pilha)
    {
        *pilha = post;
        return ant;
    }
}
void esvaziar_pilha(Pilha *pilha)
{
    Pilha *excluido = NULL;
    if (pilha->prox!=NULL)
    {
        esvaziar_pilha(pilha->prox);
        excluido = (desempilhar(&pilha));
        printf("%s\n", excluido->file->nome);
        free(excluido);
        excluido = NULL;
    }
}
Pivo *criarPivo()
{
    Pivo *pivo = (Pivo*) malloc(sizeof(Pivo));
    pivo->Root = NULL;
    pivo->atual = NULL;
    return pivo;
}
File *criarFile(char *nome)
{
    File *new_file = (File*) malloc(sizeof(File));
    new_file->nome = nome;
    new_file->prox = NULL;
    new_file->ant = NULL;
    return new_file;
}
Folder *criarFolder(char *nome)
{
    Folder *new_folder = (Folder*) malloc(sizeof(Folder));
    new_folder->ant = NULL;
    new_folder->prox = NULL;
    new_folder->nome_folder = nome;
    new_folder->subfolder = NULL;
    new_folder->file = NULL;
    new_folder->pai = NULL;
    return new_folder;
}
void iniciar(Pivo **pivo)
{
    Folder *root = criarFolder("Root");
    root->pai = root;
    (*pivo)->Root = root;
    (*pivo)->atual = root;
}
void newFile(Folder *folder,char *nome)
{
    File *nFile = criarFile(nome);
    if(folder->file == NULL)
    {
        folder->file = nFile;
    }
    else
    {
        File *aux = folder->file;
        while(aux->prox != NULL)
        {
            aux = aux->prox;
        }
        nFile->ant = aux;
        aux->prox = nFile;
    }
    return;
}
File *del(Folder **folder, char *nome)
{
    File *aux = (*folder)->file;
    if(aux == NULL)
    {
        return NULL;
    }
    else if(aux->nome == nome)
    {
        (*folder)->file = aux->prox;
    }
    else
    {
        while(aux->prox != NULL && aux->nome != nome)
        {
            aux = aux->prox;
        }
        if(aux->nome != nome)
        {
            return NULL;
        }
        else if(aux->prox == NULL)
        {
            aux->ant->prox = NULL;
        }
        else if(aux!=NULL)
        {
            aux->ant->prox = aux->prox;
        }
        return aux;
    }
}
int ls(Folder *raiz, char *nome)
{
    Folder *aux = raiz;
    File *auxL = NULL;
    if(aux->nome_folder == nome)
    {
        auxL = aux->file;
        printf("SubPastas\n");
        while(aux != NULL)
        {
            printf("%3s%s\n", " ", aux->nome_folder);
            aux = aux->prox;
        }
        printf("Arquivos\n");
        while(auxL != NULL)
        {
            printf("%3s%s\n"," ", auxL->nome);
            auxL = auxL->prox;
        }
    }
    else
    {
        aux = raiz->subfolder;
        while(aux->prox != NULL && aux->nome_folder != nome)
        {
            aux = aux->prox;
        }
        if(aux->nome_folder != nome)
        {
            puts("Nada");
            return -1;
        }
        else
        {
            auxL = aux->file;
            Folder *auxP = aux->subfolder;
            printf("SubPastas\n");
            while(auxP != NULL)
            {
                printf("%3s%s\n", " ", auxP->nome_folder);
                auxP = auxP->prox;
            }
            printf("Arquivos\n");
            while(auxL != NULL)
            {
                printf("%3s%s\n"," ", auxL->nome);
                auxL = auxL->prox;
            }
        }
    }

}
void mk(Folder **atual, char *nome)
{
    Folder *newFolder = criarFolder(nome);
    newFolder->pai = (*atual);
    Folder *atual_sub = *atual;
    if(atual_sub->subfolder == NULL)
    {
        atual_sub->subfolder = newFolder;
    }
    else
    {
        while(atual_sub->prox != NULL)
        {
            atual_sub = atual_sub->prox;
        }
        newFolder->ant = atual_sub;
        atual_sub->prox->subfolder = newFolder;
    }
}
int cd(Folder **pasta_atual, char *nome)
{
    if((*pasta_atual)->nome_folder == nome)
    {
        return 1;
    }
    else
    {
        Folder *aux = (*pasta_atual)->subfolder;

        while(aux->prox != NULL && aux->nome_folder != nome)
        {
            aux = aux->prox;
        }
        if(aux->nome_folder != nome)
        {
            return -1;
        }
        else
        {
            *pasta_atual = aux;
            return 0;
        }
    }
}
int edit(Folder **atual, char *nome)
{
    File *aux = (*atual)->file;
    if(aux == NULL)
    {
        return -1;
    }
    else if(aux->nome == nome)
    {
        printf("Digite o conteudo do arquivo:\n");
        gets(aux->dados);
        return 0;
    }
    else
    {

        while(aux->prox != NULL && aux->nome != nome)
        {
            aux = aux->prox;
        }
        if(aux->nome != nome)
        {
            return -1;
        }
        else
        {
            printf("Digite o conteudo do arquivo:\n");
            gets(aux->dados);
            return 0;
        }
    }
}
int view(Folder *atual, char *nome)
{
    if(atual->file == NULL)
    {
        return -1;
    }
    else if(atual->file->nome == nome)
    {
        printf("Conteudo do Arquivo (%s)\n", atual->file->nome);
        printf("%s\n", atual->file->dados);
    }
    else
    {
        File *aux = atual->file;

        while(aux->prox != NULL && aux->nome != nome)
        {
            aux = aux->prox;
        }
        if(aux->nome != nome)
        {
            return -1;
        }
        else
        {
            printf("Conteudo do Arquivo (%s)\n", aux->nome);
            printf("%s\n", aux->dados);
        }
    }
}
Folder *rm(Folder *raiz, char *nome)
{
    Folder *aux = raiz->subfolder;
    if(aux == NULL)
    {
        return NULL;
    }
    else if(aux->nome_folder == nome)
    {
        aux = aux->prox;
    }
    else
    {
        while(aux->prox != NULL && aux->nome_folder != nome)
        {
            aux = aux->prox;
        }
        if(aux->nome_folder != nome)
        {
            return NULL;
        }
        else if(aux->prox == NULL)
        {
            aux->ant->prox = NULL;
        }
        else if(aux!=NULL)
        {
            aux->ant->prox = aux->prox;
        }
        return aux;
    }
}
int find(Pilha **pilha, Folder *raiz, char *palavra)
{
    Folder *aux = raiz;

    if(aux == NULL)
    {

        printf("Arquivos com a palavra (%s)\n", palavra);
        esvaziar_pilha((*pilha));
    }
    else
    {
        File *auxL = aux->file;
        while(auxL->prox != NULL && strstr(auxL->dados, palavra) == NULL)
        {
            auxL = auxL->prox;
        }
        if(strstr(auxL->dados, palavra) == NULL)
        {
            return -1;
        }
        else
        {
            empilhar(pilha, auxL);
        }
        find(pilha, aux->prox, palavra);
    }
}
int cd__(Folder **atual)
{
    (*atual) = (*atual)->pai;
}
int main()
{
    char *controle;
    Pilha *pilha = cria_pilha();
    Pivo *pivo = criarPivo();
    File *retorno = NULL;
    iniciar(&pivo);
    newFile(pivo->atual, "Arquivao");
    mk(&(pivo)->atual, "Teste2");
    puts("sai");
    printf("Nome pasta:%s\nNome subpasta:%s\n", pivo->atual->nome_folder, pivo->atual->subfolder->nome_folder);
    //edit(&(pivo)->atual, "Arquivao");
    //view(pivo->atual, "Arquivao");
    cd(&(pivo)->atual, "Teste2");
    printf("Nome pasta:%s\n", pivo->atual->nome_folder);
    cd__(&(pivo)->atual);
    printf("Nome pasta:%s\n", pivo->atual->nome_folder);
    newFile(pivo->atual, "Arquivs");
    mk(&(pivo)->atual, "Teste3");
    printf("Nome pasta:%s\nNome subpasta:%s\n", pivo->atual->nome_folder, pivo->atual->subfolder->nome_folder);
    printf("Arquivo:%s\n", pivo->atual->file->nome);
    ls(pivo->Root, "Teste2");
    edit(&(pivo)->atual, "Arquivs");
    view(pivo->atual, "Arquivs");
    find(&pilha, pivo->Root->subfolder, "ser");

    return 0;

}
