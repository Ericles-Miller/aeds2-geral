#include <stdio.h>
#include <stdlib.h>


typedef struct _bloco bloco;
struct _bloco
{
	int dado;
    bloco *proximo;
};

int main(){

bloco a;

a->dado=1;
a->proximo=(bloco *)malloc(sizeof(bloco));//cria end de memoria
a->proximo->dado=2;//prox e a var que aponta para outro ponteiro 
a->proximo->proximo=(bloco *)malloc(sizeof(bloco));//aponta para outro ponteiro
a->proximo->proximo->proximo->dado=3;//prox->prox->3 

printf("%d", a->proximo->proximo->dado);//mostra 3
}

/* Fun��o armazenadora 
1° passo criar var aux e de percorrer os elem
2° alocar a var aux e verificar se aux e NULL
3° verificar se o conteudo da var q aponta para aux e NULL
4° se for verdade conteudo de p recebe end de aux
5° end aux que aponta para dados recebe  conteudo de dado
6° end aux que aponta para prox recebe conteudo de prox que aponta para NULL

7° se  o 4° passo for falso perc recebe conteudo de p que e end de *p
8° se perc q aponta p/ prox for diferente de null perc recebe perc q aponta para prox
9° perc aponta para prox que aponta para aux
10°aux aponta para dado que recebe d
11° aux que aponta par aprox que recebe null
*/
void armazena(bloco **p, int d)//*p q aponta para p
{
bloco *aux, *perc;
    aux=(bloco*)malloc(sizeof(bloco));
    if(aux==NULL)
        return;
    if(*p==NULL)
    {
        *p=aux;//p->aux->dad
        aux->dado=d;//
        aux->proximo=NULL;//prox sempre deve ser null
    }
    else
    {
        perc=*p; //perc=a
        while(perc->proximo!=NULL)
            perc=perc->proximo;//busca ate o ultimo elem
        perc->proximo=aux;
        aux->dado=d;
        aux->proximo=NULL;
    }
}


/*Fun��o removedora 
	
	Passo a passo
		1- Procurar o bloco a ser removido. ( 3 casos ) 
		2- Remover os ponteiros e isolar o bloco. 
	*/	

void remover ( bloco **l, int d ){
	bloco *perc, *aux;
	
	if(*l==NULL) 
		return;
	if((*l)->dado==d ){ // ou (**l).dado==d
		aux=*l;//conteudo de l
		*l= aux->proximo; // 8l=(*l)-> proximo//end de l aponta para aux e aux para prox
		aux->proximo=NULL;//
		free(aux);
	}
	else {
		perc=*l;
		
		while(perc->proximo->dado!=d)
			perc=perc->proximo;
		
		aux=perc->proximo;
		perc->proximo=aux->proximo;
		aux->proximo=NULL;
		free(aux);
	}
}

void imprimir(bloco **b)
{
	bloco *aux ,*perc;

	if(aux!=NULL)
	{
		return;
	}
	if(*b!=NULL)
	{
		aux=*b;
		*b=aux->proximo;
		aux->proximo=null;
		printf("\n%d",aux->dado);
	}
	else
	{
		perc=*b;
		while (perc->proximo!=NULL)
		{
			perc=perc->proximo;	
		}
		printf("\n%d",aux->dado);
		
	}
	
}

int main()
{
	Bloco a;

a->dado=1;
a->proximo=(Bloco *)malloc(sizeof(Bloco));
a->proximo->dado=2;
a->proximo->proximo=(Bloco *)malloc(sizeof(Bloco));
a->proximo->proximo->proximo->dado=3;

printf("%d", a->proximo->proximo->dado);

printf("\n-------------");

imprimir(&(*a));
}