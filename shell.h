#ifndef SHELL_H
#define SHELL_H

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include<stdbool.h>
#include <sys/wait.h>

int put_char(char c);
void print_string(char *str);
int _strlen(char *s);
size_t _strcspn(const char *s1, const char *s2);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
char *_strtok(char *str, const char *delim);

#endif
