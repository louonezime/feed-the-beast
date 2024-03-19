/*
** EPITECH PROJECT, 2024
** feed-the-beast
** File description:
** structure
*/

#include "sys/stat.h"
#include <stdio.h>

#include "syscall.h"
#include "structures.h"

void print_struct_stat(unsigned long long reg_value, syscall_t *syscall_repr)
{
    struct stat statis;

    stat(reg_value, &statis);
    printf("{\n");
    printf("    dev_t st_dev;\n");
    printf("    ino_t st_ino;\n");
    printf("    mode_t st_mode;\n");
    printf("    nlink_t st_nlink;\n");
    printf("    uid_t st_uid;\n");
    printf("    gid_t st_gid;\n");
    printf("    dev_t st_rdev;\n");
    printf("    off_t st_size;\n");
    printf("    blksize_t st_blksize;\n");
    printf("    blkcnt_t st_blocks;\n");
    printf("    time_t st_atime;\n");
    printf("    time_t st_mtime;\n");
    printf("    time_t st_ctime;\n");
    printf("};\n");
}

int handle_structures()

void check_params(struct user_regs_struct *regs, syscall_t *syscall_repr)
{
    if (syscall_repr->param1 == STRUCT_STAT_P)
        print_struct_stat(regs->rdi, syscall_repr);
    else
        dprintf(2, "%d", regs->rdi);
    if (syscall_repr->param2 == STRUCT_STAT_P)
        print_struct_stat(regs->rsi, syscall_repr);
    else
        dprintf(2, "%d", regs->rsi);
    if (syscall_repr->param3 == STRUCT_STAT_P)
        print_struct_stat(regs->rdx, syscall_repr);
    else
        dprintf(2, "%d", regs->rdx);
    if (syscall_repr->param4 == STRUCT_STAT_P)
        print_struct_stat(regs->r10, syscall_repr);
    else
        dprintf(2, "%d", regs->r10);
    if (syscall_repr->param5 == STRUCT_STAT_P)
        print_struct_stat(regs->r8, syscall_repr);
    else
        dprintf(2, "%d", regs->r8);
    if (syscall_repr->param6 == STRUCT_STAT_P)
        print_struct_stat(regs->r9, syscall_repr);
    else
        dprintf(2, "%d", regs->r9);
}
