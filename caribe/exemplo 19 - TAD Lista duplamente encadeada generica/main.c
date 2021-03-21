#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "list.h"

typedef struct aluno TAluno;
struct aluno
{
	char nome[30];
	int matricula;
};

int comp(TAluno * a1, TAluno *a2)
{
	if( a1->matricula == a2->matricula)
		return 1;
	return 0;
}

int comp_sort(TAluno * a1, TAluno *a2)
{
	if( a1->matricula < a2->matricula)
		return 0;
	return 1;
}

void print_aluno(TAluno * a)
{
	printf("Nome: %s\n", a->nome);
	printf("Matricula: %i\n\n", a->matricula);
}

void free_aluno(TAluno * a)
{
	free(a);
}


int main()
{
	TAluno *a, *aux;
	TList *l;
	
	l = build_list();
	
	a = (TAluno *)malloc(sizeof(TAluno));
	strcpy(a->nome, "joao");
	a->matricula = 10;
	insert_end(l, a);
	
	a = (TAluno *)malloc(sizeof(TAluno));
	strcpy(a->nome, "jose");
	a->matricula = 11;
	insert_end(l, a);
	
	a = (TAluno *)malloc(sizeof(TAluno));
	strcpy(a->nome, "carlos");
	a->matricula = 7;
	insert_end(l, a);
	
	a = (TAluno *)malloc(sizeof(TAluno));
	strcpy(a->nome, "maria");
	a->matricula = 23;
	insert_end(l, a);
	
	a = (TAluno *)malloc(sizeof(TAluno));
	strcpy(a->nome, "pedro");
	a->matricula = 3;
	insert_end(l, a);
	
	aux = (TAluno*)malloc(sizeof(TAluno));
	aux->matricula = 10;
	
	a = (TAluno *)malloc(sizeof(TAluno));
	strcpy(a->nome, "ana");
	a->matricula = 21;
	insert_end(l, a);
	
    /* aux usado como chave de pesquisa */
    aux = (TAluno *)malloc(sizeof(TAluno));
	aux->matricula = 23;
    a = search_list(l, aux, &comp);
	if( a != NULL)
	{
		printf("\n--------------\n");
		print_aluno(a);
		printf("\n--------------\n");
	}
	remove_list(l, aux, &comp );
    
    free(aux);

	print_list(l, &print_aluno);
	
	free_list(l, &free_aluno);
	
	return 0;
}
