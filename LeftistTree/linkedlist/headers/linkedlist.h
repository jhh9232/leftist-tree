#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "../../main.h"

typedef struct listnode lnknode;
typedef struct linkedlist lnklist;

struct listnode
{
	int data;
	lnknode* next;
	lnknode* prev;
};

struct linkedlist
{
	lnknode* head;
	lnknode* tail;
	int size;
};

void list_create(lnklist**);
void list_create_node(lnknode**, int);
int list_add_sort(lnklist**, int);

int list_exist_value(lnklist*, int value);
lnknode* list_get_node(lnklist*, int value);
void* list_get_value(lnklist*, int value);
int list_get_size(lnklist*);

//debug - print
void list_print(lnklist*);

int list_del_node(lnklist**, int);

void list_destroy(lnklist**);


#endif // !LINKEDLIST_H
