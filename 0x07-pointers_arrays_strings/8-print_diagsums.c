#include "main.h"
#include <stdio.h>

/**
 * print_diagsums - Print the sum diagonals of square matrix.
 * @a: the matrix
 * @size: the size of the matrix
 *
 * Return: Nothing
 */
void print_diagsums(int *a, int size)
{
	int index, sum1 = 0, sum2 = 0;

	for (index = 0; index < size; index++)
	{
		sum1 += a[index];
		a += siz;
	}
	a -= size;

	for (index = 0; index < size; index++)
	{
		sum2 += a[index];
		a -= size;
	}
	printf("%d, %d\n", sum1, sum2);
}
