#include<stdio.h>
#include<stdlib.h>

typedef struct stack tstack;
struct stack
{
    int size;
    int top;
    int **S
};

tstack *build_stack(int size)
{
    tstack *aux =(tstack*)malloc(sizeof(tstack));
    aux->size=size;
    aux->top=-1;
    aux->S=(int**)malloc(sizeof(int*)*size);
    return aux;
}

int empty_stack(tstack *s)
{
    if(s->top>=0)
        return 0;
    else
        return 1;
}

void push_stack(tstack *s,int *n)
{
    if(s->top != s->size-1)
    {
        s->top++;
        s->S[s->top]=n;
        printf("\n%d",*(s->S[s->top]));
    }
    else
        printf(" full stack!\n");
}

int * pop_stack(tstack *s)
{
    int *aux;
    if(!empty_stack)
    {
        aux=s->S[s->top];
        s->top--;
        return aux;
    }
    else
        printf("\nempty stack");
        return NULL;
}

void free_stack(tstack *s)
{
    int *aux;

    while(!empty_stack)
    {
        aux =pop_stack(s);
        free(aux);
    }
    free(s->S);
    free(s);
}

int main()
{
    tstack *s;
    int tam=5;
    int *aux;

    s=build_stack(tam);

    aux=(int*)malloc(sizeof(int));
    *aux =1;
    push_stack(s,aux);

    aux=(int*)malloc(sizeof(int));
    *aux =2;
    push_stack(s,aux);

    aux=(int*)malloc(sizeof(int));
    *aux =3;
    push_stack(s,aux);

    aux=(int*)malloc(sizeof(int));
    *aux =4;
    push_stack(s,aux);

    aux=(int*)malloc(sizeof(int));
    *aux =5;
    push_stack(s,aux);

    if(!empty_stack(s))
    {
        aux=pop_stack(s);
        printf("%d",*(aux));
        free(aux);
    }

    if(!empty_stack(s))
    {
        aux=pop_stack(s);
        printf("%d",*(aux));
        free(aux);
    }

    if(!empty_stack(s))
    {
        aux=pop_stack(s);
        printf("%d",*(aux));
        free(aux);
    }

    if(!empty_stack(s))
    {
        aux=pop_stack(s);
        printf("%d",*(aux));
        free(aux);
    }

    if(!empty_stack(s))
    {
        aux=pop_stack(s);
        printf("%d",*(aux));
        free(aux);
    }

return 0;
}
