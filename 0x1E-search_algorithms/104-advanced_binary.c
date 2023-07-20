#include "search_algos.h"

int rec_adv_bin_search(int *, size_t, size_t, int);

/**
* advanced_binary - advance binary search function
* @array: the array element containing integer values
* @size: the size of the array
* @value: The value to search for in the array
* Return: -1 if value is not found else the index of the element
*/

int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL || !array)
		return (-1);
	return (rec_adv_bin_search(array, 0, size - 1, value));
}

/**
 * rec_adv_bin_search - function to recursively search an array
 * @arr: The array with elements of integers
 * @left: the lowest index in the array
 * @right: the max index in the array
 * @value: the value to search for
 * Return: -1 if value not found else the index where it is found
*/

int rec_adv_bin_search(int *arr, size_t left, size_t right, int value)
{
	size_t mid, itr;

	if (left > right)
		return (-1);

	printf("Searching in array: %d", arr[left]);
	for (itr = (left + 1); itr <= right; itr++)
		printf(", %d", arr[itr]);
	putchar('\n');

	if (left == right && arr[right] == value)
		return (right);

	if (left == right && arr[right] != value)
		return (-1);

	mid = left + (right - left) / 2;

	if ((mid == left || value != arr[mid - 1]) && arr[mid] == value)
		return (mid);

	if (arr[mid] >= value)
		return (rec_adv_bin_search(arr, left, mid, value));

	return (rec_adv_bin_search(arr, mid + 1, right, value));
}
