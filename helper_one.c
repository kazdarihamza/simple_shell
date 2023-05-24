#include "shell.h"

/**
 *_strcspn - a function that gets the length of a prefix substring.
 *@s1: string
 *@s2: another string
 *Return: returns counter
 */
size_t _strcspn(const char *s1, const char *s2)
{
	const char *p1, *p2;
	size_t count = 0;

	for (p1 = s1; *p1 != '\0'; p1++)
	{
		for (p2 = s2; *p2 != '\0'; p2++)
		{
			if (*p1 == *p2)
			{
				return (count);
			}
		}
	count++;
	}
	return (count);
}
/**
 *_strcat - a fucntion that append two strings to one
 *@dest: the string that will be appended to
 *@src: the string that will be appanded
 *Return: always a string of chars
 */

char *_strcat(char *dest, const char *src)
{
	char *temp = dest;

	while (*temp)
		temp++;
	while ((*temp++ = *src++))
		;
	return (dest);
}
/**
 *_strcpy - a function that copy a string to an array
 *@dest: the array you will copy to
 *@src: the string you are copying
 *Return: the array you are copying to
 */

char *_strcpy(char *dest, const char *src)
{
	char *temp = dest;

	while ((*temp++ = *src++))
		;
	return (dest);
}
/**
	*_strtok - a fucntion that cut the part in it second argument
	*@str: the string
	*@delim:  the string we wanna remove
	*Return: a string
	*/
char *_strtok(char *str, const char *delim)
{
	static char *p;
	char *start, *end;

	if (str != NULL)
	{
		p = str;
	}

	if (p == NULL || *p == '\0')
	{
		return (NULL);
	}

	start = p;

	while (*p != '\0')
	{
		for (end = (char *) delim; *end != '\0'; end++)
		{
			if (*p == *end)
			{
				*p++ = '\0';
				return (start);
			}
		}
		p++;
	}
	return (start);
}

/**
 *_strspn - a function that gets the length of a prefix substring.
 *@str: string
 *@charset: another string
 *Return: returns counter
 */
size_t _strspn(const char *str, const char *charset)
{
	const char *s = str;
	size_t count = 0;
	int found = 0;

	while (*s != '\0')
	{
		const char *c = charset;

		found = 0;
		while (*c != '\0')
		{
			if (*s == *c)
			{
				found = 1;
				break;
			}
			c++;
		}

		if (found == 0)
			break;

		count++;
		s++;
	}
	return (count);
}
