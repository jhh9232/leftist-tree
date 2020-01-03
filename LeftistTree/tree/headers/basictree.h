#ifndef BASIC_TREE_H
#define BASIC_TREE_H

#include "../../linkedlist/headers/linkedlist.h"

typedef struct treenode btree;

struct treenode
{
	btree* parent;
	btree* left;
	btree* right;

	char* key;
	lnklist value;
	int nodecnt;
};

void tree_init(btree**);

#endif // !BASIC_TREE_H
