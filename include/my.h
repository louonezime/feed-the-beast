/*
** EPITECH PROJECT, 2024
** feed-the-beast
** File description:
** my
*/

#ifndef MY_H_
    #define MY_H_

/* ARRAY */

char **my_str_to_word_array(char *str, char separator);

void my_free_array(char **array);

int my_arraylen(char **array);

/* STR */

char *my_strcat(char *dest, char const *src);

#endif /* !MY_H_ */
