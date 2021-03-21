
#ifndef STACK_H
#define STACK_H

#define N 10

typedef struct stack TStack;
struct stack //pilha
{
	int top;
	int S[N];
};

TStack * build_stack();
int stack_empty( TStack *s);
void push(TStack *s, int elem);
int pop(TStack *s);




#endif