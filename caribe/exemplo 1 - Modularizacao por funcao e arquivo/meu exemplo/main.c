#include <stdio.h>
#include <stdlib.h>
#include "banco.h"

int  main() {

  int i;
  tconta *aux;
  tbanco *bb;

  bb=(tbanco*)malloc(sizeof(tbanco));

  printf("\nDigite A QUANTIDADE DE CONTAS:");
  scanf("%i",&bb->qtd);

  bb->qtd=(tconta*)malloc(sizeof(tconta)*bb->qtd);

  aux = bb->qtd;

  for(i=0; i<bb->qtd; i++)
  {
      (aux+i)->cli =(tcliente*)malloc(sizeof(tcliente));
  }

    ler_banco(bb);
    imprimir_banco(bb);


//----------------------desalocar------------------------------
  for ( i = 0; i<bb->qtd; i++)
  {
      free((aux+i)->cli);
  }
  free(aux);
  free(bb);

    return 0;
}
