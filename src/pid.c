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
    if (ptrace(PTRACE_INTERRUPT, pid, NULL, NULL) < OK) {
        fprintf(stderr, "strace: attach: ptrace(PTRACE_INTERRUPT, %d): ", pid);
        perror("");
        ptrace(PTRACE_DETACH, pid, 0, 0);
        return false;
    }
    if (mode == HEXA_FORMAT){
        process(pid, mode);
    }
    if (mode == S_FORMAT){
        process(pid, mode);
    }
    return true;
}
