/*
** EPITECH PROJECT, 2024
** feed-the-beast
** File description:
** structures
*/

#ifndef STRUCTURES_H_
    #define STRUCTURES_H_

    #include <stdint.h>

    #include "syscall.h"

void print_struct_stat(long long reg_value, pid_t followed_pid);
void print_filler(long long reg_value, pid_t followed_pid);

typedef struct structure_s {
    int type;
    void(*print)(long long, pid_t);
} structure_t;

static const structure_t STRUCTS[] = {
    {
        .type = STRUCT_STAT_P,
        .print = &print_struct_stat
    },
    {
        .type = STRUCT_FD_P,
        .print = &print_filler
    },
    {
        .type = CONST_STRUCT_IOVEC_P,
        .print = &print_filler
    },
    {
        .type = STRUCT_TIMEVAL_P,
        .print = &print_filler
    },
    {
        .type = STRUCT_SHMID_DS_P,
        .print = &print_filler
    },
    {
        .type = CONST_STRUCT_TIMESPEC_P,
        .print = &print_filler
    },
    {
        .type = STRUCT_TIMESPEC_P,
        .print = &print_filler
    },
    {
        .type = STRUCT_ITIMERVAL_P,
        .print = &print_filler
    },
    {
        .type = CONST_STRUCT_SOCKADDR_P,
        .print = &print_filler
    },
    {
        .type = STRUCT_SOCKADDR_P,
        .print = &print_filler
    },
    {
        .type = STRUCT_MSGHDR_P,
        .print = &print_filler
    },
    {
        .type = STRUCT_RUSAGE_P,
        .print = &print_filler
    },
    {
        .type = STRUCT_UTSNAME_P,
        .print = &print_filler
    },
    {
        .type = STRUCT_SEMBUF_P,
        .print = &print_filler
    },
    {
        .type = STRUCT_MSQID_DS_P,
        .print = &print_filler
    },
    {
        .type = STRUCT_LINUX_DIRENT_P,
        .print = &print_filler
    },
    {
        .type = STRUCT_TIMEZONE_P,
        .print = &print_filler
    },
    {
        .type = STRUCT_RLIMIT_P,
        .print = &print_filler
    },
    {
        .type = STRUCT_P,
        .print = &print_filler
    },
    {
        .type = STRUCT_TMS_P,
        .print = &print_filler
    },
    {
        .type = CONST_STRUCT_UTIMBUF_P,
        .print = &print_filler
    },
    {
        .type = STRUCT_STATFS_P,
        .print = &print_filler
    },
    {
        .type = CONST_STRUCT_SCHED_PARAM_P,
        .print = &print_filler
    },
    {
        .type = STRUCT_SCHED_PARAM_P,
        .print = &print_filler
    },
    {
        .type = STRUCT_TIMESPEC_P_,
        .print = &print_filler
    },
    {
        .type = STRUCT____ARGS_P,
        .print = &print_filler
    },
    {
        .type = STRUCT_TIMEX_P,
        .print = &print_filler
    },
    {
        .type = STRUCT_USER_DESC_P,
        .print = &print_filler
    },
    {
        .type = STRUCT_IO_EVENT_P,
        .print = &print_filler
    },
    {
        .type = STRUCT_IOCB_P,
        .print = &print_filler
    },
    {
        .type = STRUCT_LINUX_DIRENT64_P,
        .print = &print_filler
    },
    {
        .type = STRUCT_SIGEVENT_P,
        .print = &print_filler
    },
    {
        .type = CONST_STRUCT_ITIMERSPEC_P,
        .print = &print_filler
    },
    {
        .type = STRUCT_ITIMERSPEC_P,
        .print = &print_filler
    },
    {
        .type = STRUCT_EPOLL_EVENT_P,
        .print = &print_filler
    },
    {
        .type = CONST_STRUCT_TIMEVAL,
        .print = &print_filler
    },
    {
        .type = CONST_STRUCT_SIGEVENT_P,
        .print = &print_filler
    },
    {
        .type = STRUCT_MQ_ATTR_P,
        .print = &print_filler
    },
    {
        .type = STRUCT_KEXEC_SEGMENT_P,
        .print = &print_filler
    },
    {
        .type = STRUCT_POLLFD_P,
        .print = &print_filler
    },
    {
        .type = STRUCT_ROBUST_LIST_HEAD_P,
        .print = &print_filler
    },
    {
        .type = CONST_STRUCT_TIMESPEC,
        .print = &print_filler
    },
    {
        .type = STRUCT_PERF_EVENT_ATTR_P,
        .print = &print_filler
    },
    {
        .type = STRUCT_MMSGHDR_P,
        .print = &print_filler
    },
    {
        .type = STRUCT_FILE_HANDLE_P,
        .print = &print_filler
    },
    {
        .type = STRUCT__CACHE_P,
        .print = &print_filler
    },
    {
        .type = STRUCT_SCHED_ATTR_P,
        .print = &print_filler
    }
};

enum {
    STRUCTS_SIZE = sizeof(STRUCTS) / sizeof(STRUCTS[0])
};

#endif /* !STRUCTURES_H_ */
