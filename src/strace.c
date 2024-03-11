/*
** EPITECH PROJECT, 2024
** feed-the-beast
** File description:
** strace
*/

#include "strace.h"
#include "syscall.h"
#include <sys/user.h>
#include <sys/ptrace.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stddef.h>

static syscall_t retrieve_element(int opcode)
{
    for (int i = 0; i < NB_SYSCALLS; i++)
        if (table[i].op_code == opcode)
            return table[i];
}

static void process(pid_t followed_pid)
{
    int status = 0;
    long instruction = 0;
    long syscall = 0;
    syscall_t retrieved_syscall;
    struct user_regs_struct regs;

    wait4(followed_pid, &status, 0, NULL);
    while (WIFSTOPPED(status)) {
        ptrace(PTRACE_GETREGS, followed_pid, NULL, &regs);
        instruction = ptrace(PTRACE_PEEKTEXT, followed_pid, regs.rip, NULL);
        syscall = ptrace(PTRACE_PEEKTEXT, followed_pid, regs.rax, NULL);
        if ((instruction & 0xffff) == 0x050f) {
            retrieved_syscall = retrieve_element(regs.rax);
            printf("%s\n", retrieved_syscall.name);
        }
        ptrace(PTRACE_SINGLESTEP, followed_pid, 0, 0);
        wait4(followed_pid, &status, 0, NULL);
    }
    ptrace(PTRACE_DETACH, followed_pid, 0, 0);
}

int binary_process(int argc, char **argv, char **env)
{
    pid_t child_pid = 0;

    if (env == NULL)
        return ERROR;
    child_pid = fork();
    if (child_pid < 0)
        return ERROR;
    if (child_pid == 0) {
        if (ptrace(PT_TRACE_ME, 0, 0, 0) < 0)
            return ERROR;
        execve(argv[1], &argv[1], env);
    } else {
        process(child_pid);
    }
    return OK;
}
