#include <stdio.h>
#include <stdlib.h>
#include "tabelaaluno.h"


int main()
{
	TAluno *aux;
	TTabelaAluno *tabela;
	
	tabela = alocar_tabela(10);
	
	inserir_aluno(tabela, 2, "Caribe");
	inserir_aluno(tabela, 7, "Jose");
	inserir_aluno(tabela, 4, "Gabriel");
	inserir_aluno(tabela, 3, "Maria");
	inserir_aluno(tabela, 12, "Caribe2");
	inserir_aluno(tabela, 17, "Jose2");
	inserir_aluno(tabela, 14, "Gabriel2");
	inserir_aluno(tabela, 13, "Maria2");
	inserir_aluno(tabela, 22, "Caribe3");
	inserir_aluno(tabela, 27, "Jose3");
	inserir_aluno(tabela, 24, "Gabriel3");
	inserir_aluno(tabela, 33, "Maria3");
	
	imprimir_tabela(tabela);
	
	aux = localizar_aluno(tabela, 4);
	
	if( aux != NULL)
	{
		printf("Nome: %s\n",aux->nome);
	}
	else
	{
		printf("aluno nao cadastrado\n");
	}
	
	
	desalocar_tabela(tabela);
	
	return 0;
}