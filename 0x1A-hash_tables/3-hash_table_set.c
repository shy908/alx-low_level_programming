#include "hash_tables.h"

/**
 * hash_table_set - function to insert key/value element to a HashTable
 * @ht: the specified HashTable to insert/update its key/value element
 * @key: the key to search for its index
 * @value: the value to insert into the HashTable or update
 * Return: 1 if it succeeded, 0 otherwise
 */

int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	hash_node_t *item;
	hash_node_t *new_item;

	index = 0;
	item = NULL;
	new_item = NULL;

	if (ht == NULL)
		return (0);
	if (key == NULL || strcmp(key, "") == 0)
		return (0);

	index = key_index((unsigned char *)key, ht->size);
	item = ht->array[index];

	if (item && strcmp(key, item->key) == 0)
	{
		free(item->value);
		item->value = strdup(value);
		return (1);
	}

	new_item = malloc(sizeof(hash_node_t));
	if (new_item != NULL)
	{
		new_item->key = strdup(key);
		new_item->value = strdup(value);
		new_item->next = ht->array[index];
		ht->array[index] = new_item;

		return (1);
	}
	return (0);
}
