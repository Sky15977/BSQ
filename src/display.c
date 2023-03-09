/*
** EPITECH PROJECT, 2023
** display.c
** File description:
** display square
*/

#include "bsq.h"

void square_max(tab_t *tab, bsq_t *bsq)
{
    int y = bsq->y_max + 1;
    int x = bsq->x_max;
    int size_max = bsq->size_max;
    int max = bsq->size_max;

    for (; max > 0; max--) {
        for (size_max = bsq->size_max; size_max > 0; size_max--) {
            tab->tab[y][x] = 'x';
            x--;
        }
        x = bsq->x_max;
        y--;
    }
}

void display_square(tab_t *tab, bsq_t *bsq)
{
    int y;

    square_max(tab, bsq);
    for (y = 1; tab->tab[y] != 0; y++)
        write(1, tab->tab[y], tab->nb_rows + 1);
    for (y = 0; tab->tab[y] != NULL; y++)
        free(tab->tab[y]);
    for (y = 0; tab->tab[y] != NULL; y++)
        free(tab->box[y]);
    free(tab->box);
    free(tab->tab);
    free(tab);
}
