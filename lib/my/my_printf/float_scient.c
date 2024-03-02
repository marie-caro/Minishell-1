/*
** EPITECH PROJECT, 2023
** printf
** File description:
** call to put_float and put_scientific
*/

#include <stdio.h>
#include "my.h"



int my_print_float(va_list list, void *flag)
{
    int a = my_put_float(va_arg(list, double), flag);

    return a;
}

int my_print_scientific(va_list list, void *flag)
{
    int a = my_put_scientific(va_arg(list, double), flag);

    return a;
}

int my_print_scientific_maj(va_list list, void *flag)
{
    int a = my_put_scientific_maj(va_arg(list, double), flag);

    return a;
}
