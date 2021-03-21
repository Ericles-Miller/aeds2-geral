#include<stdio.h>
#include<stdlib.h>

typedef struct pilha_test test;
struct pilha_test
{
    int caps;
    int *dads;
    int topo;
};

void criarpilha(test *p, int n)
{
    p->topo = -1;
    p->caps=  n;
    p->dads= (float*)malloc(sizeof(float)*n);
}

int p_vazia(test *p)
{
    if(p->topo==-1)
    {
        return 1;
    }
    return 0;
}

int p_cheia(test *p)
{
    if(p->topo == p->caps -1)
    {
        return 1;
    }
    else
        return 0;
}
void empilhar( test *p, int dado)
{
    p->topo++;
    p->dads[p->topo]= dado;
}

int desempilhar( test *p, int dados)
{
    int aux= p->dads[p->topo];
    p->topo --;
    return aux;
}

void retorna_top( test *p)
{
    return p->dads[p->topo];
}



int main()
{

int ops,capacidade,valor;
struct pilha_test test;


    printf("Digite a capacidade da pilha:");
    scanf("%i",&capacidade);

    criarpilha(&test, capacidade);

    do {
    printf("\nDigite sua opcao:");
    printf("\n1-Empilhar");
    printf("\n2-Desempilhar");
    printf("\n3-Mostar o topo");
    printf("\n0-para sair");
    scanf("%i",&ops);

    switch(ops)
    {
    case 1:
        if(p_cheia(&test) ==1 )
        {
            printf("\nPilha cheia!!!");
        }

        else
            printf("\nDigite o valor");
            scanf("%i",&valor);
            empilhar(&test, valor);
    break;

    case 2:
        if(p_vazia(&test)==1)
        {
            printf("Pilha vazia!");
        }
        else
        valor = desempilhar(&test);
        printf("\n%i Desempilhado!",valor);
    break;
    }


    }while(ops>0 && ops<=3);

return 0;
}
