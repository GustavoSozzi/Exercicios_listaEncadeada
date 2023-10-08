#include <stdlib.h>
#include "slList.h"

//Cria a lista
SlList *sllCreate(){
    SlList *s;
    s = (SlList *)malloc(sizeof(SlList));
    if(s!=NULL){
        s->first = NULL;
        s->cur = NULL;
        return s;
    }
    return NULL;
}
//Destroi a lista
int sllDestroy(SlList **s){
    SlNode *no, *aux;
    if(s!=NULL){
        if((*s)->first != NULL){
            no = (*s)->first;
            while(no->next !=NULL){
                aux = no;
                no = no->next;
                free(aux);
            }
            free(*s);
        }
        (*s) = NULL;
        return 1;

    }
    return 0;
}

//Insere na cabeça da lista
int sllInsertFirst(SlList **s, void *elm){
    SlNode *novo;
    if(*s!=NULL){
        novo = (SlNode *)malloc(sizeof(SlNode));
        if(novo != NULL){
            novo->data = elm;
            novo->next = (*s)->first;
            (*s)->first = novo;
        }
        return 1;
    }
    return 0;
}

//Insere no final da lista
int sllInsertAsLast(SlList **s, void *elm){
    SlNode *novo, *current;
    if(*s!=NULL){
        novo = (SlNode *)malloc(sizeof(SlNode));
        if(novo != NULL){
            novo->data = elm;
            novo->next = NULL;
            if((*s)->first == NULL){
                (*s)->first = novo;
            } else {
                current = (*s)->first;
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

//Remove um elemento específico
void *sllRemoveSpecified(SlList *s, int (*cmp)(void *, void *), void *key){
    SlNode *prev, *current;
    int state;
    void *data;
    if(s!=NULL){
        if(s->first!=NULL){
            current = s->first;
            prev = NULL;
            state = cmp(current->data, key);//Se for encontrado o elemento, retorna 1
            while(state!=1 && current->next!=NULL){
                prev = current;
                current = current->next;
                state = cmp(current->data, key);
            }
            if(state == 1){
                data = current->data;
                if(prev ==NULL){
                    s->first = current->next;
                } else{
                    prev->next = current->next;
                }
                free(current);
                return data;
            }
        }
    }
    return NULL;
}

//Consulta um elemento específico
void *sllConsultaEspecificado(SlList *s, int (*cmp)(void *, void *), void *key){
    SlNode *current;
    int state;
    void *data;
    if(s!=NULL){
        if(s->first!=NULL){
            current = s->first;
            state = cmp(current->data, key);//Se for encontrado o elemento, retorna 1
            while(state!=1 && current->next!=NULL){
                current = current->next;
                state = cmp(current->data, key);
            }
            if(state == 1){
                data = current->data;
                return data;
            }
        }
    }
    return NULL;
}

//Retorna os dados do primeiro nó da lista
void *sllGetFirst(SlList *s){
    if(s!=NULL){
        if(s->first !=NULL){
            s->cur = s->first;
            return s->cur->data;
        }
    }

    return NULL;
}
//Retorna os dados dos elementos depois do primeiro da lista
void *sllGetNext(SlList *s){
    if(s!=NULL){
        if(s->first !=NULL){
            s->cur = s->cur->next;
            if(s->cur!=NULL){
                return s->cur->data;
            }
        }
    }
    return NULL;
}
//Retorna quantos elementos tem na lista
int sllNumDeElem(SlList *s){
    int i = 0;
    SlNode *aux;
    if(s!=NULL){
        if(s->first !=NULL){
            aux = s->first;
            i++;
            while(aux->next!=NULL){
                aux = aux->next;
                i++;
            }
            return i;
        }
    }
    return i;
}
