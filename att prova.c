#include <stdio.h>
#include <stdlib.h>

typedef struct st_aluno {
	unsigned int numero;
	char * nome;
	char * curso;
	float nota;
} aluno;

int main()
{
    int i;

    for (i=0; i<10; i++)
    {


	FILE *arq = fopen("Alunos.dat", "w");

	if(arq == NULL)
	{
		printf("Mensagem de Erro tal tal\n");
		exit(0);
	}

	printf("Arquivo criado com sucesso!!!\n");
	aluno novo;
	printf("\nNumero:");
	scanf("%i",&novo.numero);
    printf("nNome:");
    scanf("%s",novo.nome);
    printf("\n curso:");
    scanf("%s",novo.curso);
    printf("\nNota");
    scanf("%f",&novo.nota)
	/*novo.numero = 1234;
	novo.nome = "João Roberto";
	novo.curso = "Administração";
	novo.nota = 3.45F;*/

	puts("Gravando informações do aluno...");

	fprintf(arq, "%d,%s,%s,%.2f\n", novo.numero, novo.nome, novo.curso, novo.nota);
	fclose(arq);
    }
	return 0;
