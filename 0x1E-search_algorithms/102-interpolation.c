#include "search_algos.h"

/**
 * get_position - function to get the index of the search value
 * @arr: the array with integer elements
 * @value: the value to search for
 * @lo: the lowest index from the array
 * @hi: the highest index from the array
 * Return: the index of the value from the array
 */

int get_position(int *arr, int value, size_t lo, size_t hi)
{
	size_t pos;

	pos = lo + (((double)(hi - lo) / (arr[hi] - arr[lo]))
			* (value - arr[lo]));
	return (pos);
}

/**
 * interpolation_search - function to perform interpolation search on an array
 * of integers
 * @array: the arry with integer elements
 * @size: the size of the array
 * @value: the value to search for
 * Return: Returns the index if found else -1
 */

int interpolation_search(int *array, size_t size, int value)
{
	size_t pos, low, high;

	if (array == NULL)
		return (-1);

	for (low = 0, high = (size - 1); high >= low;)
	{
		pos = get_position(array, value, low, high);
		if (pos < size)
			printf("Value checked array[%ld] = [%d]\n", pos, array[pos]);
		else
		{
			printf("Value checked array[%ld] is out of range\n", pos);
			break;
		}

		if (array[pos] == value)
			return (pos);
		if (array[pos] > value)
			high = pos - 1;
		else
			low = pos + 1;
	}

	return (-1);
}
