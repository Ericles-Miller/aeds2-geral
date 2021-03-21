#include <stdio.h>
#include "conta.h"
#include "cliente.h"

void ler_conta( TConta * c)
{
	printf("Digite agencia: ");
	scanf("%i", &c->agencia);
	printf("Digite conta: ");
	scanf("%i", &c->cc);
	printf("Digite saldo: ");
	scanf("%f", &c->saldo);
	ler_cliente ( c->cli );
}

void imprimir_conta( TConta * c)
{
	printf("Agencia: %i\n", c->agencia);
	printf("Conta: %i\n", c->cc);
	printf("Saldo: %f\n", c->saldo);
	imprimir_cliente ( c->cli );
}