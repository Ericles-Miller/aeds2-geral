#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int main()
{
	TQueue *queue;
	TNo *no;
	
	queue = build_queue();
	enqueue(queue, 2);
	enqueue(queue, 4);
	enqueue(queue, 6);
	enqueue(queue, 8);
	enqueue(queue, 10);
	
	no = dequeue(queue);
	if(no!=NULL)
	{ 
		printf("%i\n",no->elem);
		free(no);
	}
	
	no = dequeue(queue);
	if(no!=NULL)
	{ 
		printf("%i\n",no->elem);
		free(no);
	}
	
	no = dequeue(queue);
	if(no!=NULL)
	{ 
		printf("%i\n",no->elem);
		free(no);
	}
	
	no = dequeue(queue);
	if(no!=NULL)
	{ 
		printf("%i\n",no->elem);
		free(no);
	}
	
	free_queue(queue);
	
	return 0;
}