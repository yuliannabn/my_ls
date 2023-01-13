/*
** EPITECH PROJECT, 2022
** my_ls
** File description:
** exec_flag
*/

#include "my.h"

void d_flag(int ac, char **argv)
{
    struct stat st;
    bool space = false;

    for (int a = 0; a < ac; a++) {
        if (ac == 2) {
            write(1, ".\n", 2);
            exit (0);
        }
        if (space)
            write(1, " ", 1);
        if (stat(argv[a], &st) > -1 && S_ISDIR(st.st_mode)) {
            write(1, argv[a], my_strlen(argv[a]));
            space = true;
        }
    }
    write(1, "\n", 1);
    exit (0);
}
