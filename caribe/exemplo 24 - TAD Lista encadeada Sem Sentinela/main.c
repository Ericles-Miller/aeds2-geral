#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int comp_integer( int *elem1, int *elem2 )
{
	if(*elem1 == *elem2)
		return 1;
	return 0;
}

int comp_sort( int *elem1, int *elem2 )
{
	if(*elem1 < *elem2)
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
	int *e, e2 = 5;
	TNo *l = NULL;
	
	e = (int *)malloc(sizeof(int));
	*e = 1;
	insert_sort(&l, e, &comp_sort);
	
	e = (int *)malloc(sizeof(int));
	*e = 3;
	insert_sort(&l, e, &comp_sort);
	
	e = (int *)malloc(sizeof(int));
	*e = -2;
	insert_sort(&l, e, &comp_sort);
	
	e = (int *)malloc(sizeof(int));
	*e = 2;
	insert_sort(&l, e, &comp_sort);
	
	e = search_list( l, &e2, &comp_integer );
	if( e )
	{
		printf("--\n");
		print_integer(e);
	}
	
	print_list(l, &print_integer);
	
	free_list( &l, &free_integer );
	
	return 0;
}
