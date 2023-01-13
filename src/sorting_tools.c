/*
** EPITECH PROJECT, 2022
** my_ls
** File description:
** array_sorting_flags
*/

#include "my.h"

void swap_elem(file_t **array, int index1, int index2)
{
    file_t *backup = (array)[index1];
    (array)[index1] = (array)[index2];
    (array)[index2] = backup;
}

void check_b(file_t **array, int a, int size)
{
    int b = a + 1;

    while (b < size) {
        if (array[a]->time_sec < array[b]->time_sec)
            swap_elem(array, a, b);
        b++;
    }
}

void bubble_sort_array(file_t **array, int size)
{
    int a = 0;

    while (a < size) {
        check_b(array, a, size);
        a++;
    }
}

void sort_by_time(current_t **array, int total_direc)
{
    int a = 0, size = 0;
    flags_t *fl = array[0]->flags;

    while (a < total_direc) {
        size = dir_size(array[a]->path, fl);
        bubble_sort_array(array[a]->all, size);
        a++;
    }
}
