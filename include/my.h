/*
** EPITECH PROJECT, 2024
** feed-the-beast
** File description:
** my
*/

#ifndef MY_H_
    #define MY_H_

/* STRTOK */

char **my_str_to_word_array(char *str, char separator);

void free_array(char **array);
int nb_of_words(char **array);

/* STRCAT */

char *my_strcat(char *dest, char const *src);

#endif /* !MY_H_ */
