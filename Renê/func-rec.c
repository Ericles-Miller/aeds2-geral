#include<stdio.h>
#include<stdlib.h>

typedef struct _bloco bloco;
struct  _bloco
{
    int dados;
    bloco *prox;
};

void armazenar(bloco **p,int d)
{
    bloco *aux,*perc;
    aux=(bloco*)malloc(sizeof(bloco));
    if(aux==NULL)
        return;
    if(*p==NULL)
    {
        *p=aux;
        aux->dados=d;
        aux->prox=NULL;
    }
    else
    {
        perc=*p;
        while (perc->prox!=NULL)
            perc=perc->prox;
        perc->prox=aux;
        aux->dados=d;
        aux->prox=NULL;
    }
}

int main()
{
    bloco *a;
  /*  a->dados=1;
    a->prox=(bloco*)malloc(sizeof(bloco));
    a->prox->dados=2;
    a->prox->prox=(bloco*)malloc(sizeof(bloco));
    a->prox->prox->prox->dados=3;
    printf("\n%d",a->prox->prox->dados);*/

    armazenar(&(*a),1);
    armazenar(&(*a),2);
    armazenar(&(*a),3);

}


