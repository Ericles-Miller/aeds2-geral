#include "banco.h"
#include <stdio.h>


void ler_banco(TBanco *b)
{
	int i;
	printf("Digite nome do banco: ");
	scanf("%s", b->nome);
	for(i=0;i<b->qtd;i++)
	{
		/*ler_conta( &b->contas[i]);*/
		ler_conta( b->contas + i);
	}	
}

void imprimir_banco(TBanco *b)
{
	int i;
	printf("Nome do banco: %s\n", b->nome);
	for(i=0;i<b->qtd;i++)
	{
		/*ler_conta( &b->contas[i]);*/
		imprimir_conta( b->contas + i);
	}	
}

TBanco* alocar_banco( int qtd)
{
	int i;
	TBanco *aux = (TBanco*)malloc(sizeof(TBanco));
	aux->contas = (TConta*)malloc(sizeof(TConta) * qtd);
	aux->qtd = qtd;
	for(i=0;i<qtd;i++)
	{
		aux->contas[i].cli = (TCliente*)malloc(sizeof(TCliente));
	}	
	return aux;
}

void desalocar_banco(TBanco *b)
{
	int i;
	for(i=0;i<qtd;i++)
	{
		free(b->contas[i].cli);
	}
	free(b->contas);
	free(b);
}




