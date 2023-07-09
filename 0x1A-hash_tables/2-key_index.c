#include "hash_tables.h"

/**
 * key_index - function to get the index of a given key in a HashTable
 * @key: The key to search for its index
 * @size: The size of the HashTable
 * Return: 0 if key is NULL | size = 0 else index
*/

unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	unsigned long int index;

	if (key == NULL)
		return (0);
	if (size == 0)
		return (0);
	index = hash_djb2(key) % size;

	return (index);
}
