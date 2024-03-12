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
#include <stdbool.h>

static syscall_t retrieve_element(int opcode)
{
    for (int i = 0; i < NB_SYSCALLS; i++)
        if (table[i].op_code == opcode)
            return table[i];
}

static bool syscall_exist(int opcode)
{
    for (int i = 0; i < NB_SYSCALLS; i++)
        if (table[i].op_code == opcode)
            return true;
    return false;
}

static void display_arg(pid_t followed_pid, int format,
    unsigned long register_value, bool display_comma)
{
    if (display_comma)
        printf(", ");
    printf("%#x", register_value);
}

static void display_args(pid_t followed_pid, struct user_regs_struct *regs,
    syscall_t *syscall_repr)
{
    printf("(");
    if (syscall_repr->param1 > 0)
        display_arg(followed_pid, syscall_repr->param1, regs->rdi, false);
    if (syscall_repr->param2 > 0)
        display_arg(followed_pid, syscall_repr->param2, regs->rsi, true);
    if (syscall_repr->param3 > 0)
        display_arg(followed_pid, syscall_repr->param3, regs->rdx, true);
    if (syscall_repr->param4 > 0)
        display_arg(followed_pid, syscall_repr->param4, regs->r10, true);
    if (syscall_repr->param5 > 0)
        display_arg(followed_pid, syscall_repr->param5, regs->r8, true);
    if (syscall_repr->param6 > 0)
        display_arg(followed_pid, syscall_repr->param6, regs->r9, true);
    printf(")");
}

static bool is_instruction_syscall(pid_t followed_pid,
    struct user_regs_struct *regs)
{
    long op_code = ptrace(PTRACE_PEEKTEXT, followed_pid, regs->rip, NULL);

    return ((op_code & 0xffff) == 0x050f);
}

static void display_syscall_return(bool is_syscall, pid_t followed_pid,
    struct user_regs_struct *regs)
{
    if (is_syscall) {
        ptrace(PTRACE_GETREGS, followed_pid, NULL, regs);
        printf(" = %#x\n", regs->rax);
    }
}

static void process_syscall(pid_t followed_pid, struct user_regs_struct *regs,
    bool *is_syscall)
{
    syscall_t retrieved_syscall = retrieve_element(regs->rax);

    printf("%s", retrieved_syscall.name);
    display_args(followed_pid, regs, &retrieved_syscall);
    *is_syscall = true;
}

static void process(pid_t followed_pid)
{
    int status = 0;
    struct user_regs_struct regs;
    bool is_syscall = false;

    wait4(followed_pid, &status, 0, NULL);
    while (WIFSTOPPED(status)) {
        ptrace(PTRACE_GETREGS, followed_pid, NULL, &regs);
        if (is_instruction_syscall(followed_pid, &regs) &&
        syscall_exist(regs.rax))
            process_syscall(followed_pid, &regs, &is_syscall);
        else
            is_syscall = false;
        ptrace(PTRACE_SINGLESTEP, followed_pid, 0, 0);
        wait4(followed_pid, &status, 0, NULL);
        display_syscall_return(is_syscall, followed_pid, &regs);
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
