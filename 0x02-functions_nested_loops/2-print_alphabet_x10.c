#include "main.h"

/**
 * print_alphabet_x10 - Print alphabet in lowercase 10 times
 *
 * Return: Always 0
 */
void print_alphabet_x10(void)
{
	char c;
	int i = 0;

	while (i <= 9)
	{
		for (c = 'a'; c <= 'z'; c++)
		{
			_putchar(c);
		}

		i++;
	}
}

