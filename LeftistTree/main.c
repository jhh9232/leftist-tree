#include "./stack/headers/basicstack.h"

int main()
{
	btree* tree = NULL;

	tree_insert(&tree, 1);
	tree_print(tree);
	tree_insert(&tree, 2);
	tree_insert(&tree, 3);
	//tree_insert(&tree, 0);
	tree_print(tree);
	printf("\nmin-value : %d\n", tree->data);
	tree_delete_min(&tree);
	tree_print(tree);
	tree_destroy(&tree);
	printf("\n");
	return 0;
}

//valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=valgrind-out.txt ./LeftistTree.out