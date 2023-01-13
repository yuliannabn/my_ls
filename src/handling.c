/*
** EPITECH PROJECT, 2022
** my_ls
** File description:
** handling
*/

#include "my.h"

char *malloc_file_pathname(char *path, current_t **curr, int *b, int a)
{
    struct stat st;

    stat(path_string(path, curr[(*b)]->all[a]->name), &st);
    curr[(*b)]->all[a]->folder = S_ISDIR(st.st_mode) ? true : false;
    return (path_string(path, curr[(*b)]->all[a]->name));
}

void error_handling(char *invalid_path, int *ret)
{
    struct stat st;
    int prove = stat(invalid_path, &st);

    if (prove > -1 && S_ISDIR(st.st_mode)) {
        write(2, "ls: cannot open directory '", 28);
        write(2, invalid_path, my_strlen(invalid_path));
        write(2, "': Permission denied\n", 22);
        (*ret) = 84;
    } else if (stat(invalid_path, &st) < 0) {
        write(2, "ls: cannot access '", 19);
        write(2, invalid_path, my_strlen(invalid_path));
        write(2, "': No such file or directory\n", 30);
        (*ret) = 84;
    }
}

void find_invalid(int ac, char **argv, int *ret)
{
    struct stat st;

    for (int a = 1; a < ac; a++) {
        if ((stat(argv[a], &st) < 0 || opendir(argv[a]) == NULL) &&
        argv[a][0] != '-')
            error_handling(argv[a], ret);
    }
}

void file_print(char *name, bool *space, bool *enter)
{
    if ((*space))
        write(1, " ", 1);
    write(1, name, my_strlen(name));
    (*space) = true;
    (*enter) = true;
}

char *path_string(char *path, char *file)
{
    if (path[my_strlen(path) - 1] != '/')
        return (my_strcat(my_strcat(path, "/"), file));
    else
        return (my_strcat(path, file));
}
