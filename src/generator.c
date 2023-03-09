/*
** EPITECH PROJECT, 2023
** generator.c
** File description:
** generated a map bsq
*/

#include "bsq.h"

void for_create(tab_t *tab, char *str, int y, int x)
{
    int i = 0;

    for (x++; x < (tab->nb_rows + 1) * tab->nb_cols + 1; x++) {
        for (y = 0; y < tab->nb_rows; y++) {
            tab->file[x] = str[i];
            i = (str[i + 1] == '\0') ? 0 : i + 1;
            x++;
        }
        tab->file[x] = '\n';
    }
}

void create_buffer(tab_t *tab, char *str, char *src)
{
    int nb = my_strlen(src);
    int x = 0;
    int y = 0;
    int a = 0;

    tab->nb_rows = my_getnbr(src);
    tab->nb_cols = my_getnbr(src);
    a = ((nb + tab->nb_rows + 3) * tab->nb_cols + 2);
    tab->file = malloc(sizeof(char) * a);
    for (; src[x] != '\0'; x++)
        tab->file[x] = src[x];
    tab->file[x] = '\n';
    for_create(tab, str, y, x);
    tab->file[x] = '\0';
    tab->size = x;
    return;
}

int generate_map(char *src, char *str)
{
    tab_t *tab = NULL;
    bsq_t bsq = {0, 0, 0};
    int res;

    tab = malloc(sizeof(tab_t));
    init_struct(tab);
    if (my_str_isnum(src) == 0)
        return 84;
    create_buffer(tab, str, src);
    double_tab(tab);
    free(tab->file);
    res = init_int(tab, &bsq);
    if (res == 1) {
        display_square(tab, &bsq);
        return 0;
    } else if (res == 84)
        return 84;
    display_square(tab, &bsq);
    return 0;
}
