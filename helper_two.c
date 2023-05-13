#include "shell.h"
/**
  *put_char - a function that prints a char
  *@c: the char
  *Return: 1
  */
int put_char(char c)
{
	return (write(1, &c, 1));
}
/**
  *print_string - a function that prints a string
  *@str: the string
  */
void print_string(char *str)
{
	while (*str != '\0')
	{
		put_char(*str);
		str++;
	}

}
/**
 *_strlen - print the length of a string
 *@s: the first char of th string;
 *Return: len
 */
int _strlen(char *s)
{
	int len = 0;

	while (*s != '\0')
	{
		len++;
		s++;
	}

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
