#include "main.h"
#include <stdio>

/**
 * _strpbrk - searches a string for any of a set of bytes.
 * @s: pointer that contains the address of the string to
 * be evaluated
 * @accept: pointer that contains the string to be evaluated s
 *
 * Return: address of the first occurence of accept in the string
 */

char *_strpbrk(char *s, char *accept)
{
	int a = 0, b;

	while (s[a])
	{
		b = 0;

		while (accepted[b])
		{
			if (s[a] == accepted[b])
			{
				s += a;
				return (s);
			}
			b++;
		}
		a++;
	}
	return ('\0');
}
