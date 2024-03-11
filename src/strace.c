/*
** EPITECH PROJECT, 2024
** feed-the-beast
** File description:
** strace
*/

#include "strace.h"

#include <stdio.h>
#include <sys/stat.h>
#include <stdbool.h>

static bool check_env(char **arg, char **env)
{
    return true;
}

static bool preliminaries(char **arg, char **env)
{
    struct stat statis;

    if (stat(arg[0], &statis) < OK){
        fprintf(stderr, "strace: Can't stat '%s': ", arg[0]);
        perror("");
        return false;
    }
    if (!check_env(arg, env)){
        return false;
    }
    return true;
}

int do_strace(char **arg, char **env, bool mode)
{
    if (!preliminaries(arg, env)){
        return ERROR;
    }
    if (mode == HEXA_FORMAT){
        printf("return function that handles hexa\n");
    }
    if (mode == S_FORMAT){
        printf("return function that handles s flag\n");
    }
    return ERROR;
}
