#include "./tree/headers/basictree.h"

int main()
{
	printf("Hello World!!\n");
	lnklist* list = NULL;
	list_create(&list);
	list_add_sort(&list, 5);
	list_add_sort(&list, 3);
	list_add_sort(&list, 7);
	list_add_sort(&list, 4);
	list_add_sort(&list, 6);
	list_print(list);
	int result = *(int*)list_get_value(list, 5);
	printf("result = %d\n", result);
	list_del_node(&list, 4);
	list_del_node(&list, 6);
	list_print(list);
	list_destroy(&list);
	list_print(list);
	return 0;
}

//valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=valgrind-out.txt ./LeftistTree.out