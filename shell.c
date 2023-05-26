#include "shell.h"

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
	while (true)
	{
		if ((isatty(STDIN_FILENO)))
			print_string("($) ");
		chars_read = _getline(&input, &n, stdin);
		if (chars_read == -1)
		{
			free_all(input, args);
			if (!(isatty(STDIN_FILENO)))
				exit(EXIT_SUCCESS);
			exit(EXIT_FAILURE);
		}
		input[chars_read - 1] = '\0';
		parse_input(input, args);
		if (_strcmp(args[0], "/bin/exit") == 0)
			handle_exit_command(args, input, first);
		if (*input != '\0')
			run_command(args, big_env, input);

	}
	return (0);
}
