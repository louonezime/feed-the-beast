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

static int add_arg(char *buffer, int format,
    unsigned long register_value, bool display_comma)
{
    if (display_comma){
        return sprintf(buffer, ", %#x", register_value);
    }
    return sprintf(buffer, "%#x", register_value);
}

static int get_arg_size(struct user_regs_struct *regs, syscall_t *syscall_repr)
{
    int size = 0;

    size += strlen("(");
    if (syscall_repr->param1 > 0)
        size += sizeof(regs->rdi) + 2;
    if (syscall_repr->param2 > 0)
        size += sizeof(regs->rsi) + 2;
    if (syscall_repr->param3 > 0)
        size += sizeof(regs->rdx) + 2;
    if (syscall_repr->param4 > 0)
        size += sizeof(regs->r10 + 2);
    if (syscall_repr->param5 > 0)
        size += sizeof(regs->r8 + 2);
    if (syscall_repr->param6 > 0)
        size += sizeof(regs->r9 + 2);
    size += strlen(")");
    return size;
}

static void add_params(char *buffer, struct user_regs_struct *regs,
    syscall_t *sys_repr)
{
    int offset = 0;

    offset += sprintf(buffer + offset, "(");
    if (sys_repr->param1 > 0)
        offset += add_arg(buffer + offset, sys_repr->param1, regs->rdi, false);
    if (sys_repr->param2 > 0)
        offset += add_arg(buffer + offset, sys_repr->param2, regs->rsi, true);
    if (sys_repr->param3 > 0)
        offset += add_arg(buffer + offset, sys_repr->param3, regs->rdx, true);
    if (sys_repr->param4 > 0)
        offset += add_arg(buffer + offset, sys_repr->param4, regs->r10, true);
    if (sys_repr->param5 > 0)
        offset += add_arg(buffer + offset, sys_repr->param5, regs->r8, true);
    if (sys_repr->param6 > 0)
        offset += add_arg(buffer + offset, sys_repr->param6, regs->r9, true);
    offset += sprintf(buffer + offset, ")");
}

void stock_args(bool mode, struct user_regs_struct *regs,
    syscall_t *syscall_repr)
{
    int buffer_size = get_arg_size(regs, syscall_repr);
    char *buffer = malloc(sizeof(char) * buffer_size + 1);

    if (buffer == NULL)
        return;
    memset(buffer, '\0', buffer_size + 1);
    add_params(buffer, regs, syscall_repr);
    printf("%s", buffer);
    free(buffer);
}
