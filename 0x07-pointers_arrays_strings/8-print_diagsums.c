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
	int i, n;
	int total1 = 0, total2 = 0;

	for (i = 0; i <= (size * size); i = i + size + 1)
	{
		total1 = total1 + a[i];
	}
	for (n = size - 1; n <= (size * size) - size; n = n + size - 1)
	{
		total2 = total2 + a[j];
	}
	printf("%d, %d\n", total1, total2);
}
