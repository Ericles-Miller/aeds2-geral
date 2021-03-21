#define N 10

typedef struct stack tstack;
struct  stack
{
    int top;
    int s[n];
};

tstack *build_stack()
{
    tstack *aux=(tstack*)malloc(sizeof(tstack));
    aux->top=-1;
    return aux;
}

int empty_stack(tstack *s)
{
    if(s->top >=0)
        return 0;

    else 
        return 1;
}

void push_stack(tstack *s,int elem)
{
    if(top != N-1)
    {
        s->top++;
        s->s[s->top]=elem;
    }

    else 
        printf("pilha cheia!");
}

int pop_stack(tstack *s)
{
    int aux;

    if(empty_stack(s))
    {
        aux=s->s[s->top];
        s->top--;
        return aux;
    }

    else
    {
        printf("pilha vazia!");
        return -1;
    }    
}

int main()
{


return 0;
}