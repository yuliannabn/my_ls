/*
** EPITECH PROJECT, 2022
** my_ls
** File description:
** main
*/

#include "my.h"

void modify_place(flags_t *fl, int *l, int *b)
{
    (*b) = fl->R ? (*l) : (*b);
    (*l) += 1;
    (*b) += 1;
}

void fill_curr(current_t **curr, flags_t *fl, int ac, char **av)
{
    bool space = false, enter = false, has_dir = false;
    struct stat st;
    int l = 0;
    char *p;

    for (int a = 0, b = 0; a < ac; a++) {
        p = (ac - 1 == fl->count) ? my_strdup(".") : my_strdup(av[a]);
        if (stat(p, &st) > -1 && opendir(p) != NULL && av[a][0] != '-') {
            fill_files(p, curr, &b, &l);
            has_dir = true;
            modify_place(fl, &l, &b);
        }
        if (stat(p, &st) > -1 && opendir(p) == NULL && a > 0) {
            fl->file_printing = true;
            file_print(p, &space, &enter);
        }
    }
    fl->only_file = has_dir ? false : true;
    if (enter)
        write(1, "\n", 1);
}

void my_ls(current_t **curr, int ac, char **argv)
{
    find_invalid(ac, argv, &curr[0]->ret);
    flags_t *fl = curr[0]->flags;

    fill_curr(curr, fl, ac, argv);
    if (!fl->only_file) {
        if (fl->d)
            d_flag(ac, argv);
        if (fl->r)
            reverse_flag(curr, valid_paths(ac, argv, fl));
        if (fl->t)
            sort_by_time(curr, valid_paths(ac, argv, fl));
        if (fl->l)
            ls_lflag(curr, valid_paths(ac, argv, fl));
        else
            ls_nol(curr, valid_paths(ac, argv, fl));
    }
}

int main(int ac, char **argv)
{
    flags_t *flags = malloc(sizeof(flags_t));
    current_t **curr;

    prove_flags(flags, argv, ac);
    curr = malloc(sizeof(current_t) * valid_paths(ac, argv, flags));
    curr_flags(curr, flags, ac, argv);
    my_ls(curr, ac, argv);

    return (curr[0]->ret);
}
