/*
** EPITECH PROJECT, 2023
** my_putstr
** File description:
** This file displays the characters of a string one by one
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "my.h"

int my_put_float(double nb, __attribute__((unused))void *flag)
{
    unsigned long long k = 0;
    int a = 0;
    unsigned long long j = 0;
    int i = 0;
    int stock = 0;

    if (nb == 0) {
        my_putstr("0.000000");
        return 8;
    }
    k = ABS(nb) * 1000000;
    a = (int) nb;
    i = ABS(a) * 1000000;
    j = k - i;
    stock += my_put_nbr(a);
    my_putchar('.');
    stock++;
    stock += my_put_nbr(j);
    return stock;
}
