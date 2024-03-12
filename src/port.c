/*
** EPITECH PROJECT, 2024
** feed-the-beast
** File description:
** port
*/

#include "strace.h"

#include <sys/ptrace.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>

bool attach_process_id(pid_t pid, bool mode)
{
    int status = 0;

    if (ptrace(PTRACE_SEIZE, pid, NULL, NULL) < OK) {
        send_ptrace_err("attach", "PTRACE_SEIZE", pid);
        return false;
    }
    waitpid(pid, &status, 0);
    if (mode == HEXA_FORMAT){
        process(pid);
    }
    if (mode == S_FORMAT){
        process(pid);
    }
    return true;
}
