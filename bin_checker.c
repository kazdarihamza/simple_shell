#include "shell.h"

/**
 * testStringInFolder - tests if the input is in the bin folder
 * @folderPath: bin path
 * @searchString: the cmd
 * Return: 0 success
 */

int testStringInFolder(char *folderPath, char *searchString)
{
	DIR *directory = opendir(folderPath);
	struct dirent *entry;

	searchString = searchString + 5;
	if (directory == NULL)
		return (1);
	while ((entry = readdir(directory)) != NULL)
	{
		if (_strcmp(entry->d_name, searchString) == 0)
		{
			closedir(directory);
			return (1);
		}
	}

	closedir(directory);
	return (0);
}

/**
 * handle_commands - handle command not found
 * @cmd: command
 * @env: environ
 * @input: the input
 */

void handle_commands(char **cmd, char **env, char *input)
{
	if (testStringInFolder("/bin/", cmd[0]))
	{
		execute_external_command(cmd, env, input);
		if ((isatty(STDIN_FILENO)))
			free(cmd[0]);
	}
	else if (_strlen(cmd[0]) > 5)
	{
		print_string(cmd[0] + 5);
		print_string(": command not found.\n");
		if ((isatty(STDIN_FILENO)))
			free(cmd[0]);
	}
}
