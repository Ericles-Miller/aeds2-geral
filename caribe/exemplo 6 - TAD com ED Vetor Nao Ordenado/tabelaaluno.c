#include "tabelaaluno.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

TTabelaAluno*alocar_tabela(int numMat)
{
	TTabelaAluno *aux = (TTabelaAluno*)malloc(sizeof(TTabelaAluno));
	aux->tabela = (TAluno**)malloc(sizeof(TAluno*) * numMat);
	aux->maxMatricula = numMat;
	aux->pos = 0;
	return aux;
}

void inserir_aluno(TTabelaAluno *tabelaAluno, int mat, char *nome)
{
	TAluno * aux;
	
	if(tabelaAluno->pos < tabelaAluno->maxMatricula)
	{
		aux = (TAluno*)malloc(sizeof(TAluno));
		aux->matricula = mat;
		strcpy(aux->nome, nome);
		tabelaAluno->tabela[tabelaAluno->pos++] = aux;
	}
	else
	{
		printf("tabela cheia\n");
	}
}


TAluno* localizar_aluno(TTabelaAluno *tabelaAluno, int mat)
{
	int i;
	TAluno *aux;
	
	for(i=0;i<tabelaAluno->pos;i++)
	{
		aux = tabelaAluno->tabela[i]; 
		if(aux->matricula == mat)
		{
		  return aux;
		}
	}
	return NULL;
}

void imprimir_tabela( TTabelaAluno *tabelaAluno )
{
	int i;
	TAluno *aux;
	
	for(i=0;i<tabelaAluno->pos;i++)
	{
		aux = tabelaAluno->tabela[i];
		printf("Nome: %s\n", aux->nome);
		printf("Matricula: %i\n\n",aux->matricula);
	}
}

void desalocar_tabela( TTabelaAluno *tabelaAluno )
{
	int i;
	for(i=0;i<tabelaAluno->pos;i++)
	{
		free( tabelaAluno->tabela[i]);
	}
	free(tabelaAluno->tabela);
	free(tabelaAluno);
}

