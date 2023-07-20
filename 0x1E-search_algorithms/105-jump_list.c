#include "search_algos.h"
#include <math.h>

listint_t *move_the_list(listint_t *, int);

/**
 * jump_list - searches for a value in a list of sorted integers
 * @list: pointer to the head of the list to search in
 * @size: number of nodes in list
 * @value: value to search for
 * Return: Pointer to first node where value is located or NULL
 */

listint_t *jump_list(listint_t *list, size_t size, int value)
{
	size_t jump, itr;
	listint_t *node_pos, *node_min;

	if (!list || size == 0)
		return (NULL);

	node_pos = list, node_min = list;
	jump = sqrt(size);

	while (node_pos && node_pos->next && (node_pos->n) < value)
	{
		node_min = node_pos;

		node_pos = move_the_list(node_pos, jump);
		printf("Value checked at index [%lu] = [%d]\n",
			   node_pos->index, node_pos->n);
	}

	printf("Value found between indexes [%lu] and [%lu]\n",
		   node_min->index, node_pos->index);

	for (itr = node_min->index;
		 itr <= (node_pos->index) && itr < size && (node_min->n <= value);
		 itr++, node_min = node_min->next)
	{
		printf("Value checked at index [%lu] = [%d]\n", itr, node_min->n);
		if (node_min && (node_min->n) == value)
			return (node_min);
	}

	if (node_min)
		printf("Value checked at index [%lu] = [%d]\n", itr, node_min->n);

	return (NULL);
}

/**
 * move_the_list - moves list x positions
 * using the Jump search algorithm.
 * @list: pointer to the node of list
 * @x: positions to move
 *
 * Return: Pointer to new node or NULL
 */

listint_t *move_the_list(listint_t *list, int x)
{
	int itr;

	for (itr = 0; list->next && itr < x; itr++)
		list = list->next;

	return (list);
}
