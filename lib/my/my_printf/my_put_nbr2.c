/*
** EPITECH PROJECT, 2023
** put nbr2
** File description:
** for format
*/
#include <stdio.h>
#include "my.h"



int my_put_nbr_rec_format_l(long int nb, int a)
{
    int m = 0;

    if (nb <= 9) {
        my_putchar(nb + '0');
        a++;
        return a;
    }
    m = nb % 10;
    a++;
    a = my_put_nbr_rec_format_l(nb / 10, a);
    my_putchar(m + '0');
    return a;
}

int my_put_nbr_format_l(long int nb)
{
    int a = 0;

    if (nb < 0) {
        my_putchar('-');
        nb = -nb;
        a++;
    }
    return my_put_nbr_rec_format_l(nb, a);
}

int print_format_l(va_list list, void *)
{
    int a = my_put_nbr_format_l(va_arg(list, long int));

    return a;
}
