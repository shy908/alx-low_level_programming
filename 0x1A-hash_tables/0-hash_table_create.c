#include "hash_tables.h"

/**
 * hash_table_create - function that creates a hash table
 * @size: the size of the hash table to create.
 * Return: a pointer to the hash table
 */

hash_table_t *hash_table_create(unsigned long int size)
{
	unsigned long int itr;
	hash_table_t *hash_tab_new;

	if (size > 0)
	{
		hash_tab_new = malloc(sizeof(hash_table_t));
		if (hash_tab_new)
		{
			hash_tab_new->size = size;
			hash_tab_new->array = malloc(sizeof(hash_node_t *) * size);
			if (hash_tab_new)
			{
				for (itr = 0; itr < size; itr++)
					hash_tab_new->array[itr] = NULL;
				return (hash_tab_new);
			}
			free(hash_tab_new);
			return (NULL);
		}
		return (NULL);
	}
	return (NULL);
}
