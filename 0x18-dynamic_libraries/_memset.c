#include "main.h"

/**
 * _memset - Fills the first n bytes of the memory area pointed to by s
 *           with the constant byte c
 * @s: Pointer to the memory area to be filled
 * @c: Value to be set
 * @n: Number of bytes to be filled
 *
 * Return: Pointer to the filled memory area (s)
 */
void *_memset(void *s, int c, unsigned int n)
{
	char *ptr = s;

	while (n--)
		*ptr++ = c;

	return (s);
}
