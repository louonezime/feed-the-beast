/*
** EPITECH PROJECT, 2024
** feed-the-beast
** File description:
** params
*/

#include <criterion/criterion.h>

#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ptrace.h>

#include "strace.h"
#include "structures.h"

Test(check_struct, basic_test) {
    bool result_unknown = check_struct(true, 0, 0, getpid());
    cr_assert_eq(result_unknown, false, "Expected false for unknown struct type");
}

Test(print_struct_stat, success) {
    long long reg_value = 0;
    pid_t followed_pid = getpid();
    bool result = print_struct_stat(reg_value, followed_pid);

    cr_assert(result == false, "Function should return true on success");
}

Test(print_struct_stat, error) {
    long long reg_value = 0;
    pid_t followed_pid = getpid();
    bool result = print_struct_stat(reg_value, followed_pid);

    cr_assert(result == false, "Function should return false on error");
}

Test(print_filler, success) {
    long long reg_value = 0xabcdef;
    pid_t followed_pid = getpid();
    bool result = print_filler(reg_value, followed_pid);

    cr_assert(result == true, "Function should return true on success");
}

Test(strace, syscall_exist) {
    bool result = syscall_exist(1);
    cr_assert(result, "Syscall with opcode 1 should exist");

    result = syscall_exist(1000);
    cr_assert_not(result, "Syscall with opcode 1000 should not exist");
}
