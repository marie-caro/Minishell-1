/*
** EPITECH PROJECT, 2023
** hgfdsa
** File description:
** kgfdaz
*/
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include "my.h"



int print_char(va_list list, void *)
{
    char cv = va_arg(list, int);

    write(1, &cv, 1);
    return 1;
}

int print_str(va_list list, void *)
{
    int len = 0;
    char *len2 = va_arg(list, char *);

    my_putstr(len2);
    len = my_strlen(len2);
    return len;
}

int print_nbr(va_list list, void *)
{
    int a = my_put_nbr(va_arg(list, int));

    return a;
}

int print_char_spec(__attribute__((unused)) va_list list, void *)
{
    my_putchar('%');
    return 1;
}

int print_hexoct(va_list list, void *flag)
{
    int stock = 0;
    long int a = my_print_all(list, flag, stock);

    return a;
}
