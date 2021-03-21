#ifndef QUEUE_H
#define QUEUE_H

typedef struct queue TQueue;
struct queue
{
    int size;
	int head;
	int tail;
    void **Q;
};

TQueue * build_queue(int size);
int empty_queue(TQueue *q);
int full_queue(TQueue *q);
void enqueue(TQueue *q, void* elem);
void* dequeue(TQueue *q);
void free_queue(TQueue *q, void (*free_elem)());

#endif
