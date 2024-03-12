/*
** EPITECH PROJECT, 2024
** feed-the-beast
** File description:
** util_messages
*/

#include "strace.h"

#include <stdio.h>

int send_err(const char *error)
{
    fprintf(stderr, "strace: %s.\n", error);
    return ERROR;
}

int send_err_arg(const char *error, char *arg)
{
    fprintf(stderr, "strace: %s: '%s'.\n", error, arg);
    return ERROR;
}
