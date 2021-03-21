#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int comp(int *a, int *b )
{
	if( *a < *b)
		return 1;
	else
	if( *a > *b)
		return -1;
	else
		return 0;
}

void print_integer( int *a)//recebe conteudo  dentro de  a
{
	printf("%i\n", *a);
}

void free_integer( int *a)
{
	free(a);
}

int main()
{
	void *aux;
	TNo *tree = NULL;//arvore recebe nulo
	int *elem, rm_aux = 7;
		
	elem = (int*)malloc(sizeof(int));
	*elem = 7;
	tree = insert_nodo_tree(tree, elem, &comp);
	
	elem = (int*)malloc(sizeof(int));
	*elem = 2;
	tree = insert_nodo_tree(tree, elem, &comp);
	
	elem = (int*)malloc(sizeof(int));
	*elem = 10;
	tree = insert_nodo_tree(tree, elem, &comp);
	
	elem = (int*)malloc(sizeof(int));
	*elem = 0;
	tree = insert_nodo_tree(tree, elem, &comp);
	
	elem = (int*)malloc(sizeof(int));
	*elem = 5;
	tree = insert_nodo_tree(tree, elem, &comp);
	
	elem = (int*)malloc(sizeof(int));
	*elem = 8;
	tree = insert_nodo_tree(tree, elem, &comp);
	
	elem = (int*)malloc(sizeof(int));
	*elem = 13;
	tree = insert_nodo_tree(tree, elem, &comp);
	
	elem = (int*)malloc(sizeof(int));
	*elem = 1;
	tree = insert_nodo_tree(tree, elem, &comp);
	
	elem = (int*)malloc(sizeof(int));
	*elem = 4;
	tree = insert_nodo_tree(tree, elem, &comp);
	
	elem = (int*)malloc(sizeof(int));
	*elem = 6;
	tree = insert_nodo_tree(tree, elem, &comp);
	
	elem = (int*)malloc(sizeof(int));
	*elem = 17;
	tree = insert_nodo_tree(tree, elem, &comp);
	
	elem = (int*)malloc(sizeof(int));
	*elem = 18;
	tree = insert_nodo_tree(tree, elem, &comp);//endereço de comp
	
	printf("Altura da arvore: %i\n", find_height_tree( tree));
	printf("Menor altura da arvore: %i\n", 
		   minimum_height_tree( tree));
	printf("Soma dos elementos: %i\n", sum_nodes(tree));
	printf("Eh binaria completamente: %i\n", is_binary_tree( tree));
	printf("Quantidade de folhas: %i\n", count_leaf_nodes(tree));
	printf("Quantidade de nos: %i\n", count_nodes(tree));
		   
		   
	print_tree(tree,&print_integer);
	
	tree = remove_no_tree(tree, &rm_aux, comp);
	
	aux = search_tree(tree, &rm_aux, &comp );
	if( aux )
	{
		printf("elemento encontrado\n");
		print_integer( aux );
	}
	else
	{
		printf("elemento nao encontrado\n");
	}
	
	free_tree( tree, &free_integer);
	
	return 0;
}
