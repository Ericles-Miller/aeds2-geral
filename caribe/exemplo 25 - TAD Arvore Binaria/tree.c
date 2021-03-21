#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int empty_tree(TNo * t)
{
	if( t ) 
		return 0;
	return 1;
}

void insert_tree(TNo **t, void * elem, int (*comp)() )//inserir arvore
{
	if( empty_tree( *t ))//se arvore estiver vazia
	{
		(*t) = (TNo*)malloc(sizeof(TNo));
		(*t)->elem = elem;//t aponta para raiz
		(*t)->left = NULL;//recebe null pois e a 1° vez
		(*t)->right = NULL;//idem
	}
	else
	{	/*  1 se elem maior q root
		   -1 se elem menor q root
		*/
		int cmp = comp( (*t)->elem, elem);
		if( cmp == 1) /* vou para direita*/
		{
			insert_tree(&(*t)->right, elem, comp );//t aponta para direita
		}
		else
		if( cmp == -1) /* vou para esquerda*/
		{
			insert_tree(&(*t)->left, elem, comp );//t aponta para esquerda
		}
	}
}

TNo* insert_nodo_tree(TNo *t, void * elem, int (*comp)() )
{
	if( empty_tree(t))//arvore estiver vazia
	{
		TNo * no = (TNo*)malloc(sizeof(TNo));
		no->elem = elem;
		no->left = NULL;
		no->right = NULL;
		return no; /* 6 3 5*/
	}
	else
	{
		/*  1 se elem maior q root
		   -1 se elem menor q root
		*/
		int cmp = comp( t->elem, elem);
		if( cmp == 1) /* vou para direita*/
		{
			t->right = insert_nodo_tree(t->right, elem, comp);//direita recebe dads
		}
		else
		if( cmp == -1)
		{
			t->left = insert_nodo_tree(t->left, elem, comp);
		}
		return t;
	}
}

void * search_tree( TNo *t, void *elem, int (*comp)() )
{	
	if( !empty_tree(t) )
	{
		if( !comp(t->elem, elem) )//possui um elem 
		{
			return t->elem;
		}
		else
		{
			if( comp(t->elem, elem) == -1) /* esquerda*/
			{
				return search_tree(t->left,elem,comp);//*t aponta para esquerda
			}	
			else  /* direita*/
			{
				return search_tree(t->right,elem,comp);
			}
		}
	}
	return NULL;
}

TNo * search_no_tree( TNo *t, void *elem, int (*comp)() )//**t
{	
	if( !empty_tree(t) )
	{
		if( !comp(t->elem, elem) )
		{
			return t;
		}
		else
		{
			if( comp(t->elem, elem) == -1) /* esquerda*/
			{
				return search_tree(t->left,elem,comp);
			}	
			else  /* direita*/
			{
				return search_tree(t->right,elem,comp);
			}
		}
	}
	return NULL;
}

TNo * search_no_max_set_null( TNo *t )
{
	if( !empty_tree(t) )
	{
		if(t->left == NULL && t->right == NULL)
		{ 
			return t;
		}
		else
		{
			TNo * no =  search_no_max_set_null( t->right );
			if( (t->right)->left == NULL && 
			   (t->right)->right == NULL &&
			  	t->right == no)
			{
				t->right = NULL;
			} 
			return no;
		}
	}
	return NULL;
}


TNo * remove_no_tree( TNo *t, void *elem, int (*comp)() )
{	
	if( !empty_tree(t) )
	{
		if( !comp(t->elem, elem) ) /* comp retorna 0 se iguais */
		{
			if(t->left == NULL && t->right == NULL)
			{ 
				return NULL;
			}
			else if(t->left != NULL && t->right == NULL) 
			{	
				return t->left;
			}
			else if(t->right != NULL && t->left == NULL) 
			{	
				return t->right;
			}
			else
			{
				TNo *no = search_no_max_set_null( t );
				no->left = t->left;
				no->right= t->right;
				return no;
			}
		}
		else
		{
			if( comp(t->elem, elem) == -1) /* esquerda*/
			{
				t->left = remove_no_tree(t->left,elem,comp);
				return t;
			}	
			else  /* direita*/
			{
				t->right = remove_no_tree(t->right,elem,comp);
				return t;
			}
		}
	}
	return NULL;
}


