#include "hash_tables.h"
#include <stdlib.h>

void hash_table_delete(hash_table_t *ht)
{
    unsigned long int i;
    hash_node_t *node, *temp;

    if (ht == NULL)
        return;

    for (i = 0; i < ht->size; i++)
    {
        node = ht->array[i];
        while (node)
        {
            temp = node->next;
            free(node->key);
            free(node->value);
            free(node);
            node = temp;
        }
    }

    free(ht->array);
    free(ht);
}
