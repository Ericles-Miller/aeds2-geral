#include <stdio.h>
#include <stdlib.h>
int main(void)
{
FILE *pont_arq; //cria variavel ponteiro para o arquivo
char palavra[100]; //variavel do tipo string
//abrindo o arquivo com tipo de abertura w
pont_arq = fopen("arquivo_palavra.txt", "w");
//testando se o arquivo foi realmente criado
if (pont_arq == NULL)
{
printf ("Erro na abertura do arquivo\n");
return 1;
}

printf ("Escreva uma palavra para testar gravacao de arquivo: ");
//scanf ("%[^\n]s", palavra);
gets(palavra); //Fazer a leitura da frase
//usando fprintf para armazenar a string no arquivo
fprintf (pont_arq, "%s", palavra);
//usando fclose para fechar o arquivo
fclose(pont_arq);
printf ("Dados gravados com sucesso!");
getch();
return 0;
}
