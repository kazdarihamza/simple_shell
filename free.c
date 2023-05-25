#include "shell.h"

/**
 * free_all - frees all memory
 * @input: input
 * @args: atguments
 */

void free_all(char *input, char **args)
{
	if (!(isatty(STDIN_FILENO)))
		free(args[0]);
	if ((isatty(STDIN_FILENO)))
		free(input);
}
