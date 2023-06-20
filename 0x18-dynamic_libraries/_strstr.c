#include <stddef.h>
#include "main.h"

/**
 * _strstr - Locates the first occurrence of the substring needle in the
 *           string haystack
 * @haystack: Pointer to the string to be searched
 * @needle: Pointer to the substring to search for
 *
 * Return: Pointer to the beginning of the located substring in haystack,
 *         or NULL if the substring is not found
 */
char *_strstr(char *haystack, char *needle)
{
	char *start;
	char *search;

	while (*haystack)
	{
		start = haystack;
		search = needle;

		while (*haystack && *search && *haystack == *search)
		{
			haystack++;
			search++;
		}

		if (!*search)
			return (start);

		haystack = start + 1;
	}

	return (NULL);
}
