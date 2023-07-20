#include "search_algos.h"

/**
 * linear_skip - function that searches for a value in a sorted skip list of
 * integers
 * @list: pointer to the head of the skip list to search
 * @value: value to search for
 * Return: Pointer on the first node where value is located or NULL
 */

skiplist_t *linear_skip(skiplist_t *list, int value)
{
	size_t itr;
	skiplist_t *nd_pos, *nd_min;

	if (!list)
		return (NULL);

	nd_pos = list, nd_min = list;

	while (nd_pos && nd_pos->next && (nd_pos->n) < value)
	{
		nd_min = nd_pos;

		if (nd_pos->express)
		{
			nd_pos = nd_pos->express;

			printf("Value checked at index [%lu] = [%d]\n",
			       nd_pos->index, nd_pos->n);
		}
		else
			while (nd_pos->next)
				nd_pos = nd_pos->next;
	}

	printf("Value found between indexes [%lu] and [%lu]\n",
	       nd_min->index, nd_pos->index);

	for (itr = nd_min->index;
	     itr <= (nd_pos->index) && (nd_min->n <= value);
	     itr++, nd_min = nd_min->next)
	{
		printf("Value checked at index [%lu] = [%d]\n", itr, nd_min->n);
		if (nd_min && (nd_min->n) == value)
			return (nd_min);
	}

	if (nd_min)
		printf("Value checked at index [%lu] = [%d]\n", itr, nd_min->n);

	return (NULL);
}
