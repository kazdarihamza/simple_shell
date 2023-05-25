#ifndef SHELL_H
#define SHELL_H
#include <stddef.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <sys/wait.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <signal.h>
#include <limits.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdint.h>

#define MAX_WORDS 1024
#define BUFFER_SIZE 1024
#define MAX_WORD 100
#define MAX_COMMAND_LENGTH 260
/**
 * enum MemoryAllocationType - checks if it's stack or malloc
 * @STACK: stack
 * @MALLOC: malloc
 */
enum MemoryAllocationType
{
	STACK,
	MALLOC
};

/*the main functions*/
int run_command(char **ls, char **env, char *input);
void parse_input(char *input, char **ls);
void process_input_words(char *input, char **ls, int word_count);
void execute_echo_command(char **ls, char **env);
void execute_cd_command(char **ls, char **env);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
void execute_external_command(char **ls, char **env, char *input);


/*the main fucnions*/

extern char **environ;


int put_char(const char c);
void print_string(const char *str);
int _strlen(const char *str);
size_t _strcspn(const char *s1, const char *s2);
char *_strcat(char *dest, const char *src);
char *_strcpy(char *dest, const char *src);
char *_strtok(char *str, const char *delim);
int _isspace(int c);
int _atoi(char *s);
char *_getenv(const char *name, char **environ);
int _strcmp(char *str1, char *str2);
void cut_string(char *str, char ch, char *result);
void cut_string_two(char *str, char ch, char *result);
int _setenv(char *name, char *value, int overwrite, char **environ);
int _strncmp(const char *str1, const char *str2, size_t n);
int _unsetenv(const char *name, char **environ);
void *_realloc(void *ptr, size_t size);
char *_strncpy(char *dest, const char *src, size_t n);
void ctrlc_avoid(int signl);
void print_buff(char *string, int fd);
char *_strchr(const char *str, int character);
void free_all(char *input, char **args);
void execute_setenv_command(char **ls, char **env);
void execute_unsetenv_command(char **ls, char **env);
enum MemoryAllocationType checkMemoryAllocation(void *ptr);
size_t _strspn(const char *str, const char *charset);
void handle_exit_command(char **args, char *input, char *first);
void *_memcpy(void *dest, const void *src, size_t n);
size_t malloc_usable_size(const void *ptr);
int testStringInFolder(char *folderPath, char *searchString);
void handle_commands(char **cmd, char **env, char *input);

#endif
