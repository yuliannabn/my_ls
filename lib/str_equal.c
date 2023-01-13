/*
** EPITECH PROJECT, 2022
** BSQ
** File description:
** str_equal
*/

#include <stdio.h>
#include <stdbool.h>
int my_strlen(const char *str);

bool str_equal(char *str, char *other)
{
    int a = 0;

    while (a <= my_strlen(str)) {
        if (str[a] != other[a])
            return (false);
        a++;
    }
    return (true);
}
