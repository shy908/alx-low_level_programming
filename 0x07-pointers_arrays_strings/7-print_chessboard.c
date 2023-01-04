#include "main.h"

/**
 * print_chessboard - prints the chesssboard
 * @a: pointer to matrix containing the chessboard
 *
 * Return: void
 */
void print_chessboard(char (*a)[8])
{
	int r, n;

	for (r = 0; r < 8; r++)
	{
		for (n = 0; n < 8; n++)
		{
			_putchar(a[r][n]);
		}
		_putchar(10);
	}
}