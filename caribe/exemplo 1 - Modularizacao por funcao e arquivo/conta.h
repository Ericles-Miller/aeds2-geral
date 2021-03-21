#include "cliente.h"

#ifndef CONTA_H
#define CONTA_H

typedef struct conta TConta;
struct conta
{
	int agencia;
	int cc;
	float saldo;
	TCliente *cli;
};

void ler_conta( TConta * c);
void imprimir_conta( TConta * c);


#endif