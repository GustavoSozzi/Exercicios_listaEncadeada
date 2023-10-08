#include <stdlib.h>
#include "DCList.h"

CLList *cllCreate()
{
    CLList *l;
    l = (CLList *)malloc(sizeof(CLList));
    if(l!=NULL){
        l->first = NULL;
        l->cur = NULL;
        return l;
    }
    return NULL;
}

int cllDestroyAll(CLList *l);
{
    CLNode *tmp; void *data;
    if(l!=NULL){
        if(l->first!=NULL){
            l->cur = l->first;
            while(l->cur->next!=l->first){
                tmp = l->cur;
                data = tmp->data;
                l->cur = l->cur->next;
                free(tmp);
                killNode(data);
            }
            free(l);
            return 1;
        }
    }
    return 0;
}
void killNode(void *data){
    free(data);
}

int cllInsertAfterSpec(CLList *l, void key, void *data, (int *)cmp(void *, void *)){
    ClNode *spec, afternode, node;
    int state;
    if(l!=NULL){
        if(l->first!=NULL){
            spec = l->first;
            state = cmp(spec->data, key);
            while(spec->next!=l->first && state!=true){
                spec = spec->next;
                state = cmp(spec->data, key);
            }
            if(state == true){
                node = (ClNode*)malloc(sizeof(ClNode));
                node->data = data;
                afternode = spec->next;
                node->prev = spec;
                node->next = afternode;
                spec->next = node;
                afternode->prev = node;
                return true;
            }

        }
    }

    return false;

}
int cllInsertBeforeSpec(CLList *l, void key, void *data, (int *)cmp(void *, void *)){
    ClNode *spec, *beforenode, *node;
    int state;
    if(l!=NULL){
        if(l->first!=NULL){
            spec = l->first;
            state = cmp(spec->data, key);
            while(spec->next!=l->first && state!=true){
                spec = spec->next;
                state = cmp(spec->data, key);
            }
            if(state == true){
                node = (ClNode*)malloc(sizeof(ClNode));
                node->data = data;
                beforenode = spec->prev;
                node->prev = beforenode;
                node->next = spec;
                spec->prev = node;
                beforenode->next = node;
                if(spec ==l->first){
                    l->first = node;
                }
                return true;
            }

        }
    }

    return false;

}
