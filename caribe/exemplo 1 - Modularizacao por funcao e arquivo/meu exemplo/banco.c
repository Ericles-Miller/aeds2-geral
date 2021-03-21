#include "banco.h"
#include <stdio.h>

void ler_banco(tbanco *b)
{
    printf("DIGITE O NOME DO BANCO:");
    scanf("%s",b->nome);

    for (int  i = 0; i<b->qtd;  i++)
    {
        ler_conta(&b->contas +i);
    }

}

void imprimir_banco(tbanco *b)
{
    int i;

    printf("\nNome do banco: %s",b->nome);
    for(i=0; i<b->qtd; i++)
    {
        imprimir_conta(&b->contas +i);
    }
}

tbanco *alocar_banco(int qtd)
{
    int i;

    tbanco *aux =(tbanco*)malloc(sizeof(tbanco));
    aux->contas =(tconta*)malloc(sizeof(tconta)*qtd);
    aux->qtd=qtd;

    for ( i = 0; i<qtd; i++)
    {
        aux->contas[i].cli=(tcliente*)malloc (sizeof(tcliente));
    }
    return aux;
}

void desalocar_banco(tbanco *b)
{
    int i,qtd;
    b->qtd=qtd;

    for(i=0; i<qtd; i++)
    {
        free(b->contas[i].cli);
    }
    free(b->contas);
    free(b);
}

