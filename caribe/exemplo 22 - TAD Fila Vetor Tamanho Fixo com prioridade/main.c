#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"

#define N 5

void free_elem( int * elem)
{
    free( elem);
}

int comp_elem(int *e1, int *e2)
{
    if( *e1 < *e2)
       return 1;
    return 0;
}

int main()
{
    int *e;
	TQueue *queue;
		
	queue = build_queue( N );
   
    e = (int*)malloc(sizeof(int));
    *e = 3;
	enqueue(queue, e, &comp_elem);
    
    e = (int*)malloc(sizeof(int));
    *e = 1;
	enqueue(queue, e, &comp_elem);
    
    e = (int*)malloc(sizeof(int));
    *e = 4;
	enqueue(queue, e, &comp_elem);
    
    e = (int*)malloc(sizeof(int));
    *e = 2;
	enqueue(queue, e, &comp_elem);    
    
	e = dequeue(queue);
    if( e ) printf("%i\n",*e);
    free(e);
    
	e = dequeue(queue);
    if( e ) printf("%i\n",*e);
    free(e);
    
	e = dequeue(queue);
    if( e ) printf("%i\n",*e);
    free(e);
    
    e = dequeue(queue);
    if( e ) printf("%i\n",*e);
    free(e);
    
    free_queue(queue, &free_elem);

	return 0;
}
