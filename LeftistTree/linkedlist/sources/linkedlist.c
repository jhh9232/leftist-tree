#include "../headers/linkedlist.h"

void list_create(lnklist** list)
{
	if (*list)
		return;
	(*list) = (lnklist*)malloc(sizeof(lnklist));
	(*list)->head = NULL;
	(*list)->tail = NULL;
	(*list)->size = 0;
}

void list_create_node(lnknode** lst, int value)
{
	if (*lst)
		return;
	(*lst) = (lnknode*)malloc(sizeof(lnknode));
	(*lst)->data = value;
	(*lst)->next = NULL;
	(*lst)->prev = NULL;
}

int list_exist_value(lnklist* list, int value)
{
	lnknode* curr = list->head;
	while (curr->data != value)
	{
		curr = curr->next;
		if (curr == NULL)
			return false;
	}
	return true;
}

lnknode* list_get_node(lnklist* list, int value)
{
	lnknode* curr = list->head;
	while (curr->data != value)
	{
		curr = curr->next;
		if (curr == NULL)
			return NULL;
	}
	return curr;
}

void* list_get_value(lnklist* list, int value)
{
	lnknode* curr = list->head;
	while (curr->data != value)
	{
		curr = curr->next;
		if (curr == NULL)
			return NULL;
	}
	return &(curr->data);
}

int list_get_size(lnklist* list)
{
	if (list == NULL)
		return error;
	return list->size;
}

int list_add_sort(lnklist** list, int value)
{
	lnknode* newnode = NULL;
	//값이 존재하면 삽입하지 않는다.
	if ((*list)->head == NULL)
	{
		list_create_node(&newnode, value);
		(*list)->head = newnode;
		(*list)->tail = newnode;
	}
	//첫 번째 값보다 작으면 중복되는 값은 없다고 친다.
	else if ((*list)->head->data > value)
	{
		list_create_node(&newnode, value);
		(*list)->head->prev = newnode;
		newnode->next = (*list)->head;
		(*list)->head = newnode;
	}
	else
	{
		if (list_exist_value(*list, value))
			return false;
		list_create_node(&newnode, value);
		lnknode* find_input = (*list)->head;
		while (find_input->next != NULL)
		{
			if (find_input->next->data > value)
				break;
			find_input = find_input->next;
		}
		newnode->prev = find_input;
		newnode->next = find_input->next;
		if (newnode->next != NULL)
			newnode->next->prev = newnode;
		else
			(*list)->tail = newnode;
		find_input->next = newnode;
	}
	(*list)->size++;
	return true;
}

void list_print(lnklist* list)
{
	if (list == NULL || list->head == NULL)
	{
		printf("list is empty\n");
		return;
	}
	lnknode* printnode = list->head;
	while (printnode)
	{
		printf("%d ", printnode->data);
		printnode = printnode->next;
	}
	printf("\n");
}

int list_del_node(lnklist** list, int value)
{
	if (!list)
		return false;
	lnknode* delnode = list_get_node(*list, value);
	if (!delnode)
		return false;
	if ((*list)->head == delnode)
	{
		(*list)->head = delnode->next;
		if ((*list)->head)
			(*list)->head->prev = NULL;
	}
	else
	{
		lnknode* temp_node = delnode;
		delnode->prev->next = temp_node->next;
		if (delnode->next)
			delnode->next->prev = temp_node->prev;
		else
			(*list)->tail = delnode->prev;
	}
	printf("%d - Remove\n", delnode->data);
	free(delnode);
	(*list)->size--;
	return true;
}

void list_destroy(lnklist** list)
{
	if ((*list) && (*list)->head)
	{
		while ((*list)->head != NULL)
		{
			lnknode* headnext = (*list)->head->next;
			free((*list)->head);
			(*list)->head = headnext;
		}
		(*list)->tail = NULL;
	}
	free(*list);
	(*list) = NULL;
}

//int main()
//{
//	printf("Hello World!!\n");
//	lnklist* list = NULL;
//	list_create(&list);
//	list_add_sort(&list, 5);
//	list_add_sort(&list, 3);
//	list_add_sort(&list, 7);
//	list_add_sort(&list, 4);
//	list_add_sort(&list, 6);
//	list_print(list);
//	int result = *(int*)list_get_value(list, 5);
//	printf("result = %d\n", result);
//	list_del_node(&list, 4);
//	list_del_node(&list, 6);
//	list_print(list);
//	list_destroy(&list);
//	list_print(list);
//	return 0;
//}