#ifndef SHELL_H
#define SHELL_H

#include <string.h>
#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <sys/types.h>


#define PATH_SIZE 2024
#define BUFFSIZE 1024
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

int count_words(char *str);

/* environment functions */
int print_env(void);
char *getenv_value(void);

/* path functions */
char *find_path(char **arguments);


/* display prompt */
void display_prompt(void);

char *capture_user_input(void);

/* print error */
void print_error_msgs(char *shell, int exit_status, char *prog);

/* memory functions */
void *_realloc(void *ptr, size_t old_size, size_t new_size);

/* execution functions */
int handle_builtin_cmds(char **args, int *builtin_exec);
int execute_cmds(char *cmd_path, char **argv, char **environ);
char *find_exec(char **path_list, char *filename,  int *found);
char **get_paths(void);
char **get_main_path(void);


/* directory functions */
int cd(char **arr);

/* string tokenizer function */
char **tokenizer(char **path, int exit_status);

/* free utilities */
void free_memory(char **argv, char **env);
void free_args(char **argv);

/* environment functions */
int print_env(void);
char *getenv_value();

void handle_exit(char *command, char **path_list, char **args, char *exit_status, int code);

void signal_handler(int signum);
#endif
