#include "shell.h"
/**
 * parse_input - a fucntion that cuts a string and put it as an array
 * @input: the string
 * @ls: the double pointer
 * Return: a double demintional pointer
 */
void parse_input(char *input, char **ls)
{
	int word_count = 0;

	cut_string(input, ' ', input);
	process_input_words(input, ls, word_count);
}

/**
 * process_input_words - a function that turn turn input into a double pointer
 * @input: the string
 * @ls: the double pointer
 * @word_count: an int
 * Return: word_count or NULL
 */
void process_input_words(char *input, char **ls, int word_count)
{
	char bin[] = "/bin/", *word, *command = NULL, *end;

	if (_strlen(input) == (int)_strspn(input, " ") || input == NULL)
		return;
	while (*input == ' ')
		input++;
	end = input + _strlen(input) - 1;
	while (end > input && *end == ' ')
		end--;
	*(end + 1) = '\0';
	word = _strtok(input, " ");
	while (word != NULL && word_count < MAX_WORDS)
	{
		if (word_count == 0 && _strcmp(word, "cd") == 0)
			ls[word_count++] = word;
		else if (word_count > 0 && _strcmp(ls[0], "cd") == 0)
		{
			ls[word_count++] = word;
			break;
		}
		else if (word_count == 0 && word[0] >= 'a' && word[0] <= 'z')
		{
			command = malloc(_strlen(bin) + _strlen(word) + 1);
			if (command == NULL)
			{
				perror("malloc");
				exit(EXIT_FAILURE);
			}
			_strcpy(command, bin);
			_strcat(command, word);
			ls[word_count++] = command;
		}
		else
			ls[word_count++] = word;
		word = _strtok(NULL, " ");
	}
	ls[word_count] = NULL;
}

/**
 * handle_exit_command - handle exit
 * @args: arguments
 * @input: input
 * @first: wlh ma3reft
 */
void handle_exit_command(char **args, char *input, char *first)
{
	int status;

	if (args[1] == NULL)
	{
		if (!(isatty(STDIN_FILENO)))
			free(input);
		free(args[0]);
		exit(0);
	}
	else
	{
		status = _atoi(args[1]);

		if (status < 0 || status == 0)
		{
			write(2, first, _strlen(first));
			write(2, ": 1: exit: Illegal number: ",
				_strlen(": 1: exit: Illegal number: "));
			write(2, args[1], _strlen(args[1]));
			write(2, "\n", 1);
			if (!(isatty(STDIN_FILENO)))
				free(input);
			free(args[0]);
			exit(2);
		}
		if (!(isatty(STDIN_FILENO)))
			free(input);
		free(args[0]);
		exit(status);
	}
}
