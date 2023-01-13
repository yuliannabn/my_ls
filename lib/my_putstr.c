/*
** EPITECH PROJECT, 2022
** MY_PUTSTR
** File description:
** Displays characters of a string one by one.
*/

#include <unistd.h>

int my_strlen(const char *str);

int my_putstr(char const *str)
{
    write(1, str, my_strlen(str));
}
