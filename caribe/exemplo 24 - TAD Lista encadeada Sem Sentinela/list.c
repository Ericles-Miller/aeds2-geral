#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int empty_list(TNo * l)
{
	if( l ) 
		return 0;
	return 1;
}
void insert_begin(TNo **l, void * elem )
{
	TNo * no = (TNo*)malloc(sizeof(TNo));
	no->elem = elem;
	
	if(!empty_list( *l ) )
	{
		no->next = *l;
		(*l) = no;
	}
	else
	{
		no->next = NULL;
		*l = no;
	}
}

void insert_end(TNo **l, void * elem )
{
	TNo *aux, * no = (TNo*)malloc(sizeof(TNo));
	no->elem = elem;
	no->next = NULL;
	if( !empty_list( *l ))
	{
		aux = *l;
		while( aux->next )
		{
			aux = aux->next;
		}
		aux->next = no;		
	}
	else
	{
		*l = no;
	}
}

void insert_sort(TNo **l, void * elem, int (*comp_sort)() )
{
	TNo *aux, *aux_prev, * no = (TNo*)malloc(sizeof(TNo));
	no->elem = elem;
	
	if( !empty_list( *l) )
	{
		aux = *l;
		while( aux )
		{
			if( comp_sort(elem, aux->elem))
			{
				if( aux == *l) /* inicio */
				{
					no->next = *l;
					*l = no;
					break;/*return;*/
				}
				else /*meio*/
				{
					aux_prev->next = no;
					no->next = aux;
					break;/*return*/
				}
			}
			aux_prev = aux;
			aux = aux->next;
		}
		if( !aux ) /*fim*/
		{
			aux_prev->next = no;
			no->next = NULL;
		}
	}
	else
	{
		no->next = NULL;
		*l = no;
	}
	
}

void * search_list( TNo *l, void *elem, int (*comp)() )
{
	while( l )
	{
		if( comp(elem, l->elem))
		{
			return l->elem;
		}
		l = l->next;
	}
	return NULL;
}
void print_list(TNo *l, void (*print)() )
{
	while( l )
	{
		print(l->elem);
		l = l->next;
	}
}
void free_list( TNo **l, void (*free_elem)() )
{
	TNo *aux;
	while( *l )
	{
		aux = (*l)->next;
		free_elem( (*l)->elem );
		free( *l );
		*l = aux;
	}
}