#include<stdio.h>
#include<stdlib.h>

typedef struct _bloco bloco;
struct _bloco
{
    int dads;
    bloco *prox;
};

int main()
{
    bloco a,b,c;

    a.dads=1;
    b.dads=2;
    c.dads=3;

    a.prox=&b.dads;
    b.prox=&c.dads;

    printf("%d",a.prox->prox->dads);
    return 0;
}