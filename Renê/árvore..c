/*Estrutura de dados avanada 

	�RVORE 

	TAD onde o conjunto de dados est� organizado de forma mais complexa, diferente das listas encadeadas.

	Organiza��o de forma hier�rquica. 
	Existem v�rias formas de representar �rvores, as mais comuns s�o:
		- Par�enteses aninhados (A(B)(C(D(G)(H)(E)(F(I))))
		- Diagrama de inclus�o (conjuntos matem�rica)
		- Alinhamento de n�s 
					A
					 B
					 C
	Defini�es: 
		- Uma �rvore � composta por n�s 
		- Sempre existe um n� R, denominado raiz, que cont�m zero ou mais sub�rvores, cujas raizes s�o ligadas diretamente a R;
		- Os n�s raizes da dsub�rbores s�o ditos filhos do n� pai, 
		- Os n�s sem filhos s�o chamados de folhas 
		- Existe um �nico caminho para a raiz 
		- Altura da �rbore: � o comprimento do caminho mais longo at� uma das folhas
		- N�vel de um n�: comprimento do caminho da raiz at� o n� 
		- Grau de um n�: n�mero de filhos do n�s
		- Grau da �rvore: o n�mero maiximo de golhos de um n�

	-> �RVORE BIN�RIA 
		
		cada n� tem zero um ou dois filhos, de maneira recursiva podemos definir uma �rvore bin�ria como sendo:
		- uma �rvore vazia;
		- um n� raiz tendo uas sub�rbores identificiadas como sub�rvore da direita (sad) e  a sub�rvore da esquerda (sae).

		Pela defini��o, uma sub�rvore de uma �rvore bin�ria � sempre especificada como sendo a sae ou a sad de uma �rvore maior, e qualquer das duas sub�rvores pode ser vazia 
*/
#include <stdio.h>
#include <stdlib.h>


struct arv{
	char dado;
	struct arv* esq;
	struct arv* dir;
};

typedef struct arv Arv;

Arv* inicializa (void){
	return NULL;
}

Arv* criaNo(char dado, Arv *sae, Arv *sad){
	Arv *temp = (Arv*)malloc(sizeof(Arv));
	temp->dado=dado;
	temp->esq=sae;
	temp->dir=sad;
	return temp;
}

void imprime(Arv *a){
    if(a!=NULL){
        printf("%c",a->dado);
        imprime(a->esq);
        imprime(a->dir);
    }
}

/*Arv* libera(Arv* a){
    if(a!=NULL){
            a->esq=libera(a->esq);
            a->dir=libera(a->dir);
            free(a)
    }
    return NULL;
}*/

int bisca (Arv* a, char c){
    if(a==NULL)
        return 0; //�rvore vazia ou n�o encontrada
    else
        return a->dado==c||bisca(a->esq,c)||bisca(a->dir,c);
}

int altchura(Arv *a){
    int d, e;
    if(a!=NULL){
        e=altchura(a->esq);
        d=altchura(a->dir);
        if(e==-1 && d==-1)
           return 1;

        if(e>d)
            return e++;

        return d++;

    }
    return -1;
}




int main(){
    Arv *A;
    char a='a', b='b', c='c', d='d', e='e', f='f';

    A=criaNo('a',
        criaNo('b',
            criaNo('c',
                criaNo('d',inicializa(),inicializa()),
                criaNo('e',inicializa(),inicializa())
            ),
            criaNo('f',inicializa(),inicializa())
        ),
        criaNo('g',
            criaNo('h',
                criaNo('i',
                    criaNo('j',inicializa(),inicializa()),
                    inicializa()
                ),
                inicializa()
            ),
            criaNo('k',
                criaNo('l',inicializa(),inicializa()),
                criaNo('m',inicializa(),inicializa())
            )
        )
    );



    printf("%i",altchura(A));
     return 0;
}


============================================================================================

ABB = �rvore de Busca Bin�ria 
	
	objetivo: facilitar a pesquisa por dados na mem�ria principal
	
	Regra geral: as chaves dos n�s SAE s�o sempre menores que a chave da raiz e as chaves dos n�s SAD s�o sempre maiores que a chave da raiz.
	para n dados, Leva ~ log(n)[2], se a �rvore estiver balanceada. (dados inceridos de forma aleat�ria) 

Inser��o:  

Verifica se a �rvore es� vazia
	-> se estiver vazia, cria-se um n� e insere na �rvore
	-> se n�o:
		-verifica se o dado � menor que a raiz 
			-> se for, de forma recursiva, verifica-se a SAE.
			-> sen�o, de forma recursiva, verifica-se a SAD.


typedef struct bloco{
	int dado;
	struct bloco *dir, *esq;
} No;

typedef struct{
	No *raiz
} Arvore;

