/*
** EPITECH PROJECT, 2023
** edfc
** File description:
** wedfc
*/
#include <stdio.h>
#include "my.h"



int my_put_nbr_rec_format_h(int nb, int a)
{
    int m = 0;

    if (nb <= 9) {
        my_putchar(nb + '0');
        a++;
        return a;
    }
    m = nb % 10;
    a++;
    a = my_put_nbr_rec_format_h(nb / 10, a);
    my_putchar(m + '0');
    return a;
}

int my_put_nbr_format_h(short int nb)
{
    int a = 0;

    if (nb < 0) {
        my_putchar('-');
        nb = -nb;
        a++;
    }
    return my_put_nbr_rec_format_h(nb, a);
}

int print_format_h(va_list list, void *)
{
    int a = my_put_nbr_format_h(va_arg(list, int));

    return a;
}
