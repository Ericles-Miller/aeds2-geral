/*Structs recursivas */

#include <stdio.h>
#include <stdlib.h>

typedef struct _bloco bloco;
struct _bloco
{
    int dado;
    bloco *proximo;
};

int main(){

bloco a,b,c;

a.dado=1;
b.dado=2;
c.dado=3;
a.proximo=&b;//recebe end de memoria de b
b.proximo=&c;//recebe end de memoria de c
printf("%d",&b);
printf("\n%d", a.proximo->proximo->dado);//conteudo  de c

return 0;
}
