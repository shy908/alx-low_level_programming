#include "search_algos.h"

/**
 * binary_search - function that searches for a value from an arrau of
 * numbers using the binary search algorithm
 * @array: an array of integer values
 * @size: the size of `@array`
 * @value: the value to search for in the array
 * Return: The first index where the value is located
 */

int binary_search(int *array, size_t size, int value)
{
	size_t itr = 0;
	size_t bottom = 0, half = 0, top = 0;

	top = size - 1;
	if (array == NULL || !array)
		return (-1);
	while (bottom <= top)
	{
		half = (top + bottom) / 2;

		printf("Searching in array: ");
		for (itr = bottom; itr <= top; ++itr)
		{
			if (itr != bottom)
				printf(", %d", array[itr]);
			else
				printf("%d", array[itr]);
		}
		printf("\n");
		if (array[half] < value)
			bottom = half + 1;
		else if (array[half] > value)
			top = half - 1;
		else
			return (half);
	}
	return (-1);
}
