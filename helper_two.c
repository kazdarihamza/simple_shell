#include "shell.h"
/**
	*put_char - a function that prints a char
	*@c: the char
	*Return: 1
	*/
int put_char(const char c)
{
	return (write(1, &c, 1));
}
/**
	*print_string - a function that prints a string
	*@str: the string
	*/
void print_string(const char *str)
{
	while (*str != '\0')
	{
		put_char(*str);
		str++;
	}

}
/**
 *_strlen - print the length of a string
 *@str: the first char of th string;
 *Return: len
 */
int _strlen(const char *str)
{
	int len = 0;

	while (str[len] != '\0')
		len++;
	return (len);
}

/**
 * _isspace - a fucntion checks if the char is not a space
 * @c: the char
 * Return: 0 for is not  space and 1 for it is a space
*/
int _isspace(int c)
{
	return (c == ' ' || c == '\t' || c == '\n' ||
		c == '\r' || c == '\f' || c == '\v');
}
/**
 * _atoi - converts a string to an integer
 * @s: string to be converted
 *
 * Return: the int converted from the string
 */
int _atoi(char *s)
{
int i, d, n, len, f, digit;
i = 0;
d = 0;
n = 0;
len = 0;
f = 0;
digit = 0;
while (s[len] != '\0')
len++;
while (i < len && f == 0)
{
if (s[i] == '-')
++d;
if (s[i] >= '0' && s[i] <= '9')
{
digit = s[i] - '0';
if (d % 2)
digit = -digit;
n = n * 10 + digit;
f = 1;
if (s[i + 1] < '0' || s[i + 1] > '9')
break;
f = 0;
}
i++;
}
if (f == 0)
return (0);
return (n);
}
