#ifndef LIST_H
#define LIST_H

typedef struct no TNo;
struct no
{
	void * elem;
	TNo * next;
};

int empty_list(TNo * l);

void insert_begin(TNo **l, void * elem );

void insert_end(TNo **l, void * elem );

void insert_sort(TNo **l, void * elem, int (*comp_sort)() );

void * search_list( TNo *l, void *elem, int (*comp)() );

void print_list(TNo *l, void (*print)() );

void free_list( TNo **l, void (*free_elem)() );







#endif
