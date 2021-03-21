#include "tabelaaluno.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

TTabelaAluno*alocar_tabela(int numMat)
{
	TTabelaAluno *aux = (TTabelaAluno*)malloc(sizeof(TTabelaAluno));
	aux->tabela = (TAluno**)malloc(sizeof(TAluno*) * numMat);
	aux->maxMatricula = numMat;
	aux->nElem = 0;
	return aux;
}

void inserir_aluno(TTabelaAluno *tabelaAluno, int mat, char *nome)
{
	int c;
	TAluno *aluno, *aux;
	if( tabelaAluno->nElem < tabelaAluno->maxMatricula )
	{
		aluno = (TAluno*)malloc(sizeof(TAluno));
		strcpy(aluno->nome, nome);
		aluno->matricula = mat;
		
		c = tabelaAluno->nElem;
		if(tabelaAluno->nElem != 0 )
		{
			aux = tabelaAluno->tabela[c-1];
			while(  aux->matricula > aluno->matricula )
			{
				tabelaAluno->tabela[c] = tabelaAluno->tabela[c-1];
				c--;
				aux = tabelaAluno->tabela[c-1];
			}
		}
		tabelaAluno->tabela[c] = aluno;
		tabelaAluno->nElem++;
	}
	else
	{
		printf("Tabela de alunos cheia\n");
	}
}


TAluno* localizar_aluno(TTabelaAluno *tabelaAluno, int mat)
{
	TAluno*aux;
	int inf, meio, sup;
	inf = 0;
	sup = tabelaAluno->nElem-1;
	
	while(inf <= sup )
	{
		meio = (inf+sup)/2;
		aux = tabelaAluno->tabela[meio];
		if(aux->matricula == mat)
		{
			return aux;
		}
		else
		if( aux->matricula < mat)
		{
			inf = meio + 1;
		}
		else
		{
			sup = meio - 1;
		}
		
	}
	return NULL;
}

void imprimir_tabela( TTabelaAluno *tabelaAluno )
{
	int i;
	TAluno *aux;
	
	for(i=0;i<tabelaAluno->nElem;i++)
	{
		aux = tabelaAluno->tabela[i];
		printf("Nome: %s\n", aux->nome);
		printf("Matricula: %i\n\n",aux->matricula);
	}
}

void desalocar_tabela( TTabelaAluno *tabelaAluno )
{
	int i;
	for(i=0;i<tabelaAluno->nElem;i++)
	{
		free( tabelaAluno->tabela[i]);
	}
	free(tabelaAluno->tabela);
	free(tabelaAluno);
}

