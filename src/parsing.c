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

static int parse_s_flag(char **args, char **env)
{
    args++;
    if (args[0] == NULL){
        return send_err("option requires an argument -- 's'");
    }
    return do_strace(args, env, S_FORMAT);
}

static bool attach_process_id(pid_t pid)
{
    int status = 0;

    if (ptrace(PTRACE_SEIZE, pid, NULL, NULL) < OK) {
        fprintf(stderr, "strace: attach: ptrace(PTRACE_SEIZE, %d): ", pid);
        perror("");
        return false;
    }
    waitpid(pid, &status, 0);
    process(pid);
    return true;
}

static int parse_p_flag(char *pid)
{
    pid_t processed_id = 0;

    if (pid == NULL){
        return send_err("option requires an argument -- 'p'");
    }
    processed_id = atoi(pid);
    if (processed_id == 0 && pid[0] != '0'){
        return send_err_arg("Invalid process id: ", pid);
    }
    if (!attach_process_id(processed_id)){
        return ERROR;
    }
    return OK;
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