int insereAAB(No **r, int dado){
 No *aux;

if(*r==NULL){
	aux=(No *)malloc(sizeof(No);
	if(!aux) return 0;
	aux->dado=dado;
	aux->dir=aux->esq=NULL;
	*r=aux;
	return 1;
}
else if (dado < (*r)->dado)
	return insereABB(&(*r)->esq, dado);
else if (dado >(*r)->dado);
	return insereABB(*r)->dir,dado);
retun 0;
}

// Remo��o

caso1: n� sem filhos
caso2: n� com um filho 
caso3: n� com dois filhos 
( Pgar o menor da SAD ou o maior da SAE 

No * procura maior(No *r){
	while(r->dir!=NULL)
		r=r->dir;
	return r;
} 

int removerABB(No **r, int dado){
No *aux

if(*r!=NULL){

	if(dado<(*r)->dado)
	 	return removerABB(&(*r)->esq, dado);
	
	else if(dado> (*r)->dado)
		retunrn removerABB(&(8r)->dir, dado);

	if((*r)->esq==NULL&&(*r)->dir==NULL){
		free(*r);
		*r=NULL;
		return 1;
	}
	
	else if((*r)->esq !=NULL && (*r)->dir ==NULL)
	{
		aux=*r;
		*r=aux->esq;
		aux->esq=NULL;
		free(aux); 
		return 1;
	}
	else if((*r)->dir !=NULL && (*r)->esq==NULL){
		
		aux=*r;
		*r=aux->dir;
		aux->dir=NULL; 
		free(aux);
		return 1; 
	} 

	else {
	
	aux=procuraMaior((*r)->esq);
	//copiar dados de aux para *r
	(*r)->dado=aux->dado;
	return removerABB(&(*r)->esq, aux->dado);
	}
}
return 0;
}
	
//=====================================

	Percurso (caminhamento) em �rvores bin�rias 
	
-em ordem SAE-R-SAD
-p�s ordem SAE-SAD-R
-pr� ordem R-SAE-SAD
	
in-fixa: a b c d e f g
pr�-fixa:a c b e g f d 
p�s-fixa:d b a c f e g 

in-fixa

void printEmOrdem(No *r){
if(r!=NULL){
	printEmOrdem(r->esq);
	printf("%d", r->dado);
	printEmOrdem(r->dir);
}
}

void printPreOrdem(No *r){
if(...)
	preordem(esq)
	preordem(dir)
	print
}
}

void printPosOrdem(No *r){
if(...)
	pprint
//=========================================

1)em largura: percorer pelos niveis FILA para controlar a visita��o dos n�s 

fila fifo

//necess�rio alterar a fila para que ela aciete o tipo No * e a fun��o
// enfieliera para que ela aciete n�o somete o tipo No * mas tamb�m que ela verifique se o dado � nulo ou n�o, caos NULL return 0




1- coloco a raiz na fila 
2- enquanto a fila n�o est� vazia 
	-retiro um n� 
	-coloco seus filhos na fila 
{

void printEmLargura(No *r){
Fila f;
int dado;
No *auxE;

inicializaFila(&f);
if(r!=NULL){
	enfileira(&f, r);
	while(!isEmpty(f)){
		printf("%d",f.inicio->dado->dado);
		aux=f.inicio->dado;
		desenfileira(*f);
		enfileira(&f, aux->esq);
		enfileira(&f, aux->dir);
	}
 }
}

fica como exerc�cio implementar a busca em profundidade

		


2)em profundiade: de folha em folha PILHA 



===========================================================================

�rvore AVL	�rvore binparia de busca balanceada 

Rregra de Balanceamento: a diferen�a de altura entre a SAE e a SAD � de no m�ximo 1.

Padr�es de Rota��es: 

rota��o simples � dir ou � esq (pegar no photos e anexar) -> inserido � esquerda da minha esquerda ou direita da minha direita. 

rota��o dupla esquerda direita ou direita esquerda (pegar no photos e anexar) -> inserido � esquerda da minha direita, ou � direita da minha esquerda. 

ALGORITMO

int Altura(No *r){
if(r==NULL)
	return -1;
return r->altura;
}

int Maior(int a, int b){
if (a>b)
	return a;
else return b;
}

typedef struct _No{
	int dado, altura;
	struct no *esq, *dir;
}

void rotacaoDir(No **r){
 No *aux;
 aux=(*r)->esq;
 (*r)->esq=aux->dir;
 aux->dir=*r;
 (*r)->altura=Maior(Altura((*r)->esq),Altura((*r)->dir)))+1;
 aux->altura=Maior(altura(aux->esq),(*r)->altura)+1;
 *r=aux;
}

