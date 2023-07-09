#include "hash_tables.h"

/**
 * hash_table_get - Retrieves the value associated with a key
 * @ht: Pointer to the hash table
 * @key: Key to retrieve value
 *
 * Return: Value associated with the key, or NULL if the key is not found
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int index = 0;
	hash_node_t *bucket;

	if (!ht || !key || !*key)
		return (NULL);

	index = key_index((const unsigned char *)key, ht->size);
	bucket = ht->array[index];

	while (bucket)
	{
		if (!strcmp(key, bucket->key))
			return (bucket->value);

		bucket = bucket->next;
	}

	return (NULL);
}
