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
int comp_remove(int *a, int *b )
{
	if( *a == *b)
		return 1;
	else
		return 0;
}
void print_integer( int *a)
{
	printf("%i\n", *a);
}

int main()
{
	void *aux;
	TNo *tree = NULL;
	int *elem, num = 7;
	int c;
	
	
	elem = (int*)malloc(sizeof(int));
	*elem = 7;
	insert_tree( &tree, elem, &comp )
	
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
	tree = insert_nodo_tree(tree, elem, &comp);
	
	print_tree(tree,&print_integer);
	
	c = find_height_tree( tree);
	printf("%i\n",c);
	
	aux = search_tree(tree, &num, &comp );
	if( aux )
	{
		printf("elemento encontrado\n");
		print_integer( aux );
	}
	else
	{
		printf("elemento nao encontrado\n");
	}
	return 0;
}
