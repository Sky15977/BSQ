/*
** EPITECH PROJECT, 2023
** error.c
** File description:
** error
*/

#include "bsq.h"

int manage_error(void)
{
    my_putstr("retry with -h\n");
    return 84;
}

int manage_h(void)
{
    my_putstr("USAGE:\n   ./bsq [filepath]\n\tor\n   ./bsq [number] [map]\n");
    my_putstr("\nOPTION:\n   filepath:\tis a map square\n   number:\tdefine");
    my_putstr(" a lenght of square\n   map:   \tchoice a string, ex(..o.o)\n");
    return 0;
}
