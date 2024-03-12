/*
** EPITECH PROJECT, 2024
** feed-the-beast
** File description:
** my_strcat
*/

#include <string.h>
#include <stdlib.h>

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int j = 0;
    char *final;

    final = malloc(sizeof(*final) * (strlen(dest) + strlen(src) + 1));
    while (dest[i]){
        final[i] = dest[i];
        i++;
    }
    while (src[j]){
        final[i + j] = src[j];
        j++;
    }
    final[i + j] = '\0';
    return final;
}
