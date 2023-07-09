#include "hash_tables.h"

/**
 * sorted_list - Inserts a new node in a sorted manner into the sorted hash table
 * @ht: Pointer to the sorted hash table
 * @new_node: New node to insert
 */
void sorted_list(shash_table_t *ht, shash_node_t *new_node)
{
    shash_node_t *sbucket = ht->shead;

    if (sbucket == NULL)
    {
        ht->shead = ht->stail = new_node;
        new_node->snext = new_node->sprev = NULL;
        return;
    }
    do {
        if (strcmp(new_node->key, sbucket->key) < 0)
        {
            new_node->snext = sbucket;
            new_node->sprev = sbucket->sprev;

            if (!sbucket->sprev)
                ht->shead = new_node;
            else
                sbucket->sprev->snext = new_node;
            sbucket->sprev = new_node;
            return;
        }
        sbucket = sbucket->snext;
    } while (sbucket);
    new_node->sprev = ht->stail;
    new_node->snext = ht->stail->snext;
    ht->stail->snext = new_node;
    ht->stail = new_node;
}

/**
 * shash_table_create - Creates a sorted hash table
 * @size: Size of the hash table
 *
 * Return: Pointer to the created hash table
 */
shash_table_t *shash_table_create(unsigned long int size)
{
    shash_table_t *table;

    if (size == 0)
        return (NULL);

    table = calloc(1, sizeof(shash_table_t));
    if (table == NULL)
        return (NULL);

    table->size = size;
    table->array = calloc(size, sizeof(shash_node_t *));
    if (table->array == NULL)
    {
        free(table);
        return (NULL);
    }
    return (table);
}

/**
 * shash_table_set - Adds an element to the sorted hash table
 * @ht: Pointer to the sorted hash table
 * @key: Key to add the element
 * @value: Value to add the element
 *
 * Return: 1 if it succeeded, 0 otherwise
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
    unsigned long int index = 0;
    char *valuecopy, *keycopy;
    shash_node_t  *bucket, *new_node;

    if (!ht || !key || !*key || !value)
        return (0);

    valuecopy = strdup(value);
    if (!valuecopy)
        return (0);

    index = key_index((const unsigned char *)key, ht->size);
    bucket = ht->array[index];

    while (bucket)
    {
        if (!strcmp(key, bucket->key))
        {
            free(bucket->value);
            bucket->value = valuecopy;
            return (1);
        }
        bucket = bucket->next;
    }

    new_node = calloc(1, sizeof(shash_node_t));
    if (new_node == NULL)
    {
        free(valuecopy);
        return (0);
    }

    keycopy = strdup(key);
    if (!keycopy)
    {
        free(valuecopy);
        free(new_node);
        return (0);
    }

    new_node->key = keycopy;
    new_node->value = valuecopy;
    new_node->next = ht->array[index];
    ht->array[index] = new_node;
    sorted_list(ht, new_node);

    return (1);
}

/**
 * shash_table_get - Retrieves the value associated with a key in the sorted hash table
 * @ht: Pointer to the hash table
 * @key: Key to retrieve the value
 *
 * Return: Value associated with the key, or NULL if the key doesn't exist
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
    unsigned long int index = 0;
    shash_node_t  *bucket;

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

/**
 * shash_table_print - Prints the key-value pairs of the sorted hash table
 * @ht: Pointer to the hash table
 */
void shash_table_print(const shash_table_t *ht)
{
    shash_node_t *bucket;
    int not_fin = 0;

    if (!ht)
        return;

    bucket = ht->shead;
    printf("{");
    while (bucket)
    {
        if (not_fin)
            printf(", ");
        printf("'%s': '%s'", bucket->key, bucket->value);
        not_fin = 1;
        bucket = bucket->snext;
    }
    printf("}\n");
}

/**
 * shash_table_print_rev - Prints the key-value pairs of the sorted hash table in reverse order
 * @ht: Pointer to the hash table
 */
void shash_table_print_rev(const shash_table_t *ht)
{
    shash_node_t *bucket;
    int not_fin = 0;

    if (!ht)
        return;

    bucket = ht->stail;
    printf("{");
    while (bucket)
    {
        if (not_fin)
            printf(", ");
        printf("'%s': '%s'", bucket->key, bucket->value);
        not_fin = 1;
        bucket = bucket->sprev;
    }
    printf("}\n");
}

/**
 * shash_table_delete - Frees the sorted hash table and all its nodes
 * @ht: Pointer to the hash table
 */
void shash_table_delete(shash_table_t *ht)
{
    shash_node_t *bucket, *aux_free;
    unsigned long int i = 0;

    if (!ht)
        return;

    for (i = 0; i < ht->size; i++)
    {
        bucket = ht->array[i];
        while (bucket)
        {
            aux_free = bucket;
            bucket = bucket->next;
            free(aux_free->key);
            free(aux_free->value);
            free(aux_free);
        }
    }

    free(ht->array);
    free(ht);
}
