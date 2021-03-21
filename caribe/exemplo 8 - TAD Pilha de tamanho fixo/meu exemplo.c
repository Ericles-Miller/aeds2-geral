#include<stdio.h>
#include<stdlib.h>
#define tam 10

typedef struct  elementos elem;
struct elementos
{
    int num ;
    int id;
};

typedef struct stack Tstack;
struct stack
{   
    int size; // tamanho
    int top;
    elem **dads;
};

Tstack *build_stack(int size)
{
    Tstack *s= (Tstack*) malloc(sizeof(Tstack));
    s->top=-1;
    s->dads=(elem**)malloc(sizeof(elem*)size);
    s->size=size;

    return s;
}

int empity_stack(Tstack *s)
{
    if(s->top>=0)
    {
        return 0;
    }
    else
    {
         return 1;
    }
}

void push_stack(Tstack *s, elem *e)
{
    if(s->top != s->size-1)
    {
        s->top++;
        printf("\n%i",s->top);
        s->dads[s->top]=e;
    }
    else
    {
        printf("\nPilha cheia");
    }
}

int *pop_stack(Tstack *s)
{
    int aux;

    if(! empity_stack(s))
    {
        aux=s->dads[s->top];
        s->top--;
        return aux;
    }

    else
    {
        printf("\nPilha vazia!");
        return -1;
    }
}

void free_stack(Tstack *s)
{
    elem *aux;

    while (! empity_stack(s))
    {
        aux=pop_stack(s);
        free(aux);
    }
    free(s->dads);
    free(s);    
}


/* void ler_dads( int num, int id )
{
    elem *e=(elem*)malloc(sizeof(elem));

    e->id=id;
    e->num=num;
    printf("%i ---  %i\n",num , id);
}*/
/*----------------------------------------------------------*/

int main()
{
    Tstack *s;
    elem *e ;
    
    s= build_stack(10);

    if(! empity_stack(s))
    {
        e = pop_stack(s);
        printf("\n%i",*(e));
        free(e);
    }

    e=(elem*)malloc(sizeof(elem));
    *e= 1;
    push_stack(s, e);

    e=(elem*)malloc(sizeof(elem));
    *e= 1;
    push_stack(s, e);

    e=(elem*)malloc(sizeof(elem));
    *e= 1;
    push_stack(s, e);

    e=(elem*)malloc(sizeof(elem));
    *e= 1;
    push_stack(s, e);

    e=(elem*)malloc(sizeof(elem));
    *e= 2;
    push_stack(s, e);

    e=(elem*)malloc(sizeof(elem));
    *e= 3;
    push_stack(s, e);

    e=(elem*)malloc(sizeof(elem));
    *e= 4;
    push_stack(s, e);

    e=(elem*)malloc(sizeof(elem));
    *e= 5;
    push_stack(s, e);

    e=(elem*)malloc(sizeof(elem));
    *e= 6;
    push_stack(s, e);

    e=(elem*)malloc(sizeof(elem));
    *e= 7;
    push_stack(s, e);

    e=(elem*)malloc(sizeof(elem));
    *e= 8;
    push_stack(s, e);

    e=(elem*)malloc(sizeof(elem));
    *e= 9;
    push_stack(s, e);

    e=(elem*)malloc(sizeof(elem));
    *e= 10;
    push_stack(s, e);


    printf("\n\n\n\n\n");

    if(!empity_stack(s))
	{
		e = pop_stack(s);
		printf("%i\n", *(e) );
		free(e);
	}

    
    if(!empity_stack(s))
	{
		e = pop_stack(s);
		printf("%i\n", *(e) );
		free(e);
	}

    
    if(!empity_stack(s))
	{
		e = pop_stack(s);
		printf("%i\n", *(e) );
		free(e);
	}

    
    if(!empity_stack(s))
	{
		e = pop_stack(s);
		printf("%i\n", *(e) );
		free(e);
	}

    
    if(!empity_stack(s))
	{
		e = pop_stack(s);
		printf("%i\n", *(e) );
		free(e);
	}

    
    if(!empity_stack(s))
	{
		e = pop_stack(s);
		printf("%i\n", *(e) );
		free(e);
	}

    
    if(!empity_stack(s))
	{
		e = pop_stack(s);
		printf("%i\n", *(e) );
		free(e);
	}

    
    if(!empity_stack(s))
	{
		e = pop_stack(s);
		printf("%i\n", *(e) );
		free(e);
	}

    
    if(!empity_stack(s))
	{
		e = pop_stack(s);
		printf("%i\n", *(e) );
		free(e);
	}

    
    if(!empity_stack(s))
	{
		e = pop_stack(s);
		printf("%i\n", *(e) );
		free(e);
	}

    
return 0;
}
