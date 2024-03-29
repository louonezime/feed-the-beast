/*
** EPITECH PROJECT, 2024
** feed-the-beast
** File description:
** basic
*/

#include "criterion/criterion.h"

#include "strace.h"
#include "syscall.h"

Test(parsing, binary_process)
{
    char *args[] = {"-p", "42", NULL};
    char *env[] = {NULL};

    cr_assert_eq(parse_args(args, env), ERROR);
}

Test(parsing, binary_process_s_flag)
{
    char *args[] = {"-p", "42", "-s", NULL};
    char *env[] = {NULL};

    cr_assert_eq(parse_args(args, env), ERROR);
}

Test(parsing, binary_process_s_flag_s_flag)
{
    char *args[] = {"-s", "-s", NULL};
    char *env[] = {NULL};

    cr_assert_eq(parse_args(args, env), ERROR);
}

Test(parsing, env_process)
{
    char *args[] = {"ls", "-l", NULL};
    char *env[] = {"PATH=/usr/bin", NULL};

    cr_assert_eq(parse_args(args, env), ERROR);
}

Test(parsing, wrong_numb_arg)
{
    char *args[] = {"-p", "ho"};
    char *env[] = {NULL};

    cr_assert_eq(parse_args(args, env), ERROR);
}

Test(parsing, wrong_numb_arg_2)
{
    char *args[] = {"-p"};
    char *env[] = {NULL};

    cr_assert_eq(parse_args(args, env), ERROR);
}

Test(parsing, wrong_numb_arg_3)
{
    char *args[] = {"-p", "toooto", "-s"};
    char *env[] = {NULL};

    cr_assert_eq(parse_args(args, env), ERROR);
}

Test(parsing, no_arg_s)
{
    char *args[] = {"-s", NULL};
    char *env[] = {NULL};

    cr_assert_eq(parse_args(args, env), ERROR);
}

Test(parsing, no_arg_p)
{
    char *args[] = {"-p", NULL};
    char *env[] = {NULL};

    cr_assert_eq(parse_args(args, env), ERROR);
}

Test(parsing, arg_after_s)
{
    char *args[] = {"-s", "-p", "42", NULL};
    char *env[] = {NULL};

    cr_assert_eq(parse_args(args, env), ERROR);
}

Test(parsing, double_flag)
{
    char *args[] = {"-sp", "42", NULL};
    char *env[] = {NULL};

    cr_assert_eq(parse_args(args, env), ERROR);
}

Test(error_handling, get_arg)
{
    char *path = "/usr/bin";
    char *command = "ls";
    char *result = get_arg(path, command);

    cr_assert_str_eq(result, "/usr/bin/ls");
}

Test(error_handling, check_path)
{
    char *arg[] = {"ls", NULL};
    char *env_var = "/usr/bin:/bin";
    char *path = NULL;
    char *env[] = {NULL};

    cr_assert_eq(check_path(arg, env_var, &path, env), true);
}

Test(error_handling, check_path_fail)
{
    char *arg[] = {"ls", NULL};
    char *env_var = "/usr/bin:/bin";
    char *path = NULL;
    char *env[] = {NULL};

    cr_assert_eq(check_path(arg, env_var, &path, env), true);
}
