#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 3

typedef struct aluno TAluno;
struct aluno
{
	char nome[30];
	int matricula;
};

typedef struct item TItem;
struct item
{
	char nome[30];
	int quantidade;
};

void imprimir_aluno( TAluno *a )
{
	printf("Nome: %s\n", a->nome);
	printf("Matricuila: %i\n", a->matricula);
}

void imprimir_item( TItem *i )
{
	printf("Nome: %s\n", i->nome);
	printf("Qtd: %i\n", i->quantidade);
}

void imprimir_coisas(void ** lista,void (*pf)() )
{
	int i;
	for(i=0; i<N; i++)
	{
		pf(lista[i]);
	}
}

int main()
{
	TItem *aux;
	TAluno *aux2;
	void ** lista;
	void (*pf)();
		
	lista = (void**)malloc(sizeof(void*) * N);
	
	aux = (TItem*)malloc(sizeof(TItem));
	strcpy(aux->nome, "caneta");
	aux->quantidade = 3;
	lista[0] = (void*)aux;
	
	aux = (TItem*)malloc(sizeof(TItem));
	strcpy(aux->nome, "lapis");
	aux->quantidade = 2;
	lista[1] = (void*)aux;
	
	aux = (TItem*)malloc(sizeof(TItem));
	strcpy(aux->nome, "mouse");
	aux->quantidade = 5;
	lista[2] = (void*)aux;
	
	pf = &imprimir_item;
	imprimir_coisas( lista, pf);
	free(lista[0]);
	free(lista[1]);
	free(lista[2]);
	
	aux2 = (TAluno*)malloc(sizeof(TAluno));
	strcpy(aux2->nome, "jose");
	aux2->matricula = 3;
	lista[0] = (void*)aux2;
	
	aux2 = (TAluno*)malloc(sizeof(TAluno));
	strcpy(aux2->nome, "ana");
	aux2->matricula = 2;
	lista[1] = (void*)aux2;
	
	aux2 = (TAluno*)malloc(sizeof(TAluno));
	strcpy(aux2->nome, "maria");
	aux2->matricula = 5;
	lista[2] = (void*)aux2;
	
	pf = &imprimir_aluno;
	
	imprimir_coisas( lista, pf);
	free(lista[0]);
	free(lista[1]);
	free(lista[2]);
	
	free(lista);
	
	return 0;
}


