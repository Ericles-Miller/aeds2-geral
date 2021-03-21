
#ifndef STACK_H
#define STACK_H

typedef struct stack TStack;
struct stack
{
	int size;//tamanho
	int top;//top
	int **S;
};

TStack * build_stack(int);
int stack_empty( TStack *s);
void push(TStack *, int *);
int * pop(TStack *s);
void free_stack(TStack *);

#endif