#include <stdio.h>
#include <stdlib.h>
#include "list.h"

TList * build_list()
{
	TList *l = (TList*)malloc(sizeof(TList));
	l->first = NULL;
	l->last = NULL;
	return l;
}

int empty_list(TList * l)
{
	if(l->first == NULL)
		return 1;
	return 0;
}

void * search_list( TList *l, void *elem, int (*comp)() )
{
	TNo *aux = l->first;
	
	while( aux )
	{
		if(comp(aux->elem, elem))
		{
			return aux->elem;
		}
		aux = aux->next;
	}
	printf("not found\n");
	return NULL;
}

void insert_middle(TList *l, void * elem,  int (*comp)() )
{
	TNo *aux, *old, *no = (TNo*)malloc(sizeof(TNo));
	no->elem = elem;
	no->next = NULL;
	
	if( empty_list(l) )
	{
		l->first = no;
		l->last = no;
	}
	else
	{
		/* se no->elem <= first->elem return 1*/
		if( comp(no->elem, l->first->elem))
		{
			no->next = l->first;
			l->first = no;
		}
		else
		if( !comp(no->elem, l->last->elem))
		{
			l->last->next = no;
			l->last = no;
		}
		else
		{
			old = NULL;
			aux = l->first;
			while( aux )
			{
				if( comp(no->elem, aux->elem))
				{
					old->next = no;
					no->next = aux;
					return;/*break;*/
				}
				old = aux;
				aux = aux->next;
			}
		}
	}
}

void print_list(TList *l, void (*print)() )
{
	TNo *aux = l->first;
	while( aux )
	{
		print( aux->elem );
		aux= aux->next;
	}
}


void free_list( TList *l, void (*free_elem)() )
{
	TNo *aux = l->first;
	while( aux )
	{
		free_elem( aux->elem);
		l->first = aux->next;
		free(aux);
		aux = l->first;
	}
	free(l);
}
