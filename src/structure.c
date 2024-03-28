/*
** EPITECH PROJECT, 2024
** feed-the-beast
** File description:
** structure
*/

#include <sys/stat.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <sys/ptrace.h>
#include <sys/vfs.h>

#include "strace.h"
#include "syscall.h"
#include "structures.h"

void print_struct_statfs(long long reg_value, pid_t followed_pid)
{
    long data = ptrace(PTRACE_PEEKDATA, followed_pid, reg_value, NULL);
    struct statfs *statfs_data = NULL;

    if (data < 0)
        perror("ptrace");
    statfs_data = (struct statfs *)&data;
    fprintf(stderr, "f_type=%lx, ", statfs_data->f_type);
    fprintf(stderr, "f_bsize=%lu, ", statfs_data->f_bsize);
    fprintf(stderr, "f_blocks=%lu, ", statfs_data->f_blocks);
    fprintf(stderr, "f_bfree=%lu, ", statfs_data->f_bfree);
    fprintf(stderr, "f_bavail=%lu, ", statfs_data->f_bavail);
    fprintf(stderr, "f_files=%lu, ", statfs_data->f_files);
    fprintf(stderr, "f_ffree=%lu, ", statfs_data->f_ffree);
    fprintf(stderr, "f_fsid={%d, %d}, ", statfs_data->f_fsid.__val[0],
        statfs_data->f_fsid.__val[1]);
    fprintf(stderr, "f_namelen=%lu, ", statfs_data->f_namelen);
    fprintf(stderr, "f_frsize=%lu, ", statfs_data->f_frsize);
    fprintf(stderr, "f_flags=%lu", statfs_data->f_flags);
}

void print_struct_stat(long long reg_value, pid_t followed_pid)
{
    long data = ptrace(PTRACE_PEEKDATA, followed_pid, reg_value, NULL);
    struct stat *stat_data = NULL;

    if (data < 0)
        perror("ptrace");
    stat_data = (struct stat *)&data;
    fprintf(stderr, "st_mode=%u, ", stat_data->st_mode);
    fprintf(stderr, "st_size=%lld, ", (long long)stat_data->st_size);
}

void print_filler(long long reg_value, pid_t followed_pid)
{
    (void)followed_pid;
    fprintf(stderr, "0x%llx", reg_value);
}

bool check_struct(bool mode, int format, long long register_value,
    pid_t followed_pid)
{
    for (int i = 0; i < STRUCTS_SIZE; i++){
        if (format == STRUCTS[i].type){
            fprintf(stderr, "{");
            STRUCTS[i].print(register_value, followed_pid);
            fprintf(stderr, "}");
            return true;
        }
    }
    return false;
}
