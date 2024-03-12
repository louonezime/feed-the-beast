/*
** EPITECH PROJECT, 2024
** feed-the-beast
** File description:
** my_free_array
*/

#include <unistd.h>
#include <stdlib.h>

void my_free_array(char **array)
{
    for (int i = 0; array[i] != NULL; i++){
        free(array[i]);
    }
    free(array);
}
