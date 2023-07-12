#include "search_algos.h"

/**
 * linear_search - a function that searches for an item linearly
 * @array: an array of integers
 * @size: the size of the array
 * @value: the value to search for from the array
 * Return: the first index where @value is found else -1
 */

int linear_search(int *array, size_t size, int value)
{
	size_t itr = 0;

	if (!array || array == NULL)
		return (-1);
	for (itr = 0; itr < size; itr++)
	{
		printf("Value checked array[%lu] = [%d]\n", itr, array[itr]);
		if (value == array[itr])
			return (itr);
	}
	return (-1);
}
