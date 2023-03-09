/*
** EPITECH PROJECT, 2022
** my_getnbr
** File description:
** this will return a number and as input get string
*/

#include "my.h"

static int check_str(char const *str, int i)
{
    int z = 0;

    for (; str[i] != '\0'; i++) {
        if (str[i] >= '0' && str[i] <= '9')
            z++;
    }
    return z;
}

static int check_neg(char const *str, int *i, int compt)
{
    while (str[*i] == '-' || str[*i] == '+') {
        if (str[*i] == '-')
            compt *= -1;
        (*i)++;
    }
    return compt;
}

int my_getnbr(char const *str)
{
    int	nb = 0;
    int	compt = 1;
    int	i = 0;
    int z = 0;

    compt = check_neg(str, &i, compt);
    z = check_str(str, i);
    if (z > 10)
        return 84;
    while (str[i] != '\0') {
        if (str[i] >= '0' && str[i] <= '9') {
            nb = nb * 10;
            nb = nb + str[i] - 48;
            i++;
        } else
            return (nb * compt);
    }
    return (nb * compt);
}
