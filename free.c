#include "shell.h"

/**
 * free_all - frees all memory
 * @input: input
 * @args: arguments
 */

void free_all(char *input, char **args)
{
	if (checkMemoryAllocation(input) == MALLOC &&
	checkMemoryAllocation(input) == MALLOC)
		free(input);
	if (checkMemoryAllocation(args[0]) == MALLOC &&
	checkMemoryAllocation(input) != MALLOC)
		free(args[0]);
}
