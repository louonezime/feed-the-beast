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
#include <string.h>

static syscall_t retrieve_element(int opcode)
{
    for (int i = 0; i < NB_SYSCALLS; i++){
        if (table[i].op_code == opcode){
            return table[i];
        }
    }
}

static bool syscall_exist(int opcode)
{
    for (int i = 0; i < NB_SYSCALLS; i++){
        if (table[i].op_code == opcode){
            return true;
        }
    }
    return false;
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
    syscall_t retrieved_syscall;

    if (is_syscall){
        retrieved_syscall = retrieve_element(regs->rax);
        if (retrieved_syscall.return_val == VOID){
            printf(" = ?\n");
        } else {
            ptrace(PTRACE_GETREGS, followed_pid, NULL, regs);
            printf(" = %#x\n", regs->rax);
        }
    }
}

static void process_syscall(bool mode, struct user_regs_struct *regs,
    bool *is_syscall)
{
    syscall_t retrieved_syscall;

    if (syscall_exist(regs->rax)) {
        retrieved_syscall = retrieve_element(regs->rax);
        printf("%s", retrieved_syscall.name);
        stock_args(mode, regs, &retrieved_syscall);
        *is_syscall = true;
    } else {
        *is_syscall = false;
        printf("syscall_%#x(%#x, %#x, %#x, %#x, %#x, %#x) = -1 ENOSYS "
            "(Function not implemented)\n", regs->rdi, regs->rsi, regs->rdx,
            regs->r10, regs->r8, regs->r9);
    }
}

void process(pid_t followed_pid, bool mode)
{
    int status = 0;
    struct user_regs_struct regs;
    bool is_syscall = false;

    wait4(followed_pid, &status, 0, NULL);
    while (WIFSTOPPED(status)) {
        ptrace(PTRACE_GETREGS, followed_pid, NULL, &regs);
        if (is_instruction_syscall(followed_pid, &regs))
            process_syscall(mode, &regs, &is_syscall);
        else
            is_syscall = false;
        ptrace(PTRACE_SINGLESTEP, followed_pid, 0, 0);
        wait4(followed_pid, &status, 0, NULL);
        display_syscall_return(is_syscall, followed_pid, &regs);
    }
    ptrace(PTRACE_DETACH, followed_pid, 0, 0);
    if (WIFEXITED(status)){
        printf("+++ exited with %d +++\n", WEXITSTATUS(status));
    }
}

int binary_process(char **argv, char **env, bool mode)
{
    pid_t child_pid = 0;

    child_pid = fork();
    if (child_pid < OK){
        perror("strace: fork");
        return ERROR;
    }
    if (child_pid == OK){
        if (ptrace(PT_TRACE_ME, 0, 0, 0) < OK){
            return send_ptrace_err("trace", "PT_TRACE_ME", 0);
        }
        execve(argv[0], argv, env);
    } else {
        process(child_pid, mode);
    }
    return OK;
}
