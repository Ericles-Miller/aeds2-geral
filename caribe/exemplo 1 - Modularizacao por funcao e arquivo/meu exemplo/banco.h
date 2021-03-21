#include "conta.h"

#ifndef BANCO_H
#define BANCO_H

typedef struct  banco tbanco;
struct banco
{
    char nome[30];
    int qtd;
    tconta *contas;
};

void ler_banco(tbanco *b);
void imprimir_banco(tbanco *b);
tbanco *alocar_banco(int qtd);
void desalocar_banco(tbanco *b);


#endif
