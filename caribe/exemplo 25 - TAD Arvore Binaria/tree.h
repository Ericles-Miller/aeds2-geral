#ifndef TREE_H
#define TREE_H

typedef struct no TNo;
struct no
{
	void * elem;//dado recebido
	TNo * left;//esquerda
	TNo * right;//direita
};

int empty_tree(TNo * t);

void insert_tree(TNo **t, void * elem, int (*comp)() );

TNo* insert_nodo_tree(TNo *t, void * elem, int (*comp)() );

void * search_tree( TNo *t, void *elem, int (*comp)() );

void print_tree(TNo *t, void (*print)() );

int find_height_tree( TNo *t);

TNo* remove_no_tree(TNo *t, void * elem, int (*comp)());

void free_tree( TNo *t, void (*free_elem)() );

/*void free_tree( TNo **t, void (*free_elem)() );*/

int count_leaf_nodes(TNo* t);

int count_nodes(TNo *t);

int sum_nodes(TNo *t);

int minimum_height_tree(TNo *t);

int is_binary_tree( TNo *t);

int equal_trees( TNo *t1, TNo *t2, int(*comp)() );
	
#endif
