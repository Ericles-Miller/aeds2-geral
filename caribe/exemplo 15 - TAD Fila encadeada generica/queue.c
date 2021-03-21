#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

TQueue * build_queue()
{
	TQueue * aux = (TQueue *)malloc(sizeof(TQueue ));
	aux->head = NULL;
	aux->tail = NULL;
	return aux;
}

int empty_queue(TQueue *q)
{
	if(q->head == NULL)
	{
		return 1;
	}
	return 0;
}

void enqueue(TQueue *q, void *elem)
{
	TNo *aux = (TNo*)malloc(sizeof(TNo));
	
	aux->elem = elem;
	aux->prox = NULL;
	if( empty_queue(q) )
	{
		q->head = aux;
		q->tail = aux;
	}
	else
	{
		q->tail->prox = aux;
		q->tail = aux;
	}
}

void* dequeue(TQueue *q)
{
	void *aux = NULL;
	TNo* no  = NULL;
	
	if( !empty_queue(q) )
	{
		no = q->head;
		q->head = q->head->prox;
		aux = no->elem;
		free(no);
	}
	else
	{
		printf("empty queue\n");
	}
	return aux;
}

void free_queue(TQueue *q, void (*free_elem)())
{
	void *aux;
	
	while( !empty_queue(q) )
	{
		aux = dequeue(q);
		free_elem(aux);
	}
	free(q);
}