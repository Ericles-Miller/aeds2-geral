#include <stdio.h>
#include "stack.h"


int main()
{
	TStack *s;
	
	s = build_stack();
	if(!stack_empty(s))//se pilha nao estiver  vazia
	{
		printf("%i\n", pop(s));//ex. a funcao
	}
	
	push(s, 3);
	push(s, 4);
	push(s, 1);
	push(s, 2);
	push(s, 7);
	if(!stack_empty(s))//se pilha ñ estiver vazia
	{
		printf("%i\n", pop(s));
	}
	
	if(!stack_empty(s))
	{
		printf("%i\n", pop(s));
	}
	
	if(!stack_empty(s))
	{
		printf("%i\n", pop(s));
	}
	push(s, 9);
	
	if(!stack_empty(s))
	{
		printf("%i\n", pop(s));
	}
	
	if(!stack_empty(s))
	{
		printf("%i\n", pop(s));
	}
	
	if(!stack_empty(s))
	{
		printf("%i\n", pop(s));
	}

	return 0;
}