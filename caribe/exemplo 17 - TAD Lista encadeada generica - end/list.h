#ifndef LIST_H
#define LIST_H

typedef struct no TNo;
struct no
{
	void * elem;
	TNo * next;
};

typedef struct list TList;
struct list
{
	TNo * first;
	TNo * last;
};

TList * build_list();
int empty_list(TList * l);
void insert_end(TList *l, void * elem );
void * search_list( TList *l, void *elem, int (*comp)() );
void print_list(TList *l, void (*print)() );
void free_list( TList *l, void (*free)() );







#endif
