#include "sort.h"

/**
 * insertion_sort_list - insertion sort algo
 * @list: list
 * Return: nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *i, *j, *nextnode;

	if (list == NULL || !(*list) || (*list)->next == NULL)
		return;
	i = (*list)->next;
	nextnode = i->next;
	while (i)
	{
		if (i->n < i->prev->n)
		{
			j = i->prev;
			while (j && (i->n < j->n))
			{
				if (!(j->prev))
				{
					j->prev = i;
					i->prev->next = i->next;
					if (i->next)
						i->next->prev = i->prev;
					i->next = j;
					i->prev = NULL;
					*list = i;
				}
				else
				{
					i->prev->next = i->next;
					if (i->next)
						i->next->prev = i->prev;
					j->prev->next = i;
					i->prev = j->prev;
					j->prev = i;
					i->next = j;
				}
				print_list(*list);
				j = i->prev;
			}
		}
		i = nextnode;
		i ? (nextnode = i->next) : (nextnode = NULL);
	}
}
