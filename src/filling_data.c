/*
** EPITECH PROJECT, 2022
** my_ls
** File description:
** array_sorting_flags
*/

#include "my.h"

void rec_check(char *pathfile, current_t **curr, bool enter, int *l)
{
    int ofst = 0;
    flags_t *fl = curr[0]->flags;

    if (enter && !fl->a) {
        (*l) += 1;
        ofst = (*l);
        fill_files(pathfile, curr, &ofst, l);
    }
}

void setup_file(char *pathfile, current_t **curr, int *b, int a)
{
    struct stat st;

    stat(pathfile, &st);
    curr[(*b)]->all[a]->size = st.st_size;
    curr[(*b)]->total_size += (st.st_blocks / 2);
    curr[(*b)]->all[a]->GID = my_strdup(getgrgid(st.st_gid)->gr_name);
    curr[(*b)]->all[a]->UID = my_strdup(getpwuid(st.st_uid)->pw_name);
    curr[(*b)]->all[a]->permissions = my_strdup(set_perm(st.st_mode,
    curr[(*b)]->all[a]->folder));
    curr[(*b)]->all[a]->hlinks = st.st_nlink;
    curr[(*b)]->all[a]->date = my_strdup(ctime(&st.st_mtim.tv_sec));
    curr[(*b)]->all[a]->time_sec = st.st_mtim.tv_sec;
}

void init_file_array(char *path, current_t **curr, int b, flags_t *fl)
{
    DIR *dirp = opendir(path);
    bool invalid = dirp == NULL ? true : false;
    struct dirent *data;
    int size = 0;

    curr[b]->all = malloc(sizeof(file_t) * dir_size(path, fl));
    curr[b]->path = my_strdup(path);
    if (!invalid)
        while (dirp != NULL && ((data = readdir(dirp)) != NULL))
            size++;
    invalid = (size <= 2 && !invalid) || invalid ? true : false;
    if (invalid)
        curr[b]->empty = true;
}

void if_invalid_dir(char *path, current_t **curr, int *b, int a)
{
    struct stat st;

    if (stat(path, &st) > -1 && S_ISDIR(st.st_mode) && opendir(path) == NULL) {
        curr[(*b)]->all[a] = malloc(sizeof(file_t));
        curr[(*b)]->all[a]->name = my_strdup(path);
        curr[(*b)]->invalid = true;
        curr[(*b)]->all[a]->folder = true;
        setup_file(path, curr, b, a);
        curr[(*b)]->all[a]->type = '?';
        (*b) += 1;
    }
}

void fill_files(char *path, current_t **curr, int *b, int *l)
{
    int a = 0, in = 0;
    flags_t *fl = curr[0]->flags;
    char *pathfile;
    struct dirent *data;
    DIR *d = opendir(path);

    init_file_array(path, curr, (*b), fl);
    while ((d != NULL && ((data = readdir(d)) != NULL))) {
        if ((fl->a && data->d_name[0] == '.') || (data->d_name[0] != '.')) {
            curr[(*b)]->all[a] = malloc(sizeof(file_t));
            curr[(*b)]->all[a]->name = my_strdup(data->d_name);
            curr[(*b)]->all[a]->type = data->d_type;
            pathfile = my_strdup(malloc_file_pathname(path, curr, b, a));
            in = curr[(*b)]->all[a]->folder && fl->R &&
            !str_equal(pathfile, "/bin/X11") ? true : false;
            rec_check(pathfile, curr, in, l);
            rec_setup(pathfile, curr, b, &a);
        }
    }
    if_invalid_dir(path, curr, b, a);
}
