/*
** EPITECH PROJECT, 2024
** feed-the-beast
** File description:
** structure
*/

#include <sys/stat.h>
#include <stdio.h>
#include <stdbool.h>
#include <sys/ptrace.h>
#include <sys/vfs.h>

#include "strace.h"
#include "syscall.h"
#include "structures.h"

void print_struct_statfs(long long reg_value, pid_t followed_pid)
{
    struct statfs statis;

    if (ptrace(PTRACE_PEEKDATA, followed_pid, reg_value, &statis) == -1) {
        perror("ptrace");
    }
    fprintf(stderr, "f_type=%u, f_bsize=%d, f_blocks=%lu, f_bfree=%lu, "
        "f_bavail=%d, f_files=%d, f_ffree=%d, f_fsid=%u, f_namelen=%u, "
        "f_frsize=%d, f_flags=%d, f_spare[0]=%d, f_spare[1]=%d, "
        "f_spare[2]=%d, f_spare[3]=%d",
        statis.f_type, statis.f_bsize, statis.f_blocks, statis.f_bfree,
        statis.f_bavail, statis.f_files, statis.f_ffree, statis.f_fsid,
        statis.f_namelen, statis.f_frsize, statis.f_flags, statis.f_spare[0],
        statis.f_spare[1], statis.f_spare[2], statis.f_spare[3]);

}

void print_struct_stat(long long reg_value, pid_t followed_pid)
{
    struct stat statis;

    if (ptrace(PTRACE_PEEKDATA, followed_pid, reg_value, &statis) == -1) {
        perror("ptrace");
    }
    fprintf(stderr, "st_dev=%d, st_ino=%d, st_mode=%d, st_nlink=%u, "
        "st_uid=%d, st_gid=%d, st_rdev=%d, st_size=%d, st_blksize=%d, "
        "st_blocks=%d, st_atime=%d, st_mtime=%d, st_ctime=%d",
        statis.st_dev, statis.st_ino, statis.st_mode, statis.st_nlink,
        statis.st_uid, statis.st_gid, statis.st_rdev, statis.st_size,
        statis.st_blksize, statis.st_blocks, statis.st_atime, statis.st_mtime,
        statis.st_ctime);
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
