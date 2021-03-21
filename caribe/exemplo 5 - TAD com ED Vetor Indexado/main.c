#include <stdio.h>
#include <stdlib.h>
#include "tabelaaluno.h"

int main()
{
	char *aux;
	TTabelaAluno *tabela;
	
	tabela = alocar_tabela(10);
	
	inserir_aluno(tabela, 2, "Caribe");
	inserir_aluno(tabela, 7, "Jose");
	inserir_aluno(tabela, 4, "Gabriel");
	inserir_aluno(tabela, 2, "Maria");
	
	imprimir_tabela(tabela);
	
	aux = localizar_aluno(tabela, 4);
	
	if( aux != NULL)
	{
		printf("Nome: %s\n",aux);
	}
	else
	{
		printf("aluno nao cadastrado\n");
	}
	
	
	desalocar_tabela(tabela);
	
	return 0;
}
