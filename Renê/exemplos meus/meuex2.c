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
    bloco *a;


    armazenar(&(*a),1);
    a->prox=(bloco*)malloc(sizeof(bloco));
    armazenar(&a,2);

    a->prox->prox=(bloco*)malloc(sizeof(bloco));
    armazenar(&a,3);

    printf("%d",a->prox->prox->dads);

}

void armazenar(bloco **p,int d)
{
    bloco *aux, *perc;

    aux=(bloco*)malloc(sizeof(bloco));
    if(aux == NULL)
        return;
    if(p==NULL)
    {
        *p=aux;
        aux->dads=d;
        aux->prox=NULL;
    }
    else
    {
        perc=*p;
        while (perc->prox !=NULL)
        {
            perc=perc->prox;
            perc->prox->aux;
            aux->dads=d;
            aux->prox=NULL;
        }

    }

}
