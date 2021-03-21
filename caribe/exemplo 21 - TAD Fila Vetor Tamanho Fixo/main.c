#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"

#define N 5

void free_string( char * str)
{
    free( str);
}


int main()
{
    int i;
    char *str;
	TQueue *queue;
    
	queue = build_queue( N );
    
    str = (char*)malloc(sizeof(char)*30);
    strcpy(str, "aaa");
	enqueue(queue, str);
    
    str = (char*)malloc(sizeof(char)*30);
    strcpy(str, "ccc");
	enqueue(queue, str);

    str = (char*)malloc(sizeof(char)*30);
    strcpy(str, "bbb");
	enqueue(queue, str);
	
    for(i=queue->head;i<=queue->tail;i++)
        printf("%s\n", (char*)queue->Q[i]);
        
    printf("----------------------\n");
    
	str = dequeue(queue);
    if( str ) printf("%s\n",str);
    free(str);
    
    str = dequeue(queue);
    if( str ) printf("%s\n",str);
    free(str);

    str = dequeue(queue);
    if( str ) printf("%s\n",str);
    free(str);
    
    free_queue(queue, &free_string);

	
	return 0;
}
