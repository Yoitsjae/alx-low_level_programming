#include<stdio.h>

/**
 * set_bit - sats the value of a bit to 1 at a given index
 * @n: pointer to the number to change
 * @index: index set to 1
 *
 * return 1 for success , -1 for failure
 */

int set_bit(unsigned long int *n, unsigned int index);
{
	if (index > 63)
		return (-1);

	*n = ((1UL << index) | *n);
	return (1);
}
