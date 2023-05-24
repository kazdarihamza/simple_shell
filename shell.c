#include "shell.h"

#define MAX_WORDS 1024
#define BUFFER_SIZE 1024

/**
* main - entry point
* @ac: args count
* @args: args vector
* Return: 0 on success
*/

int main(int ac, char **args)
{
	char *first = args[0];
	char *big_env[MAX_WORDS], *input = NULL;
	size_t n = 0;
	ssize_t chars_read;
	int i = 0, j = 0;

	while (environ[i] != NULL)
		i++;
	while (j < i)
	{
		big_env[j] = environ[j];
		j++;
	}
	big_env[j] = NULL;
	(void)ac;
	signal(SIGINT, ctrlc_avoid);