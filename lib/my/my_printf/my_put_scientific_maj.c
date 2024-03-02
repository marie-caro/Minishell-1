/*
** EPITECH PROJECT, 2023
** my_put_scientific
** File description:
** transform to a scientific value
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "my.h"



int puissance_maj(int count)
{
    int chiffre = 1;

    while (count > 0) {
        chiffre *= 10;
        count -= 1;
    }
    return chiffre;
}

int my_output_maj(int w, int h, int j, int b)
{
    my_put_nbr(w);
    my_putchar('.');
    if (b >= 10)
        my_put_nbr(h);
    my_put_nbr((j / b));
    my_putchar('E');
    my_putchar('+');
    return 0;
}

int my_put_scientific_maj(double nb, __attribute__((unused)) void *flag)
{
    unsigned long long int k = 0;
    unsigned long long int j = 0;
    int i = 0;
    int count = 0;
    int w = 0;
    int h = 0;
    int stock = 0;

    k = nb * 1000000;
    w = (int) nb;
    for (; w >= 10; count++)
        w /= 10;
    i = (int) nb * 1000000;
    j = k - i;
    h = (int) nb - (w * puissance_maj(count));
    my_output_maj(w, h, j, puissance_maj(count));
    if (count < 10)
        my_putchar('0');
    my_put_nbr(count);
    return stock;
}
