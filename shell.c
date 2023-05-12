#include "main.h"

#define MAX_WORDS 10

/**
* parse_input - takes input from user and makes it an array
* @input: the input from user
* Return: the array
*/

char **parse_input(char *input)
{
	char **ls = (char **) malloc(sizeof(char *) * (MAX_WORDS + 1));
	char bin[] = "/bin/";
	char *word;
	int word_count = 0;

	word = _strtok(input, " ");
	while (word != NULL && word_count < MAX_WORDS)
	{
		if (word_count == 0 && word[0] >= 'a' && word[0] <= 'z')
		{
			char *command = malloc(_strlen(bin) + _strlen(word) + 1);

			_strcpy(command, bin);
			_strcat(command, word);
			ls[word_count++] = command;
		}
		else
			ls[word_count++] = word;
		word = _strtok(NULL, " ");
	}
	ls[word_count] = NULL;
	return (ls);
}

/**
* run_command - executes the command based on the given array
* @ls: the given array
* Return: 0 on success
*/

int run_command(char **ls)
{
	pid_t pid = fork();

	if (pid == -1)
	{
		perror("Failed to fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		execve(ls[0], ls, NULL);
		perror("Failed to execute command");
		exit(EXIT_FAILURE);
	}
	else
		wait(NULL);

	return (0);
}

/**
* main - entry point
* Return: 0 on success
*/

int main(void)
{
	char *input = NULL;
	size_t size = 0;

	while (true)
	{
		char **ls = NULL;

		print_string("$ ");
		if (getline(&input, &size, stdin) == -1)
		{
			exit(EXIT_FAILURE);
		}
		input[_strcspn(input, "\n")] = '\0';

		ls = parse_input(input);
		run_command(ls);

		free(ls);
	}

	free(input);
	return (0);
}

