#include <stdio.h>
#include <stdlib.h>
#include "stack.h"


TStack * build_stack(int size)//construir
{
	TStack *aux = (TStack*)malloc(sizeof(TStack));
	aux->top = -1;//
	aux->S = (int**)malloc(sizeof(int*)*size);//alocando matriz de ponteiro
	aux->size = size;//recebe do paramentro o tam da pilha
	return aux;
}

int stack_empty( TStack *s)//pilha vazia
{
	if(s->top >= 0 )//pi nao vazia
	{
		return 0;
	}
	return 1;
}

void push(TStack *s, int *elem)//empurrar
{
	if( s->top != s->size -1 )//verifica se esta cheia
	{
		s->top++;
		s->S[s->top] = elem;
	}
	else
	{
		printf("stack full\n");
	}
}

int* pop(TStack *s)//desempilhar
{
	int *aux;
	
	if( !stack_empty(s) )
	{
		aux = s->S[ s->top ];//recebe o valor de top
		s->top--;
		return aux;
	}
	else
	{
		printf("Stack empty\n");
		return NULL;
	}
}

void free_stack(TStack * s)//desalocar
{
	int *aux;
	while( !stack_empty( s ) )//enq. nao for vazia faça
	{
		aux = pop(s);
		free(aux);//libera os dados da var referente a qtd
	}
	free(s->S);//desaloca uma vez s
	free(s);//desaloca duas vezes s
}

