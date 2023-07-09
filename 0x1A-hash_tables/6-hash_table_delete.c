#include "hash_tables.h"

/**
 * hash_table_delete - function to delete a HashTable
 * @ht: the specific HashTable to delete
 * Return: Nothing
 */

void hash_table_delete(hash_table_t *ht)
{
	hash_node_t *nodes;
	hash_node_t *htabs;
	unsigned long int itr;

	if (ht)
	{
		for (itr = 0; itr < ht->size; itr++)
		{
			nodes = ht->array[itr];
			while (nodes)
			{
				htabs = nodes->next;
				free(nodes->key);
				free(nodes->value);
				free(nodes);
				nodes = htabs;
			}
		}
		free(ht->array);
		free(ht);
	}
}
