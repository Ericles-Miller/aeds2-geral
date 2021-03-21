#include<stdio.h>
#include<stdlib.h>
#define true 1
#define false 0
#define tam 6

bloco *aux2[tam];
int i=0;

typedef struct _bloco bloco;
struct _bloco
{
    int dado;
    bloco *prox;
};

typedef struct  _pilha pilha;
struct _pilha
{
    bloco *top;
    int tamanho;
};

void criar_stack(pilha *p)
{
    p->top=NULL;
    p->tamanho=0;
}

int empity_stack(pilha p)
{
    if(p.tamanho==0)
    {
        return true;
    }
    return false;
}

int push_stack(pilha *p, int dado)
{/*
1° declarar var aux e aloca-la
2° verficar se ela nula if!aux
3°apontar aux para dad q recebe dado
4°apontar aux p/ prox q recebe null
5°aux apontar p/ prox q = end de p->top
6°top aponta p/ aux
7°tam recebe =+1*/
    bloco *aux;
    aux=(bloco*)malloc(sizeof(bloco));

    if(!aux)
        return false;

    aux->dado=dado;
    aux->prox=NULL;

    aux->prox=p->top;
    p->top=aux;
    p->tamanho++;

return true;
}

int pop(pilha *p )
{
      /*1° criar var aux de bloco
      2° verificar se a stack está vazia se sim return false
      3° aux recebe top
      4° top recebe aux prox
      5° prox recebe null
      6° free em aux
      7° tam menos 1 pos
      8° return true*/

      bloco* aux;
      if(empity_stack(*p))
        return false;
    aux2[i]=p->top;
    aux=p->top;
    p->top=aux->prox;
    aux->prox=NULL;
    free(aux);
    p->tamanho--;

    aux[i+1];
    return true;
}

void imprimir_stack(pilha *p)
{
bloco *aux;

    //printf("%d",p->top);

    for(aux=p->top; aux->prox!=NULL; aux=aux->prox)
    {
        printf("\n%d",aux->dado);
    }
    printf("\n\n");

}

/*void inverter(pilha *p)
{
    int a= p->tamanho;
    int a;

    bloco *aux;
    for (aux=p->top; aux->prox!NULL; aux->prox)
    {
        aux=p->top;
        a=&aux;
       push_stack(*p,a);
        p->top=aux->prox;
        aux->prox=NULL;
        free(aux);
        p->tamanho--;
    }

}*/

int main()
{
int c;
pilha p;

criar_stack(&p);
c=empity_stack(p);

push_stack(&p,1);
push_stack(&p,2);
push_stack(&p,3);
push_stack(&p,4);
push_stack(&p,5);
push_stack(&p,6);

imprimir_stack(&p);

pop(&p);
imprimir_stack(&p);
pop(&p);
imprimir_stack(&p);
pop(&p);
imprimir_stack(&p);
pop(&p);
imprimir_stack(&p);
pop(&p);
imprimir_stack(&p);
pop(&p);
imprimir_stack(&p);

if(pop==false)
{
    push_stack(&p,aux2[i]);
    i++;
}

imprimir_stack(&p);

return 0;
}
