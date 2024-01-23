#include "sort.h"

/**
 * insertion_sort_list - this inserts sort list
 * @list: this is the list to insert
 * Return: blank
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *st, *qr;

	if (list == NULL || *list == NULL)
		return;
	st = (*list)->next;
	while (st != NULL)
	{
		qr = st->next;
		while (st->prev != NULL && st->prev->n > st->n)
		{
			st->prev->next = st->next;
			if (st->next != NULL)
				st->next->prev = st->prev;
			st->next = st->prev;
			st->prev = st->next->prev;
			st->next->prev = st;
			if (st->prev == NULL)
				*list = st;
			else
				st->prev->next = st;
			print_list(*list);
		}
		st = qr;
	}
}
