#include <stdio.h>
#include<stdlib.h>

typedef struct list_enc lte;
struct list_enc
{
    int n;
    lte *proximo;
};

void salvar_dad(lte *l)
{
    printf("\nDigite um numero:");
    scanf("%i",&l->n);
}

void listar_dad()
{
    lte *l=(lte*)malloc(sizeof(lte));

    printf("N:%i",l->n);
}


int main()
{
    lte *p_inicio;
    lte *proximo;
    int ops;

    p_inicio=(lte*)malloc(sizeof(lte));

    if(p_inicio == NULL)
    {
        return exit(1);
    }
    proximo= p_inicio;//recebe o valor de inicio e aponta para o endereço  de p_inicio

    do {

        printf("\nDigite '1' para inclusao '2' para buscar '3' para exclusao '4' para listar '0' para sair:");
        scanf("%i",&ops);

            switch(ops)
            {
                case 1:
                    salvar_dad(p_inicio);
                    lte->proximo = (lte*)malloc(sizeof(lte));
                    lte= lte->proximo;
                break;

                case 4:
                    lte->proximo= NULL;
                    lte->n;
                    while(lte != NULL)
                    {
                        listar_dad();
                        lte=lte->proximo;
                    }

                break;
            }




    }while(ops>0 && ops <=4);

    return 0;
}
