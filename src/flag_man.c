/*
** EPITECH PROJECT, 2022
** my_ls
** File description:
** flag_man
*/

#include "my.h"

void string_flag_check(flags_t *flags, char **argv, int a)
{
    for (int b = 1; b < my_strlen(argv[a]); b++) {
        if (argv[a][b] == 'a')
            flags->a = true;
        if (argv[a][b] == 'l')
            flags->l = true;
        if (argv[a][b] == 'R')
            flags->R = true;
        if (argv[a][b] == 'd')
            flags->d = true;
        if (argv[a][b] == 'r')
            flags->r = true;
        if (argv[a][b] == 't')
            flags->t = true;
    }
}

void init_flag_struct(flags_t *flags)
{
    flags->a = false;
    flags->l = false;
    flags->d = false;
    flags->R = false;
    flags->r = false;
    flags->t = false;
    flags->file_printing = false;
    flags->only_file = false;
    flags->count = 0;
}

void prove_flags(flags_t *flags, char **argv, int ac)
{
    int a = 1;

    init_flag_struct(flags);
    while (a < ac) {
        if (argv[a][0] == '-') {
            flags->count++;
            string_flag_check(flags, argv, a);
        }
        a++;
    }
}
