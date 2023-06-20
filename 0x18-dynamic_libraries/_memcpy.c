#include "main.h"

/**
 * _memcpy - Copies n bytes from memory area src to memory area dest
 * @dest: Pointer to the destination memory area
 * @src: Pointer to the source memory area
 * @n: Number of bytes to be copied
 *
 * Return: Pointer to the destination memory area (dest)
 */
void *_memcpy(void *dest, const void *src, unsigned int n)
{
	char *d = dest;
	const char *s = src;

	while (n--)
		*d++ = *s++;

	return (dest);
}
