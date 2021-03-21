#include <stdio.h>
#include "cliente.h"

void ler_cliente(tcliente *c)
{
    printf("\nDigite nome do cliente:");
    scanf("%s",c->nome);
    printf("\nDigite o cpf do cliente:");
    scanf("%s", c->cpf);
}

void imprimir_cliente(tcliente *c)
{
    printf("\nNome do cliente: %s",c->nome);
    printf("\nCpf do cliente: %s",c->cpf);
}