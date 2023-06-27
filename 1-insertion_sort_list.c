#include "sort.h"

/**
 * insertion_sort_list - sorts a list of ints
 * @list: linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *prev_prev, *prev, *current_1, *current_next;

	if (list == NULL || *list == NULL)
		return;
	current = *list;

	while (current)
	{
		if (current->prev && current->prev->n > current->n)
		{
			prev_prev = current->prev->prev;
			prev = prev->prev;
			current_1 = current;
			current_next = current->next;
			prev->next = current_next;

			if (current_next)
				current_next->prev = prev;

			current_1->prev = prev_prev;
			current_1->next = prev;

			if (prev_prev)
				prev_prev->next = current_1;
			else
				*list = current_1;

			prev->prev = current_1;
			current = *list;
			print_list(*list);
			continue;
		}
		else
			current = current->next;
	}
}
