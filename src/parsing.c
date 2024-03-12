/*
** EPITECH PROJECT, 2024
** feed-the-beast
** File description:
** parsing
*/

#include "strace.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

static int parse_s_flag(char **args, char **env)
{
    args++;
    if (args[0] == NULL){
        return send_err("option requires an argument -- 's'");
    }
    return do_strace(args, env, S_FORMAT);
}

static int parse_p_flag(char *pid)
{
    int process = 0;

    if (pid == NULL){
        return send_err("option requires an argument -- 'p'");
    }
    process = atoi(pid);
    if (process == 0 && pid[0] != '0'){
        printf("handle_process(process)\n");
        return OK;
    }
    return send_err_arg("Invalid process id: ", pid);
}

int parse_args(char **args, char **env)
{
    if (strcmp(args[0], "-s") == OK){
        return parse_s_flag(args, env);
    }
    if (strcmp(args[0], "-p") == OK){
        return parse_p_flag(args[1]);
    }
    return do_strace(args, env, HEXA_FORMAT);
}

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
