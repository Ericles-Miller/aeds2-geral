#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

TQueue * build_queue(int size)
{
	TQueue * aux = (TQueue *)malloc(sizeof(TQueue ));
    aux->Q = (void**)malloc(sizeof(void*) * size);
    aux->size = size;
	aux->head = -1;
	aux->tail = -1;
	return aux;
}

int empty_queue(TQueue *q)
{
	if(q->head == -1)
	{
		return 1;
	}
	return 0;
}

int full_queue(TQueue *q)
{
    if(q->tail == q->size - 1)
        return 1;
    return 0;
}

void enqueue(TQueue *q, void * elem)
{	
    if( empty_queue(q))
    {
        q->head++;
        q->tail++;
        q->Q[ q->head ] = elem;
    }
    else
    if( !full_queue(q))
    {
        q->tail++;
        q->Q[ q->tail ] = elem;  
    }
    else
    {
        printf("Full queue!!\n");
    }
}

void * dequeue(TQueue *q)
{
    void * aux;
    if( !empty_queue(q))
    {
        aux = q->Q[q->head];
        q->head++;
        
        if(q->head > q->tail)
        {
            q->head = -1;
            q->tail = -1;
        }
        return aux;
    }
    else
    {
        printf("empty queue!!\n");
        return NULL;
    }
    
}

void free_queue(TQueue *q, void (*free_elem)())
{
    while( !empty_queue(q) )
    {
      free_elem( dequeue(q) );
    }
    free(q->Q);
    free(q);
}
