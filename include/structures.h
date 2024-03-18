/*
** EPITECH PROJECT, 2024
** feed-the-beast
** File description:
** structures
*/

#ifndef STRUCTURES_H_
    #define STRUCTURES_H_

#include "syscall.h"

typedef struct structure_s {
    int type;
} structure_t;

static const structure_t STRUCTS[] = {
    {
        .type = STRUCT_STAT_P,
    },
    {
        .type = STRUCT_FD_P,
    },
    {
        .type = CONST_STRUCT_IOVEC_P,
    },
    {
        .type = STRUCT_TIMEVAL_P,
    },
    {
        .type = STRUCT_SHMID_DS_P,
    },
    {
        .type = CONST_STRUCT_TIMESPEC_P,
    },
    {
        .type = STRUCT_TIMESPEC_P,
    },
    {
        .type = STRUCT_ITIMERVAL_P,
    },
    {
        .type = CONST_STRUCT_SOCKADDR_P,
    },
    {
        .type = STRUCT_SOCKADDR_P,
    },
    {
        .type = STRUCT_MSGHDR_P,
    },
    {
        .type = STRUCT_RUSAGE_P,
    },
    {
        .type = STRUCT_UTSNAME_P,
    },
    {
        .type = STRUCT_SEMBUF_P,
    },
    {
        .type = STRUCT_MSQID_DS_P,
    },
    {
        .type = STRUCT_LINUX_DIRENT_P,
    },
    {
        .type = STRUCT_TIMEZONE_P,
    },
    {
        .type = STRUCT_RLIMIT_P,
    },
    {
        .type = STRUCT_P,
    },
    {
        .type = STRUCT_TMS_P,
    },
    {
        .type = CONST_STRUCT_UTIMBUF_P,
    },
    {
        .type = STRUCT_STATFS_P,
    },
    {
        .type = CONST_STRUCT_SCHED_PARAM_P,
    },
    {
        .type = STRUCT_SCHED_PARAM_P,
    },
    {
        .type = STRUCT_TIMESPEC_P_,
    },
    {
        .type = STRUCT____ARGS_P,
    },
    {
        .type = STRUCT_TIMEX_P,
    },
    {
        .type = STRUCT_USER_DESC_P,
    },
    {
        .type = STRUCT_IO_EVENT_P,
    },
    {
        .type = STRUCT_IOCB_P,
    },
    {
        .type = STRUCT_LINUX_DIRENT64_P,
    },
    {
        .type = STRUCT_SIGEVENT_P,
    },
    {
        .type = CONST_STRUCT_ITIMERSPEC_P,
    },
    {
        .type = STRUCT_ITIMERSPEC_P,
    },
    {
        .type = STRUCT_EPOLL_EVENT_P,
    },
    {
        .type = CONST_STRUCT_TIMEVAL,
    },
    {
        .type = CONST_STRUCT_SIGEVENT_P,
    },
    {
        .type = STRUCT_MQ_ATTR_P,
    },
    {
        .type = STRUCT_KEXEC_SEGMENT_P,
    },
    {
        .type = STRUCT_POLLFD_P,
    },
    {
        .type = STRUCT_ROBUST_LIST_HEAD_P,
    },
    {
        .type = CONST_STRUCT_TIMESPEC,
    },
    {
        .type = STRUCT_PERF_EVENT_ATTR_P,
    },
    {
        .type = STRUCT_MMSGHDR_P,
    },
    {
        .type = STRUCT_FILE_HANDLE_P,
    },
    {
        .type = STRUCT__CACHE_P,
    },
    {
        .type = STRUCT_SCHED_ATTR_P,
    }
};

#endif /* !STRUCTURES_H_ */
