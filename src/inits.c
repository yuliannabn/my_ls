/*
** EPITECH PROJECT, 2022
** my_ls
** File description:
** inits
*/

#include "my.h"

int find_rec_folder(flags_t *fl, char *path)
{
    int a = 1;
    char *pathfile;
    struct stat st;
    struct dirent *data;
    DIR *dirp = opendir(path);

    if ((stat(path, &st) > -1 && opendir(path) == NULL && S_ISDIR(st.st_mode)))
        return (a);
    while (fl->R && dirp != NULL && ((data = readdir(dirp)) != NULL) &&
    !str_equal(path, "/bin")) {
        if (!fl->a && data->d_name[0] != '.') {
            pathfile = my_strdup(path_string(path, data->d_name));
            stat(pathfile, &st);
            a += S_ISDIR(st.st_mode) ? find_rec_folder(fl, pathfile) : 0;
        }
    }
    return (a);
}

int valid_paths(int ac, char **argv, flags_t *flags)
{
    struct stat st;
    int paths = 0;
    char *place;

    for (int a = 0; a < ac; a++) {
        place = (ac - 1 == flags->count) ? my_strdup(".") : my_strdup(argv[a]);
        if (stat(place, &st) > -1 && S_ISDIR(st.st_mode) &&
        argv[a][0] != '-')
            paths += find_rec_folder(flags, place);
    }
    return (paths);
}

void init_curr(current_t **curr, int limit)
{
    for (int a = 1; a < limit; a++) {
        curr[a] = malloc(sizeof(current_t));
        curr[a]->empty = false;
        curr[a]->invalid = false;
        curr[a]->total_size = 0;
    }
}

void curr_flags(current_t **curr, flags_t *fl, int ac, char **argv)
{
    curr[0] = malloc(sizeof(current_t));
    curr[0]->flags = fl;
    curr[0]->ret = 0;
    curr[0]->empty = false;
    curr[0]->invalid = false;
    curr[0]->total_size = 0;

    prove_flags(curr[0]->flags, argv, ac);
    init_curr(curr, valid_paths(ac, argv, fl));
}

int dir_size(char *path, flags_t *flags)
{
    struct dirent *data;
    DIR *dirp = opendir(path);
    int size = 0;

    while (dirp != NULL && (data = readdir(dirp)) != NULL) {
        if ((flags->a && data->d_name[0] == '.') || (data->d_name[0] != '.'))
            size++;
    }
    size = size == 0 ? 1 : size;
    return (size);
}
