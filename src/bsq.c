/*
** EPITECH PROJECT, 2023
** bsq.c
** File description:
** bsq
*/

#include "bsq.h"

void find_max(tab_t *tab, bsq_t *bsq, int y, int x)
{
    if (tab->box[y][x] > bsq->size_max) {
        bsq->size_max = tab->box[y][x];
        bsq->y_max = y;
        bsq->x_max = x;
    }
}

void find_square(tab_t *tab, int y, int x)
{
    if (y > 0 && x > 0) {
        if (tab->box[y - 1][x] == tab->box[y - 1][x - 1] &&
            tab->box[y - 1][x] == tab->box[y][x - 1])
            tab->box[y][x] = tab->box[y - 1][x] + 1;
        if (tab->box[y - 1][x] < tab->box[y - 1][x - 1] &&
            tab->box[y - 1][x] < tab->box[y][x - 1])
            tab->box[y][x] = tab->box[y - 1][x] + 1;
        if (tab->box[y][x - 1] <= tab->box[y - 1][x - 1] &&
            tab->box[y][x - 1] <= tab->box[y - 1][x])
            tab->box[y][x] = tab->box[y][x - 1] + 1;
        if (tab->box[y - 1][x - 1] <= tab->box[y][x - 1] &&
            tab->box[y - 1][x - 1] <= tab->box[y - 1][x])
            tab->box[y][x] = tab->box[y - 1][x - 1] + 1;
    }
}

int change_int(tab_t *tab, bsq_t *bsq, int y, int x)
{
    if (tab->tab[y + 1][x] != '.' && tab->tab[y + 1][x] != 'o')
        return 1;
    if (tab->tab[y + 1][x] == '.')
        tab->box[y][x] = 1;
    if (tab->tab[y + 1][x] == 'o') {
        tab->box[y][x] = 0;
        return 0;
    }
    find_square(tab, y, x);
    find_max(tab, bsq, y, x);
    return 0;
}

int init_second(tab_t *tab, bsq_t *bsq, int y, int *x)
{
    int i = y + 1;

    for (*x = 0; tab->tab[i][*x] != '\n' && tab->tab[i][*x] != '\0'; (*x)++) {
        if (change_int(tab, bsq, y, *x) == 1)
            return 1;
    }
    if (*x != tab->nb_rows)
        return 1;
    tab->box[y][*x] = -1;
    return 0;
}

int process_file(char *str)
{
    tab_t *tab = NULL;
    bsq_t bsq = {0, 0, 0};
    int res;

    tab = malloc(sizeof(tab_t));
    init_struct(tab);
    if (fs_open_file(tab, str) == 84)
        return 84;
    if (my_str_isnum(tab->tab[0]) == 0)
        return 84;
    res = init_int(tab, &bsq);
    if (res == 1) {
        display_square(tab, &bsq);
        return 0;
    } else if (res == 84)
        return 84;
    display_square(tab, &bsq);
    return 0;
}
