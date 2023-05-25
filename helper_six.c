#include "shell.h"

/**
 *print_buff - prints a string to stdout
 *@string: string to be printed
 *@fd: buffer to print out to
 *
 *Return: void, return nothing
 */
void print_buff(char *string, int fd)
{
	int i = 0;

	for (; string[i] != '\0'; i++)
		write(fd, &string[i], 1);
}

/**
 * _strchr - search for a keyword in a string
 * @str: string
 * @character: the character to search for
 * Return: returns the character or null if not found
 */
char *_strchr(const char *str, int character)
{
	char c = (char)character;

	while (*str != '\0')
	{
		if (*str == c)
			return ((char *)str);
		str++;
	}
	if (c == '\0')
	{
		return ((char *)str);
	}
	return (NULL);
}
/**
 * execute_external_command - executes a command using fork and execve
 * @ls: the command arguments array
 * @env: the environment variables array
 * @input: the input
 */
void execute_external_command(char **ls, char **env, char *input)
{
	pid_t pid;
	char *command = ls[0];

	pid = fork();
	if (pid == -1)
	{
		perror("Failed to fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		execve(command, ls, env);
		print_string("sh: 1: ");
		print_string(command);
		print_string(": not found\n");
		_exit(2);
	}
	else
	{
		int status;

		waitpid(pid, &status, 0);
		if (!WIFEXITED(status) || WEXITSTATUS(status) != 0)
		{
			free(input);
			exit(2);
		}
	}
}

/**
 * _memcpy - copies mok
 * @dest: Pointer to the destination memory block.
 * @src: Pointer to the source memory block.
 * @n: man3ref
 * Return: Pointer to the destination memory block (`dest`).
 */

void *_memcpy(void *dest, const void *src, size_t n)
{
	char *d = dest;
	const char *s = src;

	while (n--)
		*d++ = *s++;

	return (dest);
}

/**
 * malloc_usable_size - malloc
 * @ptr: pointer
 * Return: Pointer.
 */

size_t malloc_usable_size(const void *ptr)
{
	size_t *size_ptr;

	if (ptr == NULL)
		return (0);

	size_ptr = (size_t *)ptr - 1;
	return (*size_ptr);
}
