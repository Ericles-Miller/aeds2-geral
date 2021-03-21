#include <stdio.h>
#include <stdlib.h>

int * pesquisa_sequencial(int *v, int t, int x)
{
	int i;
	for(i=0; i < t; i++)
	{
		if( v[i] == x)
		{
			return &v[i];//end de v[i]
		}
	}
	return NULL;//se for falso retun null
}

int * pesquisa_binaria(int *v, int t, int x)
{//conteudo de v ,10 pos, elem
	int i1 = 0, i2 = t - 1, m;
	
	while( i1<=i2 )
	{
		m = (i1+i2)/2;//4
		if(v[m] == x)//meio do vet
		{
			return &v[m];
		}
		else
		if( x < v[m] )//antes do meio do vet
		{
			i2 = m -1;//regressa uma posiç
		}
		else //depoisdo meio do vet
		{
			i1 = m + 1;//aumenta uma  posicao
		}
	}

		return NULL;//se nao existir x
}


int main()
{
	int v[10] = {1,2,4,6,8,12,15,35,47,101};
	int n = 10, *elem;
	
	elem = pesquisa_sequencial(v, n, 14);
	if(elem)
		printf("PS: elemento encontrado\n");
	else
		printf("PS: elemento nao encontrado\n");
	
	elem = pesquisa_binaria(v, n, 14);
	if(elem)
		printf("PB: elemento encontrado\n");
	else
		printf("PB: elemento nao encontrado\n");
	

	return 0;
}
