#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

#define N 10

int main()
{
	int *aux;
	TStack *s;
	
	s = build_stack(10);//construir a pilha com 10 posiç.
	if(!stack_empty(s))
	{
		aux = pop(s);
		printf("%i\n", *(aux) );
		free(aux);
	}
	
	aux = (int*)malloc(sizeof(int));
	*aux = 3;
	push(s, aux);
	
	aux = (int*)malloc(sizeof(int));
	*aux = 4;
	push(s, aux);
	
	aux = (int*)malloc(sizeof(int));
	*aux = 1;
	push(s, aux);
	
	aux = (int*)malloc(sizeof(int));
	*aux = 2;
	push(s, aux);
	
	aux = (int*)malloc(sizeof(int));
	*aux = 7;
	push(s, aux);

	if(!stack_empty(s))
	{
		aux = pop(s);
		printf("%i\n", *(aux) );
		free(aux);
	}
	
	if(!stack_empty(s))
	{
		aux = pop(s);
		printf("%i\n", *(aux) );
		free(aux);
	}
	
	if(!stack_empty(s))
	{
		aux = pop(s);
		printf("%i\n", *(aux) );
		free(aux);
	}
	aux = (int*)malloc(sizeof(int));
	*aux = 9;
	push(s, aux);
	
	if(!stack_empty(s))
	{
		aux = pop(s);
		printf("%i\n", *(aux) );
		free(aux);
	}
	
	if(!stack_empty(s))
	{
		aux = pop(s);
		printf("%i\n", *(aux) );
		free(aux);
	}
	
	if(!stack_empty(s))
	{
		aux = pop(s);
		printf("%i\n", *(aux) );
		free(aux);
	}

	return 0;
}