#include "main.h"

/**
 * _atoi - convert a string to an integer
 * @s: input pointer to a string to be converted
 *
 * Return: integer from string
 */

int _atoi(char *s)
{
	int sign = 1, count = 0, i;
	char *init;
	int num = 0, multip;

	while ((*s < '0' || *s > '9') && (*s != '\0'))
	{
		if (*s == '-')
			sign *= -1;
		++s;
	}

	if (*s == '\0')
		return (0);

	init = s;
	while (*s >= '0' && *s <= '9')
	{
		++s;
		++count;
	}

	count--;
	multip = 10;

	for (i = 1; i < count; i++)
		multip *= 10;

	for (i = 0; i < count; i++)
	{
		num += (*init++ - '0') * multip;
		multip /= 10;
	}
	num *= sign;
	num += (*init - '0') * sign;

	return (num);
}
