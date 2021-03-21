#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

TQueue * build_queue()//construir fila
{
	TQueue * aux = (TQueue *)malloc(sizeof(TQueue ));
	aux->head = NULL;//cabeca nula
	aux->tail = NULL;//rabo nula
	return aux;
}

int empty_queue(TQueue *q)//fila vazia
{
	if(q->head == NULL)//se cabeça for nula
	{
		return 1;
	}
	return 0;
}

void enqueue(TQueue *q, int elem)//enfileirar
{
	TNo *aux = (TNo*)malloc(sizeof(TNo));//aloc para a struct no
	
	aux->elem = elem;
	aux->prox = NULL;//outra pos recebe nulo
	if( empty_queue(q) )//se estiver vazia
	{
		//se a pilha estiver vazia ambas as var terao o mesmo endereço
		q->head = aux;//end de memory do no 
		q->tail = aux;
	}
	else
	{
		q->tail->prox = aux;//rabo recebe proximo
		q->tail = aux;
	}
}

TNo* dequeue(TQueue *q)//desinfileirar
{
	TNo* aux  = NULL;
	if( !empty_queue(q) )// se nao estiver vazia
	{
		aux = q->head;//recebe o vlor da cabeça
		q->head = q->head->prox;//e cabeça recebe o valor q estava uma pos atras	
	}
	else
	{
		printf("empty queue\n");
	}
	return aux;
}

void free_queue(TQueue *q)
{
	TNo* aux;
	
	while( !empty_queue(q) )
	{
		aux = dequeue(q);
		free(aux);
	}
	free(q);
}