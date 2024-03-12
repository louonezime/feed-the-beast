/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myftp-lou.onezime
** File description:
** my_str_to_word_array
*/

#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int nb_of_words(char **array)
{
    int count = 0;

    for (int i = 0; array[i] != NULL; i++){
        count++;
    }
    return count;
}

void free_array(char **array)
{
    for (int i = 0; array[i] != NULL; i++){
        free(array[i]);
    }
    free(array);
}

static int columns(char *str, char separator)
{
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++){
        if (str[i] == separator){
            count++;
        }
    }
    if (str[strlen(str) - 1] != separator){
        count = count + 1;
    }
    return count;
}

static int word_len(char *str, char separator, int l)
{
    int word = 0;

    for (int i = l; str[i] != separator && str[i] != '\0'; i++){
        word++;
    }
    return word;
}

char **my_str_to_word_array(char *str, char separator)
{
    int len = 0;
    int new_len = 0;
    int a = 0;
    char **array = malloc((sizeof(char *)) * (columns(str, separator) + 1));

    if (array == NULL)
        return NULL;
    for (int i = 0; i < columns(str, separator); i++){
        new_len = word_len(str, separator, len);
        len += new_len + 1;
        array[i] = malloc((sizeof(char)) * (new_len + 1));
        for (int k = 0; k < new_len; k++){
            array[i][k] = str[a];
            a++;
        }
        a++;
        array[i][new_len] = '\0';
    }
    array[columns(str, separator)] = NULL;
    return array;
}

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
