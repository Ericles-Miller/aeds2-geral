#include<stdio.h>
#include "conta.h"
#include "cliente.h"

void ler_conta(tconta *c)
{
    printf("\nDIGITE AGENCIA:");
    scanf("%i",&c->agencia);
    printf("\nDIGITE CONTA:");
    scanf("%i",&c->cc);
    printf("\nDIGITE SALDO:");
    scanf("%f",&c->saldo);
    ler_cliente(c->cli);
}

void imprimir_conta(tconta *c)
{
    printf("\nAgencia: %i",c->agencia);
    printf("\nConta: %i",c->cc);
    printf("\nSaldo: %.2f", c->saldo);
    imprimir_cliente(c->cli);
}
