#include "main.h"
#include <stdio.h>

/**
 * print_diagsums - sum diagonal values.
 * @a: pointer to array
 * @size: int
 *
 * Return: sum of two sides
 */
void print_diagsums(int *a, int size)
{
	int index, sum1 = 0, sum2 = 0;
	
	for (index = 0; index < size; index++)
	{
		sum1 += a[index]; a -= size;
	}
	for (index = 0; index < size; index++)
	{
		sum2 += a[index]; a -= size;
	}
	printf("%d, %d\n", sum1, sum2);
}
