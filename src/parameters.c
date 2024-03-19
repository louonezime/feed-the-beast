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
        printf("\\n");
    if (character == '\r')
        printf("\\r");
    if (character == '\b')
        printf("\\b");
    if (character == '\a')
        printf("\\a");
    if (character == '\t')
        printf("\\t");
    if (character == '\f')
        printf("\\f");
    printf("%c", character);
}

static void display_string(unsigned long register_value, pid_t followed_pid)
{
    char character = 1;
    int max = 32;

    printf("\"");
    while (character) {
        if (max <= 0) {
            printf("\"...");
            return;
        }
        character = ptrace(PTRACE_PEEKTEXT, followed_pid, register_value, NULL);
        display_char(character);
        register_value++;
        max--;
    }
    printf("\"");
}

void display_param(bool mode, int format, long long register_value,
    pid_t followed_pid)
{
    if (mode == HEXA_FORMAT) {
        printf("%#x", register_value);
        return;
    }
    if (format == STRING)
        display_string(register_value, followed_pid);
    if (format == NUM)
        printf("%d", register_value);
    if (format != STRING && format != NUM)
        printf("%#x", register_value);
}

void display_args(bool mode, struct user_regs_struct *regs,
    syscall_t *syscall_repr, pid_t followed_pid)
{
    printf("(");
    if (syscall_repr->param1 > 0)
        display_param(mode, syscall_repr->param1, regs->rdi, followed_pid);
    if (syscall_repr->param2 > 0) {
        printf(", ");
        display_param(mode, syscall_repr->param2, regs->rsi, followed_pid);
    }
    if (syscall_repr->param3 > 0) {
        printf(", ");
        display_param(mode, syscall_repr->param3, regs->rdx, followed_pid);
    }
    if (syscall_repr->param4 > 0) {
        printf(", ");
        display_param(mode, syscall_repr->param4, regs->r10, followed_pid);
    }
    if (syscall_repr->param5 > 0) {
        printf(", ");
        display_param(mode, syscall_repr->param5, regs->r8, followed_pid);
    }
    if (syscall_repr->param6 > 0) {
        printf(", ");
        display_param(mode, syscall_repr->param6, regs->r9, followed_pid);
    }
    printf(")");
}
