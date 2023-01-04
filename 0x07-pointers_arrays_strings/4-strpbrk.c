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
	int i, n;

	for (i = 0; s[i] != '\0'; i++)
	{
		for (n = 0; accept[n] != '\0'; n++)
		{
			if (s[i] == accept[n])
				return (s + i);
		}
	}
	return (NULL)
}
