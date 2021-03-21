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


void insert_begin(TList *l, void * elem )
{
	TNo * no = (TNo*)malloc(sizeof(TNo));
	no->elem = elem;
	no->prev = NULL;
	no->next = NULL;
	if( empty_list(l) )
	{
		l->first = no;
		l->last = no;
	}
	else
	{
		no->next = l->first;
		l->first->prev = no;
		l->first = no;
	}
}

void insert_end(TList *l, void * elem )
{
	TNo *no = (TNo*)malloc(sizeof(TNo));
	no->elem = elem;
	no->next = NULL;
	no->prev = NULL;
	if( empty_list(l) )
	{
		l->first = no;
		l->last = no;
	}
	else
	{
		no->prev = l->last;
		l->last->next = no;
		l->last = no;
	}
}

void sort_list(TList *l, int (*comp)())
{
	int sort = 1;
	void * aux_elem;
	TNo *aux;
	
	if( !empty_list(l) )
	{
		while( sort )
		{
			sort = 0;
			aux = l->first;
			/* troca */
			/* while( aux->next ) */
			while( aux->next != NULL)
			{
				if( comp(aux->elem, aux->next->elem))
				{
					aux_elem = aux->next->elem;
					aux->next->elem = aux->elem;
					aux->elem = aux_elem;
					sort = 1;
				}
				aux = aux->next;
			}
		}
	}
}

TNo * search_list_no( TList *l, void *elem, int (*comp)() )
{
	TNo *aux = l->first;
	
	while( aux )
	{
		if(comp(aux->elem, elem))
		{
			return aux;
		}
		aux = aux->next;
	}
	printf("not found\n");
	return NULL;	
}

void insert_next_elem(TList *l, void * elem, void * key, int (*comp)())
{
	TNo *no;
	TNo *aux;
	
	no = (TNo*)malloc(sizeof(TNo));
	no->elem = elem;
	no->next = NULL;
	no->prev = NULL;
	
	aux = search_list_no( l, key, comp );
	if( aux )
	{
		if( aux == l->last)
		{
			no->prev = l->last;
			l->last->next = no;
			l->last = no;
		}
		else
		{
			no->next = aux->next;
			no->prev = aux;
			aux->next->prev = no;
			aux->next = no;
		}
	}
	else
	{
		no->prev = l->last;
		l->last->next = no;
		l->last = no;
	}
}

void remove_list(TList *l, void * elem, int (*comp)())
{
	TNo *aux;
	
	aux = search_list_no( l, elem, comp );
	if( aux )
	{
		if( aux == l->first )
		{
			l->first = aux->next;
			if( aux->next )
				aux->next->prev = NULL;
		}
		else
		if( aux == l->last )
		{
			l->last = aux->prev;
			aux->prev->next = NULL;
		}
		else
		{
			aux->prev->next = aux->next;
			aux->next->prev = aux->prev;
		}
		free(aux);
	}
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
