#include "sort.h"

/**
 * swap_node_ahead - Swaps a node with the node ahead of it in a
 * doubly linked list.
 *
 * @list: Pointer to the head of the doubly linked list.
 * @tail: Pointer to the tail of the doubly linked list.
 * @shaker: Pointer to the node to be swapped.
 *
 * Description:
 *   This function swaps the node pointed to by `shaker` with the node
 * immediately ahead of it in a doubly linked list. It updates the pointers
 * of adjacent nodes accordingly to maintain the integrity of the list. If
 * `shaker` points to the last node of the list, the function does nothing.
 */
void swap_node_ahead(listint_t **list, listint_t **tail, listint_t **shaker)
{
	listint_t *tmp = (*shaker)->next;

	if ((*shaker)->prev != NULL)
		(*shaker)->prev->next = tmp;
	else
		*list = tmp;

	tmp->prev = (*shaker)->prev;
	(*shaker)->next = tmp->next;

	if (tmp->next != NULL)
		tmp->next->prev = *shaker;
	else
		*tail = *shaker;

	(*shaker)->prev = tmp;
	tmp->next = *shaker;
	*shaker = tmp;
}

/**
 * swap_node_behind - Swaps a node with the node behind it in a
 * doubly linked list.
 *
 * @list: Pointer to the head of the doubly linked list.
 * @tail: Pointer to the tail of the doubly linked list.
 * @shaker: Pointer to the node to be swapped.
 *
 * Description:
 *   This function swaps the node pointed to by `shaker` with the
 * node immediately behind it in a doubly linked list. It updates the
 * pointers of adjacent nodes accordingly to maintain the integrity of
 * the list. If `shaker` points to the first node of the list, the function
 * does nothing.
 *
 */
void swap_node_behind(listint_t **list, listint_t **tail, listint_t **shaker)
{
	listint_t *tmp = (*shaker)->prev;

	if ((*shaker)->next != NULL)
		(*shaker)->next->prev = tmp;
	else
		*tail = tmp;

	tmp->next = (*shaker)->next;
	(*shaker)->prev = tmp->prev;

	if (tmp->prev != NULL)
		tmp->prev->next = *shaker;
	else
		*list = *shaker;

	(*shaker)->next = tmp;
	tmp->prev = *shaker;
	*shaker = tmp;
}

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers
 * in ascending order using the Cocktail Shaker Sort algorithm.
 *
 * @list: Pointer to the head of the doubly linked list.
 *
 * Description:
 * This function sorts a doubly linked list of integers in
 * ascending order using the Cocktail Shaker Sort algorithm.
 * The algorithm iterates over the list, swapping adjacent elements
 * if they are in the wrong order, first from the beginning to the
 * end of the list, then from the end to the beginning. This
 * process is repeated until no more swaps are needed, indicating
 * that the list is sorted.
 *
 * Prototype:
 *   void cocktail_sort_list(listint_t **list);
 *
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *tail, *shaker;
	bool shaken_not_stirred = false;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (tail = *list; tail->next != NULL;)
		tail = tail->next;

	while (shaken_not_stirred == false)
	{
		shaken_not_stirred = true;
		for (shaker = *list; shaker != tail; shaker = shaker->next)
		{
			if (shaker->n > shaker->next->n)
			{
				swap_node_ahead(list, &tail, &shaker);
				print_list((const listint_t *)*list);
				shaken_not_stirred = false;
			}
		}

		for (shaker = shaker->prev; shaker != *list;
			shaker = shaker->prev)
		{
			if (shaker->n < shaker->prev->n)
			{
				swap_node_behind(list, &tail, &shaker);
				print_list((const listint_t *)*list);
				shaken_not_stirred = false;
			}
		}
	}
}
