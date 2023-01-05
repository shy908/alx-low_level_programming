#include "main.h"
#include <stdio.h>

/**
 * print_diagsums - prints sum of two diagonals of a square matrix.
 * @a: pointer that contains the address of
 * the beginning of the matrix
 * @size: size of the square matrix
 *
 * Return: void
 */
void print_diagsums(int *a, int size)
{
	int counter1, counter2, sum1, sum2;

	sum1 = 0;
	sum2 = 0;

	for (counter1 = 0; counter1 < size; counter1++)
	{
		sum1 += a[(size + 1) * counter1];
	}
	for (counter2 = 0; counter2 < size * size; counter2++)
	{
		sum2 += a[(size - 1) * (counter2 + 1)];
	}
	printf("%d, %d\n", sum1, sum2);
}
