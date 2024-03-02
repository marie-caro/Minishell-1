/*
** EPITECH PROJECT, 2023
** edfc
** File description:
** wedfc
*/
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"

int my_puthex_l(long long nb, char conv)
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
            stock += my_putchar((nb % 16) + '0');
        else
            stock += my_putchar(((nb % 16) + b) + '0');
    }
    return stock;
}

int print_hexa_l(va_list list, void *)
{
    int a = my_puthex_l(va_arg(list, long long), 'x');

    return a;
}

int my_puthex_h(short int nb, char conv)
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
            stock += my_putchar((nb % 16) + '0');
        else
            stock += my_putchar(((nb % 16) + b) + '0');
    }
    return stock;
}

int print_hexa_h(va_list list, void *)
{
    int a = my_puthex_h(va_arg(list, int), 'x');

    return a;
}
