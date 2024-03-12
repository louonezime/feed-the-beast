/*
** EPITECH PROJECT, 2024
** feed-the-beast
** File description:
** strace
*/

#ifndef STRACE_H_
    #define STRACE_H_

    #include <stdbool.h>

    #define OK 0
    #define ERROR 84

    #define HELP_AC 2
    #define ERROR_AC 1

    #define PATHS_SEPARATOR ':'

static const bool S_FORMAT = true;
static const bool HEXA_FORMAT = false;

/* Parsing */
int parse_args(char **av, char **env);
int send_err(const char *error);
int send_err_arg(const char *error, char *arg);

/* strace */
int do_strace(char **arg, char **env, bool mode);

/* util library */
char **my_str_to_word_array(char *str, char separator);
char *my_strcat(char *dest, char const *src);
int nb_of_words(char **array);
void free_array(char **array);

#endif /* !STRACE_H_ */
