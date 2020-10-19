#include "sort.h"
/**
 * swap_func - swaps two nodes in a double linkedlist
 * @list: head of de double linked list
 * @node: node two be swapped with the next node
 *
 */
void swap_func(listint_t **list, listint_t *node)
{
	listint_t *tmp;

	tmp = node->next;
	if (tmp->next)
		tmp->next->prev = node;
	tmp->prev = node->prev;
	node->next = tmp->next;
	tmp->next = node;
	if (node->prev)
		node->prev->next = tmp;
	node->prev = tmp;
	if (*list == node)
		*list = tmp;
}

/**
 * cocktail_sort_list - sorts a doubly linked list of integers in ascending
 * order using the Cocktail shaker sort algorithm
 * @list: doubly linked list to be sorted
 *
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *current = *list;
	int flag = 1, flag1 = 0;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	while (flag > 0)
	{
		flag = 0;
		while (current->next != NULL)
		{
			flag1 = 0;
			if (current->n > current->next->n)
			{
				swap_func(list, current);
				print_list(*list);
				flag = 1;
				flag1 = 1;
			}
			if (flag1 == 0)
				current = current->next;
		}
		if (flag == 0)
			break;
		flag = 0;
		while (current->prev != NULL)
		{
			flag1 = 0;
			if (current->n < current->prev->n)
			{
				swap_func(list, current->prev);
				print_list(*list);
				flag = 1;
				flag1 = 1;
			}
			if (flag1 == 0)
				current = current->prev;
		}
	}
}
