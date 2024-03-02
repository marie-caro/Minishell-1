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



int my_puthex(long long nb, char conv)
{
    int stock = 0;
    long long a = nb % 16;
    int b = 7;

    if (conv == 'x')
        b += 32;
    if (nb > 0 && nb <= 9)
        stock += my_putchar(nb + '0');
    if (nb > 9) {
        stock += my_puthex(nb / 16, conv);
        if (a <= 9 && a >= 0)
            stock += my_putchar(a + '0');
        else
            stock += my_putchar(a + b + '0');
    }
    return stock;
}

int verif_conv(char conv, int *a, int *b)
{
    if (conv == 'o') {
        *a = 7;
        *b = 8;
    }
    return 0;
}

int if_nb_x(int nb, char conv, int *b)
{
    int stock = 0;

    if (nb == 0) {
        my_putchar('0');
        return 1;
    }
    *b = 16;
    stock += my_puthex(nb, conv);
    return stock;
}

int my_put_all(long long int nb, char conv, int stock)
{
    int a = 9;
    int b = 10;

    if (nb < 0)
        stock += my_put_nbr(4294967295 + nb);
    verif_conv(conv, &a, &b);
    if (conv == 'x' || conv == 'X') {
        stock += if_nb_x(nb, conv, &b);
        return stock;
    }
    if ((int) nb > 0 && (int) nb <= a)
        stock += my_putchar((int) nb + '0');
    if (nb == 0 && (conv != 'x' || conv != 'X'))
        stock += my_putchar((int) nb + '0');
    else if (nb > a) {
        stock += my_put_all((int) nb / b, conv, stock);
        stock += my_putchar((nb % b) + '0');
    }
    return stock;
}

int my_print_all(va_list list, void *flag, int stock)
{
    int a = my_put_all(va_arg(list, long long int), *(char *) flag, stock);

    return a;
}
