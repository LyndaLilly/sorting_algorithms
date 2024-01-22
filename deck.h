
#ifndef _DECK_H_
#define _DECK_H_

/**
 * enum kind_e - this the suit card
 * @SPADE: this is 0 spades
 * @HEART: this is hearts 1
 * @CLUB: this is 2 clubs
 * @DIAMOND: this is 3 diamonds
 */
typedef enum kind_e
{
	SPADE = 0,
	HEART,
	CLUB,
	DIAMOND
} kind_t;

/**
 * struct card_s - this is the card
 * @value: this is the value of card
 * @kind: this is the kind of card
 */
typedef struct card_s
{
	const char *value;
	const kind_t kind;
} card_t;

/**
 * struct deck_node_s - this is the card deck
 * @card: this pints to the card
 * @prev: this is the previous card
 * @next: this is the next card
 */
typedef struct deck_node_s
{
	const card_t *card;
	struct deck_node_s *prev;
	struct deck_node_s *next;
} deck_node_t;

void sort_deck(deck_node_t **deck);

#endif
