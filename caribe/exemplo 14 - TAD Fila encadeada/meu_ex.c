#include<stdio.h>
#include<stdlib.h>

typedef struct no tno;
struct no
{
    int elem;
    tno *prox;
};

typedef struct  queue tque;
struct queue
{
    tno *head;
    tno *tail;
};

tque *build_queue()
{
    tque *aux=(tque*)malloc(sizeof(tque));
    aux->head=NULL;
    aux->tail=NULL;

    return aux;
}

int empty_queue(tque *q)
{
    if(q->head == NULL)
    {
        return 1;
    }
    else return 0;
}

void enqueue(tque *q ,int elem)
{
    tno *aux=(tno*)malloc(sizeof(tno));
    aux->elem=elem;
    aux->prox =NULL;

    if(empty_queue(q))
    {
        q->head=aux;
        q->tail= aux;
    }
    else
    {
        q->tail->prox=aux;
        q->tail=aux;
    }
    
}

tno *dequeue (tque *q)
{
    tno *aux;

    if(!empty_queue(q))
    {
        aux=q->head;
        q->head=q->head->prox;
    }

    else
    {
        printf("..............");
    }
    return aux;
    
}

void free_queue(tque *q)
{
    tno *aux;

    while (!empty_queue(q))
    {
        aux=dequeue(q);
        free(aux);
    }
}

int main()
{   
    tno* aux;
    tque *q;

    q=build_queue();

    enqueue(q,1);
    enqueue(q,2);
    enqueue(q,3);
    enqueue(q,4);
    enqueue(q,5);
    enqueue(q,6);
    enqueue(q,7);
    enqueue(q,8);
    enqueue(q,9);

    
    return 0;
}