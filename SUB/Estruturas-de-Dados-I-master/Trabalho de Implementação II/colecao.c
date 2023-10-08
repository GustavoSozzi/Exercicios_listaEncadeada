#include <stdlib.h>
#include "colecao.h"
#include "funcoes.h"

/*Criar Lista*/
Col* colCriar(int valor_max){
    Col *c;
    if (valor_max>0){

        c = (Col *)malloc(sizeof(Col));
        if (c!=NULL){
            c->Elms = (void **)malloc(sizeof(void *)*valor_max);
            if(c->Elms!=NULL){
                c->maxElms = valor_max;
                c->qtd = 0;
                return c;
            }
        }
        free(c);
    }
    return NULL;
}

/*Inserir na lista*/
int colInserir(Col **c, void *elem){

    if (*c!=NULL){
        if((*c)->qtd < (*c)->maxElms){
            (*c)->Elms[(*c)->qtd] = (VidGames *)elem;
            (*c)->qtd++;
            return 1;
        }
    }
    return 0;
}
/*Consulta por nome, avaliação do usuario e ano de criação */
void *colConsulta(Col *c, void *key, int (*cmp)(void *, void *)){

    int i = 0, state = 0;
    if (c != NULL){
        if (c->qtd > 0) {
            while(state != 1 && i < c->qtd){
                state = cmp((void *)c->Elms[i], key);
                if (state == 0){
                    i++;
                }
            }
            if(state == 1){
                return c->Elms[i];
            }
        }
    }
    return NULL;
}

/*Remover elemento da lista*/
void *colRemove(Col *c, void *key, int (*cmp)(void *, void *)){

    void *data;
    int i = 0, state = 0, j;
    if (c != NULL){
        if (c->qtd > 0) {
            while(state != 1 && i < c->qtd){
                state = cmp((void *)c->Elms[i], key);
                if (state == 0){
                    i++;
                }
            }
            if(state == 1){
                data = c->Elms[i];
                for(j = i; j < c->qtd - 1; j++){
                    c->Elms[j] = c->Elms[j+1];
                }
                c->qtd--;
                return data;
            }
        }
    }
    return NULL;
}



/*Listar Todos*/
void *colGetFirst(Col *c){
    c->current = 0;
    if (c!=NULL){
        if(c->current < c->qtd){
            return c->Elms[c->current];
        }
    }
    return NULL;
}
void *colGetNext(Col *c){

    if (c!=NULL){
        c->current++;
        if(c->current < c->qtd){
            return c->Elms[c->current];
        }
    }
    return NULL;
}

/*Destruir Lista*/
Col *colDestroi(Col *c){
    int i;
    if(c != NULL){
        if(c->Elms!=NULL){
            for(i=0; i < c->maxElms; i++){
                free(c->Elms[i]);
            }
            free(c->Elms);
            free(c);
            return c;
        }
    }
    return NULL;
}
