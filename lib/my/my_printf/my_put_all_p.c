/*
** EPITECH PROJECT, 2023
** put p
** File description:
** fdx
*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "my.h"



int my_puthex_p(unsigned long long nb, char conv)
{
    int stock = 0;
    long long int a = nb % 16;
    int b = 7;

    if (conv == 'x')
        b += 32;
    if (nb > 0 && nb <= 9)
        stock += my_putchar(nb + '0');
    if (nb > 9) {
        stock += my_puthex_p(nb / 16, conv);
        if (a <= 9 && a >= 0)
            stock += my_putchar(a + '0');
        else
            stock += my_putchar(a + b + '0');
    }
    return stock;
}

int my_put_alternate(long long nb, char flag)
{
    int stock = 0;

    if (nb == 0) {
        return 0;
    }
    if (flag == 'o' || flag == 'x' || flag == 'X') {
        stock += my_putchar('0');
    }
    if (flag == 'x' || flag == 'X') {
        stock += my_putchar(flag);
    }
    return stock;
}

int flag_needed(char *str, int *i, long long nb)
{
    int stock = 0;

    if (str[*i + 1] == 'x' || str[*i + 1] == 'X' || str[*i + 1] == 'o')
        stock += my_put_alternate(nb, str[*i + 1]);
    else
        return 0;
    return stock;
}

int if_flag(char *str, int *i, long long nb)
{
    int stock = 0;

    if (str[*i] == '%') {
        if (str[*i + 1] == '+') {
                stock += my_putchar('+');
                (*i)++;
        }
        if (str[*i + 1] == '#') {
            (*i)++;
            stock += flag_needed(str, i, nb);
        }
    }
    return stock;
}
