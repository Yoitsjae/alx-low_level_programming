#include "hash_tables.h"

/**
 * hash_table_delete - Deletes a hashtable and its nodes
 * @ht: Pointer to the hash table
 */
void hash_table_delete(hash_table_t *ht)
{
	hash_node_t *bucket, *next;
	unsigned long int i;

	if (!ht)
		return;

	for (i = 0; i < ht->size; i++)
	{
		bucket = ht->array[i];
		while (bucket)
		{
			next = bucket->next;
			free(bucket->key);
			free(bucket->value);
			free(bucket);
			bucket = next;
		}
	}

	free(ht->array);
	free(ht);
}
