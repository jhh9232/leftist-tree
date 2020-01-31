#include "../headers/basicstack.h"

void stacktree_init(stack** treestack)
{
	*treestack = NULL;
}
void stacktree_push(stack** treestack, btree* node)
{
	if (!(*treestack))
	{
		*treestack = (stack*)malloc(sizeof(stack));
		(*treestack)->before = NULL;
		(*treestack)->node = node;
		(*treestack)->depth = 0;
	}
	else
	{
		stack* memory = NULL;
		memory = (stack*)malloc(sizeof(stack));
		memory->before = (*treestack);
		memory->node = node;
		memory->depth = 0;
		(*treestack) = memory;
	}
}

int stacktree_pop(stack** treestack)
{
	if (!(*treestack))
		return false;
	
	stack* memory = NULL;
	memory = (*treestack)->before;
	free(*treestack);
	(*treestack) = memory;
	return true;
}

void stacktree_destroy(stack** treestack)
{
	while (*treestack)
	{
		stacktree_pop(treestack);
	}
}

void stacktree_print(stack** treestack)
{
	if (!(*treestack))
	{
		printf("tree is empty...\n");
		return;
	}
}