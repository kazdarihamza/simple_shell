#include "shell.h"
/**
 * run_command - executes the command based on the given array
 * @ls: the given array
 * @env: the environment variables array
 * Return: 0 on success
 */
int run_command(char **ls, char **env)
{
		int i = 0;

	while (env[i] != NULL)
		i++;
	if (ls[0] == NULL)
		return (0);
	if (_strcmp(ls[0], "/bin/echo") == 0)
	{
		execute_echo_command(ls, env);
		return (0);
	}
	if (strcmp(ls[0], "cd") == 0)
	{
		execute_cd_command(ls, env);
		return (0);
	}
	else if (_strcmp(ls[0], "/bin/setenv") == 0)
	{
		execute_setenv_command(ls, env);
	}
	else if (_strcmp(ls[0], "/bin/unsetenv") == 0)
	{
		execute_unsetenv_command(ls, env);
	}
	else if (_strcmp(ls[0], "/bin/env") == 0)
	{
		i--;
		while (i >= 0)
		{
			print_string(env[i]);
			print_string("\n");
			i--;
		}
	}
	else
		execute_external_command(ls, env);
	return (0);
}

/**
 * execute_setenv_command - executes the command based on the given array
 * @ls: the given array
 * @env: the environment variables array
 */

void execute_setenv_command(char **ls, char **env)
{
	if (ls[1] != NULL && ls[2] != NULL)
	{
		if (_setenv(ls[1], ls[2], 1, env) == -1)
			perror(ls[0]);
	}
	else
	{
		print_string(ls[1]);
		print_string(": not enough arguments\n");
	}
}

/**
 * execute_unsetenv_command - executes the command based on the given array
 * @ls: the given array
 * @env: the environment variables array
 */
void execute_unsetenv_command(char **ls, char **env)
{
	if (ls[1] != NULL && ls[2] == NULL)
	{
		if (_unsetenv(ls[1], env) == -1)
			perror(ls[0]);
	}

	else
	{
		print_string(ls[1]);
		print_string(": too many arguments\n");
	}
}

/**
 * execute_echo_command - executes the echo command with environment variables
 * @ls: the command arguments array
 * @env: environment
 */
void execute_echo_command(char **ls, char **env)
{
	int i;
	char *env_var_value = NULL;

	for (i = 1; ls[i] != NULL; i++)
	{
		char *arg = ls[i];

		if (arg[0] == '$' && strcmp(arg, "$PWD") == 0)
		{
			char cwd[PATH_MAX];

			if (getcwd(cwd, sizeof(cwd)) != NULL)
				print_string(cwd);
		}
		else if (arg[0] == '$')
		{
			env_var_value = _getenv(arg + 1, env);
			if (env_var_value != NULL)
				print_string(env_var_value);
		}
		else if (arg[0] == '~')
		{
			env_var_value = _getenv("HOME", env);
			if (env_var_value != NULL)
				print_string(env_var_value);
		}
		else
		{
			cut_string_two(arg, '"', arg);
			cut_string_two(arg, '\'', arg);
			print_string(arg);
		}
		if (ls[i + 1] != NULL)
			print_string(" ");
	}
	print_string("\n");
}

/**
 * execute_cd_command - executes the cd command with directory change
 * @ls: the command arguments array
 * @env: environment
 */
void execute_cd_command(char **ls, char **env)
{
	static char previous_directory[PATH_MAX];
	char *arg = ls[1];
	char *env_var_value;

	if (arg == NULL)
	{
	getcwd(previous_directory, sizeof(previous_directory));
	chdir(_getenv("HOME", env));
	}
	else if (_strcmp(arg, "-") == 0)
	{
		if (previous_directory[0] != '\0')
		{
			print_string(previous_directory);
			print_string("\n");
			chdir(previous_directory);
		}
	}
	else
	{
		if (getcwd(previous_directory, sizeof(previous_directory)) == NULL)
		{
			perror("getcwd");
			return;
		}
		if (chdir(arg) != 0)
		{
			if (arg[0] == '$')
			{
				env_var_value = _getenv(arg + 1, env);
				if (env_var_value != NULL)
					chdir(env_var_value);
			}
			else if (arg[0] == '~')
				chdir(_getenv("HOME", env));
			if (access(arg, F_OK) != -1)
				perror(arg);
		}
	}
}

