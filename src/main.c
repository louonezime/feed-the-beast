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

int main(int ac, char **av)
{
    int i = 1;
    int status = OK;

    if (ac == 1){
        fprintf(stderr, "strace: Invalid arguments.\n");
        fprintf(stderr, "Try './strace --help' for more information.\n");
        return ERROR;
    }
    if (ac == 2 && strcmp(av[1], "--help") == 0){
        show_display();
        return OK;
    }
    while (i != ac){
        if (do_strace(av[i]) == ERROR)
            status = ERROR;
        i++;
    }
    return status;
}
