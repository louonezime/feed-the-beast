/*
** EPITECH PROJECT, 2024
** feed-the-beast
** File description:
** my_array_size
*/

#include <stdlib.h>

int my_arraylen(char **array)
{
    int count = 0;

    for (int i = 0; array[i] != NULL; i++){
        count++;
    }
    return count;
}
