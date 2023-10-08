#include <stdlib.h>

typedef struct _STACK_{
    int top;
    int maxElms;
    void **elms;
}Stack;

Stack *stkCreate(int max){
    Stack *s;
    if (max > 0){
        s = (Stack *)malloc(sizeof(Stack));
        if(s!=NULL){
            s->elms = (void **)malloc(sizeof(void *)*max);
            if (s->elms!=NULL){
                s->top = -1;
                s->maxElms = max;
                return s;
            }
        }
    }
    return NULL;
}

int stkDestroy(Stack *s){
    if (s != NULL){
        if(s->elms!=NULL){
            if(s->top>=0){
                free(s->elms);
                free(s);
                return 1;
            }
        }
    }
    return 0;
}

int stkPush(Stack *s, void *elm){
    if(s != NULL){
        if (s->top < s->maxElms-1){
            s->top++;
            s->elms[s->top] = elm;
            return 1;
        }
    }
    return 0;
}

void *stkPop(Stack *s){
    void *elm;
    if(s != NULL){
        if (s->top >= 0){
            elm = s->elms[s->top];
            s->top--;
            return elm;
        }
    }
    return NULL;
}

void *stkTop(Stack *s){
    void *elm;
    if(s != NULL){
        if (s->top >= 0){
            elm = s->elms[s->top];
            return elm;
        }
    }
    return NULL;
}


