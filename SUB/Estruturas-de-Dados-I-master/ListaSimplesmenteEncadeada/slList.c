#include <stdlib.h>
#include "slList.h"


SlList *sllCreate(){
    SlList *s;
    s = (SlList *)malloc(sizeof(SlList));
    if(s!=NULL){
        s->first = NULL;
        return s;
    }
    return NULL;
}

int sllDestroy(SlList *s){
    if(s!=NULL){
        if(s->first == NULL){
            free(s);
            return 1;
        }
    }
    return 0;
}

//Insere na cabeça da lista
int sllInsertFirst(SlList *s, void *elm){
    SlNode *novo;
    if(s!=NULL){
        novo = (SlNode *)malloc(sizeof(SlNode));
        if(novo != NULL){
            novo->data = elm;
            novo->next = s->first;
            s->first = novo;
        }
        return 1;
    }
    return 0;
}

//Remove o primeiro da lista
void *sllDestroyFirst(SlList *s){
    void *elm;
    SlNode *current;
    if(s !=NULL){
        if(s->first!=NULL){
            current = s->first;
            elm = current->data;
            s->first = current->next;
            free(current);
            return elm;
        }
    }
    return NULL;
}

//Insere no final da lista
int sllInsertAsLast(SlList *s, void *elm){
    SlNode *novo, *current;
    if(s!=NULL){
        novo = (SlNode *)malloc(sizeof(SlNode));
        if(novo != NULL){
            novo->data = elm;
            novo->next = NULL;
            if(s->first == NULL){
                s->first = novo;
            } else {
                current = s->first;
                while(current->next!=NULL){
                    current = current->next;
                }
                current->next = novo;
            }
        }
        return 1;
    }
    return 0;
}

//Remove o último elemento da lista
void *sllDestroyLast(SlList *s){
    void *elm;
    SlNode *previous = NULL, *current;

    if(s !=NULL){
        if(s->first!=NULL){
            current = s->first;
            while(current->next !=NULL){
                previous = current;
                current = current->next;
            }
            elm = current->data;
            if(previous != NULL){
                previous->next = current->next;
            } else{
                s->first = current->next;
            }
            free(current);
            return elm;
        }
    }
    return NULL;
}
void *sllRemoveSpecified(SlList *s, int (*cmp)(void *, void *), void *key){
    SlNode *prev, *cur;
    int i = 0, state;
    void *data;
    if(s!=NULL){
        if(s->first!=NULL){
            cur = s->first;
            prev = NULL;
            state = cmp(cur->data, key);//Se for encontrado o elemento, retorna 1
            while(state!=1 && cur->next!=NULL){
                prev = cur;
                cur = cur->next;
                state = cmp(cur->data, key);
            }
            if(state == 1){
                data = cur->data;
                if(prev ==NULL){
                    s->first = cur->next;
                } else{
                    prev->next = cur->next;
                }
                free(cur);
                return data;
            }
        }
    }
    return NULL;
}


