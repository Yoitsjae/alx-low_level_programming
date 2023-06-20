#include "main.h"

/**
 * _strspn - Gets the length of a prefix substring that consists of only
 *           the characters specified in accept
 * @s: Pointer to the string to be searched
 * @accept: Pointer to the string containing the characters to match
 *
 * Return: The length of the prefix substring
 */
unsigned int _strspn(char *s, char *accept)
{
	unsigned int count = 0;
	int found;

	while (*s)
	{
		found = 0;
		while (*accept)
		{
			if (*s == *accept)
			{
				count++;
				found = 1;
				break;
			}
			accept++;
		}

		if (found == 0)
			break;

		s++;
		accept = accept - count;
	}

	return (count);
}
