#include "hash_tables.h"

/**
 * key_index - Retrieves the index of a key in a hash table
 * @key: The key
 * @size: Size of the hash table
 *
 * Return: The index of the key
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	return (hash_djb2(key) % size);
}
