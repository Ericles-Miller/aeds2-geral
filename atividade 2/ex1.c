#include<stdio.h>
#include<stdlib.h>

/*Construa um código que cadastre a uma agenda de leitura, devendo apresentar ao usuário um menu
principal com as funções: Inclusao; Alteracao; Exclusao; Listar Agenda; e Sair do programa.
Cada anotação na agenda deve ter as informações: data no formato ( dia, mes e ano ); título do livro - 40
caracteres; e números de páginas. A agenda deverá ser salva em um arquivo.*/

int main()
{
    int ops;

    FILE p_arq;
    printf("----------------------MENU-------------------");

    printf("\Digite :");

    printf("1-Inclusao");
    printf("2-Alteracao");
    printf("3-Exclusao");
    printf("4-Listar Agenda");
    printf("5-Sair ");


    p_arq= fopen("arquivo.txt","w");

    if (p_arq ==NULL)
    {
        printf("O arquivo nao pode ser abertro:");
        return 1;
    }
    switch(ops)
    {
        case 1:

        break;

        case 2:

        break;

        case 3:

        break;

        case 4:

        break;

        case 5:

        break;
    }

    fclose(p_arq);
    return 0;
}
