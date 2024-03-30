/*
** EPITECH PROJECT, 2024
** feed-the-beast
** File description:
** strace
*/

#ifndef STRACE_H_
    #define STRACE_H_

    #include <stdbool.h>
    #include <aio.h>
    #include <sys/user.h>

    #define OK 0
    #define ERROR 84

    #define HELP_AC 2
    #define ERROR_AC 1

    #define ATOI_ERROR 0

    #define PATHS_SEPARATOR ':'

typedef struct syscall_s syscall_t;

static const bool S_FORMAT = true;
static const bool HEXA_FORMAT = false;

/* Parsing */
int parse_args(char **av, char **env);
int send_err(const char *error);
int send_err_arg(const char *error, char *arg);
int send_ptrace_err(const char *title, const char *request, int pid);

/* Utils */
char *get_arg(char *path, char *command);
bool check_path(char **arg, char *env_var, char **path, char **env);

/* strace */
int do_strace(char **arg, char **env, bool mode);
int binary_process(char **argv, char **env, bool mode);
void process(pid_t followed_pid, bool mode);
int attach_process_id(pid_t pid, bool mode);
syscall_t retrieve_element(int opcode);
bool is_instruction_syscall(pid_t followed_pid,struct user_regs_struct *regs);
bool syscall_exist(int opcode);

void display_args(bool mode, struct user_regs_struct *regs,
    syscall_t *syscall_repr, pid_t followed_pid);
void display_param(bool mode, int format, long long register_value,
    pid_t followed_pid);
bool check_struct(bool mode, int format, long long register_value, pid_t pid);
void display_string(unsigned long register_value, pid_t pid);
void display_next_param(bool mode, int format, long long register_value, pid_t pid);
void display_char(char character);

#endif /* !STRACE_H_ */
