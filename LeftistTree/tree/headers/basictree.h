#ifndef BASIC_TREE_H
#define BASIC_TREE_H

#include "../../linkedlist/headers/linkedlist.h"

typedef struct treenode tree;

struct treenode
{
	tree* parent;
	tree* left;
	tree* right;

	char* key;
	lnklist value;
};

#endif // !BASIC_TREE_H
