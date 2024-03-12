/*
** EPITECH PROJECT, 2024
** feed-the-beast
** File description:
** error_handling
*/

#include "strace.h"
#include "my.h"

#include <stdio.h>
#include <sys/stat.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

static char *get_arg(char *path, char *command)
{
    int j = 0;
    char *new = malloc(sizeof(char) *
        (strlen(command) + strlen(path) + 2));

    if (new == NULL)
        return NULL;
    for (int i = 0; path[i] != '\0'; i++){
        new[j] = path[i];
        j++;
    }
    new[j] = '/';
    j++;
    for (int k = 0; command[k] != '\0'; k++){
        new[j] = command[k];
        j++;
    }
    new[j] = '\0';
    return new;
}

static bool check_path(char **arg, char *env_var, char **path, char **env)
{
    int i = 0;
    char *command = NULL;
    char **paths = my_str_to_word_array(env_var, PATHS_SEPARATOR);

    if (paths == NULL)
        return NULL;
    while (paths[i] != NULL){
        command = get_arg(paths[i], arg[0]);
        if (access(command, X_OK) < OK){
            free(command);
            i++;
        } else {
            my_free_array(paths);
            *path = strdup(command);
            free(command);
            return true;
        }
    }
    my_free_array(paths);
    return false;
}

static bool check_env(char **arg, char **env, char **path_command)
{
    for (int i = 0; env[i] != NULL; i++){
        if (strncmp(env[i], "PATH", strlen("PATH")) == OK){
            return check_path(arg, env[i], path_command, env);
        }
    }
    return true;
}

static bool preliminaries(char **arg, char **env, char **path_command)
{
    struct stat statis;

    if (!check_env(arg, env, path_command)){
        if (stat(arg[0], &statis) < OK){
            fprintf(stderr, "strace: Can't stat '%s': ", arg[0]);
            perror("");
            return false;
        }
        return false;
    }
    return true;
}

int do_strace(char **arg, char **env, bool mode)
{
    char *path_command = NULL;

    if (!preliminaries(arg, env, &path_command)){
        return ERROR;
    }
    printf("path found: %s\n", path_command);
    if (mode == HEXA_FORMAT){
        printf("return function that handles hexa\n");
    }
    if (mode == S_FORMAT){
        printf("return function that handles s flag\n");
    }
    return ERROR;
}
