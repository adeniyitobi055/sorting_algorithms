#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * in ascending order using insertion sort.
 * @list:Double pointer to the list.
 *
 * Return: Sorted doubly linked list in ascended order.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *node, *temp, *next, *temp_next, *temp_prev;
	int i = 0;

	if (list == NULL || (*list)->next == NULL)
		return;
	node = *list;
	node = node->next;
	while (node != NULL)
	{
		temp = node;
		next = node->next;
		temp_next = temp->next;
		temp_prev = temp->prev;

		while (temp_prev != NULL && temp->prev->n > temp->n)
		{
			if (temp_next != NULL)
				temp_next->prev = temp_prev;
			temp_prev->next = temp_next;
			if (temp_prev->prev == NULL)
			{
				temp_prev->prev = temp;
				*list = temp;
				temp->prev = NULL;
			}
			else
			{
				temp->prev = temp_prev->prev;
				temp_prev->prev->next = temp;
				temp_prev->prev = temp;
			}
			temp->next = temp_prev;
			temp_prev = temp->prev;
			temp_next = temp->next;
			print_list(*list);
		}
		node = next;
		i++;
	}
}
