/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myftp-lou.onezime
** File description:
** my_str_to_word_array
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
