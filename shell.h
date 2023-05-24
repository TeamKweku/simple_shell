#ifndef SHELL_H
#define SHELL_H

#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <sys/types.h>

#define BUFSIZE 1024
#define VAR_ERROR "variable does not exist\n"
#define ARGS_ERROR "check the number of arguments passed\n"

extern char **environ;

/* String functions */
int _strlen(const char *s);
char *_strcpy(char *dest, const char *src);
int _strcmp(char *str1, const char *str2);
char *_strdup(const char *str);
char *_strcat(char *dest, const char *src);
int _strlen(const char *s);
int _putchar(char c);
void _puts(char *str);

/* environment functions */
void print_env(void);
char **new_env(void);
char *getenv_value(const char *str);
int set_env_var(char **arguments, char **env);
int unset_env_var(char **arguments, char **env);

/* memory functions */
void *_realloc(void *ptr, size_t old_size, size_t new_size);

/* execution functions */
int handle_builtin_cmds(char **argv, char **env);
void execute_cmds(char **argv);

/* directory functions */
int update_pwd(char **environ, char *curr_dir);
void cd(char **argv, char **env);

/* string tokenizer function */
char **tokenizer(char *string, char *delim);

/* free utilities */
void free_memory(char **argv, char **env);
void free_args(char **argv);

/* environment functions */
int set_env_var_val(char *var, char *value, char **environ);

int non_interactive(char *command);

#endif
