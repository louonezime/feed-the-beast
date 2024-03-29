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

void print_struct_stat(long long reg_value, pid_t followed_pid)
{
    long data = ptrace(PTRACE_PEEKDATA, followed_pid, reg_value, NULL);
    struct stat *stat_data = NULL;

    if (data < 0)
        perror("strace: PTRACE_PEEKDATA");
    stat_data = (struct stat *)&data;
    fprintf(stderr, "st_mode=%u, ", stat_data->st_mode);
    fprintf(stderr, "st_size=%lld, ...", (long long)stat_data->st_size);
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
