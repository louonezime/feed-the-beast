/*
** EPITECH PROJECT, 2024
** feed-the-beast
** File description:
** parameters
*/

#include "strace.h"
#include "syscall.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/user.h>
#include <sys/ptrace.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

static void display_char(char character)
{
    if (character == '\n')
        fprintf(stderr, "\\n");
    if (character == '\r')
        fprintf(stderr, "\\r");
    if (character == '\b')
        fprintf(stderr, "\\b");
    if (character == '\a')
        fprintf(stderr, "\\a");
    if (character == '\t')
        fprintf(stderr, "\\t");
    if (character == '\f')
        fprintf(stderr, "\\f");
    fprintf(stderr, "%c", character);
}

static void display_string(unsigned long register_value, pid_t pid)
{
    char character = 1;
    int max = 32;

    fprintf(stderr, "\"");
    while (character) {
        if (max <= 0) {
            fprintf(stderr, "\"...");
            return;
        }
        character = ptrace(PTRACE_PEEKTEXT, pid, register_value, NULL);
        display_char(character);
        register_value++;
        max--;
    }
    fprintf(stderr, "\"");
}

void display_param(bool mode, int format, long long register_value,
    pid_t followed_pid)
{
    if (mode == HEXA_FORMAT) {
        fprintf(stderr, "%#x", register_value);
        return;
    }
    if (format == STRING)
        display_string(register_value, followed_pid);
    if (format == NUM || format == UNSIGNED)
        fprintf(stderr, "%d", register_value);
    if (format != STRING && format != NUM && format != UNSIGNED)
        fprintf(stderr, "%#lx", register_value);
}

static void display_next_param(bool mode, int format, long long register_value,
    pid_t pid)
{
    fprintf(stderr, ", ");
    display_param(mode, format, register_value, pid);
}

void display_args(bool mode, struct user_regs_struct *regs,
    syscall_t *syscall_repr, pid_t pid)
{
    fprintf(stderr, "(");
    if (syscall_repr->param1 > 0)
        display_param(mode, syscall_repr->param1, regs->rdi, pid);
    if (syscall_repr->param2 > 0)
        display_next_param(mode, syscall_repr->param2, regs->rsi, pid);
    if (syscall_repr->param3 > 0)
        display_next_param(mode, syscall_repr->param3, regs->rdx, pid);
    if (syscall_repr->param4 > 0)
        display_next_param(mode, syscall_repr->param4, regs->r10, pid);
    if (syscall_repr->param5 > 0)
        display_next_param(mode, syscall_repr->param5, regs->r8, pid);
    if (syscall_repr->param6 > 0)
        display_next_param(mode, syscall_repr->param6, regs->r9, pid);
    fprintf(stderr, ")");
}
