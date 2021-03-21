#include "cliente.h"

#ifndef CONTA_H
#define CONTA_H

typedef struct conta tconta;
struct conta
{
    int agencia;
    int cc;
    float saldo;
    tcliente *cli;
};





#endif // !CONTA_H


