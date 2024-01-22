#include "deck.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * get_val - this gets the value of the cards
 * @str: tis is the string value of the card
 * Return: this is the relative card from 0 to 12
 */
int get_val(const char *str)
{
	int a;
	char *array[13] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9",
			"10", "Jack", "Queen", "King"};

	for (a = 0; a < 13; a++)
	{
		if (strcmp(str, array[a]) == 0)
		{
			return (a);
		}
	}
	exit(1);
}

/**
 * swap_node - this swaps the card
 * @list: this is the list of card to swap
 * @node: this is the node to swap
 * Return: nothing
 */
void swap_node(deck_node_t **list, deck_node_t *node)
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
 * sort_deck - the sorts the deck of card
 * @deck: this is the deck to sort
 * Return: blank
 */
void sort_deck(deck_node_t **deck)
{
	char ar = 1, card1, card2;
	deck_node_t *nowc;

	if (deck == NULL || *deck == NULL || (*deck)->next == NULL)
		return;
	nowc = *deck;
	while (ar != 0)
	{
		ar = 0;
		while (nowc->next != NULL)
		{
			card1 = get_val(nowc->card->value) + 13 * nowc->card->kind;
			card2 = get_val(nowc->next->card->value) + 13 * nowc->next->card->kind;
			if (card1 > card2)
			{
				swap_node(deck, nowc);
				ar = 1;
			}
			else
				nowc = nowc->next;
		}
		if (ar == 0)
			break;
		ar = 0;
		while (nowc->prev != NULL)
		{
			card1 = get_val(nowc->card->value) + 13 * nowc->card->kind;
			card2 = get_val(nowc->prev->card->value) + 13 * nowc->prev->card->kind;
			if (card1 < card2)
			{
				swap_node(deck, nowc->prev);
				ar = 1;
			}
			else
				nowc = nowc->prev;
		}
	}
}
