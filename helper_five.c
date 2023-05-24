
#include "shell.h"

/**
 *_strncpy - a fucntion that append two strings to one
 *@dest: the string that will be copied to
 *@src: the string that will be copied from
 *@n:buffer
 *Return: always a string of chars
 */


char *_strncpy(char *dest, const char *src, size_t n)
{
	char *dest_start = dest;

	while (*src && n > 0)
	{
		*dest++ = *src++;
		n--;
	}

	while (n > 0)
	{
		*dest++ = '\0';
		n--;
	}

	return (dest_start);
}
/**
 * _getc - a fucntion checks if its the end of line or not
 * @stream: the stream
 * Return: either 0 o 1
 */
int _getc(FILE *stream)
{
	char ch;
	ssize_t bytes_read = read(fileno(stream), &ch, 1);

	return ((bytes_read == 1) ? ch : EOF);
}
/**
 * _realloc - a fucntion that realocate memory
 * @ptr: the string we are relocating
 * @size: the new allocation
 * Return: the new realocated memory
 */
void *_realloc(void *ptr, size_t size)
{
	void *new_ptr;
	size_t original_size, copy_size;

	if (ptr == NULL)
		return (malloc(size));


	if (size == 0)
	{
		free(ptr);
		return (NULL);
	}

	new_ptr = malloc(size);

	if (new_ptr == NULL)
		return (NULL);

	original_size = malloc_usable_size(ptr);
	copy_size = (original_size < size) ? original_size : size;
	_memcpy(new_ptr, ptr, copy_size);

	free(ptr);

	return (new_ptr);
}
/**
 * _getline - takes ipnut from user
 * @lineptr: adress of input
 * @n: buffer
 * @stream: STDIN
 * Return: either 0 or -1
 */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	int ch;
	size_t len = 0;
	char *new_lineptr;

	if (lineptr == NULL || n == NULL || stream == NULL)
		return (-1);
	if (*lineptr == NULL)
		*n = 0;
	while ((ch = _getc(stream)) != EOF)
	{
		if (len + 1 >= *n)
		{
			*n += 1024 * 8;
			new_lineptr = _realloc(*lineptr, *n);
			if (new_lineptr == NULL)
			return (-1);
			*lineptr = new_lineptr;
		}
		(*lineptr)[len++] = ch;
		if (ch == '\n')
		break;
	}
	if (len == 0 || ch == EOF)
		return (-1);
	(*lineptr)[len] = '\0';
	return (len);
}

/**
 * ctrlc_avoid - handles the signal CTRL-C
 * @signl: signal number
 *
 * Return: void
 */
void ctrlc_avoid(int signl)
{
	if (signl == SIGINT)
		print_buff("\n($) ", STDIN_FILENO);
}
