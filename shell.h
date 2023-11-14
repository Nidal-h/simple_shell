#ifndef _SHELL_H_
#define _SHELL_H_
#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>
#include <stdarg.h>
#include <ctype.h>

/*macros*/
#define PATH_MAX_LENGTH 4096
#define PATH_SEPARATOR ":"
#define PROMPT "$ "
#define MAX_TOKENS 1024
#define BUFFER_SIZE 1024

/* prompt.c */
void prompt(void);

/* get_input.c */
char *get_input(void);
void free_last_input(void);
/* get_line.c*/
void *get_line(void);

/* built-in funcs */
int check_for_builtin(char **arguments);
int execute_buitlin(char *cmd, char **arguments);
void shell_help(void);
void shell_exit(char **arguments);
void shell_cd(char **arguments);
int shell_setenv(char **arguments);
int shell_unsetenv(char **arguments);
int shell_env(void);
int shell_clear(char **arguments);

/* signal_handler.c */
void handle_sigint(int signal);
void handle_sigquit(int signal);
void handle_sigstp(int signal);

/* execute.c */
int execute(char **arguments);

/* parser.c */
char **tokenize(char *string, const char *delimeter);
char **tokenize_input(char *input);

/* get_env.c */
char *_getenv(const char *n);

/* get_path.c */
char *get_path(void);

/* find_in_path.c */
char *find_in_path(char *cmd);

/* free.c */
void free_error(char **argp, char *arguments);
void free_tokens(char **pointer);
void free_path(void);

/* error.c */
void _puts(char *string);
void _puterror(char *error);

/* utils_funcs1.c */
int _strlen(const char *string);
int _strcmp(const char *string1, const char *string2);
int _strncmp(const char *string1, const char *string2, size_t m);
char *_strstr(char *haystack, char *needle);
char *_strchr(char *string, char ch);

/* utils_funcs2.c */
char *_strcpy(char *destination, char *source);
char *_strcat(char *destination, const char *source);
char *_strdup(const char *string);
int _putchar(char ch);
unsigned int _strspn(char *s, char *acc);

/* utils_funcs3.c */
int _atoi(const char *string);
char *_memset(char *s, char byte, unsigned int number);
char *_memcpy(char *destination, char *source, unsigned int n);
void *_realloc(void *pointer, unsigned int old_sz, unsigned int new_sz);
void *_calloc(unsigned int nmemb, unsigned int size);

#endif
