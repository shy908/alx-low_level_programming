#include "main.h"

/**
 * _isupper -  function that checks for uppercase character.
 * @c: input
 * Retuen: 1 if c i uppercase , 0 otherwise
 */
int _isupper(int c)
{
	if ((c >= 'A') && c <= 'Z')
	{
		return (1);
	}

	else
	{
		return (0);
	}
}
