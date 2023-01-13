/*
** EPITECH PROJECT, 2022
** my_ls
** File description:
** printing_tools
*/

#include "my.h"

void enter_spaces(bool *space, char *thing)
{
    if ((*space))
        write(1, thing, 1);
    (*space) = true;
}

void title_print(char *title, bool enter)
{
    if (enter) {
        write(1, title, my_strlen(title));
        write(1, ":\n", 2);
    }
}

void enter_enter(bool *enter, bool fpr, char *title, bool e)
{
    if ((*enter) || fpr)
        write(1, "\n", 1);
    (*enter) = true;
    title_print(title, e);
}
