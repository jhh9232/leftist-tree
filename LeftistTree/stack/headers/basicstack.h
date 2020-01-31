#ifndef BASIC_STACK_H
#define BASIC_STACK_H

#include "../../tree/headers/basictree.h"

typedef struct stacknode stack;

struct stacknode
{
	btree* node;
	stack* before;

	int depth;
};

void stacktree_init(stack**);
void stacktree_push(stack**, btree*);
int stacktree_pop(stack**);
void stacktree_destroy(stack**);
void stacktree_print(stack**);

#endif