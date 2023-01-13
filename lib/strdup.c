/*
** EPITECH PROJECT, 2022
** myls
** File description:
** strdup
*/

#include <stdio.h>
#include <stdlib.h>

int my_strlen(char const *str);

char *my_strdup(char const *src)
{
    int a = 0;
    int l = my_strlen(src);
    char *str = malloc(sizeof(char) * (l + 1));

    while (src[a] != '\0') {
        str[a] = src[a];
        a++;
    }
    str[a] = '\0';
    return (str);
}
