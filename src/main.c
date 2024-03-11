/*
** EPITECH PROJECT, 2024
** feed-the-beast
** File description:
** main
*/

#include "strace.h"

#include <stdio.h>
#include <string.h>

static void show_display(void)
{
    printf("\n                                __\n");
    printf("                               (oo)\n");
    printf("                                \\/\n");
    printf("                                ||\n");
    printf("                                ||\n");
    printf("                                ||,-v-,_\n");
    printf("                                ||\\ |   /\n");
    printf("                            _,'\"  \"'-,-<\n");
    printf("                           / :       /  \\\n");
    printf("                          ( :       (   /,\n");
    printf("                           \\_;       \\ __)\n");
    printf("                              \\,_ ,   |\n");
    printf("                              |  / \\  |\n");
    printf("                              | /   \\ |\n");
    printf("                              ()     ()\n");
    printf("                              //     ||\n");
    printf("                             //      ||\n");
    printf("                            //       ||\n");
    printf("                           ^^       '^^\"\n");
    printf("USAGE:\t./strace [-s] [-p <pid>|<command>]\n\n");
}

int main(int ac, char **av, char **env)
{
    if (ac == ERROR_AC){
        fprintf(stderr, "strace: Invalid arguments.\n");
        fprintf(stderr, "Try './strace --help' for more information.\n");
        return ERROR;
    }
    if (ac == HELP_AC && strcmp(av[1], "--help") == OK){
        show_display();
        return OK;
    }
    av++;
    if (parse_args(av, env) == ERROR){
        return ERROR;
    }
    return OK;
}
