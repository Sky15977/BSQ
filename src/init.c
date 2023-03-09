/*
** EPITECH PROJECT, 2023
** init.c
** File description:
** init tab & openfile
*/

#include "bsq.h"

int init_int(tab_t *tab, bsq_t *bsq)
{
    int y = 0;
    int x = 0;

    tab->box = malloc(sizeof(int *) * (tab->nb_cols + 1));
    for (; y < tab->nb_cols; y++) {
        tab->box[y] = malloc(sizeof(int) * (tab->nb_rows + 1));
        if (init_second(tab, bsq, y, &x) == 1)
            return 84;
    }
    tab->box[y] = NULL;
    if (x == 1 || y == 1)
        return 1;
    if (y != tab->nb_cols)
        return 84;
    return 0;
}

void double_tab(tab_t *tab)
{
    int i = 0;
    int x = 0;
    int y = 0;

    tab->tab = malloc(sizeof(char *) * (tab->nb_cols + 2));
    while (y <= tab->nb_cols) {
        x = 0;
        tab->tab[y] = malloc(sizeof(char) * tab->nb_rows + 2);
        while (tab->file[i] != '\0' && tab->file[i] != '\n') {
            tab->tab[y][x] = tab->file[i];
            x++;
            i++;
        }
        tab->tab[y][x] = '\n';
        tab->tab[y][x + 1] = '\0';
        y++;
        i++;
    }
    tab->tab[y] = NULL;
}

void init_square(tab_t *tab)
{
    int i = 0;
    int nb = 0;

    tab->nb_cols = my_getnbr(tab->file);
    for (; tab->file[i] != '\n'; i++);
    i++;
    for (; tab->file[i] != '\n' && tab->file[i] != 0; i++)
        nb++;
    tab->nb_rows = nb;
}

int fs_open_file(tab_t *tab, char *filepath)
{
    struct stat sb;
    int fd = open(filepath, O_RDONLY);

    if (fd == -1)
        exit(84);
    if (stat(filepath, &sb) == -1) {
        close(fd);
        exit(84);
    }
    if (sb.st_size == 0)
        return 84;
    tab->file = malloc(sizeof(char) * (sb.st_size + 1));
    tab->size = read(fd, tab->file, sb.st_size);
    tab->file[tab->size] = '\0';
    close(fd);
    init_square(tab);
    double_tab(tab);
    free(tab->file);
    return 0;
}

void init_struct(tab_t *tab)
{
    tab->nb_rows = 0;
    tab->nb_cols = 0;
    tab->size = 0;
    tab->file = NULL;
    tab->tab = NULL;
}
