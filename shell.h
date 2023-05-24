#ifndef SHELL_H
#define SHELL_H

#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <sys/types.h>



/* String functions */
int _strlen(const char *s);
char *_strcpy(char *dest, const char *src);
int _strcmp(char *str1, const char *str2);
char *_strdup(const char *str);
char *_strcat(char *dest, const char *src);
int _strlen(const char *s);
int _putchar(char c);
void _puts(char *str);


/* memory functions */
void *_realloc(void *ptr, size_t old_size, size_t new_size);

/* execution functions */
int handle_builtin_cmds(char **argv, char **env);
void execute_cmds(char **argv);

/* directory functions */
int update_pwd(char **environ, char *curr_dir);
void cd(char **argv, char **env);


#endif
