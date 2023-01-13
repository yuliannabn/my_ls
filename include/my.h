/*
** EPITECH PROJECT, 2022
** MY_H
** File description:
** ..
*/

#ifndef MY_H_
    #define MY_H_

    #include <stddef.h>
    #include <unistd.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <stdbool.h>
    #include <fcntl.h>
    #include <dirent.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <signal.h>
    #include <pwd.h>
    #include <grp.h>
    #include <time.h>
    #include <sys/ioctl.h>

    typedef struct flags_f {
        bool a, l, R, d, r, t;
        bool file_printing;
        bool only_file;
        int count;
    } flags_t;

    typedef struct file_f {
        bool folder;
        char type;
        long time_sec;
        char *permissions;
        int hlinks;
        char *GID, *UID;
        int size;
        char *date;
        char *name;
    } file_t;

    typedef struct current_f {
        int total_size;
        bool empty;
        bool invalid;
        int ret;
        char *path;
        flags_t *flags;
        file_t **all;
    } current_t;

    void enter_spaces(bool *space, char *thing);
    void enter_enter(bool *enter, bool fpr, char *title, bool e);
    void title_print(char *title, bool enter);
    void ls_lflag(current_t **curr, int valid_paths);
    void ls_nol(current_t **curr, int valid_paths);
    void sort_by_time(current_t **array, int total_direc);
    void reverse_flag(current_t **array, int total_direc);
    char *malloc_file_pathname(char *path, current_t **curr, int *b, int a);
    void check_b(file_t **array, int a, int size);
    void bubble_sort_array(file_t **array, int size);
    void setup_file(char *pathfile, current_t **curr, int *b, int a);
    void rec_setup(char *pathfile, current_t **curr, int *b, int *a);
    void fill_files(char *path, current_t **curr, int *b, int *l);
    void error_handling(char *invalid_path, int *ret);
    void find_invalid(int ac, char **argv, int *ret);
    char *path_string(char *path, char *file);
    int dir_size(char *path, flags_t *flags);
    void file_print(char *name, bool *space, bool *enter);
    char *set_perm(mode_t mode, bool folder);
    int find_rec_folder(flags_t *fl, char *path);
    int valid_paths(int ac, char **argv, flags_t *flags);
    void init_curr(current_t **current, int limit);
    void curr_flags(current_t **current, flags_t *fl, int ac, char **argv);
    void d_flag(int ac, char **argv);
    void prove_flags(flags_t *flags, char **argv, int ac);
    char *my_strdup(char const *src);
    bool str_equal(char *str, char *other);
    char *my_strcat(char *dest, char const *src);
    void put_nbr(int nb);
    int my_strlen(char const *str);
    void my_putstr(char const *str);

#endif
