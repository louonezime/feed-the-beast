/*
** EPITECH PROJECT, 2024
** feed-the-beast
** File description:
** strace
*/

#include "strace.h"

#include <stdio.h>
#include <sys/stat.h>

static int preliminaries(const char *path)
{
    struct stat statis;

    if (stat(path, &statis) < OK){
        fprintf(stderr, "strace: Can't stat '%s`: ", path);
        perror("");
        return ERROR;
    }
    return OK;
}

int do_strace(const char *arg)
{
    if (preliminaries(arg) == ERROR){
        return ERROR;
    }
    return OK;
}
