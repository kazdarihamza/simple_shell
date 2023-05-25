#include "shell.h"

/**
 * free_all - frees all memory
 * @input: input
 * @args: arguments
 */

void free_all(char *input, char **args)
{
	if ((!(isatty(STDIN_FILENO)) && *input != '\0') ||
	(checkMemoryAllocation(input) == MALLOC))
		free(input);
	if ((!(isatty(STDIN_FILENO)) || input == NULL) &&
	(checkMemoryAllocation(args[0]) == MALLOC))
		free(args[0]);
}