void print_tree(TNo *t, void (*print)() )
{
	if( !empty_tree(t) )
	{
		print_tree(t->left, print );
		print(t->elem);
		print_tree(t->right, print);
		
	}
}

int find_height_tree( TNo *t)
{
	if( !empty_tree(t) )
	{
		if( t->left == NULL && t->right == NULL)
		{
			return 0;
		}
		else
		{
			int hl = 1 + find_height_tree(t->left);
			int hr = 1 + find_height_tree(t->right);
			if( hl > hr)
			{
				return hl;
			}
			else
			{
				return hr;
			}
		}
	}
	else
	{
		return 0;
	}
}

void free_tree( TNo *t, void (*free_elem)())
{
	if( !empty_tree(t))
	{
		if(t->left == NULL && t->right == NULL)
		{
			free_elem( t->elem );
			free(t);
		}
		else
		{
			free_tree(t->left, free_elem);
			free_tree(t->right, free_elem);
			free_elem( t->elem );
			free(t);		
		}
	}
}

/*
void free_tree( TNo **t, void (*free_elem)())
{
	if( !empty_tree(*t))
	{
		if((*t)->left == NULL && (*t)->right == NULL)
		{
			free_elem( (*t)->elem );
			free(*t);
		}
		else
		{
			free_tree(&(*t)->left, free_elem);
			
			free_tree(&(*t)->right, free_elem);
			
			free_elem( (*t)->elem );
			
			free(*t);		
		}
		*t = NULL;
	}
}
*/


int count_leaf_nodes(TNo* t)
{
	if( !empty_tree(t) )
	{
		if( t->left == NULL && t->right == NULL)
		{
			return 1;
		}
		else
		{
			return count_leaf_nodes(t->left) + 
					count_leaf_nodes(t->right);
		}
	}
	return 0;
}

int count_nodes(TNo *t)
{
	if( !empty_tree(t) )
	{
		if( t->left == NULL &&  
			t->right == NULL )
		{
			return 1;
		}
		else
		{
			return 1 +	count_nodes(t->left) + 
						count_nodes(t->right);
		}
	}
	return 0;
}

int sum_nodes(TNo *t)
{
	int *value;
	if( !empty_tree(t) )
	{
		if( t->left == NULL && 
			t->right == NULL)
		{
			value = t->elem;
			return *value;
		}
		else
		{
			value = t->elem;
			return *value + sum_nodes(t->left) +
							sum_nodes(t->right);
		}
	}
	return 0;
}

int minimum_height_tree(TNo *t)
{
	if( !empty_tree(t) )
	{
		if(t->left == NULL && t->right == NULL)
		{
			return 0;
		}
		else
		{
			int hl, hr;
			hl = 1+ minimum_height_tree(t->left);
			hr = 1 + minimum_height_tree(t->right);
			if(hl<hr)
			{
				return hl;
			}
			else
			{
				return hr;
			}
		}
	}
	return 0;
}

int is_binary_tree( TNo *t)
{
	if( !empty_tree(t) )
	{
		if(t->left == NULL && t->right != NULL)
		{
			return 0;
		}
		else
		if(t->left != NULL && t->right == NULL)
		{
			return 0;
		}
		else
		if( t->left == NULL && t->right == NULL)
		{
			return 1;
		}
		else
		{
			return is_binary_tree( t->left) * is_binary_tree( t->right);
		}
	}
	return 0;
}

int equal_trees( TNo *t1, TNo *t2, int(*comp)() )
{
	if( !empty_tree(t1) && !empty_tree(t2) )
	{
		if(t1->left != NULL && t2->left == NULL) return 0;
		else
		if(t1->left == NULL && t2->left != NULL) return 0;
		else
		if(t1->right != NULL && t2->right == NULL) return 0;
		else
		if(t1->right == NULL && t2->right != NULL) return 0;
		else
		if( comp(t1->elem,t2->elem) != 0) return 0;
		else
		{
			if( t1->left == NULL && t2->left == NULL &&
				t1->right == NULL && t2->right == NULL )
				{
					if( comp(t1->elem,t2->elem) == 0 )
						return 1;
					else
						return 0;
				}
			else
			{
				return	equal_trees( t1->left, t2->left, comp ) * 
						equal_trees( t1->right, t2->right, comp );
			}
		}
	}
	return 0;
}
