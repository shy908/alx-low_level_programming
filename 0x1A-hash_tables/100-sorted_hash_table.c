#include "hash_tables.h"

/**
 * shash_table_create - function to create a shash table
 * @size: the size of the table array
 * Return: pointer to the created table else NULL if not successful
*/

shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *new_shash_t;

	if (size > 0)
	{
		new_shash_t = malloc(sizeof(shash_table_t));
		if (new_shash_t)
		{
			new_shash_t->size = size;
			new_shash_t->array = calloc(size, sizeof(shash_node_t *));
			if (new_shash_t->array)
			{
				new_shash_t->shead = NULL;
				new_shash_t->stail = NULL;
				return (new_shash_t);
			}
			free(new_shash_t);
			return (NULL);
		}
		return (NULL);
	}
	return (NULL);
}

/**
 * shash_table_set - function to add element to the shash table *
 * @ht: the specified shash table
 * @key: the key for which to add the element
 * @value: the value for the key
 * Return: 0 if failed else 1 is successful
 */

int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	shash_node_t *node = NULL;
	shash_node_t *nodeitem = NULL;
	unsigned long int index;
	char *d_key = NULL;
	char *d_value = NULL;

	if (ht)
	{
		if (ht->array)
		{
			if (key || key[0] || value)
			{
				index = key_index((unsigned char *)key, ht->size);
				node = ht->array[index];
				d_value = strdup(value);
				if (d_value)
				{
					while (node != NULL)
					{
						if (strcmp(node->key,  key))
							node = node->next;
						else
						{
							free(node->value);
							node->value = d_value;
							return (1);
						}
					}
					node = ht->array[index];
					nodeitem = malloc(sizeof(shash_node_t));
					if (nodeitem != NULL)
					{
						d_key = strdup(key);
						if (d_key)
						{
							nodeitem->key = d_key;
							nodeitem->value = d_value;
							nodeitem->next = node;
							nodeitem->sprev = NULL;
							nodeitem->snext = NULL;
							ht->array[index] = nodeitem;
							add_sorted_element(ht, nodeitem);
							return (1);
						}
						free(d_value);
						free(nodeitem);
						return (0);
					}
					free(d_value);
					return (0);
				}
				return (0);
			}
			return (0);
		}
		return (0);
	}
	return (0);
}

/**
 * shash_table_print - prints the shash table
 * @ht: shash table
 * Return: Nothing
 */

void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *key;
	int separator = 0;

	if (!ht || !(ht->array) || !(ht->shead))
		return;

	key = ht->shead;
	putchar('{');
	while (key)
	{
		if (separator)
			printf(", ");
		printf("'%s': '%s'", key->key, key->value);
		separator = 1;
		key = key->snext;
	}
	putchar('}');
	putchar('\n');
}

/**
 * shash_table_print_rev - prints the shash table in reverse order
 * @ht: the shash table
 * Return: Nothing
 */

void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *key;
	int separator = 0;

	if (!ht || !(ht->array) || !(ht->stail))
		return;

	key = ht->stail;
	putchar('{');
	while (key)
	{
		if (separator)
			printf(", ");
		printf("'%s': '%s'", key->key, key->value);
		separator = 1;
		key = key->sprev;
	}
	putchar('}');
	putchar('\n');
}

/**
 * shash_table_delete - function to delete the shash table
 * @ht: the specified shash table
 * Return: Nothing
 */

void shash_table_delete(shash_table_t *ht)
{
	shash_node_t *node;
	shash_node_t *cache;
	unsigned long int i;

	if (!ht || !(ht->array))
		return;

	for (i = 0; i < ht->size; i++)
	{
		node = ht->array[i];
		while (node)
		{
			cache = node->next;
			free(node->key);
			free(node->value);
			free(node);
			node = cache;
		}
	}
	free(ht->array);
	free(ht);
}

/**
 * add_sorted_element - add node in sorted order into the shash node
 * @ht: the shash node to add sorted element
 * @node: the node to add
 * Return: a ponter to the shash node else NULL
 */

void add_sorted_element(shash_table_t *ht, shash_node_t *node)
{
	shash_node_t *_node = ht->shead;
	shash_node_t *_node2;

	if (!ht->shead || strcmp(node->key, ht->shead->key) <= 0)
	{
		node->snext = ht->shead;
		if (ht->shead)
			ht->shead->sprev = node;
		if (!(ht->stail))
			ht->stail = node;
		ht->shead = node;
		return;
	}

	_node2 = _node->snext;
	while (_node && _node2 && strcmp(node->key, _node2->key) > 0)
		_node = _node->snext, _node2 = _node->snext;

	_node->snext = node;
	node->snext = _node2;
	node->sprev = _node;
	if (_node2)
		_node2->sprev = node;
	else
		ht->stail = node;
}
