#include "../headers/basictree.h"

void tree_init(btree** tree)
{
	if (*tree)
		tree_destroy(tree);

	(*tree) = (btree*)malloc(sizeof(btree));

	(*tree)->parent = NULL;
	(*tree)->left = NULL;
	(*tree)->right = NULL;
	(*tree)->nodecnt = 0;
	(*tree)->data = 0;
}

void tree_swap(btree** result, btree** target)
{
	btree* temp = *result;
	*result = *target;
	*target = temp;
}

void tree_merge(btree** result, btree** target)
{
	if (!(*result))
	{
		tree_swap(result, target);
		return;
	}
	if (!(*target)) return;

	if ((*result)->data > (*target)->data)
		tree_swap(result, target);
	tree_merge(&(*result)->right, target);
	if ((*result)->right)
		(*result)->right->parent = (*result);
	if (!((*result)->left))
	{
		tree_swap(&((*result)->left), &((*result)->right));
		(*result)->nodecnt = 1;
		return;
	}
	(*result)->left->parent = (*result);
	if ((*result)->right->nodecnt > (*result)->left->nodecnt)
		tree_swap(&((*result)->right), &((*result)->left));
	
	(*result)->nodecnt = (*result)->right->nodecnt + 1;
}

void tree_insert(btree** tree, int data)
{
	if (!(*tree))
	{
		tree_init(tree);
		(*tree)->data = data;
		return;
	}
	btree* newtree = NULL;
	tree_init(&newtree);
	newtree->data = data;

	tree_merge(tree, &newtree);

}

void tree_delete_min(btree** tree)
{
	if (!(*tree))
		return;

	btree* tree_left = (*tree)->left;
	btree* tree_right = (*tree)->right;
	free(*tree);
	*tree = NULL;
	tree_left->parent = NULL;
	tree_right->parent = NULL;
	if (!tree_left)
	{
		*tree = tree_right;
		return;
	}
	if (!tree_right)
	{
		*tree = tree_left;
		return;
	}

	tree_merge(&tree_left, &tree_right);
	*tree = tree_left;
}

void draw_tree_hor2(btree* tree, int depth, char* path, int right)
{
	int space = 5;
	// stopping condition
	if (tree == NULL)
		return;

	// increase spacing
	depth++;

	// start with right node
	draw_tree_hor2(tree->right, depth, path, 1);

	// set | draw map
	path[depth - 2] = 0;

	if (right)
		path[depth - 2] = 1;

	if (tree->left)
		path[depth - 1] = 1;

	// print root after spacing
	printf("\n");

	for (int i = 0; i < depth - 1; i++)
	{
		if (i == depth - 2)
			printf("+");
		else if (path[i])
			printf("|");
		else
			printf(" ");

		for (int j = 1; j < space; j++)
			if (i < depth - 2)
				printf(" ");
			else
				printf("-");
	}

	printf("%d\n", tree->data);

	// vertical spacers below
	for (int i = 0; i < depth; i++)
	{
		if (path[i])
			printf("|");
		else
			printf(" ");

		for (int j = 1; j < space; j++)
			printf(" ");
	}

	// go to left node
	draw_tree_hor2(tree->left, depth, path, 0);
}

//primary fuction
void tree_print(btree* tree)
{
	// should check if we don't exceed this somehow..
	char path[255] = {};
	if (tree == NULL)
	{
		printf("Tree is EMPTY\n");
		return;
	}
	//initial depth is 0
	draw_tree_hor2(tree, 0, path, 0);
}

void tree_destroy(btree** tree)
{
	if (!(*tree))
		return;
	if ((*tree)->left != NULL)
		tree_destroy(&(*tree)->left);
	if ((*tree)->right != NULL)
		tree_destroy(&(*tree)->right);

	free(*tree);
	*tree = NULL;
	return;
}