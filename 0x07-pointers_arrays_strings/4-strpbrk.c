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
	unsigned int counter;

	for (; *s != '\0'; s++)
	{
		for (counter = 0; accept[counter] != '\0'; counter++)
		{
			if (*s == accept[counter])
				return (s);
		}
	}
	return (0);
}
