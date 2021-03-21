#ifndef LIST_H
#define LIST_H

typedef struct no TNo;
struct no
{
	void * elem;//dads
	TNo * next;//prox posiç.
};

typedef struct list TList;
struct list
{
	TNo * first;//primeira
	TNo * last;//ultima
};

TList * build_list();
int empty_list(TList * l);
void insert_begin(TList *l, void * elem );
void * search_list( TList *l, void *elem, int (*comp)() );
void print_list(TList *l, void (*print)() );
void free_list( TList *l, void (*free)() );







#endif
