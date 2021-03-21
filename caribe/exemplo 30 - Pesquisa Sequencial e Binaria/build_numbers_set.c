#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define PARAM 4

/* ./executavel intervalo-quantidade-arquivo de saida */
/*  ./build 500 100000 input100000.txt */
int main(int argc, char * argv[])
{
	FILE *pf;
    int i, num, count, interval;
	char file_name[255];
	
	/* exemplo para medir o tempo de execucao*/
	double tempo;
	clock_t tmp_inicio, tmp_fim, duracao;

	if( argc == PARAM)
	{
		interval = atoi(  argv[1] );
		count = atoi(  argv[2]);
		strcpy(file_name, argv[3]);
		
		if( (pf = fopen(file_name, "wb") )== NULL )
		{
			printf("ERROR- FILE OPEN: %s\n", file_name);
		}
		else
		{
			srand(time(NULL)); /*usado para geracao de numeros aleatorio e calculo de tempo de execucao*/
			tmp_inicio = clock();
			
			for (i=0; i<count; i++)
			{
				num = rand() % interval;
				fwrite( &num, sizeof (int), 1, pf);
			}
			tmp_fim = clock();
			tempo = ( (double) (tmp_fim - tmp_inicio) )  / CLOCKS_PER_SEC;
			printf("Duracao : %lf s\n", tempo);
			fclose(pf);
		}
	}
	else
	{
		printf("ERROR- NUMBER OF PARAMETERS\n");
	}
     
      return 0;
}