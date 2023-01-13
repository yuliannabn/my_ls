/*
** EPITECH PROJECT, 2022
** my_ls
** File description:
** permissions
*/

#include "my.h"

void file_type(mode_t mode, char *string, bool folder)
{
    string[0] = folder ? 'd' : '-';
    string[0] = S_ISCHR(mode) ? 'c' : string[0];
    string[0] = S_ISLNK(mode) ? 'l' : string[0];
    string[0] = S_ISBLK(mode) ? 'b' : string[0];
}

void perm_usr(mode_t mode, char *string)
{
    string[1] = mode & S_IRUSR ? 'r' : string[1];
    string[2] = mode & S_IWUSR ? 'w' : string[2];
    string[3] = mode & S_IXUSR ? 'x' : string[3];
}

void perm_grp(mode_t mode, char *string)
{
    string[4] = mode & S_IRGRP ? 'r' : string[4];
    string[5] = mode & S_IWGRP ? 'w' : string[5];
    string[6] = mode & S_IXGRP ? 'x' : string[6];
}

void perm_other(mode_t mode, char *string)
{
    string[7] = mode & S_IROTH ? 'r' : string[7];
    string[8] = mode & S_IWOTH ? 'w' : string[8];
    string[9] = mode & S_IXOTH ? 'x' : string[9];
    string[9] = mode & S_ISVTX ? 't' : string[9];
}

char *set_perm(mode_t mode, bool folder)
{
    char *string = my_strdup("----------");

    file_type(mode, string, folder);
    perm_usr(mode, string);
    perm_grp(mode, string);
    perm_other(mode, string);
    return (string);
}
