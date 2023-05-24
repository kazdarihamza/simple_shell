#include "shell.h"

/**
 * checkMemoryAllocation - checks if it's stack or malloc
 * @ptr:string to check
 * Return: malloc or stack
 */
enum MemoryAllocationType checkMemoryAllocation(void *ptr)
{

	void *temp = malloc(1);
	ptrdiff_t diff = (char *)ptr - (char *)temp;

	if (ptr == NULL)
		return (STACK);
	if (temp == NULL)
		return (STACK);
	free(temp);

	if (diff >= 0)
		return (STACK);
	else
		return (MALLOC);
}

/**
 * _unsetenv - remove environment
 * @name: variable to remove its env
 * @env: environment
 * Return: 0 (success)
 */
int _unsetenv(const char *name, char **env)
{
	int nameLength = _strlen(name);
	int i = 0, j, count = 0;

	while (env[i] != NULL)
	{
		if (_strncmp(env[i], name, nameLength) == 0
			&& env[i][nameLength] == '=')
		{
			j = i;
			count = 1;
			while (env[j] != NULL)
			{
				env[j] = env[j + 1];
				j++;
			}
			return (0);
		}
		i++;
	}
	if (count == 0)
	{
		return (-1);
	}
	else
		return (0);
}

/**
 * _setenv - set environment
 * @name: variable to set its env
 * @overwrite: 0 if doesnt exists, 1 if it already exists
 * @value: the environment
 * @env: environment
 * Return: 0 (success)
 */
int _setenv(char *name, char *value, int overwrite, char **env)
{
	int i = 0, len = 0, count = 0;
	char *new_var;

	if (!name || !value)
		return (-1);

	while (env[i])
	{
		len = _strlen(name);
		if (strncmp(env[i], name, len) == 0)
		{
			if (overwrite)
			{
				new_var = malloc(_strlen(name) + _strlen(value) + 2);
				_strcpy(new_var, name);
				_strcat(new_var, "=");
				_strcat(new_var, value);
				env[i] = new_var;
				count = 0;
				free(new_var);
				return (0);
			}
		}
		i++;
	}
	if (count == 0)
	{
		new_var = malloc(_strlen(name) + _strlen(value) + 2);
		_strcpy(new_var, name);
		_strcat(new_var, "=");
		_strcat(new_var, value);
		env[i] = new_var;
	}
	return (0);
}
