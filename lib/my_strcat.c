/*
** EPITECH PROJECT, 2022
** my_ls
** File description:
** my_strcat
*/

#include <stdlib.h>

int my_strlen(char const *str);

char *my_strcat(char *dest, char const *src)
{
    int a = 0;
    int dest_len = my_strlen(dest);
    char *_dest = malloc(sizeof(char) * (dest_len + my_strlen(src)) + 1);

    for (int b = 0; dest[b] != '\0'; b++)
        _dest[b] = dest[b];
    for (; src[a] != '\0'; a++)
        _dest[dest_len + a] = src[a];
    _dest[dest_len + a] = '\0';
    return (_dest);
}
