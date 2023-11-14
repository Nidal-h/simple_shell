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

/* prompt */
void prompt(void);
/* get line */
void *get_line(void);

/* get input */
char *get_input(void);
void free_last_input(void);

/* signal handler */
void handle_sigint(int signal);
void handle_sigquit(int signal);
void handle_sigstp(int signal);


/* built-in funcions */
int check_for_builtin(char **arguments);
int execute_buitlin(char *cmd, char **arguments);
void shell_help(void);
void shell_exit(char **arguments);
void shell_cd(char **arguments);
int shell_setenv(char **arguments);
int shell_unsetenv(char **arguments);
int shell_env(void);
int shell_clear(char **arguments);


/* find in path */
char *find_in_path(char *cmd);

/* execute */
int execute(char **arguments);

/* parser */
char **tokenize(char *string, const char *delimeter);
char **tokenize_input(char *input);

/* get env */
char *_getenv(const char *n);


/* get path */
char *get_path(void);


/* utils funcs1 */
int _strlen(const char *string);
int _strcmp(const char *string1, const char *string2);
int _strncmp(const char *string1, const char *string2, size_t m);
char *_strstr(char *haystack, char *needle);
char *_strchr(char *string, char ch);


/* utils funcs3 */
int _atoi(const char *string);
char *_memset(char *s, char byte, unsigned int number);
char *_memcpy(char *destination, char *source, unsigned int n);
void *_realloc(void *pointer, unsigned int old_sz, unsigned int new_sz);
void *_calloc(unsigned int nmemb, unsigned int size);



/* free */
void free_error(char **argp, char *arguments);
void free_tokens(char **pointer);
void free_path(void);


/* error */
void _puts(char *string);
void _puterror(char *error);



/* utils_funcs2 */
char *_strcpy(char *destination, char *source);
char *_strcat(char *destination, const char *source);
char *_strdup(const char *string);
int _putchar(char ch);
unsigned int _strspn(char *s, char *acc);


#endif
