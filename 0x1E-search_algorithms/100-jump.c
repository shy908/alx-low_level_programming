#include "search_algos.h"
#include <math.h>

/**
 * jump_search - function to perform search operation on a sorted array
 * @array: the sorted array of integer values
 * @size: the length or size of @array
 * @value: the value to seach for from @array
 * Return: The index of @value else nothing
 */

int jump_search(int *array, size_t size, int value)
{
	size_t jump, pos_at = 0, min = 0, itr = 0;

	if (!array || size == 0)
		return (-1);

	jump = sqrt(size);

	while (pos_at < size && array[pos_at] < value)
	{
		printf("Value checked array[%lu] = [%d]\n",
				pos_at, array[pos_at]);
		min = pos_at;
		pos_at += jump;
	}

	printf("Value found between indexes [%lu] and [%lu]\n", min, pos_at);

	if (pos_at > (size - 1))
		pos_at = size - 1;
	for (itr = min; itr <= pos_at && array[itr] <= value; itr++)
	{
		printf("Value checked array[%lu] = [%d]\n", itr, array[itr]);
		if (array[itr] == value)
			return (itr);
	}
	return (-1);
}
