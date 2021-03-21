
#ifndef TABELAALUNO_H
#define TABELAALUNO_H

#define TAM_MAX 30

typedef struct tabelaAluno TTabelaAluno;
struct tabelaAluno
{
	char **tabelaAluno;
	int maxMatricula;
};

TTabelaAluno*alocar_tabela(int numMat);
void inserir_aluno(TTabelaAluno *tabela, int mat, char *nome);
char * localizar_aluno(TTabelaAluno *tabela, int mat);
void imprimir_tabela( TTabelaAluno *tabela );
void desalocar_tabela( TTabelaAluno *tabela );

#endif