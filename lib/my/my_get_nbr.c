/*
** EPITECH PROJECT, 2023
** radar
** File description:
** my_get_nbr.c
*/
#include <stdio.h>
#include <stdlib.h>
#include "my.h"

int my_compute_power_rec(int nb, int p)
{
    if (p == 1) {
        return (nb);
    }
    if (p == 0) {
        return (1);
    }
    if (p < 0) {
        return (0);
    } else {
        p--;
        return (my_compute_power_rec(nb, p) * nb);
    }
}

int what_power(char *new_str)
{
    int len = my_strlenn(new_str);
    int nb = 0;
    long long int new_nbr = 0;

    for (int i = 0; i < len; i++) {
        nb = len - i - 1;
        new_str[i] -= '0';
        new_nbr += new_str[i] * my_compute_power_rec(10, nb);
    }
    return new_nbr;
}

int my_get_nbr(char *str)
{
    int len = my_strlenn(str);
    int power;
    char *new_str;
    char *help_str = malloc(sizeof(char) * (len + 1));

    new_str = my_strdup(str);
    for (int i = 0; i <= len; i++) {
        if (i < len && (new_str[i] <= '9' && new_str[i] >= '0'))
            help_str[i] = new_str[i];
        if ((i == len) || (str[i] > '9') || (str[i] < '0')) {
            new_str[i] = '\0';
            break;
        }
    }
    power = what_power(new_str);
    return power;
}
