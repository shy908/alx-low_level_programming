#include "main.h"
#include <stdio.h>

/**
 * print_diagsums - Print the sum diagonals of square matrix.
 * @a: the matrix
 * @size: the size
 *
 * Return: Nothing
 */
void print_diagsums(int *a, int size)
{
	int i, sum1 = 0, sum2 = 0;

	for (i = 0; i < (size * size); i++)
	{
		if (i % (size + 1) == 0)
			sum1 += *(a + i);
		if (i % (size - 1) == 0 && i != 0 && i < size * size - 1)
			sum2 += *(a + i);
	}
	printf("%d\n", sum1, sum2);
}
