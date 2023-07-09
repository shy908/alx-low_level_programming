#include "hash_tables.h"

/**
 * hash_table_get - function to retrieve a value for the hashtable linked to\
 * the key specified
 * @ht: the HashTable from which to get the value from
 * @key: the key whose index the value will be gotten from
 * Return: the value if successful else 0
*/

char *hash_table_get(const hash_table_t *ht, const char *key)
{
	hash_node_t *item;
	unsigned long int index = 0;

	if (ht)
	{
		if (key)
		{
			index = key_index((const unsigned char *)key, ht->size);
			item = ht->array[index];
			if (item)
			{
				while (item && strncmp(item->key, key, strlen(key)) != 0)
					item = item->next;
				if (item != NULL)
					return (item->value);
				else
					return (0);
			}
			return (0);
		}
		return (0);
	}
	return (0);
}
