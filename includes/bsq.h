/*
** EPITECH PROJECT, 2022
** bsq.h
** File description:
** write all functions in your libmy.a
*/

#include <stdio.h>

#include "my.h"
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>

#ifndef BSQ_H
    #define BSQ_H

    #define ERROR_MAP ("Bad map encodage\n")

    typedef struct tab_s {
        int nb_rows;
        int nb_cols;
        int size;
        char *file;
        char **tab;
        int **box;
    } tab_t;

    typedef struct bsq_s {
        int size_max;
        int x_max;
        int y_max;
    } bsq_t;

//error.c
    int manage_error(void);
    int manage_h(void);

//init.c
    int init_int(tab_t *tab, bsq_t *bsq);
    void double_tab(tab_t *tab);
    void init_square(tab_t *tab);
    int fs_open_file(tab_t *tab, char *filepath);
    void init_struct(tab_t *tab);

//display.c
    void square_max(tab_t *tab, bsq_t *bsq);
    void display_square(tab_t *tab, bsq_t *bsq);

//bsq.c
    void find_max(tab_t *tab, bsq_t *bsq, int y, int x);
    void find_square(tab_t *tab, int y, int x);
    int change_int(tab_t *tab, bsq_t *bsq, int y, int x);
    int init_second(tab_t *tab, bsq_t *bsq, int y, int *x);
    int process_file(char *str);

//generator.c
    void for_create(tab_t *tab, char *str, int y, int x);
    void create_buffer(tab_t *tab, char *str, char *src);
    int generate_map(char *src, char *str);

#endif
