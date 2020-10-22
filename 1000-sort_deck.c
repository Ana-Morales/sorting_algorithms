#include "deck.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/**
 * swap_func - swaps two nodes in a double linkedlist
 * @deck: head of de double linked list
 * @node1: node1 two be swapped
 * @node2: node2 two be swapped
 *
 */
void swap_func(deck_node_t **deck, deck_node_t *node1, deck_node_t *node2)
{
	deck_node_t *tmp;

	if (node1->next == node2)
	{
		if (node2->next)
			node2->next->prev = node1;
		node2->prev = node1->prev;
		node1->next = node2->next;
		node2->next = node1;
		if (node1->prev)
			node1->prev->next = node2;
		node1->prev = node2;
		if (*deck == node1)
			*deck = node2;
	}
	else
	{
		node1->next->prev = node2;
		if (node1->prev)
			node1->prev->next = node2;
		node2->prev->next = node1;
		if (node2->next)
			node2->next->prev = node1;
		tmp = node1->next;
		node1->next = node2->next;
		node2->next = tmp;
		tmp = node2->prev;
		node2->prev = node1->prev;
		node1->prev = tmp;
		if (*deck == node1)
			*deck = node2;
	}
}
/**
 * partition - reorder the deck so that all elements with values less than
 * the pivot come before the pivot, while all elements with values greater than
 * the pivot come after it
 * @deck: deck of cards
 * @lo: lower index
 * @hi: higher index
 *
 * Return: pivot final index
 */
int partition(deck_node_t **deck, int lo, int hi)
{
	deck_node_t *pivot = *deck, *pi = *deck, *pj = *deck, *tmp = *deck;
	int i, j, k, v;
	kind_t p;
	char *s = "A234567891JQK";

	for (i = 0; i < lo; i++)
	{
		pivot = pivot->next;
		pi = pi->next;
		pj = pj->next;
	}
	while (i < hi)
	{
		pivot = pivot->next;
		i++;
	}
	p = pivot->card->kind;
	i = lo;
	for (j = lo; j < hi; j++)
	{
		for (k = 0; s[k] != pj->card->value[0]; k++)
			;
		for (v = 0; s[v] != pivot->card->value[0]; v++)
			;
		if ((pj->card->kind < p) || (pj->card->kind == p && k <= v))
		{
			if (pi != pj)
			{
				swap_func(deck, pi, pj);
				tmp = pi;
				pi = pj;
				pj = tmp;
			}
			pi = pi->next, i++;
		}
		pj = pj->next;
	}
	if (pi != pivot)
		swap_func(deck, pi, pivot);
	return (i);
}
/**
 * quicksort - sorts an deck of cards in ascending order
 * using the Quick sort algorithm
 * @deck: deck to be sorted
 * @lo: starting position
 * @hi: ending position
 *
 */
void quicksort(deck_node_t **deck, int lo, int hi)
{
	int p;

	if (lo < hi)
	{
		p = partition(deck, lo, hi);
		quicksort(deck, lo, p - 1);
		quicksort(deck, p + 1, hi);
	}

}
/**
 * sort_deck - sorts a deck of cards
 * @deck: deck of cards
 *
 */
void sort_deck(deck_node_t **deck)
{
	if (deck == NULL || *deck == NULL || (*deck)->next == NULL)
		return;
	quicksort(deck, 0, 51);
}
