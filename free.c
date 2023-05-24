#include "shell.h"

/**
 * free_all - frees all memory
 * @input: input
 * @args: atguments
 */

void free_all(char *input, char **args)
{
	(void)args;
	(void)input;
	if (!(isatty(STDIN_FILENO)))
		exit(EXIT_SUCCESS);
	exit(EXIT_FAILURE);
}
