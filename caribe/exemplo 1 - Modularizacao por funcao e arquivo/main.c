#include <stdio.h>
#include <stdlib.h>
#include "banco.h"


int main(void)
{
	int i;
	TConta *aux;
	TBanco *BB;
	
	BB = (TBanco*)malloc(sizeof(TBanco));	//alocação de banco
	printf("Digite quantidade de contas: ");
	scanf("%i",&BB->qtd);//salva dentro da struct de banco
	BB->contas = (TConta*)malloc(sizeof(TConta)*BB->qtd);//aloca a qtd de contas e salva dentro da struct de banco

	/*
	for(i=0;i<BB->qtd;i++)
	{
		BB->contas[i].cli = (TCliente*)malloc(sizeof(TClinte));
	}
	*/
	
	aux = BB->contas;//var ponteiro recebe os ender. de memorias com as qtd de contas
	for(i=0;i<BB->qtd;i++)
	{
		(aux+i)->cli = (TCliente*)malloc(sizeof(TCliente));//alocação pra memoria
	}
	ler_banco (BB);// passa por parametro tudo que esta no endereço bb
	imprimir_banco(BB);
	
	/*aux = BB->contas;*/
	for(i=0;i<BB->qtd;i++)
	{
		free((aux+i)->cli);
	}
	free(aux);
	free(BB);
	
	/*
	for(i=0;i<BB->qtd;i++)
	{
		free(BB->contas[i].cli);
	}
	free(BB->contas);
	free(BB);
	*/
	
	
	
	
	return 0;
}