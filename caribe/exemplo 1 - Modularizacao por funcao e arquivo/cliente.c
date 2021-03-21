#include <stdio.h>
#include "cliente.h"

void ler_cliente( TCliente * c)
{
	printf("Digite nome do cliente: ");
	scanf("%s", c->nome);
	printf("Digite CPF do cliente: ");
	scanf("%s", c->cpf);
}

void imprimir_cliente( TCliente  *c)
{
	printf("Nome do cliente: %s\n", c->nome);
	printf("CPF do cliente: %s\n", c->cpf);
}