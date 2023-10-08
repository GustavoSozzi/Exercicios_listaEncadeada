#include <stdlib.h>
#include "Dllist.h"


DLList *sllCreate(){
    DLList *l;
    l = (DLList *)malloc(sizeof(DLList));
    if(l!=NULL){
        l->first = NULL;
        l->cur = NULL;
        return l;
    }
    return NULL;
}


int dllDestroy(DLList *l){
    if(l!=NULL){
        if(l->first == NULL){
            free(l);
            return 1;
        }
    }
    return 0;
}

int dllInsertAfterSpec(DLList *l, int (*cmp)(void *, void *), void *key, void *data){
    DLNode *spec, *prox, *newnode;
    int state;
    if(l!=NULL){
        if(l->first!=NULL){
            spec = l->first;
            state = cmp(cur->data, key);//Se for encontrado o elemento, retorna 1
            while(state!=1 && spec->next!=NULL){
                spec = spec->next;
                state = cmp(cur->data, key);
            }
            if(state == 1){
                newnode = (DLNode *)malloc(sizeof(DLNode));
                if(newnode!=NULL){
                    newnode->data = data;
                    prox = spec->next;
                    newnode->next = spec->next;
                    newnode->prev = spec;
                    spec->next = newnode;
                    if(prox!=NULL){
                        prox->prev = newnode;
                    }
                    return 1;
                }
            }
        } else{
            newnode = (DLNode *)malloc(sizeof(DLNode));
            if(newnode!=NULL){
                    newnode->data = data;
                    newnode->next = NULL;
                    newnode->prev = NULL;
                    l->first = newnode;
                    return 1;
        }
    }
    return 0;
}

