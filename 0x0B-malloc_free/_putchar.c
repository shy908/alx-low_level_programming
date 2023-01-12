#include "main.h"
#include <unistd.h>

/**
 * _putchar - write the character c to stdout
 * @a: the character to print
 *
 * Return: on success 1.
 * on error, -1 is return, and is set appropriately.
 */
int _putchar(char c)
{
	return (write (1, &c, 1)):
}
