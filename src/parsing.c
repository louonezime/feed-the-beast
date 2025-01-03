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
#include <sys/ptrace.h>
#include <sys/wait.h>

static int parse_p_flag(char *pid, bool mode, char **args)
{
    pid_t processed_id = 0;

    if (pid == NULL){
        return send_err("option requires an argument -- 'p'");
    }
    processed_id = atoi(pid);
    if (processed_id == ATOI_ERROR && pid[0] != '0'){
        return send_err_arg("Invalid process id: ", pid);
    }
    if (args[2] != NULL){
        if (strcmp(args[2], "-s") == OK){
            return attach_process_id(processed_id, HEXA_FORMAT);
        }
    }
    return attach_process_id(processed_id, mode);
}

static int parse_s_flag(char **args, char **env)
{
    args++;
    if (args[0] == NULL){
        return send_err("option requires an argument -- 's'");
    }
    if (strcmp(args[0], "-p") == OK){
        return parse_p_flag(args[1], S_FORMAT, args);
    }
    return do_strace(args, env, S_FORMAT);
}

int parse_args(char **args, char **env)
{
    if (strcmp(args[0], "-s") == OK){
        return parse_s_flag(args, env);
    }
    if (strcmp(args[0], "-p") == OK){
        return parse_p_flag(args[1], HEXA_FORMAT, args);
    }
    if (strcmp(args[0], "-sp") == OK || strcmp(args[0], "-ps") == OK){
        return parse_p_flag(args[1], S_FORMAT, args);
    }
    return do_strace(args, env, HEXA_FORMAT);
}
