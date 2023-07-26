#include "sort.h"

/**
 * insertion_sort_list - a function that sorts a doubly linked list
 * of integers in ascending order
 *                       using the Insertion sort algorithm.
 *
 * @list: The doubly linked list to be sorted
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current;
	listint_t *insertion_point;

	if (!list || !(*list) || !(*list)->next)
		return;

	current = (*list)->next;

	while (current != NULL)
	{
		insertion_point = current;
		current = current->next;

		while (insertion_point->prev != NULL &&
insertion_point->n < insertion_point->prev->n)
		{
			if (insertion_point->next != NULL)
				insertion_point->next->prev = insertion_point->prev;

			insertion_point->prev->next = insertion_point->next;
			insertion_point->next = insertion_point->prev;
			insertion_point->prev = insertion_point->prev->prev;
			insertion_point->next->prev = insertion_point;

			if (insertion_point->prev == NULL)
				*list = insertion_point;

			else
				insertion_point->prev->next = insertion_point;

			print_list(*list);
		}
	}
}
