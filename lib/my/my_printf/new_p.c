/*
** EPITECH PROJECT, 2023
** new pc
** File description:
** p
*/

#include "my.h"


#include <stdlib.h>

int my_put_p(void *str)
{
    int a = 0;

    if (str != NULL) {
        my_putstr("0x");
        a = my_puthex_p((unsigned long long) str, 'x');
        return a;
    } else {
        my_putstr("(nil)");
        return 5;
    }
    return 0;
}

int my_print_p(va_list list, __attribute__((unused)) void *flag)
{
    int a = my_put_p(va_arg(list, void *));

    return a;
}
