#include "conta.h"

#ifndef BANCO_H
#define BANCO_H

typedef struct banco TBanco;
struct banco
{
	char nome[30];
	int qtd;
	TConta * contas;
};

void ler_banco(TBanco *b);
void imprimir_banco(TBanco *b);
TBanco* alocar_banco( int qtd); 
void desalocar_banco(TBanco *b);

#endif