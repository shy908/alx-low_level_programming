#include "main.h"

/**
 * puts_half - prints half of a string
 * @str: imput
 */
void puts_half(char *str)
{
	int len = o;

	while (*str != '\0')
	{
		len++;
		str++
	}

	str -= (len / 2);
	while (*str != '\0')
	{
		_putchar(*str);
		str++;
	}
	_putchar('\n');
}
