/*
** EPITECH PROJECT, 2022
** BSQ
** File description:
** my_strlen
*/

int my_strlen(const char *str)
{
    int a = 0;

    while (str[a] != '\0')
        a++;
    return (a);
}