int insereAVL(No **r, int dado){
No *aux;
 if(*r==NULL){
	aux=(No *)malloc(sizeof(No));
	if(aux==NULL) return 0;
	aux->dado=dado
	aux->altura=0;
	aux-esq=aux->dir=NULL;
	*r=aux;
	return 1;
 }
 
 else if(dado<(*r)->dado){
 	if (insereAVL(&(*r)->esq, dado))//balanceia 
		if(Altura((*r)->esq)-Altura((*r)->dir)==2){
			if(dado<(*r)->esq->dado)
				rotacaoDir(r);
			else rotacaoEsqDir(r);
			}
		}
	}
	else if (insereAVL(&(*r)->dir, dado))//balanceia 
		if(Altura((*r)->dir)-Altura((*r)->esq)==2){
			if(dado<(*r)->dir->dado)
				rotacaoEsq(r);
			else rotacaoDirEsq(r);
			}
		}
	}
 (*r)->altura=Maior(Altura((*r)->esq),Altura((*r)->dir)+1));
 return 1;
}


//REMO��O 

int removeAVL(No **r, int dado){

if(*r==NULL) return 0;
else if((*r)->dado>dao){
	if(removeAVL(&(*r)->esq, dado))
		if(Altura((*r)->dir)-Altura((*r)->esq)==2){
			if(Altura(*r)->dir->dir)>Altura(*r)->dir->esq))
				rota��oEsquerda(r);
			else
				rota��oDireitaEsquerda(r);
		}
	}
else if((*r)->dado<dado){
	if(removeAVL(&(*r)->dir, dado))
		if(Altura((*r)->esq)-Altura((*r)->dir)==2){
			if(Altura(*r)->esq->esq)>Altura(*r)->esq->dir))
				rota��oDireita(r);
			else
				rota��oEsqurdaDireita(r);
		}
	}
else{
//removeABB
//return 1;
}
(*r)->altura=Maior((*r)->dir->altura, (*r)->esq->tamanho)+1;
return 1;
}


===========================================================================

Heap

heap de m�ximo: toda raiz � maior que seus filhos 
heap de minimo: toda raiz � menor que seus filhos

array: [10][5][3][1][4][2][0]

pai: |_(i-1)/2_|
esq: 2i+1
dir: 2i+2
heapfica(A,p){
esq=2*p+1;
dir=2*p+2;
if(esq<tam(A)&&
ConstroiHeap(A){
meio=round((i+f)/2)
for (p=meio; i>meio; p--){
	hipifica(A,p)


IMPLEMENTEAR O HEAP COM �RVORE BALANCEADA


===========================================================================

HEAP BIN�RIO  


sendo h a sua altra, um heap binpario � sempre completo no n�vel h ou h-1. Se for completo no n�vel h-1, os n�s no n�vel h s�o agrupados mais � esquerda.  


typedef struct{
	int *v;
	int fim;
	int tam;
}heapbin;

int InicializaHeap( heapbin *hb, int tam) {
hb->v=(int *)malloc(siezeof(int)*tam);
hb->fim=tam-1;
hb->tam=tam;
if(!hb->v) return 0;
return 1;
}
int ConstroiMaxHeap(heapbin *hb){
int meio=(hb->fim+1)/2
for(; meio>=0;meio--){
	maxheapifica(hb,meio);


void MaxHeapFica( heapbin *hb, int meio){ 
int maior, esq, dir;
maior=meio;
esq=2*meio+1;
dir=2*meio+2;
	if(esq<hb->bin && hv->v[esq]>hb->v[meio])
		maior=esq;
	if(dir<hb->fim && hb->v[dir]>hb->v[maior])
		maior=dir;
	if(maior!=meio){
		troca(hb->v, maior);
		maxheapfica(hb, maior);
	}
}

int RemoveRaizHeap(heapbin *hb){
int aux=hb->v[0];
hb->v[0]=hb->v[hb->fim];
hb->fim--;
MaxHeapFica(hb, 0);
return aux;
}

void InsereMaxHeap(heapbin *hb, int novo){
int *aux;

if(hb->fim<hb->tam-1){
	hb->v[hb->fim+1]=novo;
	hb->fim++;
	}
HeapficaSubindo(heapbin *hb, int pos){
int pai=(pai-1)/2;
	if(hb->v[pos]>hb->v[pai])
		troca(hb->v, pos, pai);
HeapficaSubindo(hb, pai);
}

else {
	aux=(int *)malloc(sizeof(int)*hb->tam+1);
	copia(hb->v, aux);
	hb->tam++;
	hb->fim++;
	free(hb->v);
	hb->v=aux;
	}
HeapficaSubindo(hb->v, hb->fim);
}
===========================================================================
Heap Bin�rio (dinamico)



typedef struct bloco[
	int dado; 
	struct bloco *pai, *esq, *dir;
}No;

void ControiMaxHeapDinamic( No **raiz){




