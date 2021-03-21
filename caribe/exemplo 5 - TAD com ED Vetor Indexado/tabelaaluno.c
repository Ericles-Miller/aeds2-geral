#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "tabelaaluno.h"


TTabelaAluno*alocar_tabela(int numMat)
{
	int i;
	TTabelaAluno* aux = (TTabelaAluno*)malloc(sizeof(TTabelaAluno));
	aux->maxMatricula = numMat;
	aux->tabelaAluno = (char **)malloc(sizeof(char*)*numMat);
	for(i=0;i<numMat;i++)
	{
		aux->tabelaAluno[i] = NULL;
	}
	return aux;
}

void inserir_aluno(TTabelaAluno *tabela, int mat, char *nome)
{
	if( mat > 0 && mat <= tabela->maxMatricula )
	{
		if( tabela->tabelaAluno[mat-1] == NULL)
		{
			tabela->tabelaAluno[mat-1] = (char*)malloc(sizeof(char) * TAM_MAX);
			strcpy(tabela->tabelaAluno[mat-1], nome);
		}
		else
		{
			printf("aluno ja cadastrado\n");
		}
	}
	else
	{
		printf("Matricula invalida\n");
	}
}

char * localizar_aluno(TTabelaAluno *tabela, int mat)
{
	if( mat > 0 && mat <= tabela->maxMatricula )
	{
		if( tabela->tabelaAluno[mat-1] != NULL)
		{
			return tabela->tabelaAluno[mat-1];
		}
		else
		{
			printf("aluno nao estah cadastrado\n");
			return NULL;
		}
	}
	else
	{
		printf("Matricula invalida\n");
		return NULL;
	}
}

void imprimir_tabela( TTabelaAluno *tabela )
{
	int i;
	
	for(i=0;i<tabela->maxMatricula;i++)
	{
		if( tabela->tabelaAluno[i] != NULL )
		{
			printf("Matricula: %i\nNome do aluno: %s\n", i+1, tabela->tabelaAluno[i] );
		}
	}
}

void desalocar_tabela( TTabelaAluno *tabela )
{
	int i;
	for(i=0;i<tabela->maxMatricula; i++ )
	{
		if(tabela->tabelaAluno[i] != NULL)
		{
			free(tabela->tabelaAluno[i]);
		}
	}
	free(tabela->tabelaAluno);
	free(tabela);
}
