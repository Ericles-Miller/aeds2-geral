#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int comp_integer( int *elem1, int *elem2 )
{
	if(*elem1 == *elem2)
		return 1;
	return 0;
}

void print_integer( int *elem)
{
	printf("%i\n", *elem);
}

void free_integer(int *elem )
{
	free(elem);
}


int main()
{
	int *e, e_s = 10;
	TList *l;
	
	l = build_list();
	
	e = (int *)malloc(sizeof(int));
	*e = 4;
	insert_begin(l, e);
	
	e = (int *)malloc(sizeof(int));
	*e = 2;
	insert_begin(l, e);
	
	e = (int *)malloc(sizeof(int));
	*e = 3;
	insert_begin(l, e);
	
	e = (int *)malloc(sizeof(int));
	*e = 1;
	insert_begin(l, e);
	
	e = (int *)malloc(sizeof(int));
	*e = 2;
	insert_begin(l, e);
	
	e = search_list( l, &e_s, &comp_integer );
	if( e != NULL)
	{
		printf("-%i\n", *e);
	}
	
	print_list(l, &print_integer);
	
	free_list(l, &free_integer);
	
	
	return 0;
}
