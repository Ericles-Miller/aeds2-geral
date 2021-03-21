#ifndef QUEUE_H
#define QUEUE_H

typedef struct no TNo;
struct no
{
	void* elem;
	TNo *prox;
};

typedef struct queue TQueue;
struct queue
{
	TNo *head;
	TNo *tail;
};

TQueue * build_queue();
int empty_queue(TQueue *q);
void enqueue(TQueue *q, void *elem);
void* dequeue(TQueue *q);
void free_queue(TQueue *q, void (*free_elem)());



#endif