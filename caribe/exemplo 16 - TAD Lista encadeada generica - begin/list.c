#include <stdio.h>
#include <stdlib.h>
#include "list.h"

TList * build_list()//costruir
{
	TList *l = (TList*)malloc(sizeof(TList));
	l->first = NULL;//começo receb null
	l->last = NULL;//fim recebe null
	return l;
}

int empty_list(TList * l)//list vazia
{
	if(l->first == NULL)//se gor nula
		return 1;
	return 0;
}

void * search_list( TList *l, void *elem, int (*comp)() )//pesq. list
{
	TNo *aux = l->first;//aux receb primeiro dado da list
	
	while( aux )//se for true
	{
		if(comp(aux->elem, elem))//end de comp 
		{
			return aux->elem;//retorn o prieiro 
		}
		aux = aux->next;//proximo da lista
	}
	printf("not found\n");
	return NULL;
}

void insert_begin(TList *l, void * elem )//inserir inicio
{
	TNo *no = (TNo*)malloc(sizeof(TNo));
	no->elem = elem;
	no->next = NULL;
	
	if( empty_list(l) )
	{
		l->first = no;
		l->last = no;
	}
	else
	{
		no->next = l->first;
		l->first = no;
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
