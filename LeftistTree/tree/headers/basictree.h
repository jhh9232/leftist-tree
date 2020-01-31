#ifndef BASIC_TREE_H
#define BASIC_TREE_H

#include "../../main.h"

typedef struct treenode btree;

struct treenode
{
	btree* parent;
	btree* left;
	btree* right;

	int data;
	int nodecnt;
};

void tree_init(btree**);
void tree_insert(btree**, int);

void tree_swap(btree**, btree**);
void tree_merge(btree**, btree**);

void tree_print(btree*);

void tree_delete_min(btree**);
void tree_destroy(btree**);

#endif // !BASIC_TREE_H
