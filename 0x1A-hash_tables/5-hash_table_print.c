#include "hash_tables.h"

/**
 * hash_table_print - Prints the key-value pairs in the hash table
 * @ht: Pointer to the hash table
 */
void hash_table_print(const hash_table_t *ht)
{
	hash_node_t *bucket;
	unsigned int flag = 0;
	unsigned long int i;

	if (!ht)
		return;

	printf("{");
	for (i = 0; i < ht->size; i++)
	{
		bucket = ht->array[i];
		while (bucket)
		{
			if (flag)
				printf(", ");
			printf("'%s': '%s'", bucket->key, bucket->value);
			flag = 1;
			bucket = bucket->next;
		}
	}
	printf("}\n");
}
