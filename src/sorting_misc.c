/*
** EPITECH PROJECT, 2023
** my_ls
** File description:
** sorting_misc
*/

#include "my.h"

void reverse_array(file_t **array, int size)
{
    int a = 0;
    file_t *backup;

    size--;
    while (a < size) {
        backup = array[a];
        array[a] = array[size];
        array[size] = backup;
        size--;
        a++;
    }
}

void reverse_flag(current_t **array, int total_direc)
{
    int a = 0, size = 0;
    flags_t *fl = array[0]->flags;

    while (a < total_direc) {
        size = dir_size(array[a]->path, fl);
        reverse_array(array[a]->all, size);
        a++;
    }
}

void rec_setup(char *pathfile, current_t **curr, int *b, int *a)
{
    setup_file(pathfile, curr, b, (*a));
    free(pathfile);
    (*a) += 1;
}
