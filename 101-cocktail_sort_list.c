#include "sort.h"
#include <stdio.h>

/**
 * swap - this swaps the array
 * @list: this is the list to swap
 * @node: the node swap list
 *
 * Return: void
 */
void swap(listint_t **list, listint_t *node)
{
	node->next->prev = node->prev;
	if (node->prev)
		node->prev->next = node->next;
	else
		*list = node->next;
	node->prev = node->next;
	node->next = node->next->next;
	node->prev->next = node;
	if (node->next)
		node->next->prev = node;
}

/**
 * cocktail_sort_list - this sorts the cocktail list
 * @list: this is the list of cocktail
 * Return: nothing
 */
void cocktail_sort_list(listint_t **list)
{
	char turn = 1;
	listint_t *strs;

	if (list == NULL || *list == NULL)
		return;
	strs = *list;
	while (turn != 0)
	{
		turn = 0;
		while (strs->next != NULL)
		{
			if (strs->next->n < strs->n)
			{
				swap(list, strs);
				turn = 1;
				print_list(*list);
			}
			else
				strs = strs->next;
		}
		if (turn == 0)
			break;
		turn = 0;
		while (strs->prev != NULL)
		{
			if (strs->prev->n > strs->n)
			{
				swap(list, strs->prev);
				turn = 1;
				print_list(*list);
			}
			else
				strs = strs->prev;
		}
	}
}
