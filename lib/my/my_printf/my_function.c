/*
** EPITECH PROJECT, 2023
** kyhuds
** File description:
** ygfvd
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"



int my_putchar(char c)
{
    write(1, &c, 1);
    return 1;
}

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return i;
}

int my_put_nbr_rec(long long int nb, int a)
{
    int m = 0;

    if (nb <= 9) {
        my_putchar(nb + '0');
        a++;
        return a;
    }
    m = nb % 10;
    a++;
    a = my_put_nbr_rec(nb / 10, a);
    my_putchar(m + '0');
    return a;
}

int my_put_nbr(long long int nb)
{
    int a = 0;

    if (nb < 0) {
        my_putchar('-');
        nb = -nb;
        a++;
    }
    return my_put_nbr_rec(nb, a);
}

int my_putstr(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        my_putchar(str[i]);
    }
    return 0;
}
