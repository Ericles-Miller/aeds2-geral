#include <stdio.h>
#include <stdlib.h>
#include "stack.h"	


TStack * build_stack() //construir pilha
{
	TStack *aux = (TStack*)malloc(sizeof(TStack));
	aux->top = -1;
	return aux;
}

int stack_empty( TStack *s)//esvaziar
{
	if(s->top >= 0 )
	{
		return 0;
	}
	return 1;
}

void push(TStack *s, int elem)//empurrar
{
	if( s->top != N -1 )//see o top for diferente de -1
	{
		s->top++;//top recebe o +1 elemento
		s->S[s->top] = elem;
	}
	else
	{
		printf("stack full\n");//pilha cheia
	}
}

int pop(TStack *s)
{
	int aux;
	
	if( !stack_empty(s) )//se pilha for diferente de vazia
	{
		aux = s->S[ s->top ];//S recebe o valor de top
		s->top--;//reduz uma posicao pois começa em 0
		return aux;//retora o valor da posição
	}
	else
	{
		printf("Stack empty\n");
		return -1;//pilha vazia
	}
}

