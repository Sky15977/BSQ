/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** main
*/

#include "bsq.h"

int main(int ac, char **av)
{
    if (ac < 2 || ac > 3)
        return manage_error();
    if (av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == 0)
        return manage_h();
    if (ac == 3)
        return generate_map(av[1], av[2]);
    return process_file(av[1]);
}
