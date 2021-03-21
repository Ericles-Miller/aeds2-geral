#include<stdio.h>
#include<stdlib.h>

typedef struct produtos prod;
struct produtos
{
    char nome[15];
    int cod;
    float preco;
    int estoque;
    int desconto;
};

typedef struct pilha pi;
struct pilha
{
    int topo;
    float *elemento;
    int caps;
    prod *dados;
};


void criar_p(pi *p, int c)
{
    p->topo=-1;
    p->caps= c;
    p->elemento=(float*)malloc(sizeof(float)*c);

}

int p_vazia (pi *p)
{
    if(p->topo==-1)
    {
        return 1;
    }
    else
        return 0;
}
int p_cheia(pi *p)
{
    if (p->topo == p->caps -1)
    {
        return 1;
    }
    else
        return 0;
}

void empilhar(pi *p, int a)
{
    p->topo++;
    p->elemento[p->topo] = a;
}

void desempilhar( pi *p)
{
    float aux = p-> elemento[p->topo];
    p->topo--;

    return aux;
}

float retornartopo(pi *p)
{
    return p->elemento[p->topo];
}

void cadastrar_p(prod *p)
{
        printf("Digite o nome do produto:");
        scanf("%s",p->nome);
        printf("\nDigite o codio do produto:");
        scanf("%i",&p->cod);
        printf("\nDigite o preço do produto:");
        scanf("%f",&p->preco);
        printf("Digite a quantidade de estoque:");

        printf("\nDigite o desconto");
        scanf("%i",&p->desconto);

        p->desconto = p->preco * p->desconto/100;
}


int main()
{
int caps, ops;
pi pilha;
prod p=(prod*) malloc(sizeof(prod));

    printf("Digite a capacidade da pilha:");
    scanf("%i",&caps);

    do
    {
        printf("\nDigite sua opcao:");
        printf("\n1-Empilhar");
        printf("\n2-Desempilhar");
        printf("\n3-Mostar o topo");
        printf("\n0-para sair");
        scanf("%i",&ops);

        switch(ops)
        {
            case 1:

            if(p_cheia(&pilha)==1 )
                {
                    printf("\nPilha cheia:");
                }

                else
                {
                   cadastrar_p(p);
                   empilhar_p(&pilha,p);
                }
            break;

        }
    }while(ops>0 && ops<=4);



return 0;
}
