/*
** EPITECH PROJECT, 2022
** my_ls
** File description:
** printing
*/

#include "my.h"

void total_print(current_t **curr, int a)
{
    write(1, "total ", 6);
    put_nbr(curr[a]->total_size);
    write(1, "\n", 1);
}

void write_date(char *date)
{
    int a = 4;

    while (a < 16) {
        write(1, &date[a], 1);
        a++;
    }
}

void l_print(current_t **curr, int a, int v, bool *space)
{
    enter_spaces(space, "\n");
    write(1, curr[a]->all[v]->permissions,
    my_strlen(curr[a]->all[v]->permissions));
    write(1, " ", 1);
    put_nbr(curr[a]->all[v]->hlinks);
    write(1, " ", 1);
    write(1, curr[a]->all[v]->UID, my_strlen(curr[a]->all[v]->UID));
    write(1, " ", 1);
    write(1, curr[a]->all[v]->GID, my_strlen(curr[a]->all[v]->GID));
    write(1, " ", 1);
    put_nbr(curr[a]->all[v]->size);
    write(1, " ", 1);
    write_date(curr[a]->all[v]->date);
    write(1, " ", 1);
    write(1, curr[a]->all[v]->name, my_strlen(curr[a]->all[v]->name));
}

void ls_lflag(current_t **curr, int valid_paths)
{
    flags_t *fl = curr[0]->flags;
    int a = 0, size = 0;
    bool space = false, enter = false, title = valid_paths > 1 ? true : false;

    while (a < valid_paths) {
        size = dir_size(curr[a]->path, fl);
        if (curr[a]->invalid)
            error_handling(curr[a]->path, &curr[0]->ret);
        else {
            enter_enter(&enter, fl->file_printing, curr[a]->path, title);
            total_print(curr, a);
        }
        for (int v = 0; v < size && !curr[a]->empty; v++)
            l_print(curr, a, v, &space);
        space = false;
        if (!curr[a]->empty)
            write(1, "\n", 1);
        a++;
    }
}

void ls_nol(current_t **curr, int valid_paths)
{
    flags_t *fl = curr[0]->flags;
    int a = 0, size = 0;
    bool space = false, enter = false, title = valid_paths > 1 ? true : false;

    while (a < valid_paths) {
        size = dir_size(curr[a]->path, fl);
        if (curr[a]->invalid)
            error_handling(curr[a]->path, &curr[0]->ret);
        else
            enter_enter(&enter, fl->file_printing, curr[a]->path, title);
        for (int v = 0; v < size && !curr[a]->empty; v++) {
            enter_spaces(&space, " ");
            write(1, curr[a]->all[v]->name, my_strlen(curr[a]->all[v]->name));
        }
        space = false;
        if (!curr[a]->empty)
            write(1, "\n", 1);
        a++;
    }
}
