 
#ifndef TABELAALUNO_H
#define TABELAALUNO_H

typedef struct aluno TAluno;
struct aluno
{
	char nome[30];
	int matricula;
};

typedef struct tabelaaluno TTabelaAluno;
struct tabelaaluno
{
	int maxMatricula;
	int pos;
	TAluno **tabela;
};

TTabelaAluno*alocar_tabela(int numMat);
void inserir_aluno(TTabelaAluno *tabela, int mat, char *nome);
TAluno* localizar_aluno(TTabelaAluno *tabela, int mat);
void imprimir_tabela( TTabelaAluno *tabela );
void desalocar_tabela( TTabelaAluno *tabela );

#endif
