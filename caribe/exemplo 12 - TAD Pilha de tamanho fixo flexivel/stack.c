#include <stdio.h>
#include <stdlib.h>
#include "stack.h"


TStack * build_stack(int size)
{
	TStack *aux = (TStack*)malloc(sizeof(TStack));
	aux->top = -1;
	aux->S = (int**)malloc(sizeof(int*)*size);
	aux->size = size;
	return aux;
}

int stack_empty( TStack *s)
{
	if(s->top >= 0 )
	{
		return 0;
	}
	return 1;
}

void grow_stack (TStack *s)//crescer pilha
{
	int i, **new_vector;

	new_vector = (int**)malloc(sizeof(int*)* s->size*2);
	for(i=0;i<s->size;i++)
	{
		new_vector[i] = s->S[i]; 
	}
	free(s->S);
	s->size *= 2;
	s->S = new_vector;
}

void push(TStack *s, int *elem)
{

	if( s->top != s->size -1 )
	{
		s->top++;
		s->S[s->top] = elem;
	}
	else
	{
		grow_stack(s);
		s->top++;
		s->S[s->top] = elem;
	}
}

int* pop(TStack *s)
{
	int *aux;
	
	if( !stack_empty(s) )
	{
		aux = s->S[ s->top ];
		s->top--;
		return aux;
	}
	else
	{
		printf("Stack empty\n");
		return NULL;
	}
}

void free_stack(TStack * s)
{
	int *aux;
	while( !stack_empty( s ) )
	{
		aux = pop(s);
		free(aux);
	}
	free(s->S);
	free(s);
}

