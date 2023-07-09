#include "hash_tables.h"

/**
 * hash_table_print - function to print the contents of the HashTable
 * @ht: the specific HashTable to print from
 * Return: Nothing
*/

void hash_table_print(const hash_table_t *ht)
{
	unsigned long int itr;
	unsigned long int jtr;
	hash_node_t *item;

	itr = 0;
	jtr = 0;

	if (ht)
	{
		putchar('{');
		for (itr = jtr = 0; itr < ht->size; itr++)
		{
			if (ht->array[itr] != NULL)
			{
				item = ht->array[itr];
				while (item)
				{
					if (jtr)
						printf(", ");
					printf("'%s': '%s'", item->key, item->value);
					item = item->next;
					jtr = 1;
				}
			}
		}
		putchar('}');
		putchar('\n');
	}
}
