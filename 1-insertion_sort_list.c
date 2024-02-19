#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * using insertion sort.
 *
 * @list: Pointer to a pointer to the head of the doubly linked list.
 *
 * Description:
 *   This function sorts a doubly linked list of integers in ascending order
 *   using the insertion sort algorithm. It iterates through the list, moving
 *   each element to its correct position within the sorted portion of
 * the list.
 *   At each step, the function adjusts the links between nodes to maintain the
 *   doubly linked list structure and calls a print_list function to display
 * the current state of the list after each swap operation.
 *
 * Prototype:
 *   void insertion_sort_list(listint_t **list);
 *
 * Return:
 *   This function does not return a value; it modifies the input doubly
 * linked list
 *   in place to sort it in ascending order.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp;

	if (list == NULL || *list == NULL)
		return;

	current = (*list)->next;

	while (current != NULL)
	{
		temp = current;
		current = current->next;

		while (temp->prev != NULL && temp->n < temp->prev->n)
		{
			temp->prev->next = temp->next;

			if (temp->next != NULL)
				temp->next->prev = temp->prev;

			temp->next = temp->prev;
			temp->prev = temp->prev->prev;
			temp->next->prev = temp;

			if (temp->prev == NULL)
				*list = temp;
			else
				temp->prev->next = temp;

			print_list(*list);
		}
	}
}
