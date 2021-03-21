#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

void free_integer( void * elem)
{
	free(elem);
}

int main()
{
	TQueue *queue;
	int *num;
	
	queue = build_queue();
	
	num = (int*)malloc(sizeof(int));
	*num = 2;
	enqueue(queue, num);
	
	num = (int*)malloc(sizeof(int));
	*num = 4;
	enqueue(queue, num);
	
	num = (int*)malloc(sizeof(int));
	*num = 6;
	enqueue(queue, num);
	
	num = (int*)malloc(sizeof(int));
	*num = 8;
	enqueue(queue, num);
	
	num = (int*)malloc(sizeof(int));
	*num = 10;
	enqueue(queue, num);
	
	num = dequeue(queue);
	if(num!=NULL)
	{ 
		printf("%i\n",*num);
		free(num);
	}
	
	num = dequeue(queue);
	if(num!=NULL)
	{ 
		printf("%i\n",*num);
		free(num);
	}
	
	num = dequeue(queue);
	if(num!=NULL)
	{ 
		printf("%i\n",*num);
		free(num);
	}
	
	num = dequeue(queue);
	if(num!=NULL)
	{ 
		printf("%i\n",*num);
		free(num);
	}
	
	free_queue(queue, &free_integer);
	
	return 0;
}