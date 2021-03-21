#ifndef QUEUE_H
#define QUEUE_H

typedef struct no TNo;
struct no
{
	int elem;
	TNo *prox;//proxima pos
};

typedef struct queue TQueue;//fila
struct queue
{
	TNo *head;//cabeça
	TNo *tail;//rabo
};

TQueue * build_queue();
int empty_queue(TQueue *q);
void enqueue(TQueue *q, int elem);
TNo* dequeue(TQueue *q);
void free_queue(TQueue *q);



#endif